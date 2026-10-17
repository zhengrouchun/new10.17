/* 解决OLED更新与测量逻辑耦合：公开显示服务接口。 */
#ifndef DIV_DISPLAY_H
#define DIV_DISPLAY_H
#include "div_app_types.h"
void DivDisplay_Initialize(void); /* 初始化项目已有OLED驱动。 */
void DivDisplay_SetMeasurement(const DivMeasurement *measurement); /* 缓存一轮测量结果并请求刷新。 */
void DivDisplay_RequestRefresh(void); /* 请求主循环刷新显示。 */
void DivDisplay_Service(void); /* 刷新发生变化的OLED画面。 */
void DivDisplay_ServiceStatus(void); /* 定时输出运行状态。 */
void DivDisplay_ReportProgress(int completed_pages); /* OLED写入进度回调。 */
#endif /* DIV_DISPLAY_H */
