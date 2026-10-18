/* 解决电源互锁与停止断电分散：公开电源安全接口。 */
#ifndef DIV_POWER_H
#define DIV_POWER_H
#include <stdint.h>
void DivPower_Initialize(void); /* 初始化电源模块并保证两路关闭。 */
void DivPower_AllOff(void); /* 关闭测试和运行电源输出。 */
int DivPower_StopIsActive(void); /* 查询停止锁存或PA5当前按下状态。 */
void DivPower_ClearStopRequest(void); /* 仅在有效复测时解除停止锁存。 */
int DivPower_WaitWithoutStop(uint32_t milliseconds); /* 等待期间可被停止取消。 */
int DivPower_Select(uint16_t selected_pin); /* 按先断后合互锁选择一路电源。 */
void DivEmergencyStop(void); /* 外部中断和故障处理使用的紧急断电入口。 */
#endif /* DIV_POWER_H */
