#line 1 "../Src/main.c"
 















 
 
 
#line 1 "../Inc/main.h"
 
















 
 

 







 
#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

















 

 







 
#line 1 "../Inc/stm32f1xx_hal_conf.h"
 















 
 

 







 
 

 


 



 
 
 
 
 
 
 
 
 
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

 
 

#line 79 "../Inc/stm32f1xx_hal_conf.h"

 




 












 






 









 









 

 


 





#line 159 "../Inc/stm32f1xx_hal_conf.h"

 



 
 

 

 

 
#line 178 "../Inc/stm32f1xx_hal_conf.h"

 





 

 

 

 





 




#line 212 "../Inc/stm32f1xx_hal_conf.h"





 





 




 



 


 

#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"















 

 







 
#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h"

















 

 







 
#line 1 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"


























 



 



 
    






  


 



 






 

#line 77 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"



 
  
#line 90 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"



 
#line 102 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"



 



 

#line 1 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"
























 




 



 
    









 


 







 



 




 

  
typedef enum
{
 
  NonMaskableInt_IRQn         = -14,     
  HardFault_IRQn              = -13,     
  MemoryManagement_IRQn       = -12,     
  BusFault_IRQn               = -11,     
  UsageFault_IRQn             = -10,     
  SVCall_IRQn                 = -5,      
  DebugMonitor_IRQn           = -4,      
  PendSV_IRQn                 = -2,      
  SysTick_IRQn                = -1,      

 
  WWDG_IRQn                   = 0,       
  PVD_IRQn                    = 1,       
  TAMPER_IRQn                 = 2,       
  RTC_IRQn                    = 3,       
  FLASH_IRQn                  = 4,       
  RCC_IRQn                    = 5,       
  EXTI0_IRQn                  = 6,       
  EXTI1_IRQn                  = 7,       
  EXTI2_IRQn                  = 8,       
  EXTI3_IRQn                  = 9,       
  EXTI4_IRQn                  = 10,      
  DMA1_Channel1_IRQn          = 11,      
  DMA1_Channel2_IRQn          = 12,      
  DMA1_Channel3_IRQn          = 13,      
  DMA1_Channel4_IRQn          = 14,      
  DMA1_Channel5_IRQn          = 15,      
  DMA1_Channel6_IRQn          = 16,      
  DMA1_Channel7_IRQn          = 17,      
  ADC1_2_IRQn                 = 18,      
  USB_HP_CAN1_TX_IRQn         = 19,      
  USB_LP_CAN1_RX0_IRQn        = 20,      
  CAN1_RX1_IRQn               = 21,      
  CAN1_SCE_IRQn               = 22,      
  EXTI9_5_IRQn                = 23,      
  TIM1_BRK_IRQn               = 24,      
  TIM1_UP_IRQn                = 25,      
  TIM1_TRG_COM_IRQn           = 26,      
  TIM1_CC_IRQn                = 27,      
  TIM2_IRQn                   = 28,      
  TIM3_IRQn                   = 29,      
  TIM4_IRQn                   = 30,      
  I2C1_EV_IRQn                = 31,      
  I2C1_ER_IRQn                = 32,      
  I2C2_EV_IRQn                = 33,      
  I2C2_ER_IRQn                = 34,      
  SPI1_IRQn                   = 35,      
  SPI2_IRQn                   = 36,      
  USART1_IRQn                 = 37,      
  USART2_IRQn                 = 38,      
  USART3_IRQn                 = 39,      
  EXTI15_10_IRQn              = 40,      
  RTC_Alarm_IRQn              = 41,      
  USBWakeUp_IRQn              = 42,      
} IRQn_Type;



 

#line 1 "../Drivers/CMSIS/Include/core_cm3.h"
 




 
















 










#line 1 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"
 
 





 









     
#line 27 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"
     











#line 46 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"





 

     

     
typedef   signed          char int8_t;
typedef   signed short     int int16_t;
typedef   signed           int int32_t;
typedef   signed       __int64 int64_t;

     
typedef unsigned          char uint8_t;
typedef unsigned short     int uint16_t;
typedef unsigned           int uint32_t;
typedef unsigned       __int64 uint64_t;

     

     
     
typedef   signed          char int_least8_t;
typedef   signed short     int int_least16_t;
typedef   signed           int int_least32_t;
typedef   signed       __int64 int_least64_t;

     
typedef unsigned          char uint_least8_t;
typedef unsigned short     int uint_least16_t;
typedef unsigned           int uint_least32_t;
typedef unsigned       __int64 uint_least64_t;

     

     
typedef   signed           int int_fast8_t;
typedef   signed           int int_fast16_t;
typedef   signed           int int_fast32_t;
typedef   signed       __int64 int_fast64_t;

     
typedef unsigned           int uint_fast8_t;
typedef unsigned           int uint_fast16_t;
typedef unsigned           int uint_fast32_t;
typedef unsigned       __int64 uint_fast64_t;

     




typedef   signed           int intptr_t;
typedef unsigned           int uintptr_t;


     
typedef   signed     long long intmax_t;
typedef unsigned     long long uintmax_t;




     

     





     





     





     

     





     





     





     

     





     





     





     

     






     






     






     

     


     


     


     

     
#line 216 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"

     



     






     
    
 



#line 241 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"

     







     










     











#line 305 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdint.h"






 
#line 35 "../Drivers/CMSIS/Include/core_cm3.h"

















 




 



 

#line 1 "../Drivers/CMSIS/Include/cmsis_version.h"
 




 
















 










 
#line 64 "../Drivers/CMSIS/Include/core_cm3.h"

 









 







#line 114 "../Drivers/CMSIS/Include/core_cm3.h"

#line 1 "../Drivers/CMSIS/Include/cmsis_compiler.h"
 




 
















 




#line 29 "../Drivers/CMSIS/Include/cmsis_compiler.h"



 
#line 1 "../Drivers/CMSIS/Include/cmsis_armcc.h"
 




 
















 









 













   
   


 
#line 103 "../Drivers/CMSIS/Include/cmsis_armcc.h"

 



 





 
 






 
 





 
static __inline uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __asm("control");
  return(__regControl);
}






 
static __inline void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __asm("control");
  __regControl = control;
}






 
static __inline uint32_t __get_IPSR(void)
{
  register uint32_t __regIPSR          __asm("ipsr");
  return(__regIPSR);
}






 
static __inline uint32_t __get_APSR(void)
{
  register uint32_t __regAPSR          __asm("apsr");
  return(__regAPSR);
}






 
static __inline uint32_t __get_xPSR(void)
{
  register uint32_t __regXPSR          __asm("xpsr");
  return(__regXPSR);
}






 
static __inline uint32_t __get_PSP(void)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  return(__regProcessStackPointer);
}






 
static __inline void __set_PSP(uint32_t topOfProcStack)
{
  register uint32_t __regProcessStackPointer  __asm("psp");
  __regProcessStackPointer = topOfProcStack;
}






 
static __inline uint32_t __get_MSP(void)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  return(__regMainStackPointer);
}






 
static __inline void __set_MSP(uint32_t topOfMainStack)
{
  register uint32_t __regMainStackPointer     __asm("msp");
  __regMainStackPointer = topOfMainStack;
}






 
static __inline uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __asm("primask");
  return(__regPriMask);
}






 
static __inline void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __asm("primask");
  __regPriMask = (priMask);
}









 







 







 
static __inline uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __asm("basepri");
  return(__regBasePri);
}






 
static __inline void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __asm("basepri");
  __regBasePri = (basePri & 0xFFU);
}







 
static __inline void __set_BASEPRI_MAX(uint32_t basePri)
{
  register uint32_t __regBasePriMax      __asm("basepri_max");
  __regBasePriMax = (basePri & 0xFFU);
}






 
static __inline uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  return(__regFaultMask);
}






 
static __inline void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __asm("faultmask");
  __regFaultMask = (faultMask & (uint32_t)1U);
}









 
static __inline uint32_t __get_FPSCR(void)
{





   return(0U);

}






 
static __inline void __set_FPSCR(uint32_t fpscr)
{





  (void)fpscr;

}


 


 



 




 






 







 






 








 










 










 






                  





 








 

__attribute__((section(".rev16_text"))) static __inline __asm uint32_t __REV16(uint32_t value)
{
  rev16 r0, r0
  bx lr
}








 

__attribute__((section(".revsh_text"))) static __inline __asm int16_t __REVSH(int16_t value)
{
  revsh r0, r0
  bx lr
}









 









 








 
#line 532 "../Drivers/CMSIS/Include/cmsis_armcc.h"







 











 












 












 














 














 














 










 









 









 









 

__attribute__((section(".rrx_text"))) static __inline __asm uint32_t __RRX(uint32_t value)
{
  rrx r0, r0
  bx lr
}








 








 








 








 








 








 


#line 780 "../Drivers/CMSIS/Include/cmsis_armcc.h"

   


 



 

#line 862 "../Drivers/CMSIS/Include/cmsis_armcc.h"
 


#line 35 "../Drivers/CMSIS/Include/cmsis_compiler.h"




 
#line 263 "../Drivers/CMSIS/Include/cmsis_compiler.h"




#line 116 "../Drivers/CMSIS/Include/core_cm3.h"

















 
#line 155 "../Drivers/CMSIS/Include/core_cm3.h"

 






 
#line 171 "../Drivers/CMSIS/Include/core_cm3.h"

 




 












 



 






 



 
typedef union
{
  struct
  {
    uint32_t _reserved0:27;               
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} APSR_Type;

 


















 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:23;               
  } b;                                    
  uint32_t w;                             
} IPSR_Type;

 






 
typedef union
{
  struct
  {
    uint32_t ISR:9;                       
    uint32_t _reserved0:1;                
    uint32_t ICI_IT_1:6;                  
    uint32_t _reserved1:8;                
    uint32_t T:1;                         
    uint32_t ICI_IT_2:2;                  
    uint32_t Q:1;                         
    uint32_t V:1;                         
    uint32_t C:1;                         
    uint32_t Z:1;                         
    uint32_t N:1;                         
  } b;                                    
  uint32_t w;                             
} xPSR_Type;

 






























 
typedef union
{
  struct
  {
    uint32_t nPRIV:1;                     
    uint32_t SPSEL:1;                     
    uint32_t _reserved1:30;               
  } b;                                    
  uint32_t w;                             
} CONTROL_Type;

 






 







 



 
typedef struct
{
  volatile uint32_t ISER[8U];                
        uint32_t RESERVED0[24U];
  volatile uint32_t ICER[8U];                
        uint32_t RSERVED1[24U];
  volatile uint32_t ISPR[8U];                
        uint32_t RESERVED2[24U];
  volatile uint32_t ICPR[8U];                
        uint32_t RESERVED3[24U];
  volatile uint32_t IABR[8U];                
        uint32_t RESERVED4[56U];
  volatile uint8_t  IP[240U];                
        uint32_t RESERVED5[644U];
  volatile  uint32_t STIR;                    
}  NVIC_Type;

 



 







 



 
typedef struct
{
  volatile const  uint32_t CPUID;                   
  volatile uint32_t ICSR;                    
  volatile uint32_t VTOR;                    
  volatile uint32_t AIRCR;                   
  volatile uint32_t SCR;                     
  volatile uint32_t CCR;                     
  volatile uint8_t  SHP[12U];                
  volatile uint32_t SHCSR;                   
  volatile uint32_t CFSR;                    
  volatile uint32_t HFSR;                    
  volatile uint32_t DFSR;                    
  volatile uint32_t MMFAR;                   
  volatile uint32_t BFAR;                    
  volatile uint32_t AFSR;                    
  volatile const  uint32_t PFR[2U];                 
  volatile const  uint32_t DFR;                     
  volatile const  uint32_t ADR;                     
  volatile const  uint32_t MMFR[4U];                
  volatile const  uint32_t ISAR[5U];                
        uint32_t RESERVED0[5U];
  volatile uint32_t CPACR;                   
} SCB_Type;

 















 






























 




#line 457 "../Drivers/CMSIS/Include/core_cm3.h"

 





















 









 


















 










































 









 















 


















 


















 









 















 







 



 
typedef struct
{
        uint32_t RESERVED0[1U];
  volatile const  uint32_t ICTR;                    

  volatile uint32_t ACTLR;                   



} SCnSCB_Type;

 



 










 







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t LOAD;                    
  volatile uint32_t VAL;                     
  volatile const  uint32_t CALIB;                   
} SysTick_Type;

 












 



 



 









 







 



 
typedef struct
{
  volatile  union
  {
    volatile  uint8_t    u8;                  
    volatile  uint16_t   u16;                 
    volatile  uint32_t   u32;                 
  }  PORT [32U];                          
        uint32_t RESERVED0[864U];
  volatile uint32_t TER;                     
        uint32_t RESERVED1[15U];
  volatile uint32_t TPR;                     
        uint32_t RESERVED2[15U];
  volatile uint32_t TCR;                     
        uint32_t RESERVED3[29U];
  volatile  uint32_t IWR;                     
  volatile const  uint32_t IRR;                     
  volatile uint32_t IMCR;                    
        uint32_t RESERVED4[43U];
  volatile  uint32_t LAR;                     
  volatile const  uint32_t LSR;                     
        uint32_t RESERVED5[6U];
  volatile const  uint32_t PID4;                    
  volatile const  uint32_t PID5;                    
  volatile const  uint32_t PID6;                    
  volatile const  uint32_t PID7;                    
  volatile const  uint32_t PID0;                    
  volatile const  uint32_t PID1;                    
  volatile const  uint32_t PID2;                    
  volatile const  uint32_t PID3;                    
  volatile const  uint32_t CID0;                    
  volatile const  uint32_t CID1;                    
  volatile const  uint32_t CID2;                    
  volatile const  uint32_t CID3;                    
} ITM_Type;

 



 



























 



 



 



 









   







 



 
typedef struct
{
  volatile uint32_t CTRL;                    
  volatile uint32_t CYCCNT;                  
  volatile uint32_t CPICNT;                  
  volatile uint32_t EXCCNT;                  
  volatile uint32_t SLEEPCNT;                
  volatile uint32_t LSUCNT;                  
  volatile uint32_t FOLDCNT;                 
  volatile const  uint32_t PCSR;                    
  volatile uint32_t COMP0;                   
  volatile uint32_t MASK0;                   
  volatile uint32_t FUNCTION0;               
        uint32_t RESERVED0[1U];
  volatile uint32_t COMP1;                   
  volatile uint32_t MASK1;                   
  volatile uint32_t FUNCTION1;               
        uint32_t RESERVED1[1U];
  volatile uint32_t COMP2;                   
  volatile uint32_t MASK2;                   
  volatile uint32_t FUNCTION2;               
        uint32_t RESERVED2[1U];
  volatile uint32_t COMP3;                   
  volatile uint32_t MASK3;                   
  volatile uint32_t FUNCTION3;               
} DWT_Type;

 






















































 



 



 



 



 



 



 



























   







 



 
typedef struct
{
  volatile const  uint32_t SSPSR;                   
  volatile uint32_t CSPSR;                   
        uint32_t RESERVED0[2U];
  volatile uint32_t ACPR;                    
        uint32_t RESERVED1[55U];
  volatile uint32_t SPPR;                    
        uint32_t RESERVED2[131U];
  volatile const  uint32_t FFSR;                    
  volatile uint32_t FFCR;                    
  volatile const  uint32_t FSCR;                    
        uint32_t RESERVED3[759U];
  volatile const  uint32_t TRIGGER;                 
  volatile const  uint32_t FIFO0;                   
  volatile const  uint32_t ITATBCTR2;               
        uint32_t RESERVED4[1U];
  volatile const  uint32_t ITATBCTR0;               
  volatile const  uint32_t FIFO1;                   
  volatile uint32_t ITCTRL;                  
        uint32_t RESERVED5[39U];
  volatile uint32_t CLAIMSET;                
  volatile uint32_t CLAIMCLR;                
        uint32_t RESERVED7[8U];
  volatile const  uint32_t DEVID;                   
  volatile const  uint32_t DEVTYPE;                 
} TPI_Type;

 



 



 












 






 



 





















 






 





















 






 



 


















 






   


#line 1242 "../Drivers/CMSIS/Include/core_cm3.h"







 



 
typedef struct
{
  volatile uint32_t DHCSR;                   
  volatile  uint32_t DCRSR;                   
  volatile uint32_t DCRDR;                   
  volatile uint32_t DEMCR;                   
} CoreDebug_Type;

 




































 






 







































 







 






 







 


 







 

 
#line 1391 "../Drivers/CMSIS/Include/core_cm3.h"

#line 1400 "../Drivers/CMSIS/Include/core_cm3.h"






 










 


 



 





 

#line 1451 "../Drivers/CMSIS/Include/core_cm3.h"

#line 1461 "../Drivers/CMSIS/Include/core_cm3.h"




 













 
static __inline void __NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);              

  reg_value  =  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR;                                                    
  reg_value &= ~((uint32_t)((0xFFFFUL << 16U) | (7UL << 8U)));  
  reg_value  =  (reg_value                                   |
                ((uint32_t)0x5FAUL << 16U) |
                (PriorityGroupTmp << 8U) );                
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR =  reg_value;
}






 
static __inline uint32_t __NVIC_GetPriorityGrouping(void)
{
  return ((uint32_t)((((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) >> 8U));
}







 
static __inline void __NVIC_EnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetEnableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISER[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_DisableIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICER[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
    do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);
    do { __schedule_barrier(); __isb(0xF); __schedule_barrier(); } while (0U);
  }
}









 
static __inline uint32_t __NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}







 
static __inline void __NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ISPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}







 
static __inline void __NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->ICPR[(((uint32_t)IRQn) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)IRQn) & 0x1FUL));
  }
}









 
static __inline uint32_t __NVIC_GetActive(IRQn_Type IRQn)
{
  if ((int32_t)(IRQn) >= 0)
  {
    return((uint32_t)(((((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IABR[(((uint32_t)IRQn) >> 5UL)] & (1UL << (((uint32_t)IRQn) & 0x1FUL))) != 0UL) ? 1UL : 0UL));
  }
  else
  {
    return(0U);
  }
}










 
static __inline void __NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if ((int32_t)(IRQn) >= 0)
  {
    ((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)IRQn)]               = (uint8_t)((priority << (8U - 4U)) & (uint32_t)0xFFUL);
  }
  else
  {
    ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)IRQn) & 0xFUL)-4UL] = (uint8_t)((priority << (8U - 4U)) & (uint32_t)0xFFUL);
  }
}










 
static __inline uint32_t __NVIC_GetPriority(IRQn_Type IRQn)
{

  if ((int32_t)(IRQn) >= 0)
  {
    return(((uint32_t)((NVIC_Type *) ((0xE000E000UL) + 0x0100UL) )->IP[((uint32_t)IRQn)]               >> (8U - 4U)));
  }
  else
  {
    return(((uint32_t)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->SHP[(((uint32_t)IRQn) & 0xFUL)-4UL] >> (8U - 4U)));
  }
}












 
static __inline uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));

  return (
           ((PreemptPriority & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL)) << SubPriorityBits) |
           ((SubPriority     & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL)))
         );
}












 
static __inline void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* const pPreemptPriority, uint32_t* const pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & (uint32_t)0x07UL);    
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7UL - PriorityGroupTmp) > (uint32_t)(4U)) ? (uint32_t)(4U) : (uint32_t)(7UL - PriorityGroupTmp);
  SubPriorityBits     = ((PriorityGroupTmp + (uint32_t)(4U)) < (uint32_t)7UL) ? (uint32_t)0UL : (uint32_t)((PriorityGroupTmp - 7UL) + (uint32_t)(4U));

  *pPreemptPriority = (Priority >> SubPriorityBits) & (uint32_t)((1UL << (PreemptPriorityBits)) - 1UL);
  *pSubPriority     = (Priority                   ) & (uint32_t)((1UL << (SubPriorityBits    )) - 1UL);
}










 
static __inline void __NVIC_SetVector(IRQn_Type IRQn, uint32_t vector)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  vectors[(int32_t)IRQn + 16] = vector;
}









 
static __inline uint32_t __NVIC_GetVector(IRQn_Type IRQn)
{
  uint32_t *vectors = (uint32_t *)((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->VTOR;
  return vectors[(int32_t)IRQn + 16];
}





 
__declspec(noreturn) static __inline void __NVIC_SystemReset(void)
{
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                          
 
  ((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR  = (uint32_t)((0x5FAUL << 16U)    |
                           (((SCB_Type *) ((0xE000E000UL) + 0x0D00UL) )->AIRCR & (7UL << 8U)) |
                            (1UL << 2U)    );          
  do { __schedule_barrier(); __dsb(0xF); __schedule_barrier(); } while (0U);                                                           

  for(;;)                                                            
  {
    __nop();
  }
}

 

 







 





 








 
static __inline uint32_t SCB_GetFPUType(void)
{
    return 0U;            
}


 



 





 













 
static __inline uint32_t SysTick_Config(uint32_t ticks)
{
  if ((ticks - 1UL) > (0xFFFFFFUL ))
  {
    return (1UL);                                                    
  }

  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->LOAD  = (uint32_t)(ticks - 1UL);                          
  __NVIC_SetPriority (SysTick_IRQn, (1UL << 4U) - 1UL);  
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->VAL   = 0UL;                                              
  ((SysTick_Type *) ((0xE000E000UL) + 0x0010UL) )->CTRL  = (1UL << 2U) |
                   (1UL << 1U)   |
                   (1UL );                          
  return (0UL);                                                      
}



 



 





 

extern volatile int32_t ITM_RxBuffer;                               










 
static __inline uint32_t ITM_SendChar (uint32_t ch)
{
  if (((((ITM_Type *) (0xE0000000UL) )->TCR & (1UL )) != 0UL) &&       
      ((((ITM_Type *) (0xE0000000UL) )->TER & 1UL               ) != 0UL)   )      
  {
    while (((ITM_Type *) (0xE0000000UL) )->PORT[0U].u32 == 0UL)
    {
      __nop();
    }
    ((ITM_Type *) (0xE0000000UL) )->PORT[0U].u8 = (uint8_t)ch;
  }
  return (ch);
}







 
static __inline int32_t ITM_ReceiveChar (void)
{
  int32_t ch = -1;                            

  if (ITM_RxBuffer != ((int32_t)0x5AA55AA5U))
  {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ((int32_t)0x5AA55AA5U);        
  }

  return (ch);
}







 
static __inline int32_t ITM_CheckChar (void)
{

  if (ITM_RxBuffer == ((int32_t)0x5AA55AA5U))
  {
    return (0);                               
  }
  else
  {
    return (1);                               
  }
}

 










#line 132 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"
#line 1 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/system_stm32f1xx.h"
















 



 



   
  


 









 



 




 

extern uint32_t SystemCoreClock;           
extern const uint8_t  AHBPrescTable[16U];   
extern const uint8_t  APBPrescTable[8U];    



 



 



 



 



 



 
  
extern void SystemInit(void);
extern void SystemCoreClockUpdate(void);


 









 
  


 
#line 133 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"
#line 134 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



    



 

typedef struct
{
  volatile uint32_t SR;
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMPR1;
  volatile uint32_t SMPR2;
  volatile uint32_t JOFR1;
  volatile uint32_t JOFR2;
  volatile uint32_t JOFR3;
  volatile uint32_t JOFR4;
  volatile uint32_t HTR;
  volatile uint32_t LTR;
  volatile uint32_t SQR1;
  volatile uint32_t SQR2;
  volatile uint32_t SQR3;
  volatile uint32_t JSQR;
  volatile uint32_t JDR1;
  volatile uint32_t JDR2;
  volatile uint32_t JDR3;
  volatile uint32_t JDR4;
  volatile uint32_t DR;
} ADC_TypeDef;

typedef struct
{
  volatile uint32_t SR;                
  volatile uint32_t CR1;               
  volatile uint32_t CR2;               
  uint32_t  RESERVED[16];
  volatile uint32_t DR;                
} ADC_Common_TypeDef;



 

typedef struct
{
  uint32_t  RESERVED0;
  volatile uint32_t DR1;
  volatile uint32_t DR2;
  volatile uint32_t DR3;
  volatile uint32_t DR4;
  volatile uint32_t DR5;
  volatile uint32_t DR6;
  volatile uint32_t DR7;
  volatile uint32_t DR8;
  volatile uint32_t DR9;
  volatile uint32_t DR10;
  volatile uint32_t RTCCR;
  volatile uint32_t CR;
  volatile uint32_t CSR;
} BKP_TypeDef;
  


 

typedef struct
{
  volatile uint32_t TIR;
  volatile uint32_t TDTR;
  volatile uint32_t TDLR;
  volatile uint32_t TDHR;
} CAN_TxMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t RIR;
  volatile uint32_t RDTR;
  volatile uint32_t RDLR;
  volatile uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;



 
  
typedef struct
{
  volatile uint32_t FR1;
  volatile uint32_t FR2;
} CAN_FilterRegister_TypeDef;



 
  
typedef struct
{
  volatile uint32_t MCR;
  volatile uint32_t MSR;
  volatile uint32_t TSR;
  volatile uint32_t RF0R;
  volatile uint32_t RF1R;
  volatile uint32_t IER;
  volatile uint32_t ESR;
  volatile uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  volatile uint32_t FMR;
  volatile uint32_t FM1R;
  uint32_t  RESERVED2;
  volatile uint32_t FS1R;
  uint32_t  RESERVED3;
  volatile uint32_t FFA1R;
  uint32_t  RESERVED4;
  volatile uint32_t FA1R;
  uint32_t  RESERVED5[8];
  CAN_FilterRegister_TypeDef sFilterRegister[14];
} CAN_TypeDef;



 

typedef struct
{
  volatile uint32_t DR;            
  volatile uint8_t  IDR;           
  uint8_t       RESERVED0;     
  uint16_t      RESERVED1;       
  volatile uint32_t CR;             
} CRC_TypeDef;




 

typedef struct
{
  volatile uint32_t IDCODE;
  volatile uint32_t CR;
}DBGMCU_TypeDef;



 

typedef struct
{
  volatile uint32_t CCR;
  volatile uint32_t CNDTR;
  volatile uint32_t CPAR;
  volatile uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  volatile uint32_t ISR;
  volatile uint32_t IFCR;
} DMA_TypeDef;





 

typedef struct
{
  volatile uint32_t IMR;
  volatile uint32_t EMR;
  volatile uint32_t RTSR;
  volatile uint32_t FTSR;
  volatile uint32_t SWIER;
  volatile uint32_t PR;
} EXTI_TypeDef;



 

typedef struct
{
  volatile uint32_t ACR;
  volatile uint32_t KEYR;
  volatile uint32_t OPTKEYR;
  volatile uint32_t SR;
  volatile uint32_t CR;
  volatile uint32_t AR;
  volatile uint32_t RESERVED;
  volatile uint32_t OBR;
  volatile uint32_t WRPR;
} FLASH_TypeDef;



 
  
typedef struct
{
  volatile uint16_t RDP;
  volatile uint16_t USER;
  volatile uint16_t Data0;
  volatile uint16_t Data1;
  volatile uint16_t WRP0;
  volatile uint16_t WRP1;
  volatile uint16_t WRP2;
  volatile uint16_t WRP3;
} OB_TypeDef;



 

typedef struct
{
  volatile uint32_t CRL;
  volatile uint32_t CRH;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t BRR;
  volatile uint32_t LCKR;
} GPIO_TypeDef;



 

typedef struct
{
  volatile uint32_t EVCR;
  volatile uint32_t MAPR;
  volatile uint32_t EXTICR[4];
  uint32_t RESERVED0;
  volatile uint32_t MAPR2;  
} AFIO_TypeDef;


 

typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t OAR1;
  volatile uint32_t OAR2;
  volatile uint32_t DR;
  volatile uint32_t SR1;
  volatile uint32_t SR2;
  volatile uint32_t CCR;
  volatile uint32_t TRISE;
} I2C_TypeDef;



 

typedef struct
{
  volatile uint32_t KR;            
  volatile uint32_t PR;            
  volatile uint32_t RLR;           
  volatile uint32_t SR;            
} IWDG_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CSR;
} PWR_TypeDef;



 

typedef struct
{
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;


} RCC_TypeDef;



 

typedef struct
{
  volatile uint32_t CRH;
  volatile uint32_t CRL;
  volatile uint32_t PRLH;
  volatile uint32_t PRLL;
  volatile uint32_t DIVH;
  volatile uint32_t DIVL;
  volatile uint32_t CNTH;
  volatile uint32_t CNTL;
  volatile uint32_t ALRH;
  volatile uint32_t ALRL;
} RTC_TypeDef;



 

typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SR;
  volatile uint32_t DR;
  volatile uint32_t CRCPR;
  volatile uint32_t RXCRCR;
  volatile uint32_t TXCRCR;
  volatile uint32_t I2SCFGR;
} SPI_TypeDef;



 
typedef struct
{
  volatile uint32_t CR1;              
  volatile uint32_t CR2;              
  volatile uint32_t SMCR;             
  volatile uint32_t DIER;             
  volatile uint32_t SR;               
  volatile uint32_t EGR;              
  volatile uint32_t CCMR1;            
  volatile uint32_t CCMR2;            
  volatile uint32_t CCER;             
  volatile uint32_t CNT;              
  volatile uint32_t PSC;              
  volatile uint32_t ARR;              
  volatile uint32_t RCR;              
  volatile uint32_t CCR1;             
  volatile uint32_t CCR2;             
  volatile uint32_t CCR3;             
  volatile uint32_t CCR4;             
  volatile uint32_t BDTR;             
  volatile uint32_t DCR;              
  volatile uint32_t DMAR;             
  volatile uint32_t OR;               
}TIM_TypeDef;




 
 
typedef struct
{
  volatile uint32_t SR;          
  volatile uint32_t DR;          
  volatile uint32_t BRR;         
  volatile uint32_t CR1;         
  volatile uint32_t CR2;         
  volatile uint32_t CR3;         
  volatile uint32_t GTPR;        
} USART_TypeDef;



 
  
typedef struct
{
  volatile uint16_t EP0R;                   
  volatile uint16_t RESERVED0;                  
  volatile uint16_t EP1R;                  
  volatile uint16_t RESERVED1;                    
  volatile uint16_t EP2R;                  
  volatile uint16_t RESERVED2;                    
  volatile uint16_t EP3R;                   
  volatile uint16_t RESERVED3;                    
  volatile uint16_t EP4R;                  
  volatile uint16_t RESERVED4;                    
  volatile uint16_t EP5R;                  
  volatile uint16_t RESERVED5;                    
  volatile uint16_t EP6R;                  
  volatile uint16_t RESERVED6;                    
  volatile uint16_t EP7R;                  
  volatile uint16_t RESERVED7[17];              
  volatile uint16_t CNTR;                  
  volatile uint16_t RESERVED8;                    
  volatile uint16_t ISTR;                  
  volatile uint16_t RESERVED9;                    
  volatile uint16_t FNR;                   
  volatile uint16_t RESERVEDA;                    
  volatile uint16_t DADDR;                 
  volatile uint16_t RESERVEDB;                    
  volatile uint16_t BTABLE;                
  volatile uint16_t RESERVEDC;                    
} USB_TypeDef;




 

typedef struct
{
  volatile uint32_t CR;    
  volatile uint32_t CFR;   
  volatile uint32_t SR;    
} WWDG_TypeDef;



 
  


 











 




#line 612 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"


#line 624 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"










 






 
  


   

#line 688 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"




 



 

  

 

  

 

  

 
    
 
 
 

 
 
 
 
 

 




 




 




 
 
 
 
 

 
#line 757 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 764 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 774 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 784 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"






 
#line 803 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
 
 
 
 

 




 




 




 




 




 




 




 




 




 






 
#line 875 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 883 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 900 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
 
 
 
 

 
#line 938 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"


 
 










 










 
#line 971 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 981 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 989 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







 
#line 1003 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







 



















 
#line 1038 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"




#line 1088 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 1096 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







  
#line 1113 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 1166 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"


 
#line 1187 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





#line 1201 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"









 
#line 1226 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





#line 1237 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 1250 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"










 
#line 1273 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"




 
#line 1296 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





#line 1310 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"









 
#line 1335 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





#line 1346 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 1359 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"










 
#line 1379 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







 





#line 1398 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

   
#line 1427 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"


 
 
 
 
 
 

 








































































































 








































































































 
#line 1695 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 1745 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 1795 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 1844 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 1894 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 1947 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 

 
#line 1958 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2006 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 2013 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2028 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 
#line 2046 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







 
#line 2061 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







 
#line 2076 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







 
#line 2094 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







 
#line 2109 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"











 
#line 2128 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 
#line 2140 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 2151 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"


 
#line 2166 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2187 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2208 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

   
#line 2229 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2250 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2264 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2285 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2306 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

   
#line 2327 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2348 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2362 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2383 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2404 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

   
#line 2425 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2446 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2460 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2481 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2502 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

   
#line 2523 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2544 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 



 
 
 
 
 

 
#line 2613 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2635 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"
 
 
#line 2694 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2715 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2774 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2795 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2854 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2875 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2934 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 2955 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3014 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3035 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
 
 
 
 

 
#line 3127 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3213 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3239 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"























 




 




 




 
 
 
 
 



 


 
#line 3304 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 



 
#line 3318 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3343 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3350 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3358 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3365 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 



 
#line 3389 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3396 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





#line 3407 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3420 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3428 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3435 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3442 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3449 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3456 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3463 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3470 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3477 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3485 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3492 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3499 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3506 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3513 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3520 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3527 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3534 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3541 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3548 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 




 




 




 




 




 
#line 3588 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3597 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3606 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3615 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3623 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3633 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3642 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3651 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3660 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3669 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3678 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3688 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3697 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3706 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3715 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3724 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3733 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3743 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3752 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3761 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3770 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







 




 




 




 




 
#line 3804 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"


 
 
 
 
 
 
#line 3827 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

















 
#line 3854 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3861 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3886 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3894 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 3901 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





#line 3913 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







#line 3926 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 3973 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 4011 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 4037 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 






#line 4051 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 4058 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"











#line 4075 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 4082 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 







#line 4102 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







#line 4116 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 






#line 4130 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 4137 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"











#line 4154 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 4161 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 







#line 4181 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







#line 4195 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 4239 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 




 




 




 




 




 




 




 
#line 4292 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







#line 4317 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 4327 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 4336 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 
 
 
 
 

 
#line 4358 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 4378 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 




 




 




 




 




 




 




 
 
 
 
 

 




 
#line 4437 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 
#line 4450 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
 
 
 
 

 
#line 4468 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 4477 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 
#line 4493 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 4502 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







 







 




 
 
 
 
 

 
#line 4537 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

  
#line 4569 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 

                                                                            
#line 4581 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"


                                                                                
#line 4591 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"
                                                                                
#line 4599 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 










#line 4620 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"
                                                                           
















#line 4643 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 



                                                                          






#line 4664 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"










                                                                           






#line 4687 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 










#line 4708 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

















#line 4731 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 










#line 4752 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

















#line 4775 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 










#line 4796 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

















#line 4819 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 










#line 4840 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

















#line 4863 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 










#line 4884 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

















#line 4907 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 










#line 4928 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

















#line 4951 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
 
#line 4993 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5025 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5042 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5068 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





     




 
 




 




 




 




 




 




 




 




 

 




 




 




 




 




 




 




 




 

 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 


 

 




 




 




 




 




 




 




 




 

 




#line 5268 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 




#line 5286 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 




#line 5304 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 




#line 5322 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 




#line 5340 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 




#line 5358 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 




#line 5376 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 




#line 5394 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 

 


#line 5410 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5422 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5434 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5446 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5458 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5470 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5482 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5494 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5506 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5518 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5530 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5542 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5554 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5566 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5578 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 


#line 5590 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



 
 
 
 
 

 
 
#line 5631 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5660 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5710 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 5723 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 5736 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5750 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5764 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5808 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5819 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 5826 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 5833 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5862 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
 
#line 5880 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5891 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5905 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5919 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5936 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5947 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5961 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5975 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 5992 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

   
#line 6003 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6017 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6031 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6045 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6056 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6070 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6084 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6098 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6109 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6123 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6137 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
 
#line 6146 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6193 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6240 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6287 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6334 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6432 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6530 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6628 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6726 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6824 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 6922 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 7020 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 7118 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 7216 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 7314 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 7412 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 7510 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 7608 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 7706 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 7804 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 7902 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8000 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8098 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8196 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8294 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8392 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8490 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8588 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8686 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8784 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8882 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 8980 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9078 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
 
 
 
 

 
#line 9095 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 9102 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 9133 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9153 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9179 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 




 




 








 
 
 
 
 

 
#line 9253 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9264 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 9280 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 



#line 9315 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 
#line 9327 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 
#line 9376 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9402 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9413 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 
 
 
 
 

 
#line 9456 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 
#line 9469 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9513 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9536 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"











 
#line 9581 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9594 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 
 
 
 
 

 




#line 9629 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9643 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"







#line 9677 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
 
 
 
 
 
#line 9690 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 9700 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




#line 9715 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 







 
#line 9737 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9769 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 
#line 9782 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

#line 9801 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 




 

 
#line 9816 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9824 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9832 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9840 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9848 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9856 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9864 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"

 
#line 9872 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"





 



  



 

 









     


 


 

 
#line 9913 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"
  
 






 


 


 



 


 


 



 
 































































































#line 10062 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"



























    





    















 


                                            




 




 




 




                                     




 




 




 




 




 


 


 











  
 
 
 
 
  
 
 

 
#line 10203 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"


 
#line 10222 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f103xb.h"




 



 





  

  
  

#line 131 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"
#line 142 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"



 



   
typedef enum 
{
  RESET = 0, 
  SET = !RESET
} FlagStatus, ITStatus;

typedef enum 
{
  DISABLE = 0, 
  ENABLE = !DISABLE
} FunctionalState;


typedef enum
{
  SUCCESS = 0U,
  ERROR = !SUCCESS
} ErrorStatus;



 




 
















 
 
#line 202 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"

 
#line 211 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"

 
#line 220 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"

 
#line 229 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"

 
#line 238 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"

 
#line 247 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"




 

#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

















 

 
#line 356 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"


#line 255 "../Drivers/CMSIS/Device/ST/STM32F1xx/Include/stm32f1xx.h"










 



 
  



#line 30 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h"
#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

















 

 







 
 
 



 
#line 46 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 
#line 93 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 101 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"
















 



 





 



 
#line 150 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 217 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"







 



 
#line 235 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 
#line 249 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 






 



 

#line 277 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






#line 289 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"














 



 
#line 322 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"





#line 367 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 377 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 439 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






 



 

#line 563 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 

#line 580 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 

#line 605 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 704 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"




 




 
#line 725 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 





 



 


















#line 776 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"





#line 788 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 795 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"









#line 811 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 826 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 
#line 854 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 
#line 870 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 879 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 890 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1002 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1019 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 
#line 1043 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 





 



 






 



 















 
 







 



 








 



 














 



 










 



 







































 



 


#line 1200 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






 



 

 
#line 1222 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

 












 



 

































#line 1283 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"
















#line 1305 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 




 















 




 
#line 1346 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 









#line 1376 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 



#line 1414 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1424 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1443 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"










#line 1470 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"







 



 




 



 

























 




 








 



 




 



 
#line 1554 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 

#line 1571 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1583 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1624 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"





 



 











 

#line 1674 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1688 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 

 



 



 



 








 




 




 



 
#line 1739 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

 












#line 1776 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 
#line 1809 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 
#line 1824 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 









#line 1857 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1868 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 

#line 1898 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 1906 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






#line 1922 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



#line 2011 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 
#line 2025 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 





 



 



 



 
#line 2064 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 



 



 






 




 



 

 



 





 



 
#line 2125 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"









 




 
#line 2153 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2174 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2185 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2194 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2207 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2216 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 







 



 
#line 2252 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2267 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


#line 2300 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 
#line 2468 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



#line 2478 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 

#line 2494 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 







 



 

#line 2517 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 

#line 2545 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 










 



 














 




 




 




 







 




 
#line 2623 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 




 
#line 2673 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2687 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 




 








#line 2967 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 2981 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3198 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3217 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3224 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3245 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3393 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

 



#line 3418 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3439 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3556 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3565 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3582 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3597 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






#line 3626 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

















#line 3652 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"





#line 3679 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"





#line 3690 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3699 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3732 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3750 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"












#line 3768 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3791 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3831 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3917 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"



 



 




 



 
#line 3943 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"










#line 3971 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3978 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 3993 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"











 



 




#line 4021 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 4047 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 4073 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 4080 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 4092 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 

#line 4106 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"








 



 
#line 4127 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 







 



 













 




 









#line 4181 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 












#line 4207 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 4216 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"

#line 4225 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"








 



 








#line 4258 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"







 



 

#line 4278 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"






 



 




 



 
#line 4312 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 







 



 
#line 4339 "../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy/stm32_hal_legacy.h"


 



 





 



 





 



 



 








#line 31 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h"
#line 1 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stddef.h"
 






 

 
 
 





 





#line 34 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stddef.h"




  typedef signed int ptrdiff_t;



  



    typedef unsigned int size_t;    
#line 57 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stddef.h"



   



      typedef unsigned short wchar_t;  
#line 82 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stddef.h"



    




   




  typedef long double max_align_t;









#line 114 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stddef.h"



 

#line 32 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h"

 



 
typedef enum
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;



 
typedef enum
{
  HAL_UNLOCKED = 0x00U,
  HAL_LOCKED   = 0x01U
} HAL_LockTypeDef;

 





























 


#line 103 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h"







#line 125 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h"


 
#line 154 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h"




 









 


#line 187 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h"



 



 


#line 204 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_def.h"








#line 28 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"




 



 

 



 



 
typedef struct
{
  uint32_t PLLState;      
 

  uint32_t PLLSource;     
 

  uint32_t PLLMUL;        
 
} RCC_PLLInitTypeDef;



 
typedef struct
{
  uint32_t ClockType;             
 

  uint32_t SYSCLKSource;          
 

  uint32_t AHBCLKDivider;         
 

  uint32_t APB1CLKDivider;        
 

  uint32_t APB2CLKDivider;        
 
} RCC_ClkInitTypeDef;



 

 


 



 






 



 







 



 





 



 






 



 







 



 





 



 






 



 







 



 






 



 






 



 
#line 212 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"



 



 








 



 






 




 





 



 




 



 
#line 270 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"


 









 
 




 
#line 296 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

 




 



 

 



 







 
#line 328 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 336 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 344 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 352 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"








 







 

#line 378 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"



 







 
#line 397 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 405 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 413 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 421 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 429 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 437 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 445 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"












 







 

#line 481 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"



 







 
#line 500 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 508 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 516 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 524 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 532 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 540 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 548 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 556 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 564 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 571 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"







 







 

#line 606 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"



 




 
#line 621 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"




#line 631 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"






 




 
#line 650 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"





#line 662 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"







 



 










 









 





 



 





 






 




 



 






















 
#line 772 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"



 



 

















 
#line 820 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"



 



 






 




 































 








 




 



 








 









 




 



 

#line 937 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"











 








 



 






















 








 




 




 





 



 




 




 
















 

















 


















 



















 





 
























 






 



 

 
#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"















 

 







 
#line 28 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 



 



 

#line 54 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"






 



 






#line 85 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 107 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"










#line 171 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"






#line 184 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"










 

 



 

#line 222 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 
typedef struct
{
  uint32_t OscillatorType;       
 






  uint32_t HSEState;              
 

  uint32_t HSEPredivValue;       
 

  uint32_t LSEState;              
 

  uint32_t HSIState;              
 

  uint32_t HSICalibrationValue;   
 

  uint32_t LSIState;              
 

  RCC_PLLInitTypeDef PLL;          




} RCC_OscInitTypeDef;

#line 277 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 
typedef struct
{
  uint32_t PeriphClockSelection;      
 

  uint32_t RTCClockSelection;         
 

  uint32_t AdcClockSelection;         
 

#line 306 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"




  uint32_t UsbClockSelection;         
 


} RCC_PeriphCLKInitTypeDef;



 

 



 



 
#line 341 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 



 







 

#line 385 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"






 





 




#line 431 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 444 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 



#line 471 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 

#line 532 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 

#line 559 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 



 
#line 578 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"


 

#line 606 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 

 


 







 

#line 637 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 650 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 663 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 676 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 724 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 







 

#line 764 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 







 

#line 786 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"




#line 801 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 809 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 817 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 825 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"







#line 841 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"




#line 911 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 950 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1016 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1028 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1058 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 







 

#line 1149 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 







 

#line 1172 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"




#line 1205 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1217 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"




#line 1242 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1263 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1284 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1314 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 







 

#line 1375 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 

#line 1401 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"




 








#line 1422 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"













#line 1453 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1465 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1483 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"







#line 1499 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 




 









#line 1526 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"










#line 1544 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1552 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1560 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"

#line 1570 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 



 

#line 1591 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"







 





#line 1612 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"


 






 

#line 1665 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"




 








 







 




#line 1710 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"








 









 




 

#line 1844 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"


 

 


 



 

HAL_StatusTypeDef HAL_RCCEx_PeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
void              HAL_RCCEx_GetPeriphCLKConfig(RCC_PeriphCLKInitTypeDef  *PeriphClkInit);
uint32_t          HAL_RCCEx_GetPeriphCLKFreq(uint32_t PeriphClk);



 

#line 1886 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc_ex.h"



 



 



 








#line 1143 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

 


 



 

 
HAL_StatusTypeDef HAL_RCC_DeInit(void);
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency);



 



 

 
void              HAL_RCC_MCOConfig(uint32_t RCC_MCOx, uint32_t RCC_MCOSource, uint32_t RCC_MCODiv);
void              HAL_RCC_EnableCSS(void);
void              HAL_RCC_DisableCSS(void);
uint32_t          HAL_RCC_GetSysClockFreq(void);
uint32_t          HAL_RCC_GetHCLKFreq(void);
uint32_t          HAL_RCC_GetPCLK1Freq(void);
uint32_t          HAL_RCC_GetPCLK2Freq(void);
void              HAL_RCC_GetOscConfig(RCC_OscInitTypeDef  *RCC_OscInitStruct);
void              HAL_RCC_GetClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t *pFLatency);

 
void              HAL_RCC_NMI_IRQHandler(void);

 
void              HAL_RCC_CSSCallback(void);



 



 



 



 

 

 
#line 1208 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"



 



 
#line 1222 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"



 




 






 
 


 


 


 



 
 



 



 
 



 



 



 





 

 


 


 


 








 



 


 






 

#line 1331 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"

#line 1356 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_rcc.h"



 



 



 








#line 239 "../Inc/stm32f1xx_hal_conf.h"


#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio.h"
















 

 







 
#line 29 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio.h"



 



 

 


 



 
typedef struct
{
  uint32_t Pin;       
 

  uint32_t Mode;      
 

  uint32_t Pull;      
 

  uint32_t Speed;     
 
} GPIO_InitTypeDef;



 
typedef enum
{
  GPIO_PIN_RESET = 0u,
  GPIO_PIN_SET
} GPIO_PinState;


 

 



 



 
#line 99 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio.h"




 










 
#line 121 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio.h"













 




 






 




 





 



 

 


 






 







 







 







 







 



 

 
#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"
















 

 







 
#line 29 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"



 



 
 
 



 




 



 

#line 69 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 86 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"


 



 














 



 




 





 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 






 







 







 







 







 







 








 






 






 











 









 


#line 346 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 364 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 383 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 401 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"





 






 






 






 


#line 446 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 463 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"





 






 






 







 


#line 511 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 530 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 549 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 566 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 583 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 599 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 616 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 633 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 650 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 667 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 684 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 701 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 718 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 735 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 752 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 771 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"

#line 798 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"



 



 



 
#line 827 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"













#line 846 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio_ex.h"









 

 
 



 



 
void HAL_GPIOEx_ConfigEventout(uint32_t GPIO_PortSource, uint32_t GPIO_PinSource);
void HAL_GPIOEx_EnableEventout(void);
void HAL_GPIOEx_DisableEventout(void);



 



 



 



 







#line 213 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio.h"

 


 



 
 
void  HAL_GPIO_Init(GPIO_TypeDef  *GPIOx, GPIO_InitTypeDef *GPIO_Init);
void  HAL_GPIO_DeInit(GPIO_TypeDef  *GPIOx, uint32_t GPIO_Pin);


 



 
 
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void HAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_GPIO_LockPin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_IRQHandler(uint16_t GPIO_Pin);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);



 



 
 
 
 


 



 

 


 
#line 280 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_gpio.h"


 

 


 



 



 



 







#line 243 "../Inc/stm32f1xx_hal_conf.h"


#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_exti.h"
















 

 







 
#line 29 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_exti.h"



 




 

 



 



 
typedef enum
{
  HAL_EXTI_COMMON_CB_ID          = 0x00U
} EXTI_CallbackIDTypeDef;



 
typedef struct
{
  uint32_t Line;                     
  void (* PendingCallback)(void);    
} EXTI_HandleTypeDef;



 
typedef struct
{
  uint32_t Line;      
 
  uint32_t Mode;      
 
  uint32_t Trigger;   
 
  uint32_t GPIOSel;   

 
} EXTI_ConfigTypeDef;



 

 


 



 
#line 114 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_exti.h"



 



 





 



 






 




 
#line 157 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_exti.h"


 



 

 


 



 

 


 


 







 




 




 




 
#line 211 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_exti.h"


 

 


 














#line 260 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_exti.h"





 

 



 




 
 
HAL_StatusTypeDef HAL_EXTI_SetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_GetConfigLine(EXTI_HandleTypeDef *hexti, EXTI_ConfigTypeDef *pExtiConfig);
HAL_StatusTypeDef HAL_EXTI_ClearConfigLine(EXTI_HandleTypeDef *hexti);
HAL_StatusTypeDef HAL_EXTI_RegisterCallback(EXTI_HandleTypeDef *hexti, EXTI_CallbackIDTypeDef CallbackID, void (*pPendingCbfn)(void));
HAL_StatusTypeDef HAL_EXTI_GetHandle(EXTI_HandleTypeDef *hexti, uint32_t ExtiLine);


 




 
 
void              HAL_EXTI_IRQHandler(EXTI_HandleTypeDef *hexti);
uint32_t          HAL_EXTI_GetPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
void              HAL_EXTI_ClearPending(EXTI_HandleTypeDef *hexti, uint32_t Edge);
void              HAL_EXTI_GenerateSWI(EXTI_HandleTypeDef *hexti);



 



 



 



 







#line 247 "../Inc/stm32f1xx_hal_conf.h"


#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma.h"
















 

 







 
#line 29 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma.h"



 



 

 



 



 
typedef struct
{
  uint32_t Direction;                 

 

  uint32_t PeriphInc;                 
 

  uint32_t MemInc;                    
 

  uint32_t PeriphDataAlignment;       
 

  uint32_t MemDataAlignment;          
 

  uint32_t Mode;                      


 

  uint32_t Priority;                  
 
} DMA_InitTypeDef;



 
typedef enum
{
  HAL_DMA_STATE_RESET             = 0x00U,   
  HAL_DMA_STATE_READY             = 0x01U,   
  HAL_DMA_STATE_BUSY              = 0x02U,   
  HAL_DMA_STATE_TIMEOUT           = 0x03U    
}HAL_DMA_StateTypeDef;



 
typedef enum
{
  HAL_DMA_FULL_TRANSFER           = 0x00U,     
  HAL_DMA_HALF_TRANSFER           = 0x01U      
}HAL_DMA_LevelCompleteTypeDef;



 
typedef enum
{
  HAL_DMA_XFER_CPLT_CB_ID          = 0x00U,     
  HAL_DMA_XFER_HALFCPLT_CB_ID      = 0x01U,     
  HAL_DMA_XFER_ERROR_CB_ID         = 0x02U,      
  HAL_DMA_XFER_ABORT_CB_ID         = 0x03U,      
  HAL_DMA_XFER_ALL_CB_ID           = 0x04U       
    
}HAL_DMA_CallbackIDTypeDef;



 
typedef struct __DMA_HandleTypeDef
{
  DMA_Channel_TypeDef        *Instance;                                                     
  
  DMA_InitTypeDef            Init;                                                          
  
  HAL_LockTypeDef            Lock;                                                          
  
  volatile HAL_DMA_StateTypeDef  State;                                                         
  
  void                       *Parent;                                                       
  
  void                       (* XferCpltCallback)( struct __DMA_HandleTypeDef * hdma);      
  
  void                       (* XferHalfCpltCallback)( struct __DMA_HandleTypeDef * hdma);  
  
  void                       (* XferErrorCallback)( struct __DMA_HandleTypeDef * hdma);     

  void                       (* XferAbortCallback)( struct __DMA_HandleTypeDef * hdma);     
  
  volatile uint32_t              ErrorCode;                                                     

  DMA_TypeDef                *DmaBaseAddress;                                              
  
  uint32_t                   ChannelIndex;                                                 

} DMA_HandleTypeDef;    


 

 



 



 







 



 






 



 




 



 




 



 





 



 





 



 




 



 






 




 





 



 
#line 270 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma.h"


 



 


 


 




 






 






 



 










 











 











 






 




 

 
#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h"
















 

 







 
#line 29 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h"



 



 

  
 
 


 
 
#line 162 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h"


 





 
#line 179 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h"





 
#line 193 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h"





 
#line 207 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h"





 
#line 221 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma_ex.h"












 














 




 


  


 



 



 




        



#line 356 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_dma.h"

 


 



 
 
HAL_StatusTypeDef HAL_DMA_Init(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_DeInit (DMA_HandleTypeDef *hdma);


 



 
 
HAL_StatusTypeDef HAL_DMA_Start (DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Start_IT(DMA_HandleTypeDef *hdma, uint32_t SrcAddress, uint32_t DstAddress, uint32_t DataLength);
HAL_StatusTypeDef HAL_DMA_Abort(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_Abort_IT(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_PollForTransfer(DMA_HandleTypeDef *hdma, uint32_t CompleteLevel, uint32_t Timeout);
void HAL_DMA_IRQHandler(DMA_HandleTypeDef *hdma);
HAL_StatusTypeDef HAL_DMA_RegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID, void (* pCallback)( DMA_HandleTypeDef * _hdma));
HAL_StatusTypeDef HAL_DMA_UnRegisterCallback(DMA_HandleTypeDef *hdma, HAL_DMA_CallbackIDTypeDef CallbackID);



 



 
 
HAL_DMA_StateTypeDef HAL_DMA_GetState(DMA_HandleTypeDef *hdma);
uint32_t HAL_DMA_GetError(DMA_HandleTypeDef *hdma);


 



 

 


 































  

 



 



 







#line 251 "../Inc/stm32f1xx_hal_conf.h"


















#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_cortex.h"
















 

 







 
#line 29 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_cortex.h"



 



  
 


 

#line 75 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_cortex.h"



 

 



 



 
#line 99 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_cortex.h"


 



 





 

#line 244 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_cortex.h"



 


 

 


 
  


 
 
void HAL_NVIC_SetPriorityGrouping(uint32_t PriorityGroup);
void HAL_NVIC_SetPriority(IRQn_Type IRQn, uint32_t PreemptPriority, uint32_t SubPriority);
void HAL_NVIC_EnableIRQ(IRQn_Type IRQn);
void HAL_NVIC_DisableIRQ(IRQn_Type IRQn);
void HAL_NVIC_SystemReset(void);
uint32_t HAL_SYSTICK_Config(uint32_t TicksNumb);


 



 
 
uint32_t HAL_NVIC_GetPriorityGrouping(void);
void HAL_NVIC_GetPriority(IRQn_Type IRQn, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority);
uint32_t HAL_NVIC_GetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_SetPendingIRQ(IRQn_Type IRQn);
void HAL_NVIC_ClearPendingIRQ(IRQn_Type IRQn);
uint32_t HAL_NVIC_GetActive(IRQn_Type IRQn);
void HAL_SYSTICK_CLKSourceConfig(uint32_t CLKSource);
void HAL_SYSTICK_IRQHandler(void);
void HAL_SYSTICK_Callback(void);

#line 292 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_cortex.h"


 



 

 
 
 
 


 















#line 389 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_cortex.h"



 

 



  



 
  





 

#line 271 "../Inc/stm32f1xx_hal_conf.h"


#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"

















 

 







 
#line 30 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"


 



  

  


 








 
typedef struct
{
  uint32_t DataAlign;                        

 
  uint32_t ScanConvMode;                     









 
  FunctionalState ContinuousConvMode;         

 
  uint32_t NbrOfConversion;                  

 
  FunctionalState  DiscontinuousConvMode;    


 
  uint32_t NbrOfDiscConversion;              

 
  uint32_t ExternalTrigConv;                 


 
}ADC_InitTypeDef;





  
typedef struct 
{
  uint32_t Channel;                





 
  uint32_t Rank;                   

 
  uint32_t SamplingTime;           







 
}ADC_ChannelConfTypeDef;





 
typedef struct
{
  uint32_t WatchdogMode;      
 
  uint32_t Channel;           

 
  FunctionalState  ITMode;    
 
  uint32_t HighThreshold;     
 
  uint32_t LowThreshold;      
 
  uint32_t WatchdogNumber;     
}ADC_AnalogWDGConfTypeDef;



  
 





 




 






 





 




 





  
typedef struct __ADC_HandleTypeDef
{
  ADC_TypeDef                   *Instance;               

  ADC_InitTypeDef               Init;                    

  DMA_HandleTypeDef             *DMA_Handle;             

  HAL_LockTypeDef               Lock;                    
  
  volatile uint32_t                 State;                   

  volatile uint32_t                 ErrorCode;               

#line 197 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"
}ADC_HandleTypeDef;


#line 221 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"



 



 



 



 











 




 




 



 
 
 
 




 



 




 



 
 
 
#line 304 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"





 



 
#line 322 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"


 



 
#line 345 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"


 



 
#line 359 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"


 



 





 



 





 



 





 



 







 




  

 



 



 
 
 
 
#line 430 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"


 



 
#line 444 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"

#line 452 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"

#line 460 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"

#line 469 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"

#line 478 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"


 

 




 


 



 
 
     









 


    




 


    








 


    








 











 













 


    










 






 
#line 597 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"



 

 



 
 
 





 









 








 









 






 







 








 








 








 








 








 







 












 







 







 







 
 
 
















    
#line 782 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"










#line 810 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"

#line 819 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"

#line 836 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"

#line 844 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"











 



 



 



 



 



 
      


 
    
 
#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"
















 

 







 
#line 29 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"



 



  

  


 











 
typedef struct 
{
  uint32_t InjectedChannel;                       





 
  uint32_t InjectedRank;                          

 
  uint32_t InjectedSamplingTime;                  







 
  uint32_t InjectedOffset;                        


 
  uint32_t InjectedNbrOfConversion;               



 
  FunctionalState InjectedDiscontinuousConvMode;  





 
  FunctionalState AutoInjectedConv;               






 
  uint32_t ExternalTrigInjecConv;                 






 
}ADC_InjectionConfTypeDef;






 
typedef struct
{
  uint32_t Mode;              







 

  
}ADC_MultiModeTypeDef;                                                          




 


 
   


 



 






 



 




 
    


 
 
 

 
#line 175 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"

#line 184 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"

 


#line 201 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"




 



 
 
 

 






#line 227 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"

 



#line 245 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"




 




 
#line 265 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"


 




 


 



 



 
 
 
 

 
#line 300 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"

#line 310 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"

 




 



 
 
 
 

 
#line 336 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"

#line 345 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"

 





 



 


 

 



 
 
 

    









 
#line 397 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"










 
#line 425 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"






 
#line 444 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"





 
#line 462 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"





 
#line 480 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"







 










 


       












 



 

#line 564 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"

#line 612 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"

#line 625 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc_ex.h"



       
   
    

    
    
   
 


 

 


 

 
HAL_StatusTypeDef       HAL_ADCEx_Calibration_Start(ADC_HandleTypeDef* hadc);

 
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedPollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);

 
HAL_StatusTypeDef       HAL_ADCEx_InjectedStart_IT(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADCEx_InjectedStop_IT(ADC_HandleTypeDef* hadc);


 
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStart_DMA(ADC_HandleTypeDef *hadc, uint32_t *pData, uint32_t Length);
HAL_StatusTypeDef       HAL_ADCEx_MultiModeStop_DMA(ADC_HandleTypeDef *hadc); 


 
uint32_t                HAL_ADCEx_InjectedGetValue(ADC_HandleTypeDef* hadc, uint32_t InjectedRank);

uint32_t                HAL_ADCEx_MultiModeGetValue(ADC_HandleTypeDef *hadc);


 
void                    HAL_ADCEx_InjectedConvCpltCallback(ADC_HandleTypeDef* hadc);


 


 


 
HAL_StatusTypeDef       HAL_ADCEx_InjectedConfigChannel(ADC_HandleTypeDef* hadc,ADC_InjectionConfTypeDef* sConfigInjected);

HAL_StatusTypeDef       HAL_ADCEx_MultiModeConfigChannel(ADC_HandleTypeDef *hadc, ADC_MultiModeTypeDef *multimode);



 




 




  



 
  




#line 883 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_adc.h"

 


 



 


 
HAL_StatusTypeDef       HAL_ADC_Init(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADC_DeInit(ADC_HandleTypeDef *hadc);
void                    HAL_ADC_MspInit(ADC_HandleTypeDef* hadc);
void                    HAL_ADC_MspDeInit(ADC_HandleTypeDef* hadc);









 

 



 


 
HAL_StatusTypeDef       HAL_ADC_Start(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADC_Stop(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADC_PollForConversion(ADC_HandleTypeDef* hadc, uint32_t Timeout);
HAL_StatusTypeDef       HAL_ADC_PollForEvent(ADC_HandleTypeDef* hadc, uint32_t EventType, uint32_t Timeout);

 
HAL_StatusTypeDef       HAL_ADC_Start_IT(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef       HAL_ADC_Stop_IT(ADC_HandleTypeDef* hadc);

 
HAL_StatusTypeDef       HAL_ADC_Start_DMA(ADC_HandleTypeDef* hadc, uint32_t* pData, uint32_t Length);
HAL_StatusTypeDef       HAL_ADC_Stop_DMA(ADC_HandleTypeDef* hadc);

 
uint32_t                HAL_ADC_GetValue(ADC_HandleTypeDef* hadc);

 
void                    HAL_ADC_IRQHandler(ADC_HandleTypeDef* hadc);
void                    HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
void                    HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc);
void                    HAL_ADC_LevelOutOfWindowCallback(ADC_HandleTypeDef* hadc);
void                    HAL_ADC_ErrorCallback(ADC_HandleTypeDef *hadc);


 


 


 
HAL_StatusTypeDef       HAL_ADC_ConfigChannel(ADC_HandleTypeDef* hadc, ADC_ChannelConfTypeDef* sConfig);
HAL_StatusTypeDef       HAL_ADC_AnalogWDGConfig(ADC_HandleTypeDef* hadc, ADC_AnalogWDGConfTypeDef* AnalogWDGConfig);


 


 


 
uint32_t                HAL_ADC_GetState(ADC_HandleTypeDef* hadc);
uint32_t                HAL_ADC_GetError(ADC_HandleTypeDef *hadc);


 




 


 


 
HAL_StatusTypeDef ADC_Enable(ADC_HandleTypeDef* hadc);
HAL_StatusTypeDef ADC_ConversionStop_Disable(ADC_HandleTypeDef* hadc);
void              ADC_StabilizationTime(uint32_t DelayUs);
void              ADC_DMAConvCplt(DMA_HandleTypeDef *hdma);
void              ADC_DMAHalfConvCplt(DMA_HandleTypeDef *hdma);
void              ADC_DMAError(DMA_HandleTypeDef *hdma);


  




  



 






#line 275 "../Inc/stm32f1xx_hal_conf.h"










#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash.h"















 

 







 
#line 28 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash.h"
   


 



 
  


 



 



 















   

  


   



 
typedef enum 
{
  FLASH_PROC_NONE              = 0U, 
  FLASH_PROC_PAGEERASE         = 1U,
  FLASH_PROC_MASSERASE         = 2U,
  FLASH_PROC_PROGRAMHALFWORD   = 3U,
  FLASH_PROC_PROGRAMWORD       = 4U,
  FLASH_PROC_PROGRAMDOUBLEWORD = 5U
} FLASH_ProcedureTypeDef;



 
typedef struct
{
  volatile FLASH_ProcedureTypeDef ProcedureOnGoing;  
  
  volatile uint32_t               DataRemaining;     

  volatile uint32_t               Address;           

  volatile uint64_t               Data;              

  HAL_LockTypeDef             Lock;              

  volatile uint32_t               ErrorCode;        
 
} FLASH_ProcessTypeDef;



 

 


   



 








 



  






 




 






 

#line 158 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash.h"


   
  
 




 
 



 






 







 




 





  
  





  







  




 





    



  





 




 
  


  

 
#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"















 

 







 
#line 28 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"



 



  



 







   



 





















 





 
#line 86 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"

 






 





 








#line 116 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"

 






 








 
#line 140 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"

 






 
#line 155 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"



   

  


   



 
typedef struct
{
  uint32_t TypeErase;   
 
  
  uint32_t Banks;       
     
  
  uint32_t PageAddress; 

 
  
  uint32_t NbPages;     
 
                                                          
} FLASH_EraseInitTypeDef;



 
typedef struct
{
  uint32_t OptionType;  
 

  uint32_t WRPState;    
 

  uint32_t WRPPage;     
 

  uint32_t Banks;        
  
    
  uint8_t RDPLevel;     
 

#line 211 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"
  uint8_t USERConfig;   


 


  uint32_t DATAAddress; 
 
  
  uint8_t DATAData;     
 
} FLASH_OBProgramInitTypeDef;



 

 


   



  



  



        




         
        



 



  





 



 
#line 276 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"


 



 



  



 







 



  





 



 
 
#line 326 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"
        
       
 
#line 355 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"


 
#line 396 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"
         
        


 
 




 
#line 413 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"
       
 
#line 421 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"

 
#line 429 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"
      
 
#line 437 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"



 



 




 
  


  




 



  




  



  




 

#line 488 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"



 




 



 



  




 
#line 527 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"










 
  



 
#line 554 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"







   



 
  



 

 


 




  

#line 673 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"







  









  












 












 
#line 728 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash_ex.h"





 



 

 


 



 
 
HAL_StatusTypeDef  HAL_FLASHEx_Erase(FLASH_EraseInitTypeDef *pEraseInit, uint32_t *PageError);
HAL_StatusTypeDef  HAL_FLASHEx_Erase_IT(FLASH_EraseInitTypeDef *pEraseInit);



 



 
 
HAL_StatusTypeDef  HAL_FLASHEx_OBErase(void);
HAL_StatusTypeDef  HAL_FLASHEx_OBProgram(FLASH_OBProgramInitTypeDef *pOBInit);
void               HAL_FLASHEx_OBGetConfig(FLASH_OBProgramInitTypeDef *pOBInit);
uint32_t           HAL_FLASHEx_OBGetUserData(uint32_t DATAAdress);


 



 



 



 






#line 247 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_flash.h"

 


 
  


 
 
HAL_StatusTypeDef HAL_FLASH_Program(uint32_t TypeProgram, uint32_t Address, uint64_t Data);
HAL_StatusTypeDef HAL_FLASH_Program_IT(uint32_t TypeProgram, uint32_t Address, uint64_t Data);

 
void       HAL_FLASH_IRQHandler(void);
  
void       HAL_FLASH_EndOfOperationCallback(uint32_t ReturnValue);
void       HAL_FLASH_OperationErrorCallback(uint32_t ReturnValue);



 



 
 
HAL_StatusTypeDef HAL_FLASH_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_Lock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Unlock(void);
HAL_StatusTypeDef HAL_FLASH_OB_Lock(void);
void HAL_FLASH_OB_Launch(void);



 



 
 
uint32_t HAL_FLASH_GetError(void);



 



 

 


 
HAL_StatusTypeDef       FLASH_WaitForLastOperation(uint32_t Timeout);






 



 



 








#line 287 "../Inc/stm32f1xx_hal_conf.h"






















#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_pwr.h"
















 

 







 
#line 29 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_pwr.h"



 



 

 



  



 
typedef struct
{
  uint32_t PVDLevel;   
 

  uint32_t Mode;      
 
}PWR_PVDTypeDef;




 


 



  





 

 
 



  



 
#line 92 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_pwr.h"
                                                          


 



 
#line 107 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_pwr.h"



 




 





 



 





 



 





 



 





 



 







 



 

 


 















 







 





 





 





 





 






 






 






 






 





 






 







 





 





 



 

 


 






















 



 



 
  


 

 
void HAL_PWR_DeInit(void);
void HAL_PWR_EnableBkUpAccess(void);
void HAL_PWR_DisableBkUpAccess(void);



 



 

 
void HAL_PWR_ConfigPVD(PWR_PVDTypeDef *sConfigPVD);
 
void HAL_PWR_EnablePVD(void);
void HAL_PWR_DisablePVD(void);

 
void HAL_PWR_EnableWakeUpPin(uint32_t WakeUpPinx);
void HAL_PWR_DisableWakeUpPin(uint32_t WakeUpPinx);

 
void HAL_PWR_EnterSTOPMode(uint32_t Regulator, uint8_t STOPEntry);
void HAL_PWR_EnterSLEEPMode(uint32_t Regulator, uint8_t SLEEPEntry);
void HAL_PWR_EnterSTANDBYMode(void);

void HAL_PWR_EnableSleepOnExit(void);
void HAL_PWR_DisableSleepOnExit(void);
void HAL_PWR_EnableSEVOnPend(void);
void HAL_PWR_DisableSEVOnPend(void);



void HAL_PWR_PVD_IRQHandler(void);
void HAL_PWR_PVDCallback(void);


 



 



 



 






#line 311 "../Inc/stm32f1xx_hal_conf.h"


























#line 1 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"
















 

 







 
#line 29 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"



 



 

 


 



 
typedef struct
{
  uint32_t BaudRate;                  


 

  uint32_t WordLength;                
 

  uint32_t StopBits;                  
 

  uint32_t Parity;                    




 

  uint32_t Mode;                      
 

  uint32_t HwFlowCtl;                 
 

  uint32_t OverSampling;              

 
} UART_InitTypeDef;







































 
typedef enum
{
  HAL_UART_STATE_RESET             = 0x00U,    
 
  HAL_UART_STATE_READY             = 0x20U,    
 
  HAL_UART_STATE_BUSY              = 0x24U,    
 
  HAL_UART_STATE_BUSY_TX           = 0x21U,    
 
  HAL_UART_STATE_BUSY_RX           = 0x22U,    
 
  HAL_UART_STATE_BUSY_TX_RX        = 0x23U,    

 
  HAL_UART_STATE_TIMEOUT           = 0xA0U,    
 
  HAL_UART_STATE_ERROR             = 0xE0U     
 
} HAL_UART_StateTypeDef;







 
typedef uint32_t HAL_UART_RxTypeTypeDef;









 
typedef uint32_t HAL_UART_RxEventTypeTypeDef;



 
typedef struct __UART_HandleTypeDef
{
  USART_TypeDef                 *Instance;         

  UART_InitTypeDef              Init;              

  const uint8_t                 *pTxBuffPtr;       

  uint16_t                      TxXferSize;        

  volatile uint16_t                 TxXferCount;       

  uint8_t                       *pRxBuffPtr;       

  uint16_t                      RxXferSize;        

  volatile uint16_t                 RxXferCount;       

  volatile HAL_UART_RxTypeTypeDef ReceptionType;       

  volatile HAL_UART_RxEventTypeTypeDef RxEventType;    

  DMA_HandleTypeDef             *hdmatx;           

  DMA_HandleTypeDef             *hdmarx;           

  HAL_LockTypeDef               Lock;              

  volatile HAL_UART_StateTypeDef    gState;           

 

  volatile HAL_UART_StateTypeDef    RxState;          
 

  volatile uint32_t                 ErrorCode;         

#line 212 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"

} UART_HandleTypeDef;

#line 243 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"



 

 


 



 
#line 265 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"


 



 




 



 




 



 





 



 






 



 





 



 




 



 






 



 




 



 




 





 
#line 371 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"


 









 













 



 




 



 





 



 

 


 






 
#line 446 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"





 



















 























 







 
#line 511 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"






 







 







 







 

















 



















 


















 
















 



















 



















 



















 
#line 696 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"




 





 



 

 


 



 

 
HAL_StatusTypeDef HAL_UART_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_Init(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_LIN_Init(UART_HandleTypeDef *huart, uint32_t BreakDetectLength);
HAL_StatusTypeDef HAL_MultiProcessor_Init(UART_HandleTypeDef *huart, uint8_t Address, uint32_t WakeUpMethod);
HAL_StatusTypeDef HAL_UART_DeInit(UART_HandleTypeDef *huart);
void HAL_UART_MspInit(UART_HandleTypeDef *huart);
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart);

 
#line 739 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"



 



 

 
HAL_StatusTypeDef HAL_UART_Transmit(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Receive(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint32_t Timeout);
HAL_StatusTypeDef HAL_UART_Transmit_IT(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Transmit_DMA(UART_HandleTypeDef *huart, const uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UART_DMAPause(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAResume(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_DMAStop(UART_HandleTypeDef *huart);

HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size, uint16_t *RxLen,
                                           uint32_t Timeout);
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef HAL_UARTEx_ReceiveToIdle_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);

HAL_UART_RxEventTypeTypeDef HAL_UARTEx_GetRxEventType(UART_HandleTypeDef *huart);

 
HAL_StatusTypeDef HAL_UART_Abort(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_Abort_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortTransmit_IT(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_UART_AbortReceive_IT(UART_HandleTypeDef *huart);

void HAL_UART_IRQHandler(UART_HandleTypeDef *huart);
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_RxHalfCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortTransmitCpltCallback(UART_HandleTypeDef *huart);
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart);

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size);



 



 
 
HAL_StatusTypeDef HAL_LIN_SendBreak(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_EnterMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_MultiProcessor_ExitMuteMode(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableTransmitter(UART_HandleTypeDef *huart);
HAL_StatusTypeDef HAL_HalfDuplex_EnableReceiver(UART_HandleTypeDef *huart);


 



 
 
HAL_UART_StateTypeDef HAL_UART_GetState(const UART_HandleTypeDef *huart);
uint32_t              HAL_UART_GetError(const UART_HandleTypeDef *huart);


 



 
 
 
 


 


 







 

 


 
#line 865 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal_uart.h"






 









 






 

 


 

HAL_StatusTypeDef UART_Start_Receive_IT(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);
HAL_StatusTypeDef UART_Start_Receive_DMA(UART_HandleTypeDef *huart, uint8_t *pData, uint16_t Size);



 



 



 







#line 339 "../Inc/stm32f1xx_hal_conf.h"






























 
#line 385 "../Inc/stm32f1xx_hal_conf.h"







#line 30 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"



 



 

 



 



 
typedef enum
{
  HAL_TICK_FREQ_10HZ         = 100U,
  HAL_TICK_FREQ_100HZ        = 10U,
  HAL_TICK_FREQ_1KHZ         = 1U,
  HAL_TICK_FREQ_DEFAULT      = HAL_TICK_FREQ_1KHZ
} HAL_TickFreqTypeDef;


 
 
extern volatile uint32_t uwTick;
extern uint32_t uwTickPrio;
extern HAL_TickFreqTypeDef uwTickFreq;



 
 


 











 

 


 





 






 




#line 111 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#line 119 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#line 127 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#line 135 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#line 143 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#line 151 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"



 





 





 






 







 




#line 193 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

 



 




#line 210 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#line 218 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#line 226 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#line 234 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"


#line 243 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#line 251 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#line 259 "../Drivers/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"



 



 





 

 


 


 
 
HAL_StatusTypeDef HAL_Init(void);
HAL_StatusTypeDef HAL_DeInit(void);
void HAL_MspInit(void);
void HAL_MspDeInit(void);
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);


 



 
 
void HAL_IncTick(void);
void HAL_Delay(uint32_t Delay);
uint32_t HAL_GetTick(void);
uint32_t HAL_GetTickPrio(void);
HAL_StatusTypeDef HAL_SetTickFreq(HAL_TickFreqTypeDef Freq);
HAL_TickFreqTypeDef HAL_GetTickFreq(void);
void HAL_SuspendTick(void);
void HAL_ResumeTick(void);
uint32_t HAL_GetHalVersion(void);
uint32_t HAL_GetREVID(void);
uint32_t HAL_GetDEVID(void);
uint32_t HAL_GetUIDw0(void);
uint32_t HAL_GetUIDw1(void);
uint32_t HAL_GetUIDw2(void);
void HAL_DBGMCU_EnableDBGSleepMode(void);
void HAL_DBGMCU_DisableDBGSleepMode(void);
void HAL_DBGMCU_EnableDBGStopMode(void);
void HAL_DBGMCU_DisableDBGStopMode(void);
void HAL_DBGMCU_EnableDBGStandbyMode(void);
void HAL_DBGMCU_DisableDBGStandbyMode(void);


 



 



 
 
 


 


 
 


 


 
 
 


 



 








#line 31 "../Inc/main.h"

 
 

 

 
 

 

 
 

 

 
 

 

 
void Error_Handler(void);

 
void DivEmergencyStop(void);  
void DivButtonsTick(void);  

 

 
#line 75 "../Inc/main.h"

 

 





#line 21 "../Src/main.c"

 
 
#line 1 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"
 
 
 





 






 







 




  
 








#line 47 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"


  



    typedef unsigned int size_t;    









 
 

 



    typedef struct __va_list __va_list;






   




 




typedef struct __fpos_t_struct {
    unsigned __int64 __pos;
    



 
    struct {
        unsigned int __state1, __state2;
    } __mbstate;
} fpos_t;
   


 


   

 

typedef struct __FILE FILE;
   






 

#line 136 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"


extern FILE __stdin, __stdout, __stderr;
extern FILE *__aeabi_stdin, *__aeabi_stdout, *__aeabi_stderr;

#line 166 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"
    

    

    





     



   


 


   


 

   



 

   


 




   


 





    


 






extern __declspec(__nothrow) int remove(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int rename(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) FILE *tmpfile(void);
   




 
extern __declspec(__nothrow) char *tmpnam(char *  );
   











 

extern __declspec(__nothrow) int fclose(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) int fflush(FILE *  );
   







 
extern __declspec(__nothrow) FILE *fopen(const char * __restrict  ,
                           const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   








































 
extern __declspec(__nothrow) FILE *freopen(const char * __restrict  ,
                    const char * __restrict  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(2,3)));
   








 
extern __declspec(__nothrow) void setbuf(FILE * __restrict  ,
                    char * __restrict  ) __attribute__((__nonnull__(1)));
   




 
extern __declspec(__nothrow) int setvbuf(FILE * __restrict  ,
                   char * __restrict  ,
                   int  , size_t  ) __attribute__((__nonnull__(1)));
   















 
#pragma __printf_args
extern __declspec(__nothrow) int fprintf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   


















 
#pragma __printf_args
extern __declspec(__nothrow) int _fprintf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   




 
#pragma __printf_args
extern __declspec(__nothrow) int _printf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __printf_args
extern __declspec(__nothrow) int sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






 
#pragma __printf_args
extern __declspec(__nothrow) int _sprintf(char * __restrict  , const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));


#pragma __printf_args
extern __declspec(__nothrow) int snprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   















 

#pragma __printf_args
extern __declspec(__nothrow) int _snprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , ...) __attribute__((__nonnull__(3)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int fscanf(FILE * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   






























 
#pragma __scanf_args
extern __declspec(__nothrow) int _fscanf(FILE * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   






 
#pragma __scanf_args
extern __declspec(__nothrow) int _scanf(const char * __restrict  , ...) __attribute__((__nonnull__(1)));
   



 
#pragma __scanf_args
extern __declspec(__nothrow) int sscanf(const char * __restrict  ,
                    const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   








 
#pragma __scanf_args
extern __declspec(__nothrow) int _sscanf(const char * __restrict  ,
                     const char * __restrict  , ...) __attribute__((__nonnull__(1,2)));
   



 

 
extern __declspec(__nothrow) int vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int _vfscanf(FILE * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int _vscanf(const char * __restrict  , __va_list) __attribute__((__nonnull__(1)));
extern __declspec(__nothrow) int _vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) int __ARM_vsscanf(const char * __restrict  , const char * __restrict  , __va_list) __attribute__((__nonnull__(1,2)));

extern __declspec(__nothrow) int vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int _vprintf(const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) int vfprintf(FILE * __restrict  ,
                    const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int vsprintf(char * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int __ARM_vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));

extern __declspec(__nothrow) int vsnprintf(char * __restrict  , size_t  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   







 

extern __declspec(__nothrow) int _vsprintf(char * __restrict  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vfprintf(FILE * __restrict  ,
                     const char * __restrict  , __va_list  ) __attribute__((__nonnull__(1,2)));
   



 
extern __declspec(__nothrow) int _vsnprintf(char * __restrict  , size_t  ,
                      const char * __restrict  , __va_list  ) __attribute__((__nonnull__(3)));
   



 

#pragma __printf_args
extern __declspec(__nothrow) int asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));

#pragma __printf_args
extern __declspec(__nothrow) int __ARM_asprintf(char **  , const char * __restrict  , ...) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) int __ARM_vasprintf(char **  , const char * __restrict  , __va_list  ) __attribute__((__nonnull__(2)));
   








 

extern __declspec(__nothrow) int fgetc(FILE *  ) __attribute__((__nonnull__(1)));
   







 
extern __declspec(__nothrow) char *fgets(char * __restrict  , int  ,
                    FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   










 
extern __declspec(__nothrow) int fputc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   







 
extern __declspec(__nothrow) int fputs(const char * __restrict  , FILE * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int getc(FILE *  ) __attribute__((__nonnull__(1)));
   







 




    extern __declspec(__nothrow) int (getchar)(void);

   





 
extern __declspec(__nothrow) char *gets(char *  ) __attribute__((__nonnull__(1)));
   









 
extern __declspec(__nothrow) int putc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   





 




    extern __declspec(__nothrow) int (putchar)(int  );

   



 
extern __declspec(__nothrow) int puts(const char *  ) __attribute__((__nonnull__(1)));
   





 
extern __declspec(__nothrow) int ungetc(int  , FILE *  ) __attribute__((__nonnull__(2)));
   






















 

extern __declspec(__nothrow) size_t fread(void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   











 

extern __declspec(__nothrow) size_t __fread_bytes_avail(void * __restrict  ,
                    size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,3)));
   











 

extern __declspec(__nothrow) size_t fwrite(const void * __restrict  ,
                    size_t  , size_t  , FILE * __restrict  ) __attribute__((__nonnull__(1,4)));
   







 

extern __declspec(__nothrow) int fgetpos(FILE * __restrict  , fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   








 
extern __declspec(__nothrow) int fseek(FILE *  , long int  , int  ) __attribute__((__nonnull__(1)));
   














 
extern __declspec(__nothrow) int fsetpos(FILE * __restrict  , const fpos_t * __restrict  ) __attribute__((__nonnull__(1,2)));
   










 
extern __declspec(__nothrow) long int ftell(FILE *  ) __attribute__((__nonnull__(1)));
   











 
extern __declspec(__nothrow) void rewind(FILE *  ) __attribute__((__nonnull__(1)));
   





 

extern __declspec(__nothrow) void clearerr(FILE *  ) __attribute__((__nonnull__(1)));
   




 

extern __declspec(__nothrow) int feof(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) int ferror(FILE *  ) __attribute__((__nonnull__(1)));
   


 
extern __declspec(__nothrow) void perror(const char *  );
   









 

extern __declspec(__nothrow) int _fisatty(FILE *   ) __attribute__((__nonnull__(1)));
    
 

extern __declspec(__nothrow) void __use_no_semihosting_swi(void);
extern __declspec(__nothrow) void __use_no_semihosting(void);
    





 











#line 1021 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\stdio.h"



 

#line 25 "../Src/main.c"
#line 1 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\string.h"
 
 
 
 




 








 












#line 38 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\string.h"


  



    typedef unsigned int size_t;    
#line 54 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\string.h"




extern __declspec(__nothrow) void *memcpy(void * __restrict  ,
                    const void * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) void *memmove(void *  ,
                    const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   







 
extern __declspec(__nothrow) char *strcpy(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncpy(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 

extern __declspec(__nothrow) char *strcat(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) char *strncat(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 






 

extern __declspec(__nothrow) int memcmp(const void *  , const void *  , size_t  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strcmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 
extern __declspec(__nothrow) int strncmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcasecmp(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   





 
extern __declspec(__nothrow) int strncasecmp(const char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






 
extern __declspec(__nothrow) int strcoll(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   







 

extern __declspec(__nothrow) size_t strxfrm(char * __restrict  , const char * __restrict  , size_t  ) __attribute__((__nonnull__(2)));
   













 


#line 193 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) void *memchr(const void *  , int  , size_t  ) __attribute__((__nonnull__(1)));

   





 

#line 209 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   




 

extern __declspec(__nothrow) size_t strcspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   




 

#line 232 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strpbrk(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   




 

#line 247 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strrchr(const char *  , int  ) __attribute__((__nonnull__(1)));

   





 

extern __declspec(__nothrow) size_t strspn(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));
   



 

#line 270 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\string.h"
extern __declspec(__nothrow) char *strstr(const char *  , const char *  ) __attribute__((__nonnull__(1,2)));

   





 

extern __declspec(__nothrow) char *strtok(char * __restrict  , const char * __restrict  ) __attribute__((__nonnull__(2)));
extern __declspec(__nothrow) char *_strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

extern __declspec(__nothrow) char *strtok_r(char *  , const char *  , char **  ) __attribute__((__nonnull__(2,3)));

   

































 

extern __declspec(__nothrow) void *memset(void *  , int  , size_t  ) __attribute__((__nonnull__(1)));
   



 
extern __declspec(__nothrow) char *strerror(int  );
   





 
extern __declspec(__nothrow) size_t strlen(const char *  ) __attribute__((__nonnull__(1)));
   



 

extern __declspec(__nothrow) size_t strlcpy(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   
















 

extern __declspec(__nothrow) size_t strlcat(char *  , const char *  , size_t  ) __attribute__((__nonnull__(1,2)));
   






















 

extern __declspec(__nothrow) void _membitcpybl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpybb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpyhb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitcpywb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovebb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovehb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewl(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
extern __declspec(__nothrow) void _membitmovewb(void *  , const void *  , int  , int  , size_t  ) __attribute__((__nonnull__(1,2)));
    














































 







#line 502 "D:\\Stu15\\Documents\\Keil stm32\\code\\ARM\\ARMCC\\bin\\..\\include\\string.h"



 

#line 26 "../Src/main.c"
#line 1 "../Inc/oled_display.h"
#line 4 "../Inc/oled_display.h"



int Oled_Init(void);  
int Oled_IsOnline(void);  
uint8_t Oled_Address(void);  
const char *Oled_ProbeError(uint8_t candidate);  
const char *Oled_ProbeStage(uint8_t candidate);  
void Oled_SetLine(int row, const char *text);  
int Oled_Flush(void);  
void Oled_SetProgressCallback(void (*callback)(int completed_pages));  
#line 27 "../Src/main.c"
#line 1 "../Inc/oled_bus_timeout_fix.h"
#line 4 "../Inc/oled_bus_timeout_fix.h"




void OledBus_Init(void);  
const char *OledBus_Diagnose(void);  
int OledBus_Write(uint8_t address, const uint8_t *data, uint16_t count);  
const char *OledBus_Error(void);  
const char *OledBus_Stage(void);  
#line 28 "../Src/main.c"
#line 1 "../Inc/div_diagnosis.h"
 
#line 5 "../Inc/div_diagnosis.h"







typedef struct  
{
    int32_t vb_min;  
    int32_t vb_max;  
    int32_t va_min;  
    int32_t va_max;  
} DivBounds;  

static const DivBounds div_bounds[9] =  
{
    {422, 488, 889, 928},  
    {-5, 5, 985, 1015},  
    {985, 1015, 985, 1015},  
    {811, 855, 811, 855},  
    {-5, 5, 811, 855},  
    {555, 621, 862, 903},  
    {284, 342, 919, 956},  
    {267, 322, 862, 903},  
    {591, 659, 919, 956}  
};

static uint32_t DivCodeToMillivolts(uint32_t raw)  
{
    return (raw * 3300 + (4095 / 2)) / 4095;  
}

static int DivClassify(int32_t vb_mv, int32_t va_mv)  
{
    int matches = 0;  
    int matched_case = (-1);  
    int index;  
    for (index = 0; index < 9; ++index)  
    {
        const DivBounds *bounds = &div_bounds[index];  
        if (vb_mv >= bounds->vb_min && vb_mv <= bounds->vb_max &&  
            va_mv >= bounds->va_min && va_mv <= bounds->va_max)  
        {
            ++matches;  
            matched_case = index;  
        }
    }
    return matches == 1 ? matched_case : (-1);  
}
#line 29 "../Src/main.c"

 

 
 
typedef struct  
{
    uint32_t vb_raw;  
    uint32_t va_raw;  
    uint32_t vb_mv;  
    uint32_t va_mv;  
    uint32_t adc_conversions;  
    uint32_t feature_reads;  
    uint32_t elapsed_ms;  
    int vb_valid;  
    int va_valid;  
    int state;  
    const char *error;  
} DivMeasurement;  

typedef struct  
{
    GPIO_PinState raw_level;  
    GPIO_PinState stable_level;  
    uint32_t changed_ms;  
} RetestButton;  

 

 
 
#line 75 "../Src/main.c"

 

 
 

 

 
ADC_HandleTypeDef hadc1;

UART_HandleTypeDef huart1;

 
static volatile int power_gpio_ready = 0;  
static volatile int stop_requested = 0;  
static int detection_pending = 1;  
static int stop_reported = 0;  
static RetestButton retest_button = {GPIO_PIN_SET, GPIO_PIN_SET, 0};  

static volatile int buttons_ready = 0;  
static volatile int retest_event_pending = 0;  
static volatile int retest_armed = 1;  
static volatile int display_dirty = 1;  
static DivMeasurement last_measurement;  
static int has_measurement = 0;  




static uint32_t last_status_ms = 0;  
static uint32_t last_auto_measure_ms = 0;  

 

 
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_USART1_UART_Init(void);
 
static const char *ReadAdcChannel(uint32_t channel, uint32_t *raw, uint32_t *conversions);  
static void SendReport(const DivMeasurement *result);  
static void RunDivDetection(void);  
static void AllPowerOff(void);  
static void ServiceControls(void);  
static void ServiceStatus(void);  

 

 
 
static void AllPowerOff(void)  
{
    if (power_gpio_ready)  
    {
        HAL_GPIO_WritePin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), ((uint16_t)0x1000) | ((uint16_t)0x2000), GPIO_PIN_RESET);  
    }
}

static int StopIsActive(void)  
{
    return stop_requested || HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), ((uint16_t)0x0020)) == GPIO_PIN_RESET;  
}

void DivEmergencyStop(void)  
{
    if (!stop_requested)  
    {
        retest_event_pending = 0;  
        retest_armed = 0;  
        display_dirty = 1;  
    }
    stop_requested = 1;  
    AllPowerOff();  
}

void HAL_GPIO_EXTI_Callback(uint16_t pin)  
{
    if (pin == ((uint16_t)0x0020))  
    {
        DivEmergencyStop();  
    }
}

static int WaitWithoutStop(uint32_t milliseconds)  
{
    uint32_t started_ms = HAL_GetTick();  
    while (HAL_GetTick() - started_ms < milliseconds)  
    {
        if (StopIsActive())  
        {
            DivEmergencyStop();  
            return 0;  
        }
        HAL_Delay(1);  
    }
    if (StopIsActive())  
    {
        DivEmergencyStop();  
        return 0;  
    }
    return 1;  
}

static int SelectPower(uint16_t selected_pin)  
{
    uint32_t previous_interrupt_mask;  
    int enabled = 0;  
    AllPowerOff();  
    if (selected_pin != ((uint16_t)0x1000) && selected_pin != ((uint16_t)0x2000))  
    {
        return 0;  
    }
    if (!WaitWithoutStop(5))  
    {
        return 0;  
    }
    previous_interrupt_mask = __get_PRIMASK();  
    __disable_irq();  
    if (!StopIsActive())  
    {
        HAL_GPIO_WritePin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), selected_pin, GPIO_PIN_SET);  
        enabled = 1;  
    }
    __set_PRIMASK(previous_interrupt_mask);  
    return enabled;  
}

void DivButtonsTick(void)  
{
    GPIO_PinState current_level;  
    uint32_t now_ms;  
    if (!buttons_ready)  
    {
        return;  
    }
    current_level = HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), ((uint16_t)0x0010));  
    now_ms = HAL_GetTick();  
    if (HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), ((uint16_t)0x0020)) == GPIO_PIN_RESET)  
    {
        retest_armed = 0;  
        retest_event_pending = 0;  
    }
    if (current_level != retest_button.raw_level)  
    {
        retest_button.raw_level = current_level;  
        retest_button.changed_ms = now_ms;  
    }
    if (current_level != retest_button.stable_level && now_ms - retest_button.changed_ms >= 20)  
    {
        retest_button.stable_level = current_level;  
        if (current_level == GPIO_PIN_RESET && retest_armed && HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), ((uint16_t)0x0020)) == GPIO_PIN_SET)  
        {
            retest_event_pending = 1;  
            retest_armed = 0;  
        }
    }
    if (current_level == GPIO_PIN_SET && retest_button.stable_level == GPIO_PIN_SET && now_ms - retest_button.changed_ms >= 20 && HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), ((uint16_t)0x0020)) == GPIO_PIN_SET)  
    {
        retest_armed = 1;  
    }
}
static int RetestWasPressed(void)  
{
    uint32_t saved_mask = __get_PRIMASK();  
    int pressed;  
    __disable_irq();  
    pressed = retest_event_pending;  
    retest_event_pending = 0;  
    __set_PRIMASK(saved_mask);  
    return pressed;  
}

static const char *ReadAdcChannel(uint32_t channel, uint32_t *raw, uint32_t *conversions)  
{
    ADC_ChannelConfTypeDef selected = {0};  
    if (StopIsActive())  
    {
        return "STOP_REQUESTED";  
    }
    selected.Channel = channel;  
    selected.Rank = 0x00000001U;  
    selected.SamplingTime = ((uint32_t)((0x4UL << (0U)) | (0x2UL << (0U)) | (0x1UL << (0U))));  
    if (HAL_ADC_ConfigChannel(&hadc1, &selected) != HAL_OK)  
    {
        return "ADC_CONFIG_FAILED";  
    }
    if (StopIsActive())  
    {
        return "STOP_REQUESTED";  
    }
    if (HAL_ADC_Start(&hadc1) != HAL_OK)  
    {
        if (HAL_ADC_Stop(&hadc1) != HAL_OK)  
        {
            return "ADC_START_AND_STOP_FAILED";  
        }
        return "ADC_START_FAILED";  
    }
    if (HAL_ADC_PollForConversion(&hadc1, 20) != HAL_OK)  
    {
        if (HAL_ADC_Stop(&hadc1) != HAL_OK)  
        {
            return "ADC_POLL_AND_STOP_FAILED";  
        }
        return "ADC_POLL_FAILED";  
    }
    *raw = HAL_ADC_GetValue(&hadc1);  
    ++(*conversions);  
    if (HAL_ADC_Stop(&hadc1) != HAL_OK)  
    {
        return "ADC_STOP_FAILED";  
    }
    if (*raw > 4095)  
    {
        return "ADC_RANGE_FAILED";  
    }
    return "OK";  
}

static void SendReport(const DivMeasurement *result)  
{
    char line[384];  
    char state_text[16] = "UNKNOWN";  
    char vb_raw_text[12] = "NA";  
    char va_raw_text[12] = "NA";  
    char vb_mv_text[12] = "NA";  
    char va_mv_text[12] = "NA";  
    const char *kind = "UNKNOWN";  
    int written;  
    last_measurement = *result;  
    has_measurement = 1;  
    display_dirty = 1;  
    if (result->state >= 0)  
    {
        snprintf(state_text, sizeof(state_text), "DIV%d", result->state);  
        kind = result->state == 0 ? "NORMAL" : "FAULT";  
    }
    if (result->vb_valid)  
    {
        snprintf(vb_raw_text, sizeof(vb_raw_text), "%lu", (unsigned long)result->vb_raw);  
        snprintf(vb_mv_text, sizeof(vb_mv_text), "%lu", (unsigned long)result->vb_mv);  
    }
    if (result->va_valid)  
    {
        snprintf(va_raw_text, sizeof(va_raw_text), "%lu", (unsigned long)result->va_raw);  
        snprintf(va_mv_text, sizeof(va_mv_text), "%lu", (unsigned long)result->va_mv);  
    }
    written = snprintf(line, sizeof(line),  
        "STATE=%s KIND=%s VB_RAW=%s VB_MV=%s VA_RAW=%s VA_MV=%s "  
        "FEATURE_READS=%lu ADC_CONVERSIONS=%lu ELAPSED_MS=%lu "  
        "RUN_POWER=%s TEST_POWER=%s POWER_SOURCE=GPIO_LEVEL ERROR=%s\r\n",  
        state_text, kind, vb_raw_text, vb_mv_text, va_raw_text, va_mv_text,  
        (unsigned long)result->feature_reads, (unsigned long)result->adc_conversions,  
        (unsigned long)result->elapsed_ms,  
        HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), ((uint16_t)0x2000)) == GPIO_PIN_SET ? "ON" : "OFF",  
        HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), ((uint16_t)0x1000)) == GPIO_PIN_SET ? "ON" : "OFF",  
        result->error);  
    if (written < 0 || written >= (int)sizeof(line))  
    {
        Error_Handler();  
    }
    if (HAL_UART_Transmit(&huart1, (uint8_t *)line, (uint16_t)written, 1000) != HAL_OK)  
    {
        Error_Handler();  
    }
}

static void RunDivDetection(void)  
{
    DivMeasurement result = {0};  
    uint32_t started_ms = HAL_GetTick();  
    result.state = (-1);  
    result.error = "STOP_REQUESTED";  
    if (!SelectPower(((uint16_t)0x1000)) || !WaitWithoutStop(20))  
    {
        AllPowerOff();  
        result.elapsed_ms = HAL_GetTick() - started_ms;  
        SendReport(&result);  
        return;  
    }
    result.error = ReadAdcChannel(0x00000000U, &result.vb_raw, &result.adc_conversions);  
    if (strcmp(result.error, "OK") == 0)  
    {
        result.vb_valid = 1;  
        result.vb_mv = DivCodeToMillivolts(result.vb_raw);  
        ++result.feature_reads;  
        result.error = ReadAdcChannel(((uint32_t)( (0x01UL << (0U)))), &result.va_raw, &result.adc_conversions);  
        if (strcmp(result.error, "OK") == 0)  
        {
            result.va_valid = 1;  
            result.va_mv = DivCodeToMillivolts(result.va_raw);  
            ++result.feature_reads;  
            result.state = DivClassify((int32_t)result.vb_mv, (int32_t)result.va_mv);  
        }
    }
    if (StopIsActive())  
    {
        result.state = (-1);  
        result.error = "STOP_REQUESTED";  
        AllPowerOff();  
    }
    else if (strcmp(result.error, "OK") == 0 && result.vb_valid && result.va_valid && result.state == 0)  
    {
        if (!SelectPower(((uint16_t)0x2000)) || StopIsActive())  
        {
            result.state = (-1);  
            result.error = "STOP_REQUESTED";  
            AllPowerOff();  
        }
    }
    else  
    {
        AllPowerOff();  
    }
    result.elapsed_ms = HAL_GetTick() - started_ms;  
    SendReport(&result);  
}

static void SendStopEvent(void)  
{
    const char stopped[] = "EVENT=STOP RUN_POWER=OFF TEST_POWER=OFF MODE=WAIT_RETEST\r\n";  
    if (HAL_UART_Transmit(&huart1, (uint8_t *)stopped, sizeof(stopped) - 1, 1000) != HAL_OK)  
    {
        Error_Handler();  
    }
}

static void ServiceControls(void)  
{
    if (StopIsActive())  
    {
        DivEmergencyStop();  
        detection_pending = 0;  
        if (!stop_reported)  
        {
            SendStopEvent();  
            stop_reported = 1;  
        }
    }
    if (RetestWasPressed() && HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), ((uint16_t)0x0020)) == GPIO_PIN_SET)  
    {
        uint32_t previous_interrupt_mask = __get_PRIMASK();  
        __disable_irq();  
        if (HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), ((uint16_t)0x0020)) == GPIO_PIN_SET)  
        {
            stop_requested = 0;  
            detection_pending = 1;  
            stop_reported = 0;  
        }
        __set_PRIMASK(previous_interrupt_mask);  
    }
    if (!StopIsActive() && 1000 > 0 &&  
        HAL_GetTick() - last_auto_measure_ms >= 1000)  
    {
        detection_pending = 1;  
    }
    if (detection_pending && !StopIsActive())  
    {
        detection_pending = 0;  
        last_auto_measure_ms = HAL_GetTick();  
        RunDivDetection();  
    }
}

static void ServiceStatus(void)  
{
    uint32_t now_ms = HAL_GetTick();  
    char line[384];  
    char measured_state[20] = "WAITING";  
    int written;  
    if (now_ms - last_status_ms < 1000)  
    {
        return;  
    }
    last_status_ms = now_ms;  
    if (StopIsActive())  
    {
        snprintf(measured_state, sizeof(measured_state), "STOPPED");  
    }
    else if (has_measurement && strcmp(last_measurement.error, "OK") != 0)  
    {
        snprintf(measured_state, sizeof(measured_state), "ERROR");  
    }
    else if (has_measurement && last_measurement.state >= 0)  
    {
        snprintf(measured_state, sizeof(measured_state), "DIV%d", last_measurement.state);  
    }
    else if (has_measurement)  
    {
        snprintf(measured_state, sizeof(measured_state), "UNKNOWN");  
    }
#line 494 "../Src/main.c"
    written = snprintf(line, sizeof(line),  
        "HEARTBEAT_MS=%lu STATE=%s RUN_GPIO=%s TEST_GPIO=%s OLED=DISPLAY_OFF AUTO_MEASURE_MS=%d\r\n",  
        (unsigned long)now_ms, measured_state,  
        HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), ((uint16_t)0x2000)) == GPIO_PIN_SET ? "HIGH" : "LOW",  
        HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), ((uint16_t)0x1000)) == GPIO_PIN_SET ? "HIGH" : "LOW",  
        1000);  

    if (written < 0 || written >= (int)sizeof(line))  
    {
        Error_Handler();  
    }
    if (HAL_UART_Transmit(&huart1, (uint8_t *)line, (uint16_t)written, 1000) != HAL_OK)  
    {
        Error_Handler();  
    }
}

static void ReportOledProgress(int completed_pages)  
{
    char message[64];  
    int length = snprintf(message, sizeof(message), "OLED_REFRESH_PAGE=%d/%d CHUNK=16\r\n", completed_pages, 8);  
    if (length <= 0 || length >= (int)sizeof(message))  
    {
        Error_Handler();  
    }
    if (HAL_UART_Transmit(&huart1, (uint8_t *)message, (uint16_t)length, 1000) != HAL_OK)  
    {
        Error_Handler();  
    }
}

static void ServiceDisplay(void)  
{
#line 605 "../Src/main.c"
    if (display_dirty)  
    {
        display_dirty = 0;  
    }

}

 




 
int main(void)
{

   

   

   

   
  HAL_Init();

   

   

   
  SystemClock_Config();

   

   

   
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_USART1_UART_Init();
   

    OledBus_Init();  

  const char startup[] = "BOOT=AUTO_VOLT_METER_1HZ_20261013 MODE=CONTINUOUS VREF_MV=3300 ADC_BITS=12 BAUD=9600 OLED=DISPLAY_OFF AUTO_MEASURE_MS=1000\r\n";  
  const char calibration_error[] = "STATE=UNKNOWN ERROR=ADC_CALIBRATION_FAILED RUN_POWER=OFF TEST_POWER=OFF\r\n";  
  HAL_Delay(50);  
  if (HAL_UART_Transmit(&huart1, (uint8_t *)startup, sizeof(startup) - 1, 1000) != HAL_OK)  
  {
    Error_Handler();  
  }
  if (HAL_ADCEx_Calibration_Start(&hadc1) != HAL_OK)  
  {
    HAL_UART_Transmit(&huart1, (uint8_t *)calibration_error, sizeof(calibration_error) - 1, 1000);  
    Error_Handler();  
  }

  
  {  
    char diagnostic[120];  
    int length = snprintf(diagnostic, sizeof(diagnostic), "OLED_PIN_TEST=%s EXPECT=HH/LH/HL/HH ORDER=SCL,SDA BUS=GPIO\r\n", OledBus_Diagnose());  
    if (length > 0 && length < (int)sizeof(diagnostic))  
    {
      if (HAL_UART_Transmit(&huart1, (uint8_t *)diagnostic, (uint16_t)length, 1000) != HAL_OK)  
      {
        Error_Handler();  
      }
    }
  }

  retest_button.raw_level = HAL_GPIO_ReadPin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), ((uint16_t)0x0010));  
  retest_button.stable_level = retest_button.raw_level;  
  retest_button.changed_ms = HAL_GetTick();  
  buttons_ready = 1;  
  Oled_SetProgressCallback(ReportOledProgress);  

   

   
   
  while (1)  
  {
     

     
    ServiceControls();  
    ServiceDisplay();  
    ServiceStatus();  
    HAL_Delay(1);  
  }

   
}




 
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  

 
  RCC_OscInitStruct.OscillatorType = 0x00000002U;
  RCC_OscInitStruct.HSIState = (0x1UL << (0U));
  RCC_OscInitStruct.HSICalibrationValue = 0x10U;
  RCC_OscInitStruct.PLL.PLLState = 0x00000000U;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  
 
  RCC_ClkInitStruct.ClockType = 0x00000002U|0x00000001U
                              |0x00000004U|0x00000008U;
  RCC_ClkInitStruct.SYSCLKSource = 0x00000000U;
  RCC_ClkInitStruct.AHBCLKDivider = 0x00000000U;
  RCC_ClkInitStruct.APB1CLKDivider = 0x00000000U;
  RCC_ClkInitStruct.APB2CLKDivider = 0x00000000U;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, 0x00000000U) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = 0x00000002U;
  PeriphClkInit.AdcClockSelection = 0x00000000U;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}





 
static void MX_ADC1_Init(void)
{

   

   

  ADC_ChannelConfTypeDef sConfig = {0};

   

   

  
 
  hadc1.Instance = ((ADC_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00002400UL));
  hadc1.Init.ScanConvMode = 0x00000000U;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ((uint32_t)((0x4UL << (17U)) | (0x2UL << (17U)) | (0x1UL << (17U))));
  hadc1.Init.DataAlign = 0x00000000U;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  
 
  sConfig.Channel = 0x00000000U;
  sConfig.Rank = 0x00000001U;
  sConfig.SamplingTime = ((uint32_t)((0x4UL << (0U)) | (0x2UL << (0U)) | (0x1UL << (0U))));
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
   

   

}





 
static void MX_USART1_UART_Init(void)
{

   

   

   

   
  huart1.Instance = ((USART_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00003800UL));
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = 0x00000000U;
  huart1.Init.StopBits = 0x00000000U;
  huart1.Init.Parity = 0x00000000U;
  huart1.Init.Mode = ((uint32_t)((0x1UL << (3U)) | (0x1UL << (2U))));
  huart1.Init.HwFlowCtl = 0x00000000U;
  huart1.Init.OverSampling = 0x00000000U;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
   

   

}





 
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
   

   

   
  do { volatile uint32_t tmpreg; ((((RCC_TypeDef *)((0x40000000UL + 0x00020000UL) + 0x00001000UL))->APB2ENR) |= ((0x1UL << (4U)))); tmpreg = ((((RCC_TypeDef *)((0x40000000UL + 0x00020000UL) + 0x00001000UL))->APB2ENR) & ((0x1UL << (4U)))); (void)tmpreg; } while(0U);
  do { volatile uint32_t tmpreg; ((((RCC_TypeDef *)((0x40000000UL + 0x00020000UL) + 0x00001000UL))->APB2ENR) |= ((0x1UL << (2U)))); tmpreg = ((((RCC_TypeDef *)((0x40000000UL + 0x00020000UL) + 0x00001000UL))->APB2ENR) & ((0x1UL << (2U)))); (void)tmpreg; } while(0U);
  do { volatile uint32_t tmpreg; ((((RCC_TypeDef *)((0x40000000UL + 0x00020000UL) + 0x00001000UL))->APB2ENR) |= ((0x1UL << (3U)))); tmpreg = ((((RCC_TypeDef *)((0x40000000UL + 0x00020000UL) + 0x00001000UL))->APB2ENR) & ((0x1UL << (3U)))); (void)tmpreg; } while(0U);

   
  HAL_GPIO_WritePin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00001000UL)), ((uint16_t)0x2000), GPIO_PIN_SET);

   
  HAL_GPIO_WritePin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), ((uint16_t)0x1000)|((uint16_t)0x2000), GPIO_PIN_RESET);

   
  HAL_GPIO_WritePin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), ((uint16_t)0x0040)|((uint16_t)0x0080), GPIO_PIN_SET);

   
  GPIO_InitStruct.Pin = ((uint16_t)0x2000);
  GPIO_InitStruct.Mode = 0x00000001u;
  GPIO_InitStruct.Pull = 0x00000000u;
  GPIO_InitStruct.Speed = ((0x2UL << (0U)));
  HAL_GPIO_Init(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00001000UL)), &GPIO_InitStruct);

   
  GPIO_InitStruct.Pin = ((uint16_t)0x0010);
  GPIO_InitStruct.Mode = 0x00000000u;
  GPIO_InitStruct.Pull = 0x00000001u;
  HAL_GPIO_Init(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), &GPIO_InitStruct);

   
  GPIO_InitStruct.Pin = ((uint16_t)0x0020);
  GPIO_InitStruct.Mode = 0x10210000u;
  GPIO_InitStruct.Pull = 0x00000001u;
  HAL_GPIO_Init(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), &GPIO_InitStruct);

   
  GPIO_InitStruct.Pin = ((uint16_t)0x1000)|((uint16_t)0x2000);
  GPIO_InitStruct.Mode = 0x00000001u;
  GPIO_InitStruct.Pull = 0x00000000u;
  GPIO_InitStruct.Speed = ((0x2UL << (0U)));
  HAL_GPIO_Init(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), &GPIO_InitStruct);

   
  GPIO_InitStruct.Pin = ((uint16_t)0x0040)|((uint16_t)0x0080);
  GPIO_InitStruct.Mode = 0x00000011u;
  GPIO_InitStruct.Pull = 0x00000000u;  
  GPIO_InitStruct.Speed = ((0x2UL << (0U)));  
  HAL_GPIO_Init(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), &GPIO_InitStruct);

   
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

   
  GPIO_InitTypeDef configured = {0};
  HAL_GPIO_WritePin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), ((uint16_t)0x1000) | ((uint16_t)0x2000), GPIO_PIN_RESET);  
  configured.Pin = ((uint16_t)0x1000) | ((uint16_t)0x2000);  
  configured.Mode = 0x00000001u;  
  configured.Pull = 0x00000000u;  
  configured.Speed = ((0x2UL << (0U)));  
  HAL_GPIO_Init(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000C00UL)), &configured);  
  configured.Pin = ((uint16_t)0x2000);  
  HAL_GPIO_WritePin(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00001000UL)), ((uint16_t)0x2000), GPIO_PIN_SET);  
  HAL_GPIO_Init(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00001000UL)), &configured);  
  power_gpio_ready = 1;  
  configured.Pin = ((uint16_t)0x0010);  
  configured.Mode = 0x00000000u;  
  configured.Pull = 0x00000001u;  
  HAL_GPIO_Init(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), &configured);  
  configured.Pin = ((uint16_t)0x0020);  
  configured.Mode = 0x10210000u;  
  HAL_GPIO_Init(((GPIO_TypeDef *)((0x40000000UL + 0x00010000UL) + 0x00000800UL)), &configured);  
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);  
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);  

   
}

 

 




 
void Error_Handler(void)
{
   
   
  DivEmergencyStop();  
  __disable_irq();  
  while (1)  
  {
  }
   
}
