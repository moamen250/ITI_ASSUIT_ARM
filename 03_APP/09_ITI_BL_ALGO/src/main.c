/**************************************************************************/
/************************* Standard  LIB **********************************/
/**************************************************************************/
#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/********************************** MCAL **********************************/
/**************************************************************************/
/**
 * 1- MRCC
 * 2- MGPIO
 * 3- SYSTICK
 * 4- MUSART
 * 5- MFDI
 * */
#include "MRCC_Interface.h"
#include "MGPIO_Inteface.h"
#include "MSTK_Interface.h"
#include "MUSART_Interface.h"
#include "MFDI_Interface.h"


/**************************************************************************/
/****************************  System Variables ***************************/
/**************************************************************************/
//volatile u8 TimeOutFlag = 0 ;

//New data type pointer to function
typedef void(*Function_t)(void) ;

Function_t Add_to_call = 0 ;  // void (*Add_to_call)(void) = 0 ;

void Func_CallBack(void)
{
	/*Set Time out Flag*/
	//TimeOutFlag = 1 ;

	/*Set Address to call with RESET_ISR(Startup code of Application)*/
	Add_to_call = *(Function_t *)0x08004004 ;

	Add_to_call() ; //update PC -> initialized with  start address of startup code
}



void main(void)
{
    //Step 1: Initialize System Clock is 16MHz from HSI

	//Step 2: Enable peripherals From RCC [MGPIO- MUSART - MFDI]


	//Step3: Configure UART1 Pins [TX(PA9) ,RX(PA10)] From GPIO -> MODE_ALTF , ALTF_NO(7)


	//Step4: Indicate to I am  in BootLoader PA1 , PA2 -> High


    //Step5: Initialize USART -> 9600 bps


	//Step6:  Enable USART


	//Step7: Set Time to wait Data from UART and if the timeout is occurred jumb on the application part

	//MSTK_voidSetIntervalSingle(1500000,Func_CallBack) ; //Asynch

    // Loop forever
	while( 1 /*TimeOutFlag == 0*/)
	{
      //Polling UART for 1.5 Sec
		 //if data not recevied jumb to old application
	  // during 1.5 sec you received
		 //Stop timer to receive the application Code
	     // flash each received record by MFDI
	     //End of hex file ->  and  and Check RT = 0x01
//		if(RT == 0x01)
//		{
//			/*wait 1.5 sec then jumb to application code*/
//		  MSTK_voidSetIntervalSingle(1500000,Func_CallBack) ; //Asynch
//			/*Indicate to successful flashing  PA1 -> low */
//		}
	}

}
