/* 解决应用参数散落在 main.c：集中保存检测、按键和串口参数。 */
#ifndef DIV_CONFIG_H
#define DIV_CONFIG_H
#include "main.h"

#define DIV_REFERENCE_SERIAL_MODE 0 /* 1=PB12使能1V测试并按截图连续报告，不切3V；0=原正常工况切3V流程。 */
#define ADC_TIMEOUT_MILLISECONDS 20 /* 最多等待一次 ADC 转换 20 ms。 */
#define UART_TIMEOUT_MILLISECONDS 200 /* 57600波特下短日志通常几十毫秒内完成；200ms保留充足余量。 */
#define REPORT_BUFFER_SIZE 384 /* 容纳整条带状态和错误信息的报告。 */
#define BUTTON_TRACE_BUFFER_SIZE 512 /* 容纳按键电平、配置、累计采样和最长低电平时间。 */
#define TEST_POWER_PIN GPIO_PIN_12 /* PB12，芯片第 25 脚，控制 1 V 测试电源开关。 */
#define RUN_POWER_PIN GPIO_PIN_13 /* PB13，芯片第 26 脚，控制 3 V 运行电源开关。 */
#define RETEST_BUTTON_PIN GPIO_PIN_4 /* PA4，芯片第 14 脚，复测按钮按下接地。 */
#define STOP_BUTTON_PIN GPIO_PIN_5 /* PA5，芯片第 15 脚，停止按钮按下接地。 */
#define POWER_BREAK_MILLISECONDS 5 /* 两路电源都断开后等待 5 ms，保证先断后合。 */
#define TEST_POWER_OBSERVATION_MILLISECONDS 1000 /* 正常运行只需短暂稳定；若人工观察1V可临时改回1500或更大。 */
#define TEST_SAMPLE_HOLD_MILLISECONDS 5000 /* ADC采样后保持1V测试5秒：此窗口内Proteus电压表、串口TEST_SAMPLE和OLED显示的是同一轮1V检测数据；随后再切换最终供电。 */
#define BUTTON_DEBOUNCE_MILLISECONDS 20 /* 复测按钮稳定 20 ms 后接受一次按下事件。 */
#define CONTROL_POLL_MILLISECONDS 1 /* 主循环每隔 1 ms 检查复测；停止由中断立即断电。 */
#define RETEST_TRACE_INTERVAL_MILLISECONDS 5000 /* 主循环诊断改为5秒一次，避免与HEARTBEAT重复占用串口。 */
#define STATUS_INTERVAL_MILLISECONDS 2000 /* 每2秒一次简短心跳；按钮事件仍即时打印，减少Proteus串口负载。 */
#define AUTO_MEASURE_INTERVAL_MILLISECONDS 0 /* 零表示仅启动时及按PA4复测时检测，不自动重复采样。 */
#define TERMINAL_STARTUP_WAIT_MILLISECONDS 50 /* 上电后给Proteus虚拟终端50ms建立接收状态。 */
#define DIV_NORMAL_CASE 0 /* 正常工况为 DIV0，只有该状态允许进入运行。 */
#define OLED_PROGRESS_TRACE_ENABLE 0 /* 0=关闭每次OLED页写入的串口日志，显著减少阻塞；需要定位OLED时再改1。 */


#endif /* DIV_CONFIG_H */
