#include "OLED_Font.h" /* 引入参考字模与图案数据。 */
#include "OLED.h" /* 引入驱动声明与 HAL 引脚类型。 */

/*引脚配置*/
#define OLED_W_SCL(x)		HAL_GPIO_WritePin(SCL_GPIO_Port, SCL_Pin, (GPIO_PinState)(x)) /* 将 SCL 写操作映射到 PB6 的 HAL 输出。 */
#define OLED_W_SDA(x)		HAL_GPIO_WritePin(SDA_GPIO_Port, SDA_Pin, (GPIO_PinState)(x)) /* 将 SDA 写操作映射到 PB7 的 HAL 输出。 */


static void OLED_I2C_Delay(void)
{
    volatile uint32_t i;
    for (i = 0; i < 12U; ++i)
    {
        __NOP();
    }
}



/**
  * @brief  I2C开始
  * @param  无
  * @retval 无
  */
void OLED_I2C_Start(void)
{
    OLED_W_SDA(1); OLED_I2C_Delay();
    OLED_W_SCL(1); OLED_I2C_Delay();
    OLED_W_SDA(0); OLED_I2C_Delay();
    OLED_W_SCL(0); OLED_I2C_Delay();
}

/**
  * @brief  I2C停止
  * @param  无
  * @retval 无
  */
void OLED_I2C_Stop(void)
{
    OLED_W_SDA(0); OLED_I2C_Delay();
    OLED_W_SCL(1); OLED_I2C_Delay();
    OLED_W_SDA(1); OLED_I2C_Delay();
}

/**
  * @brief  I2C发送一个字节
  * @param  Byte 要发送的一个字节
  * @retval 无
  */
void OLED_I2C_SendByte(uint8_t Byte)
{
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        OLED_W_SCL(0);
        OLED_I2C_Delay();
        OLED_W_SDA((Byte & (0x80U >> i)) ? 1 : 0);
        OLED_I2C_Delay();
        OLED_W_SCL(1);
        OLED_I2C_Delay();
        OLED_W_SCL(0);
        OLED_I2C_Delay();
    }
    OLED_W_SDA(1);
    OLED_I2C_Delay();
    OLED_W_SCL(1);
    OLED_I2C_Delay();
    OLED_W_SCL(0);
    OLED_I2C_Delay();
}
/**
  * @brief  OLED写命令
  * @param  Command 要写入的命令
  * @retval 无
  */
void OLED_WriteCommand(uint8_t Command) /* OLED写命令。 */
{
	OLED_I2C_Start(); /* 在发送命令地址之前建立起始条件。 */
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x00);		//写命令
	OLED_I2C_SendByte(Command); /* 发送本次控制器命令。 */
	OLED_I2C_Stop(); /* 结束命令事务并释放总线。 */
}

/**
  * @brief  OLED写数据
  * @param  Data 要写入的数据
  * @retval 无
  */
void OLED_WriteData(uint8_t Data) /* OLED写数据。 */
{
	OLED_I2C_Start(); /* 在发送数据地址之前建立起始条件。 */
	OLED_I2C_SendByte(0x78);		//从机地址
	OLED_I2C_SendByte(0x40);		//写数据
	OLED_I2C_SendByte(Data); /* 发送本次显存数据。 */
	OLED_I2C_Stop(); /* 结束数据事务并释放总线。 */
}

/**
  * @brief  OLED设置光标位置
  * @param  Y 以左上角为原点，向下方向的坐标，范围：0~7
  * @param  X 以左上角为原点，向右方向的坐标，范围：0~127
  * @retval 无
  */
void OLED_SetCursor(uint8_t Y, uint8_t X) /* OLED设置光标位置。 */
{
	OLED_WriteCommand(0xB0 | Y);					//设置Y位置
	OLED_WriteCommand(0x10 | ((X & 0xF0) >> 4));	//设置X位置高4位
	OLED_WriteCommand(0x00 | (X & 0x0F));			//设置X位置低4位
}

/**
  * @brief  OLED清屏
  * @param  无
  * @retval 无
  */
void OLED_Clear(void)
{
    uint8_t i, page;
    for (page = 0; page < 8; ++page)
    {
        OLED_SetCursor(page, 0);
        OLED_I2C_Start();
        OLED_I2C_SendByte(0x78);
        OLED_I2C_SendByte(0x40);
        for (i = 0; i < 128; ++i)
        {
            OLED_I2C_SendByte(0x00);
        }
        OLED_I2C_Stop();
    }
}

/**
  * @brief  OLED显示一个字符
  * @param  Line 行位置，范围：1~4
  * @param  Column 列位置，范围：1~16
  * @param  Char 要显示的一个字符，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char) /* OLED显示一个字符。 */
{      	
	uint8_t i; /* 保存当前半字符的列索引。 */
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 8);		//设置光标位置在上半部分
	for (i = 0; i < 8; i++) /* 发送字符上半部分的八列字模。 */
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i]);			//显示上半部分内容
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 8);	//设置光标位置在下半部分
	for (i = 0; i < 8; i++) /* 发送字符下半部分的八列字模。 */
	{
		OLED_WriteData(OLED_F8x16[Char - ' '][i + 8]);		//显示下半部分内容
	}
}

/**
  * @brief  OLED显示字符串
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  String 要显示的字符串，范围：ASCII可见字符
  * @retval 无
  */
void OLED_ShowString(uint8_t Line,
                     uint8_t Column,
                     char *String)
{
    uint8_t part, i, j;
    uint8_t ch;

    if (Line < 1 || Line > 4 ||
        Column < 1 || Column > 16 ||
        String == 0)
    {
        return;
    }

    /* 每一行16像素，分成上下两个8像素页 */
    for (part = 0; part < 2; part++)
    {
        OLED_SetCursor(
            (Line - 1) * 2 + part,
            (Column - 1) * 8
        );

        /* 整页字符数据只建立一次I2C事务 */
        OLED_I2C_Start();
        OLED_I2C_SendByte(0x78);
        OLED_I2C_SendByte(0x40);

        for (i = 0;
             String[i] != '\0' &&
             (uint16_t)Column + i <= 16;
             i++)
        {
            ch = (uint8_t)String[i];

            if (ch < 32 || ch > 126)
            {
                ch = ' ';
            }

            for (j = 0; j < 8; j++)
            {
                OLED_I2C_SendByte(
                    OLED_F8x16[ch - ' '][part * 8 + j]
                );
            }
        }

        OLED_I2C_Stop();
    }
}



/**
  * @brief  OLED次方函数
  * @retval 返回值等于X的Y次方
  */
uint32_t OLED_Pow(uint32_t X, uint32_t Y) /* OLED次方函数。 */
{
	uint32_t Result = 1; /* 将连乘结果初值设为一。 */
	while (Y--) /* 按指数次数执行连乘，指数为零时跳过。 */
	{
		Result *= X; /* 把结果再乘一次底数。 */
	}
	return Result; /* 返回整数幂计算结果。 */
}

/**
  * @brief  OLED显示数字（十进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~4294967295
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length) /* OLED显示数字（十进制，正数）。 */
{
	uint8_t i; /* 保存当前十进制位的显示索引。 */
	for (i = 0; i < Length; i++) /* 按照给定显示位数逐位处理。 */
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(10, Length - i - 1) % 10 + '0'); /* 提取当前十进制位，转换为 ASCII 数字后显示。 */
	}
}

/**
  * @brief  OLED显示数字（十进制，带符号数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：-2147483648~2147483647
  * @param  Length 要显示数字的长度，范围：1~10
  * @retval 无
  */
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length) /* OLED显示数字（十进制，带符号数）。 */
{
	uint8_t i; /* 保存带符号数字的位索引。 */
	uint32_t Number1; /* 保存数字部分所用的无符号值。 */
	if (Number >= 0) /* 判断是否采用正号分支。 */
	{
		OLED_ShowChar(Line, Column, '+'); /* 在首列显示正号。 */
		Number1 = Number; /* 将非负输入传递给数字拆位过程。 */
	}
	else /* 输入为负数时执行此分支。 */
	{
		OLED_ShowChar(Line, Column, '-'); /* 在首列显示负号。 */
		Number1 = -Number; /* 沿用参考实现，取反后用于数字部分；当前四行流程不调用此接口。 */
	}
	for (i = 0; i < Length; i++) /* 按指定长度依次处理数字位。 */
	{
		OLED_ShowChar(Line, Column + i + 1, Number1 / OLED_Pow(10, Length - i - 1) % 10 + '0'); /* 在符号之后逐位显示十进制数字。 */
	}
}

/**
  * @brief  OLED显示数字（十六进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~0xFFFFFFFF
  * @param  Length 要显示数字的长度，范围：1~8
  * @retval 无
  */
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length) /* OLED显示数字（十六进制，正数）。 */
{
	uint8_t i, SingleNumber; /* 保存显示索引和当前十六进制位。 */
	for (i = 0; i < Length; i++) /* 遍历所需的十六进制显示位。 */
	{
		SingleNumber = Number / OLED_Pow(16, Length - i - 1) % 16; /* 提取当前十六进制位，范围为零至十五。 */
		if (SingleNumber < 10) /* 零至九应使用数字字符。 */
		{
			OLED_ShowChar(Line, Column + i, SingleNumber + '0'); /* 把零至九转换为 ASCII 数字后显示。 */
		}
		else /* 十至十五应使用字母字符。 */
		{
			OLED_ShowChar(Line, Column + i, SingleNumber - 10 + 'A'); /* 把十至十五转换为 A 至 F 后显示。 */
		}
	}
}

/**
  * @brief  OLED显示数字（二进制，正数）
  * @param  Line 起始行位置，范围：1~4
  * @param  Column 起始列位置，范围：1~16
  * @param  Number 要显示的数字，范围：0~1111 1111 1111 1111
  * @param  Length 要显示数字的长度，范围：1~16
  * @retval 无
  */
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length) /* OLED显示数字（二进制，正数）。 */
{
	uint8_t i; /* 保存当前二进制显示位的索引。 */
	for (i = 0; i < Length; i++) /* 按照指定显示位数逐位处理。 */
	{
		OLED_ShowChar(Line, Column + i, Number / OLED_Pow(2, Length - i - 1) % 2 + '0'); /* 提取二进制位，转换为字符零或一后显示。 */
	}
}



/**
  * @brief  显示BMP图片
  * @param  图片大小：128×64
  * @param  起始点坐标(x0,y0)
  * @param  结束点坐标(x1,y1)
  * @param  x的范围0～127
  * @param  y的范围0～7
  * @retval 无
  */
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char num) /* 显示BMP图片。 */
{ 	
 unsigned int j=0; /* 从图案的第一个数据字节开始读取。 */
 unsigned char x,y; /* 保存图案列坐标和页坐标。 */
  
  if(y1%8==0) y=y1/8; /* 沿用参考接口计算整页边界；后面的页循环会重新设置 y。 */
  else y=y1/8+1; /* 沿用参考接口计算非整页边界，当前文字显示不调用此接口。 */
	for(y=y0;y<y1;y++) /* 按参考接口给出的起止页逐页绘制。 */
	{
		OLED_SetCursor(y,x0); /* 定位到当前图案页的起始列。 */
        for(x=x0;x<x1;x++) /* 遍历图案的各列。 */
	    {      
	    	OLED_WriteData(BMP[num][j++]); /* 发送所选图案当前字节，并递增数据索引。 */
	    }
	}
} 
 
/**
  * @brief  显示汉字
  * @param  汉字大小：16×16
  * @param  Line 行位置，范围：1~4
  * @param  Column 列位置，范围：1~8
  * @retval 无
  */
void OLED_ShowCHinese(uint8_t Line, uint8_t Column, unsigned char num) /* 显示汉字。 */
{      			    

    uint8_t i; /* 保存汉字半高部分的列索引。 */
	OLED_SetCursor((Line - 1) * 2, (Column - 1) * 16);		//设置光标位置在上半部分
	for (i = 0; i < 16; i++) /* 发送汉字上半部分的十六列。 */
	{
		OLED_WriteData(HZ[num][i]);			//显示上半部分内容
	}
	OLED_SetCursor((Line - 1) * 2 + 1, (Column - 1) * 16);	//设置光标位置在下半部分
	for (i = 0; i < 16; i++) /* 发送汉字下半部分的十六列。 */
	{
		OLED_WriteData(HZ[num][i + 16]);		//显示下半部分内容
	}    
}

/**
  * @brief  OLED初始化
  * @param  无
  * @retval 无
  */
void OLED_Init(void) /* OLED初始化。 */
{
    /* 上电等待由oled_display.c中的HAL_Delay(50)统一完成，避免Proteus空循环拖慢启动。 */

	OLED_WriteCommand(0xAE);	//关闭显示
	
	OLED_WriteCommand(0xD5);	//设置显示时钟分频比/振荡器频率
	OLED_WriteCommand(0x80); /* 写入前一条显示时钟命令的参考参数。 */
	
	OLED_WriteCommand(0xA8);	//设置多路复用率
	OLED_WriteCommand(0x3F); /* 将扫描复用比设为 64 行减一。 */
	
	OLED_WriteCommand(0xD3);	//设置显示偏移
	OLED_WriteCommand(0x00); /* 将垂直偏移设为零。 */
	
	OLED_WriteCommand(0x40);	//设置显示开始行
	
	OLED_WriteCommand(0xA1);	//设置左右方向，0xA1正常 0xA0左右反置
	
	OLED_WriteCommand(0xC8);	//设置上下方向，0xC8正常 0xC0上下反置

	OLED_WriteCommand(0xDA);	//设置COM引脚硬件配置
	OLED_WriteCommand(0x12); /* 写入参考屏幕的 COM 引脚排列参数。 */
	
	OLED_WriteCommand(0x81);	//设置对比度控制
	OLED_WriteCommand(0xCF); /* 写入参考对比度参数。 */

	OLED_WriteCommand(0xD9);	//设置预充电周期
	OLED_WriteCommand(0xF1); /* 写入参考预充电周期参数。 */

	OLED_WriteCommand(0xDB);	//设置VCOMH取消选择级别
	OLED_WriteCommand(0x30); /* 写入参考 VCOMH 电平参数。 */

	OLED_WriteCommand(0xA4);	//设置整个显示打开/关闭

	OLED_WriteCommand(0xA6);	//设置正常/倒转显示

	OLED_WriteCommand(0x8D);	//设置充电泵
	OLED_WriteCommand(0x14); /* 启用参考配置中的内部电荷泵。 */

	OLED_WriteCommand(0xAF);	//开启显示
		
	OLED_Clear();				//OLED清屏
}


