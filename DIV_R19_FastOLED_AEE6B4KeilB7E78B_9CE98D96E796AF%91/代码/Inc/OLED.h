#ifndef __OLED_H /* 防止重复包含参考驱动声明。 */
#define __OLED_H /* 标记本头文件已经加载。 */

#include "main.h" /* 使用 HAL 类型及 PB6/PB7 引脚定义。 */



void OLED_Init(void); /* OLED初始化。 */
void OLED_Clear(void); /* OLED清屏。 */
void OLED_I2C_Start(void); /* I2C开始。 */
void OLED_I2C_Stop(void); /* I2C停止。 */
void OLED_I2C_SendByte(uint8_t Byte); /* I2C发送一个字节。 */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char); /* OLED显示一个字符。 */
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String); /* OLED显示字符串。 */
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length); /* OLED显示数字（十进制，正数）。 */
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length); /* OLED显示数字（十进制，带符号数）。 */
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length); /* OLED显示数字（十六进制，正数）。 */
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length); /* OLED显示数字（二进制，正数）。 */
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char num); /* 显示BMP图片。 */
void OLED_ShowCHinese(unsigned char x,unsigned char y,unsigned char num); /* 显示汉字。 */

#endif /* 结束头文件保护。 */


