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
//TODO


/**************************************************************************/
/*                          Define RCC AHP2 CLK Enable                    */
/**************************************************************************/
//TODO


/**************************************************************************/
/*                          Define RCC APB1 CLK Enable                    */
/**************************************************************************/
//TODO

/**************************************************************************/
/*                          Define RCC APB2 CLK Enable                    */
/**************************************************************************/
//TODO




/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/



ES_t MRCC_errEnablePeripherialClk(MRCC_uddtBusName Copy_uddtBusName, u8 Copy_u8PerNum)   ;
ES_t MRCC_errDisablePeripherialClk(MRCC_uddtBusName Copy_uddtBusName, u8 Copy_u8PerNum)  ;
ES_t MRCC_errInitSystemClk(void)                                                         ;

#endif /* MRCC_INTERFACE_H_ */
