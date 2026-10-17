#include "oled_display.h" /* 声明主程序使用的四行文字接口。 */
#include "OLED.h" /* 调用从参考工程原样复制的初始化和显示函数。 */
#include <stddef.h> /* 用 NULL 明确表示没有指针或回调。 */
#include <string.h> /* 使用 strlen 和 memcpy 管理固定宽度文字。 */
#define OLED_POWER_UP_WAIT_MILLISECONDS 50 /* 保留原主工程在首次通信前的 50 ms 上电稳定等待。 */

static char display_lines[OLED_TEXT_ROWS][OLED_TEXT_COLUMNS + 1]; /* 保存待显示的四行字符及字符串结束符。 */
static int display_initialized = 0; /* 记录是否执行了参考驱动的初始化，不冒充从机 ACK。 */
static void (*page_completed)(int completed_pages) = NULL; /* 保存可选的显示进度回调。 */

int Oled_Init(void) /* 在 GPIO 初始化后调用参考驱动的完整初始化和清屏流程。 */
{
    int row; /* 遍历屏幕四行，建立全空格的初始内容。 */
    HAL_Delay(OLED_POWER_UP_WAIT_MILLISECONDS); /* 参考代码的空循环可能被编译器优化，使用 HAL 毫秒时钟保证等待存在。 */
    OLED_Init(); /* 参考驱动依次发送初始化命令、开屏命令并清空显存。 */
    OLED_ShowString(1, 1, "BOOT OLED"); /* 清屏结束后立即写入非零字模，用于确认 MCU 已执行到显示阶段。 */
    for (row = 0; row < OLED_TEXT_ROWS; ++row) /* 把各行缓冲初始化为空白。 */
    {
        memset(display_lines[row], ' ', OLED_TEXT_COLUMNS); /* 用空格覆盖旧字符。 */
        display_lines[row][OLED_TEXT_COLUMNS] = '\0'; /* 保证每行是合法的 C 字符串。 */
    }
    display_initialized = 1; /* 仅表示已执行初始化；参考驱动没有读取 ACK。 */
    return display_initialized; /* 告诉上层初始化函数已经执行。 */
}

int Oled_IsInitialized(void) /* 查询参考驱动初始化是否执行。 */
{
    return display_initialized; /* 此值不能证明 OLED 已响应或实际点亮。 */
}

uint8_t Oled_Address(void) /* 返回参考工程实际使用的七位地址。 */
{
    return 0x3C; /* 参考工程发送的写地址 0x78 对应七位地址 0x3C。 */
}

void Oled_SetLine(int row, const char *text) /* 把本轮真实测量数据写入指定行。 */
{
    size_t length; /* 保存截断后的可显示字符数。 */
    if (row < 0 || row >= OLED_TEXT_ROWS || text == NULL) /* 拒绝无效行号和空指针。 */
    {
        return; /* 不修改现有显示内容。 */
    }
    length = strlen(text); /* 计算传入文字的实际长度。 */
    if (length > OLED_TEXT_COLUMNS) /* 防止超过参考字库的每行十六列。 */
    {
        length = OLED_TEXT_COLUMNS; /* 截掉屏幕右侧无法容纳的字符。 */
    }
    memset(display_lines[row], ' ', OLED_TEXT_COLUMNS); /* 清除上一轮较长文字的残留。 */
    memcpy(display_lines[row], text, length); /* 复制本轮能够显示的字符。 */
    display_lines[row][OLED_TEXT_COLUMNS] = '\0'; /* 给 OLED_ShowString 提供正确终止符。 */
}

void Oled_SetProgressCallback(void (*callback)(int completed_pages)) /* 设置每完成一行的通知。 */
{
    page_completed = callback; /* 仅保存函数地址，由刷新流程调用。 */
}

int Oled_Flush(void) /* 按参考工程的 OLED_ShowString 调用方式刷新四行。 */
{
    int row; /* 依次处理从上到下的四行。 */
    if (!display_initialized) /* 禁止在 OLED_Init 之前发送文字。 */
    {
        return 0; /* 告诉上层本轮没有执行显示。 */
    }
    for (row = 0; row < OLED_TEXT_ROWS; ++row) /* 每一文字行对应两个八像素显存页。 */
    {
        OLED_ShowString((uint8_t)(row + 1), 1, display_lines[row]); /* 用参考驱动的 8×16 字模从第一列写入整行。 */
        if (page_completed != NULL) /* 注册过进度回调时发送当前完成位置。 */
        {
            page_completed((row + 1) * 2); /* 第四行完成时共写入八个显存页。 */
        }
    }
    return 1; /* 只表示函数执行结束；参考驱动不验证 ACK 或物理画面。 */
}
