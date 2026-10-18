/* 解决工况表和判别算法定义在头文件：集中实现九工况判别。 */
#include "div_diagnosis.h" /* 引入工况边界类型和判别接口声明。 */

const DivBounds div_bounds[DIV_CASE_COUNT] = /* 保存九种工况的实测电压闭区间。 */
{
    {422, 488, 889, 928}, /* DIV0：正常。 */
    {-5, 5, 985, 1015}, /* DIV1：R1断路。 */
    {985, 1015, 985, 1015}, /* DIV2：R2断路。 */
    {811, 855, 811, 855}, /* DIV3：R1短路。 */
    {-5, 5, 811, 855}, /* DIV4：R2短路。 */
    {555, 621, 862, 903}, /* DIV5：R1改为5 kOhm。 */
    {284, 342, 919, 956}, /* DIV6：R1改为20 kOhm。 */
    {267, 322, 862, 903}, /* DIV7：R2改为5 kOhm。 */
    {591, 659, 919, 956} /* DIV8：R2改为20 kOhm。 */
};

uint32_t DivCodeToMillivolts(uint32_t raw) /* 将12位ADC原码换算为整数毫伏。 */
{
    return (raw * DIV_ADC_REFERENCE_MV + DIV_ADC_ROUNDING_BIAS) / DIV_ADC_MAX_CODE; /* 使用参考电压缩放并四舍五入。 */
}

int DivClassify(int32_t vb_mv, int32_t va_mv) /* 只有唯一匹配工况才返回有效编号。 */
{
    int matches = 0; /* 记录命中的工况数量。 */
    int matched_case = DIV_UNKNOWN; /* 默认没有可接受的唯一工况。 */
    int index; /* 保存当前检查的工况下标。 */

    for (index = 0; index < DIV_CASE_COUNT; ++index) /* 检查完整的九工况表。 */
    {
        const DivBounds *bounds = &div_bounds[index]; /* 取得当前工况的电压边界。 */
        if (vb_mv >= bounds->vb_min && vb_mv <= bounds->vb_max && /* 检查VB是否在闭区间内。 */
            va_mv >= bounds->va_min && va_mv <= bounds->va_max) /* 检查VA是否也在同一工况闭区间内。 */
        {
            ++matches; /* 记录一次同时匹配。 */
            matched_case = index; /* 暂存本次命中的工况编号。 */
        }
    }

    return matches == 1 ? matched_case : DIV_UNKNOWN; /* 多重命中或没有命中都返回未知。 */
}


const char *DivStateNameAscii(int state) /* 文件2.0工况名称；当前OLED字库不含所需中文，使用等价ASCII。 */
{
    static const char *const names[DIV_CASE_COUNT] =
    {
        "NORMAL",   /* DIV0 正常 */
        "R1 OPEN",  /* DIV1 R1断路 */
        "R2 OPEN",  /* DIV2 R2断路 */
        "R1 SHORT", /* DIV3 R1短路 */
        "R2 SHORT", /* DIV4 R2短路 */
        "R1=5K",    /* DIV5 R1为5kOhm */
        "R1=20K",   /* DIV6 R1为20kOhm */
        "R2=5K",    /* DIV7 R2为5kOhm */
        "R2=20K"    /* DIV8 R2为20kOhm */
    };
    return (state >= 0 && state < DIV_CASE_COUNT) ? names[state] : "UNKNOWN";
}
