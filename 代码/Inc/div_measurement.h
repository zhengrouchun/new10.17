/* 解决ADC流程塞在主程序：公开单次DIV测量入口。 */
#ifndef DIV_MEASUREMENT_H
#define DIV_MEASUREMENT_H
void DivMeasurement_Run(void); /* 执行供电、采样、判别和报告。 */
#endif /* DIV_MEASUREMENT_H */
