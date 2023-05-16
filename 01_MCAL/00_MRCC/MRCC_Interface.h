/**************************************************************************/
/* Auther                : Amr Wahba                                      */
/* Version               : V1.0.0                                         */
/* Date                  : 6 May 2023                                     */
/* Description           : MRCC_Interface.h                               */
/*Features               :                                                */
/*        - MRCC_errEnablePeripherialClk()                                */
/*        - MRCC_errDisablePeripherialClk()                               */
/*        - MRCC_errInitSystemClk()                                       */
/*Future update     :                                                     */
/*        -                                                               */
/**************************************************************************/

/**************************************************************************/
/*    - What i sell To customer ?                                         */
/*               * The Architect Give The APIs                            */
/*                          1-  The Name of Function                      */
/*                          2-  what is the input                         */
/*                          3-  Return Type                               */
/*                          4-  Object Like Macros                        */
/**************************************************************************/


/**************************************************************************/
/*                    Guard for calling one time in .c files              */
/**************************************************************************/


#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_


/**************************************************************************/
/*                          Define BUS Name                               */
/**************************************************************************/

typedef enum
{
	MRCC_AHB1 = 0 ,
	MRCC_AHB2     ,
	MRCC_APB1     ,
	MRCC_APB2     ,
    MRCC_INVALID_BUS
}MRCC_uddtBusName;



/**************************************************************************/
/*                          Define RCC AHP1 CLK Enable                    */
/**************************************************************************/

#define MRCC_GPIOA_EN      0U
#define MRCC_GPIOB_EN      1U
#define MRCC_GPIOC_EN      2U
#define MRCC_GPIOD_EN      3U
#define MRCC_DMA1_EN       21U
#define MRCC_DMA1_EN       22U
 //TODO


/**************************************************************************/
/*                          Define RCC AHP2 CLK Enable                    */
/**************************************************************************/
#define MRCC_OTGFS_EN      7U
//TODO

/**************************************************************************/
/*                          Define RCC APB1 CLK Enable                    */
/**************************************************************************/
#define MRCC_TIM2_EN      0U
#define MRCC_TIM3_EN      1U
#define MRCC_TIM4_EN      2U
#define MRCC_TIM5_EN      3U
#define MRCC_WWDG_EN      11U
#define MRCC_SPI2_EN      14U
#define MRCC_SPI3_EN      15U
#define MRCC_USART2_EN    17U
#define MRCC_I2C1_EN      21U
#define MRCC_I2C2_EN      22U
#define MRCC_I2C3_EN      23U
#define MRCC_PWR_EN       28U
//TODO

/**************************************************************************/
/*                          Define RCC APB2 CLK Enable                    */
/**************************************************************************/
#define MRCC_TIM1_EN      0U
#define MRCC_USART1_EN    4U
#define MRCC_USART6_EN    5U
#define MRCC_ADC1_EN      8U
#define MRCC_SDIO_EN      11U
#define MRCC_SPI1_EN      12U
#define MRCC_SPI4_EN      13U
#define MRCC_SYSCFG_EN    14U
#define MRCC_TIM9_EN      16U
#define MRCC_TIM10_EN     17U
#define MRCC_TIM11_EN     18U
//TODO




/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/



ES_t MRCC_errEnablePeripherialClk(MRCC_uddtBusName Copy_uddtBusName, u8 Copy_u8PerNum)   ;
ES_t MRCC_errDisablePeripherialClk(MRCC_uddtBusName Copy_uddtBusName, u8 Copy_u8PerNum)  ;
ES_t MRCC_errInitSystemClk(void)                                                         ;

#endif /* MRCC_INTERFACE_H_ */
