DIV_REQUIREMENTS_R16

本版只修当前已经由串口证据确认的两个核心问题，不修改文件2.0的DIV0~DIV8判别区间。

1. ADC 两次转换的节点映射修正
R15 实测：
- 正常电路出现第一转换约 912mV、第二转换约 454mV；文件理论是 VA≈909mV、VB≈455mV。
- DIV4 类非对称工况出现第一转换约 718mV、第二转换约 0mV，也证明第一转换是 VA、第二转换是 VB。
因此 R16 改为：第一次 GetValue -> VA，第二次 GetValue -> VB。
这会直接修复 R15 中 DIV0、DIV1、DIV4 因 VB/VA 对调导致的 UNKNOWN/误判。

2. 供电逻辑按文件2.0保持不变
- 检测阶段：TEST=ON，RUN=OFF。
- DIV0 检测结束：TEST=OFF，RUN=ON。
- DIV1~DIV8 或 UNKNOWN 检测结束：TEST=OFF，RUN=OFF。
- STOP：TEST=OFF，RUN=OFF。
故障检测结束后 T:OFF R:OFF 是文件要求，不是错误。

3. 每次测试必须从正常基线恢复，再只改变一个条件
DIV0：R1=10k,R2=10k, SW6闭,SW4闭,SW5断,SW2断。
DIV1 R1断路：只把 SW6 断开。
DIV2 R2断路：只把 SW4 断开。
DIV3 R1短路：恢复正常后只把 SW5 闭合。
DIV4 R2短路：恢复正常后只把 SW2 闭合。
如果 DIV4 测得 VA≈718mV，数学上对应 R1≈5k（1V、Rs=2k 时 5k/(2k+5k)≈714mV），说明测试 DIV4 时 R1 没恢复到10k或存在等效5k通路；此时程序返回 UNKNOWN 是正确的。

4. 验收先看 TEST_SAMPLE
正常应：VB≈455, VA≈909。
DIV1：VB≈0, VA≈1000。
DIV2：VB≈1000, VA≈1000。
DIV3：VB≈833, VA≈833。
DIV4：VB≈0, VA≈833。
OLED 应与同一轮最终 STATE/VB/VA 完全一致。

5. 启动确认
必须看到 FW=DIV_REQ_R16。
TEST_SAMPLE 中会出现 ADC_ORDER=VA_THEN_VB。
