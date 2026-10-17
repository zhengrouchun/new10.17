/* 解决工况判别实现混在头文件：这里只声明判别数据和接口。 */
#ifndef DIV_DIAGNOSIS_H
#define DIV_DIAGNOSIS_H
#include <stdint.h>
#define DIV_ADC_REFERENCE_MV 3300 /* ADC参考电压，单位mV。 */
#define DIV_ADC_MAX_CODE 4095 /* 12位ADC最大原码。 */
#define DIV_ADC_ROUNDING_BIAS (DIV_ADC_MAX_CODE / 2) /* 整数毫伏换算四舍五入偏置。 */
#define DIV_CASE_COUNT 9 /* 支持DIV0至DIV8九种工况。 */
#define DIV_UNKNOWN (-1) /* 未匹配到唯一工况时返回此值。 */
typedef struct /* 保存一个工况的VB和VA闭区间。 */
{ int32_t vb_min; /* VB最小电压，mV。 */ int32_t vb_max; /* VB最大电压，mV。 */ int32_t va_min; /* VA最小电压，mV。 */ int32_t va_max; /* VA最大电压，mV。 */ } DivBounds; /* 工况边界类型。 */
extern const DivBounds div_bounds[DIV_CASE_COUNT]; /* 只读工况边界表。 */
uint32_t DivCodeToMillivolts(uint32_t raw); /* 将ADC原码换算为mV。 */
int DivClassify(int32_t vb_mv, int32_t va_mv); /* 根据VB、VA实测值唯一判别工况。 */
const char *DivStateNameAscii(int state); /* 返回适合当前8x16 ASCII OLED显示的工况名称。 */
#endif /* DIV_DIAGNOSIS_H */
