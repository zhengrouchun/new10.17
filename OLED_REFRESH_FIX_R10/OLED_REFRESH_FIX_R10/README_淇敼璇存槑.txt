R10 OLED刷新修复

已确认现象：
- RETEST_ACCEPTED、DETECTION_START 正常。
- ADC_CONVERSIONS=2、FEATURE_READS=2、ERROR=OK 正常。
- 串口可得到 STATE=DIV3 等新结果。
- 但 OLED 在 STOP 后仍停留在 DIV STOPPED。
- 心跳仍显示 STATE=WAITING。

根因：
R9 div_measurement.c 的 SendReport() 中：
#if OLED_DISPLAY_ENABLE
    DivDisplay_SetMeasurement(result);
#endif
但 div_measurement.c 没有包含定义 OLED_DISPLAY_ENABLE 的 oled_display.h。
因此在该编译单元中 OLED_DISPLAY_ENABLE 可能是未定义宏，#if 会按 0 处理，
导致 DivDisplay_SetMeasurement(result) 被编译器直接移除。

这与现象完全一致：
- 串口使用 result 局部变量，所以能打印最新 DIV3/电压。
- OLED 使用 div_display.c 内部缓存 last_measurement/has_measurement，
  由于从未收到 DivDisplay_SetMeasurement()，缓存一直没有新数据。
- STOP 时 DivEmergencyStop() 会单独调用 DivDisplay_RequestRefresh()，
  因而 OLED 能显示 DIV STOPPED；但 RETEST 测量结束后没有新结果进入显示模块，
  所以仍停在 STOPPED。

修改：
- 删除 SendReport() 中围绕 DivDisplay_SetMeasurement(result) 的 #if OLED_DISPLAY_ENABLE。
- 改为无条件调用 DivDisplay_SetMeasurement(result)。
- div_display.c 自己负责 OLED 是否真正启用，不需要测量模块重复做条件编译。

替换：
Src/div_measurement.c

预期：
STOP -> 松开 -> 改电路 -> RETEST 后，若串口得到：
STATE=DIV3 KIND=FAULT VB_MV=836 VA_MV=836 ERROR=OK
则 OLED 应刷新为类似：
DIV3 FAULT
VB:836 mV
VA:836 mV
T:OFF R:OFF
