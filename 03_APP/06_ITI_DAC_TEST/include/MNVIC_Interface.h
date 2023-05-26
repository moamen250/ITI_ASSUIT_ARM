/**************************************************************************/
/* Auther                : Peter Essam                                    */
/* Version               : V1.0.0                                         */
/* Date                  : 19-5-2023                                      */
/* Description           : MNVIC_Interface.h                              */
/* Features              :                                                */
/*           1- MNVIC_errInitSoftwareSystemPriority()                     */
/*           2- MNVIC_errEnablePerInterrupt()                             */
/*           3- MNVIC_errDisablePerInterrupt()                            */
/*           4- MNVIC_errSetPendingInterrupt()                            */
/*           5- MNVIC_errClearPeningInterrupt()                           */
/*           6- MNVIC_errIsInterruptActive()                              */
/*           7- MNVIC_errSetInterruptPriority()                           */
/**************************************************************************/

/**************************************************************************/
/*                    Guard for calling one time in .c files              */
/**************************************************************************/


#ifndef MNVIC_INTERFACE_H_
#define MNVIC_INTERFACE_H_


typedef enum 
{

INT_WWDG              = 00,
INT_EXTI16_PVD            ,
INT_EXTI21_TAMP_STAMP     ,
INT_EXTI22_RTC_WKUP       ,
INT_FLASH                 ,
INT_RCC                   ,
INT_EXTI0                 ,
INT_EXTI1                 ,
INT_EXTI2                 ,
INT_EXTI3                 ,
INT_EXTI4                 ,
INT_DMA1_Stream0          ,
INT_DMA1_Stream1          ,
INT_DMA1_Stream2          ,
INT_DMA1_Stream3          ,
INT_DMA1_Stream4          ,
INT_DMA1_Stream5          ,
INT_DMA1_Stream6          ,
INT_ADC               = 18,
INT_EXTI9_5           = 23,
INT_TIM1_BRK_TIM9         ,
INT_TIM1_UP_TIM10         ,
INT_TIM1_TRG_COM_TIM1     ,
INT_TIM1_CC               ,
INT_TIM2                  ,
INT_TIM3                  ,
INT_TIM4                  ,
INT_I2C1_EV               ,
INT_I2C1_ER               ,
INT_I2C2_EV               ,
INT_I2C2_ER               ,
INT_SPI1                  ,
INT_SPI2                  ,
INT_USART1                ,
INT_USART2            = 38,
INT_EXTI15_10         = 40,
INT_EXTI17_RTC_Alarm      ,
INT_EXTI18_OTG_FS_WKU     ,
INT_DMA1_Stream7      = 47,
INT_SDIO              = 49,
INT_TIM5                  ,
INT_SPI3              = 51,
INT_DMA2_Stream0      = 56,
INT_DMA2_Stream1          ,
INT_DMA2_Stream2          ,
INT_DMA2_Stream3          ,
INT_DMA2_Stream4      = 60,
INT_OTG_FS            = 67,
INT_DMA2_Stream5          ,
INT_DMA2_Stream6          ,
INT_DMA2_Stream7          ,
INT_USART6                ,
INT_I2C3_EV               ,
INT_I2C3_ER           = 73,
INT_FPU               = 81,
INT_SPI4              = 84,
}MNVIC_INTPosition_VectorTable_t;


typedef enum
{
	MNVIC_G16_S0 = 3 ,
	MNVIC_G8_S2      ,
	MNVIC_G4_S4      ,
	MNVIC_G2_S8      ,
	MNVIC_G0_S16     ,
	MNVIC_INVALID_Priority
}MNVIC_SysPriority_t ;

typedef enum
{
	MNVIC_GROUP_PRI0 = 0 ,
	MNVIC_GROUP_PRI1     ,
	MNVIC_GROUP_PRI2     ,
	MNVIC_GROUP_PRI3     ,
	MNVIC_GROUP_PRI4     ,
	MNVIC_GROUP_PRI5     ,
	MNVIC_GROUP_PRI6     ,
	MNVIC_GROUP_PRI7     ,
	MNVIC_GROUP_PRI8     ,
	MNVIC_GROUP_PRI9     ,
	MNVIC_GROUP_PRI10     ,
	MNVIC_GROUP_PRI11     ,
	MNVIC_GROUP_PRI12     ,
	MNVIC_GROUP_PRI13     ,
	MNVIC_GROUP_PRI14     ,
	MNVIC_GROUP_PRI15     ,
    MNVIC_GROUP_INVALID
}MNVIC_GPriority_t ;


typedef enum
{
	MNVIC_SUBGROUP_PRI0 = 0 ,
	MNVIC_SUBGROUP_PRI1     ,
	MNVIC_SUBGROUP_PRI2     ,
	MNVIC_SUBGROUP_PRI3     ,
	MNVIC_SUBGROUP_PRI4     ,
	MNVIC_SUBGROUP_PRI5     ,
	MNVIC_SUBGROUP_PRI6     ,
	MNVIC_SUBGROUP_PRI7     ,
	MNVIC_SUBGROUP_PRI8     ,
	MNVIC_SUBGROUP_PRI9     ,
	MNVIC_SUBGROUP_PRI10     ,
	MNVIC_SUBGROUP_PRI11     ,
	MNVIC_SUBGROUP_PRI12     ,
	MNVIC_SUBGROUP_PRI13     ,
	MNVIC_SUBGROUP_PRI14     ,
	MNVIC_SUBGROUP_PRI15     ,
    MNVIC_SUBGROUP_INVALID
}MNVIC_SUBPriority_t ;
/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/

ES_t MNVIC_errInitSoftwareSystemPriority(MNVIC_SysPriority_t Copy_uddtPriorityOption)           ;
ES_t MNVIC_errEnablePerInterrupt(u8 Copy_u8IntIndex)                                            ;
ES_t MNVIC_errDisablePerInterrupt(u8 Copy_u8IntIndex)                                           ;
ES_t MNVIC_errSetPendingInterrupt(u8 Copy_u8IntIndex)                                           ;
ES_t MNVIC_errClearPeningInterrupt(u8 Copy_u8IntIndex)                                          ;
ES_t MNVIC_errIsInterruptActive(u8 Copy_u8IntIndex , u8* Copy_pu8ActiveStatus)                  ;
ES_t MNVIC_errSetInterruptPriority(u8 Copy_u8IntIndex ,MNVIC_GPriority_t Copy_uddtGPriority ,MNVIC_SUBPriority_t  Copy_uddtSubGPriority )                 ;


#endif /* MNVIC_INTERFACE_H_ */
