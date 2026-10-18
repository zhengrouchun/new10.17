#include "main.h" /* 引入GPIO、时钟与毫秒计数接口。 */
#include "oled_bus_timeout_fix.h" /* 引入本文件公开接口与OLED_USE_SOFTWARE_I2C宏。 */

/* 引脚定义：与main.h中的SCL_Pin/SDA_Pin一致，PB6接OLED第3脚SCL，PB7接第4脚SDA。 */
#define OLED_SCL_PIN GPIO_PIN_6 /* PB6连接OLED第3脚SCL。 */
#define OLED_SDA_PIN GPIO_PIN_7 /* PB7连接OLED第4脚SDA。 */
#define OLED_BUS_PINS (OLED_SCL_PIN | OLED_SDA_PIN) /* 同时选择两根总线引脚。 */

/* 短延时循环次数：满足Proteus仿真与真实SSD1306的建立/保持时间，真实硬件下约数微秒。 */
#define OLED_BUS_DELAY_LOOPS 30

static const char *bus_error = "OK"; /* 保存最近交易的真实结果，供串口诊断。 */
static const char *bus_stage = "IDLE"; /* 保存最近交易阶段，成功后为DONE。 */

static void BusDelay(void) /* 有限短延时，保证SCL高低宽度与数据建立时间。 */
{
    volatile int remaining; /* 防止编译器把延时循环优化删除。 */
    for (remaining = OLED_BUS_DELAY_LOOPS; remaining > 0; --remaining)
    {
        __NOP(); /* 至少消耗一个CPU周期。 */
    }
}

static void BusSetScl(int high) /* 开漏模式下写1=释放（由上拉拉高），写0=拉低。 */
{
    HAL_GPIO_WritePin(GPIOB, OLED_SCL_PIN, high ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

static void BusSetSda(int high) /* 同上，SDA线由主机驱动。 */
{
    HAL_GPIO_WritePin(GPIOB, OLED_SDA_PIN, high ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void OledBus_Init(void) /* 接管显示引脚：开漏+上拉，与CubeMX(.ioc)一致；修复此前NOPULL丢失上拉导致I2C失败的根因。 */
{
    GPIO_InitTypeDef gpio = {0}; /* 初始化GPIO配置结构体。 */
    __HAL_RCC_GPIOB_CLK_ENABLE(); /* 开启PB6和PB7所在端口的时钟。 */
    __HAL_RCC_I2C1_CLK_ENABLE(); /* 临时开启I2C1时钟，允许访问控制寄存器。 */
    CLEAR_BIT(I2C1->CR1, I2C_CR1_PE); /* 关闭硬件I2C，避免外设占用软件总线引脚。 */
    __HAL_RCC_I2C1_CLK_DISABLE(); /* 软件实现不使用I2C1外设时钟。 */
    gpio.Pin = OLED_BUS_PINS; /* 同时配置PB6和PB7。 */
    gpio.Mode = GPIO_MODE_OUTPUT_OD; /* 开漏输出，与参考代码和CubeMX一致。 */
    gpio.Pull = GPIO_PULLUP; /* 关键修复：保留内部上拉，开漏释放后由电阻把线拉高；此前NOPULL导致浮空、I2C时序失败。 */
    gpio.Speed = GPIO_SPEED_FREQ_HIGH; /* 高速GPIO边沿。 */
    HAL_GPIO_Init(GPIOB, &gpio); /* 应用软件I2C引脚配置。 */
    BusSetScl(1); /* 空闲时SCL为高。 */
    BusSetSda(1); /* 空闲时SDA为高，符合I2C总线空闲状态。 */
    BusDelay();
    HAL_Delay(50); /* 上电稳定延时，SSD1306上电后建议等待再通信。 */
}

const char *OledBus_Diagnose(void) /* 启动时执行一次独立线测试，返回SCL/SDA的四组读数（顺序SCL,SDA）。 */
{
    static char levels[] = "HH/HH/HH/HH"; /* 四组依次是释放、只拉低SCL、只拉低SDA、恢复；避免C三字符组改变字符串长度。 */
    BusSetScl(1); BusSetSda(1); BusDelay();
    levels[0] = HAL_GPIO_ReadPin(GPIOB, OLED_SCL_PIN) == GPIO_PIN_SET ? 'H' : 'L'; /* 保存时钟读数。 */
    levels[1] = HAL_GPIO_ReadPin(GPIOB, OLED_SDA_PIN) == GPIO_PIN_SET ? 'H' : 'L'; /* 保存数据读数。 */
    BusSetScl(0); BusDelay();
    levels[3] = HAL_GPIO_ReadPin(GPIOB, OLED_SCL_PIN) == GPIO_PIN_SET ? 'H' : 'L';
    levels[4] = HAL_GPIO_ReadPin(GPIOB, OLED_SDA_PIN) == GPIO_PIN_SET ? 'H' : 'L';
    BusSetScl(1); BusSetSda(0); BusDelay();
    levels[6] = HAL_GPIO_ReadPin(GPIOB, OLED_SCL_PIN) == GPIO_PIN_SET ? 'H' : 'L';
    levels[7] = HAL_GPIO_ReadPin(GPIOB, OLED_SDA_PIN) == GPIO_PIN_SET ? 'H' : 'L';
    BusSetScl(1); BusSetSda(1); BusDelay();
    levels[9] = HAL_GPIO_ReadPin(GPIOB, OLED_SCL_PIN) == GPIO_PIN_SET ? 'H' : 'L';
    levels[10] = HAL_GPIO_ReadPin(GPIOB, OLED_SDA_PIN) == GPIO_PIN_SET ? 'H' : 'L';
    return levels; /* 返回静态字符串供串口打印。 */
}

/* 每发送八位就读取第九位应答；开漏输出写高即可释放SDA，无需切换输入模式。 */
static void I2C_Start(void) /* SCL高时SDA由高变低，产生START。 */
{
    BusSetSda(1);
    BusSetScl(1);
    BusDelay();
    BusSetSda(0);
    BusDelay();
    BusSetScl(0);
    BusDelay();
}

static void I2C_Stop(void) /* SCL高时SDA由低变高，产生STOP。 */
{
    BusSetSda(0);
    BusSetScl(1);
    BusDelay();
    BusSetSda(1);
    BusDelay();
}

static int I2C_WriteByte(uint8_t value) /* 发送八位数据，并返回从机在第九个时钟是否应答。 */
{
    int bit; /* 记录当前发送的是字节中的哪一位。 */
    int acknowledged; /* 保存第九个时钟期间从机是否把SDA拉低。 */
    for (bit = 0; bit < 8; ++bit)
    {
        BusSetSda((value & 0x80) ? 1 : 0); /* 先建立数据位。 */
        BusDelay(); /* 保证SDA在SCL上升沿之前保持稳定。 */
        BusSetScl(1); /* 从机在SCL高电平期间采样。 */
        BusDelay();
        BusSetScl(0); /* 结束该数据位。 */
        BusDelay();
        value = (uint8_t)(value << 1); /* 下一位移到最高位。 */
    }
    BusSetSda(1); /* 主机释放开漏SDA，让从机能够驱动应答位。 */
    BusDelay(); /* 等待SDA释放完成，再产生第九个时钟。 */
    BusSetScl(1); /* 第九个时钟的高电平是从机应答采样窗口。 */
    BusDelay(); /* 等待从机拉低SDA并使电平稳定。 */
    acknowledged = HAL_GPIO_ReadPin(GPIOB, OLED_SDA_PIN) == GPIO_PIN_RESET; /* SDA为低表示ACK，为高表示NACK。 */
    BusSetScl(0); /* 结束应答时钟，准备发送下一字节或停止信号。 */
    BusDelay(); /* 保证时钟低电平保持时间。 */
    return acknowledged; /* 把实际应答交给交易层判断。 */
}

int OledBus_Write(uint8_t address, const uint8_t *data, uint16_t count) /* 为OLED执行一次完整写交易。 */
{
    uint16_t index; /* 逐字节处理控制字、命令或像素数据。 */
    bus_error = "OK"; /* 开始新交易，清除上一笔错误。 */
    bus_stage = "ADDRESS"; /* 先检查OLED是否应答七位设备地址。 */
    I2C_Start(); /* 发起本次I2C写交易。 */
    if (!I2C_WriteByte((uint8_t)(address << 1))) /* 七位地址左移，最低位零表示写；检查地址应答。 */
    {
        bus_error = "ADDRESS_NACK"; /* 地址未应答通常表示接线、供电或地址错误。 */
        I2C_Stop(); /* 即使无应答也释放两根总线。 */
        return 0; /* 不把未连接的OLED报告为在线。 */
    }
    for (index = 0; index < count; ++index)
    {
        bus_stage = index == 0 ? "CONTROL" : "PAYLOAD"; /* 区分控制字和命令或像素数据。 */
        if (!I2C_WriteByte(data[index])) /* 每个字节都必须收到从机应答。 */
        {
            bus_error = index == 0 ? "CONTROL_NACK" : "PAYLOAD_NACK"; /* 记录拒绝的是哪类字节。 */
            I2C_Stop(); /* 失败时仍然释放总线。 */
            return 0; /* 把失败交给OLED初始化和在线状态处理。 */
        }
    }
    I2C_Stop(); /* 所有字节都获应答后发送停止信号。 */
    BusSetSda(1); /* 所有返回路径都释放总线，恢复空闲高电平。 */
    BusSetScl(1); /* 释放SCL，让总线恢复空闲高电平。 */
    bus_stage = "DONE"; /* 完整交易成功后才报告完成。 */
    return 1; /* 地址、控制字和数据都得到应答才表示发送成功。 */
}

const char *OledBus_Error(void) /* 返回最近交易的实际错误。 */
{
    return bus_error; /* 返回稳定的常量字符串。 */
}

const char *OledBus_Stage(void) /* 返回最近交易停止的阶段。 */
{
    return bus_stage; /* 返回失败位置或DONE。 */
}
