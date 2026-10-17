DIV_REQUIREMENTS_R13（基于你最新上传的 代码(2).zip）

本包针对上一轮“串口新结果正确，但OLED仍显示旧工况/错误电压；检测后电压表与1V理论值混淆；启动串口慢”的问题。

替换文件：
1. Src/div_measurement.c
   - 每轮ADC成功后、1V测试电源仍为ON时，立即输出 TEST_SAMPLE。
   - TEST_SAMPLE 中的 VB_MV/VA_MV 才用于与文件2.0理论表对照。
   - 保留文件2.0 DIV0~DIV8区间和真实ADC判别，不按开关状态硬编码工况。

2. Src/OLED.c
   - 软件I2C增加最小时序裕量。
   - OLED_Clear 从1024个独立数据事务改为8个页连续事务。
   - 删除OLED_Init中的1000x1000空循环（外层 Oled_Init 已有 HAL_Delay）。

3. Src/main.c、Src/div_control.c
   - 固件标识统一为 FW=DIV_REQ_R13。
   - 启动行显示实际 BAUD=57600。

4. Src/usart.c + ADC_CubeMX_Keil.ioc
   - UART统一为57600，避免源码/.ioc/终端三处不一致。

5. Inc/div_config.h
   - 减少周期日志频率，按钮/检测事件仍即时输出。

Proteus Virtual Terminal 请设置：57600, 8N1。

验证优先看：
正常：TEST_SAMPLE VB约455mV，VA约909mV -> DIV0
R1断路：TEST_SAMPLE VB约0mV，VA约1000mV -> DIV1
R1短路：TEST_SAMPLE VB约833mV，VA约833mV -> DIV3
R1=20k：TEST_SAMPLE VB约312mV，VA约938mV -> DIV6

注意：检测完成后若T:OFF/R:OFF，外部电压表接近0是正常的；正常工况切到R:ON后，电压表进入3V运行阶段，不能再与1V理论值直接比较。
