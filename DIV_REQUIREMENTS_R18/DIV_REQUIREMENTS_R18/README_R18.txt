DIV R18 - 5-second synchronized observation window

Purpose
1. Keep the deterministic ADC method from R17:
   PA0 / ADC_CHANNEL_0 = VB
   PA1 / ADC_CHANNEL_1 = VA
   Each channel is explicitly configured and read; no scan-rank order guessing.
2. Solve the "Proteus voltmeter != UART/OLED" comparison problem by giving one fixed 5 s window in the SAME 1 V test stage.

What happens after RETEST
- TEST power (1 V) ON, RUN power (3 V) OFF.
- Wait for the test network to settle.
- Read VB and VA.
- Print TEST_SAMPLE with TEST_GPIO=HIGH, RUN_GPIO=LOW and HOLD_MS=5000.
- Immediately cache and refresh the OLED with this same VB/VA result.
- Keep 1 V test power ON for 5000 ms.
  During these 5 seconds compare:
    * Proteus voltmeters at DIV_VB / DIV_VA
    * UART TEST_SAMPLE VB_MV / VA_MV
    * OLED VB / VA
  They should be the same measurement stage.
- After the 5 s window:
    * DIV0 normal -> TEST OFF, RUN ON.
    * Fault/UNKNOWN -> TEST OFF, RUN OFF.
- OLED keeps the captured 1 V VB/VA values while T/R shows the current final power state after the final refresh.

Important
- Startup line must contain: FW=DIV_REQ_R18
- UART: 57600, 8N1.
- Do not compare a post-test Proteus voltmeter reading with the latched test value. Compare only during the 5 s HOLD window.
- Initial automatic measurement happens before OLED initialization, so for a three-way comparison use RETEST after startup.

Recommended DIV0 validation
R1_DIV=10k, R2_DIV=10k, SW6 closed, SW4 closed, SW5 open, SW2 open.
During the 5 s test window expect roughly:
  VB ~ 455 mV
  VA ~ 909 mV
  TEST_ENABLE/PB12 high
  RUN_ENABLE/PB13 low
After the window and a valid DIV0 result:
  TEST off, RUN on.
