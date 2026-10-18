#ifndef OLED_BUS_TIMEOUT_FIX_H /* 防止重复包含总线修复接口。 */
#define OLED_BUS_TIMEOUT_FIX_H /* 标记头文件已经包含。 */
#include <stdint.h> /* 使用明确位宽的地址和字节数。 */
#define OLED_USE_SOFTWARE_I2C 1 /* 当前CubeMX工程使用GPIO软件I2C。 */
#if !OLED_USE_SOFTWARE_I2C /* 当前工程已删除硬件I2C初始化，不能只改宏就切换总线。 */
#error Restore CubeMX I2C1 initialization before selecting hardware I2C
#endif /* 需要硬件模式时须同时恢复句柄、初始化和CubeMX配置。 */
void OledBus_Init(void); /* 关闭硬件I2C1并释放PB6/PB7，保留外接上拉。 */
const char *OledBus_Diagnose(void); /* 返回释放、单线拉低和恢复的四组SCL/SDA读数。 */
int OledBus_Write(uint8_t address, const uint8_t *data, uint16_t count); /* 收到地址和全部数据的ACK且STOP成功才返回真。 */
const char *OledBus_Error(void); /* 返回可读错误名称，避免只报告无法定位的超时码。 */
const char *OledBus_Stage(void); /* 返回最近一次交易所处阶段。 */
#endif /* 结束重复包含保护。 */
