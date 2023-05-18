/*#########################################################################################################*/
/**************************************************************************/
/*Author            : 3'ada m7moud                                       */
/*Version           : V1.0.0                                              */
/*Date              : 14 May 2023                                       */
/*Description       : HDCMOTOR_Prog.c                                   */

/**************************************************************************/


/*/***********************************************************************************************************************************************/
/*                                                      Include  LIB Files                                                                     */
/***********************************************************************************************************************************************/

#include  "LSTD_TYPES.h"
#include  "LBIT_MATH.h"
#include  "LERROR_STATES.h"

#include "MGPIO_Inteface.h"
#include "MRCC_Interface.h"

/***********************************************************************************************************************************************/
/*                                                  Include Peripherals Files                                                                  */
/***********************************************************************************************************************************************/


#include"HDCMOTOR_Config.h"
#include"HDCMOTOR_Private.h"
#include"HDCMOTOR_Interface.h"



/******************************************************************************************************************************/
/* 1- Function Description                                                                                                    */
/*               @brief    : Initialize the DC_MOTOR                                                                         */
/* 2- Function Return                                                                                                        */
 /*                   -no retrn                                                                                              */
/*                                                                                                                          */
/*                                                                                                                          */
/*                                                                                                                          */
/***********************************************************************************************************************************************/
 void HDCMOTOR_DCMOTOR_Init(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum1,MGPIO_uddtPinNum Copy_uddtPinNum2,u8 Copy_u8PinMode)
{
	//ES_t Loc_State;

	MRCC_errEnablePeripherialClk(MRCC_AHB1,Copy_uddtPortNum);
	MGPIO_errSetPinMode(Copy_uddtPortNum, Copy_uddtPinNum1,Copy_u8PinMode);
	MGPIO_errSetPinMode(Copy_uddtPortNum, Copy_uddtPinNum2,Copy_u8PinMode);


}


 /******************************************************************************************************************************/
 /* 1- Function Description                                                                                                    */
 /*                       : STOP DC_MOTOR                                                                         */
 /* 2- Function Return                                                                                                        */
  /*                   -no retrn                                                                                              */
 /*                                                                                                                          */
 /*                                                                                                                          */
 /*                                                                                                                          */
 /***************************************************************************************************************************/
 void HDCMOTOR_DCMOTOR_OFF(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum1,MGPIO_uddtPinNum Copy_uddtPinNum2)
 {
 	//ES_t Loc_State;

	 MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtPinNum1,MGPIO_PIN_LOW);
	 MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtPinNum2,MGPIO_PIN_LOW);
 	//MRCC_errDisablePeripherialClk(MRCC_AHB1,MRCC_GPIOA_EN);



 }

/******************************************************************************************************************************/
/* 1- Function Description                                                                                                    */
/*                       : DCMOTOR_Set_CLKWise                                                                       */
/* 2- Function Return                                                                                                        */
 /*                   -no retrn                                                                                              */
/*                                                                                                                          */
/*                                                                                                                          */
/*                                                                                                                          */
/***********************************************************************************************************************************************/

void HDCMOTOR_DCMOTOR_Set_CLKWise(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum1,MGPIO_uddtPinNum Copy_uddtPinNum2)
{

	//ES_t LOC_uddtState=MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtPinNum, Copy_u8PinValue);
	//return LOC_uddtState;
	 //SET_BIT(Copy_uddtPortNum,Copy_uddtPinNum1);
	 //CLR_BIT(Copy_uddtPortNum,Copy_uddtPinNum2);
	 //MGPIO_errSetPortData(Copy_uddtPortNum,1);
	 MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtPinNum1,MGPIO_PIN_HIGH);
	MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtPinNum2,MGPIO_PIN_LOW);
}


/******************************************************************************************************************************/
/* 1- Function Description                                                                                                    */
/*                       : DCMOTOR_Set_ACLKWise                                                                       */
/* 2- Function Return                                                                                                        */
 /*                   -no retrn                                                                                              */
/*                                                                                                                          */
/*                                                                                                                          */
/*                                                                                                                          */
/***********************************************************************************************************************************************/
void HDCMOTOR_DCMOTOR_Set_ACLKWise(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum1,MGPIO_uddtPinNum Copy_uddtPinNum2)
{

	//ES_t LOC_uddtState=MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtPinNum, Copy_u8PinValue);
	//return LOC_uddtState;
	//SET_BIT(Copy_uddtPortNum,Copy_uddtPinNum1);
    //CLR_BIT(Copy_uddtPortNum,Copy_uddtPinNum2);
	 //MGPIO_errSetPortData(Copy_uddtPortNum,2);
	 MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtPinNum2,MGPIO_PIN_HIGH);
	MGPIO_errSetPinData(Copy_uddtPortNum,Copy_uddtPinNum1,MGPIO_PIN_LOW);
}
