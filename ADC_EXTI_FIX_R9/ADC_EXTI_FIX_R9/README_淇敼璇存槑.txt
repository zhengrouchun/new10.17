ADC + RETEST 持久化修复 R9

1. RETEST 为什么 Generate Code 后消失
当前 .ioc 原来记录的是 PA4.Signal=GPIO_Input，所以你手工改 gpio.c 每次都会被 CubeMX 覆盖。
正确设置：PA4 -> GPIO_EXTI4，Falling Edge，Pull-up，并在 NVIC 勾选 EXTI line4 interrupt。
本包的 .ioc 已同步为 GPXTI4，并启用 EXTI4_IRQn。

2. ADC 为什么改
已跑通参考工程使用：Scan ENABLE + Discontinuous ENABLE + NbrOfConversion=2 + NbrOfDiscConversion=1，两个 Rank 依次读取。
你的工程原来是 Scan DISABLE + 每次动态 HAL_ADC_ConfigChannel；Proteus 中出现 ADC_POLL_FAILED。
本包改为：Rank1=PA0/ADC1_IN0/VB，Rank2=PA1/ADC1_IN1/VA，采样时间239.5 cycles。
DivMeasurement 改成两次 HAL_ADC_Start/Poll/GetValue，和参考例程的工作方式一致，不再动态切换通道。

3. 使用方法
优先在 CubeMX GUI 中确认 PA4/ADC 配置，然后 Generate Code。
再覆盖 Src/adc.c 与 Src/div_measurement.c（如果 Generate Code 已生成相同 adc.c，则只需 div_measurement.c）。
Keil Rebuild，确认0 errors。

验收：按 RETEST 后应看到 ADC_CONVERSIONS=2、FEATURE_READS=2，ERROR=OK。
