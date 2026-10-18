#ifndef OLED_DISPLAY_H /* 防止头文件被重复包含。 */
#define OLED_DISPLAY_H /* 标记此显示接口已经声明。 */
#include <stdint.h> /* 提供七位地址的无符号字节类型。 */
#define OLED_DISPLAY_ENABLE 1 /* 编译并执行 OLED 初始化及真实测量结果的刷新流程。 */
#define OLED_TEXT_ROWS 4 /* 参考工程使用四个 16 像素高的文字行。 */
#define OLED_TEXT_COLUMNS 16 /* 128 像素宽的屏幕每行显示十六个 8 像素字符。 */
int Oled_Init(void); /* 调用参考驱动的初始化与清屏流程。 */
int Oled_IsInitialized(void); /* 查询初始化状态，无法证明从机已应答。 */
uint8_t Oled_Address(void); /* 返回参考驱动固定使用的七位地址 0x3C。 */
void Oled_SetLine(int row, const char *text); /* 设置从零开始编号的一行显示内容。 */
int Oled_Flush(void); /* 使用参考驱动的 OLED_ShowString 写入四行文字。 */
void Oled_SetProgressCallback(void (*callback)(int completed_pages)); /* 注册每行写入结束后的通知。 */
#endif /* OLED_DISPLAY_H */
