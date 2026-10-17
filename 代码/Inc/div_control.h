/* 解决按键和主循环调度耦合：公开控制模块接口。 */
#ifndef DIV_CONTROL_H
#define DIV_CONTROL_H
void DivControl_InitializeButtons(void); /* 初始化RETEST事件状态。 */
void DivControl_OnRetestInterrupt(void); /* PA4 EXTI4下降沿中断：只锁存一次复测请求。 */
void DivButtonsTick(void); /* 兼容旧接口；RETEST改为EXTI4后不再由SysTick调用。 */
void DivControl_Trace(const char *event); /* 输出按键和控制状态快照。 */
void DivControl_Service(void); /* 主循环处理停止、复测和测量调度。 */
#endif /* DIV_CONTROL_H */
