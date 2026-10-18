/* 解决测量和显示各自维护结果结构：共享一次测量记录。 */
#ifndef DIV_APP_TYPES_H
#define DIV_APP_TYPES_H
#include <stdint.h>
typedef struct /* 保存一次检测结果，初始化时所有有效标志为假。 */
{
    uint32_t vb_raw; /* VB 的真实 ADC 原码，仅在 vb_valid 为真时可用。 */
    uint32_t va_raw; /* VA 的真实 ADC 原码，仅在 va_valid 为真时可用。 */
    uint32_t vb_mv; /* VB 四舍五入后的 mV 值。 */
    uint32_t va_mv; /* VA 四舍五入后的 mV 值。 */
    uint32_t adc_conversions; /* 每次 Poll 成功并 GetValue 后递增。 */
    uint32_t feature_reads; /* 实际获得有效读数的不同节点数。 */
    uint32_t elapsed_ms; /* 包含电源稳定、采样、观察窗口及最终切换的累计时间。 */
    uint32_t cycle_id; /* 本次RETEST/上电测量流水号，串口及OLED使用同一编号。 */
    uint32_t sample_tick_ms; /* 读取VA/VB之后的毫秒时间戳，供与Proteus同一时刻的电压表比较。 */
    int vb_valid; /* VB 已有效采样时为真，未读时输出 NA。 */
    int va_valid; /* VA 已有效采样时为真，未读时输出 NA。 */
    int state; /* 唯一工况编号，或 DIV_UNKNOWN。 */
    const char *error; /* OK 或明确的 ADC 错误阶段。 */
} DivMeasurement; /* 为本次采集记录定义类型名。 */


#endif /* DIV_APP_TYPES_H */
