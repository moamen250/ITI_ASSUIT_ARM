
/**************************************************************************/
/*Author            : Mohamed Sayed EL_Gawy                               */
/*Version           : V1.0.0                                              */
/*Date              : 6 MAY 2023                                          */
/*Description       : MGPIO_Program.c                                     */
/*Features          :                                                     */
/*        - MGPIO_errSetPinMode()                                         */
/*        - MGPIO_errSetPinData()                                         */
/*        - MGPIO_errGetPinData()                                         */
/*        - MGPIO_errSetPullType()                                        */
/*        - MGPIO_errSetPinOutType()                                      */
/*        - MGPIO_errSetPinOutSpeed()                                     */
/*        - MGPIO_errSetPinLock()                                         */
/*        - MGPIO_errSetOrResetPinAtomic()                                */
/*        - MGPIO_errSetPinAltFun()                                       */
/*Future update     :                                                     */
/*        - Write Some APIs or PORT                                       */
/**************************************************************************/

/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/

#include "MGPIO_Private.h"
#include "MGPIO_Config.h"
#include "MGPIO_Inteface.h"

/******************************************************************************/
/*                        MGPIO Functions implementation                      */
/******************************************************************************/



ES_t MGPIO_errSetPinMode(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinMode)
{
//TODO
}
ES_t MGPIO_errSetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinValue)
{
//TODO
}
ES_t MGPIO_errGetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 *Copy_pu8PinMode)
{
//TODO
}

ES_t MGPIO_errSetPullType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PullType)
{
	/**FUNCTION TO SELECT PIN PULL TYPE**/
	//variable to return error state
	ES_t Local_ErrState = ES_OK;
	//switch for port num
	switch(Copy_uddtPortNum)
	{
		case MGPIO_PORTA:
			//switch for pin num
			switch(Copy_uddtPinNum)
			{
				case MGPIO_PIN0:
				//switch for pull type
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,0);
					CLR_BIT(GPIOA_PUPDR,1);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,0);
					CLR_BIT(GPIOA_PUPDR,1);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,0);
					SET_BIT(GPIOA_PUPDR,1);
				break;
				} //end of pull type switch for pin0
				
				case MGPIO_PIN1:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,2);
					CLR_BIT(GPIOA_PUPDR,3);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,2);
					CLR_BIT(GPIOA_PUPDR,3);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,2);
					SET_BIT(GPIOA_PUPDR,3);
				break;
				} //end of pull type switch for pin1
				
				case MGPIO_PIN2:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,4);
					CLR_BIT(GPIOA_PUPDR,5);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,4);
					CLR_BIT(GPIOA_PUPDR,5);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,4);
					SET_BIT(GPIOA_PUPDR,5);
				break;
				} //end of pull type switch for pin2
				
				case MGPIO_PIN3:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,6);
					CLR_BIT(GPIOA_PUPDR,7);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,6);
					CLR_BIT(GPIOA_PUPDR,7);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,6);
					SET_BIT(GPIOA_PUPDR,7);
				break;
				} //end of pull type switch for pin3
				
				case MGPIO_PIN4:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,8);
					CLR_BIT(GPIOA_PUPDR,9);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,8);
					CLR_BIT(GPIOA_PUPDR,9);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,8);
					SET_BIT(GPIOA_PUPDR,9);
				break;
				} //end of pull type switch for pin4
				
				case MGPIO_PIN5:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,10);
					CLR_BIT(GPIOA_PUPDR,11);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,10);
					CLR_BIT(GPIOA_PUPDR,11);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,10);
					SET_BIT(GPIOA_PUPDR,11);
				break;
				} //end of pull type switch for pin5
				
				case MGPIO_PIN6:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,12);
					CLR_BIT(GPIOA_PUPDR,13);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,12);
					CLR_BIT(GPIOA_PUPDR,13);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,12);
					SET_BIT(GPIOA_PUPDR,13);
				break;
				} //end of pull type switch for pin6
				
				case MGPIO_PIN7:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,14);
					CLR_BIT(GPIOA_PUPDR,15);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,14);
					CLR_BIT(GPIOA_PUPDR,15);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,14);
					SET_BIT(GPIOA_PUPDR,15);
				break;
				} //end of pull type switch for pin7
				
				case MGPIO_PIN8:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,16);
					CLR_BIT(GPIOA_PUPDR,17);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,16);
					CLR_BIT(GPIOA_PUPDR,17);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,16);
					SET_BIT(GPIOA_PUPDR,17);
				break;
				} //end of pull type switch for pin8
				
				case MGPIO_PIN9:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,18);
					CLR_BIT(GPIOA_PUPDR,19);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,18);
					CLR_BIT(GPIOA_PUPDR,19);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,18);
					SET_BIT(GPIOA_PUPDR,19);
				break;
				} //end of pull type switch for pin9
				
				case MGPIO_PIN10:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,20);
					CLR_BIT(GPIOA_PUPDR,21);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,20);
					CLR_BIT(GPIOA_PUPDR,21);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,20);
					SET_BIT(GPIOA_PUPDR,21);
				break;
				} //end of pull type switch for pin10
				
				case MGPIO_PIN11:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,22);
					CLR_BIT(GPIOA_PUPDR,23);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,22);
					CLR_BIT(GPIOA_PUPDR,23);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,22);
					SET_BIT(GPIOA_PUPDR,23);
				break;
				} //end of pull type switch for pin11
				
				case MGPIO_PIN12:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,24);
					CLR_BIT(GPIOA_PUPDR,25);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,24);
					CLR_BIT(GPIOA_PUPDR,25);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,24);
					SET_BIT(GPIOA_PUPDR,25);
				break;
				} //end of pull type switch for pin12
				
				case MGPIO_PIN13:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,26);
					CLR_BIT(GPIOA_PUPDR,27);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,26);
					CLR_BIT(GPIOA_PUPDR,27);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,26);
					SET_BIT(GPIOA_PUPDR,27);
				break;
				} //end of pull type switch for pin13
				
				case MGPIO_PIN14:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,28);
					CLR_BIT(GPIOA_PUPDR,29);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,28);
					CLR_BIT(GPIOA_PUPDR,29);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,28);
					SET_BIT(GPIOA_PUPDR,29);
				break;
				} //end of pull type switch for pin14
				
				case MGPIO_PIN15:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOA_PUPDR,30);
					CLR_BIT(GPIOA_PUPDR,31);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOA_PUPDR,30);
					CLR_BIT(GPIOA_PUPDR,31);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOA_PUPDR,30);
					SET_BIT(GPIOA_PUPDR,31);
				break;
				} //end of pull type switch for pin15
			} //end of pin switch
		break;
		
		case MGPIO_PORTB:
					//switch for pin num
			switch(Copy_uddtPinNum)
			{
				case MGPIO_PIN0:
				//switch for pull type
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,0);
					CLR_BIT(GPIOB_PUPDR,1);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,0);
					CLR_BIT(GPIOB_PUPDR,1);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,0);
					SET_BIT(GPIOB_PUPDR,1);
				break;
				} //end of pull type switch for pin0
				
				case MGPIO_PIN1:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,2);
					CLR_BIT(GPIOB_PUPDR,3);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,2);
					CLR_BIT(GPIOB_PUPDR,3);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,2);
					SET_BIT(GPIOB_PUPDR,3);
				break;
				} //end of pull type switch for pin1
				
				case MGPIO_PIN2:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,4);
					CLR_BIT(GPIOB_PUPDR,5);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,4);
					CLR_BIT(GPIOB_PUPDR,5);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,4);
					SET_BIT(GPIOB_PUPDR,5);
				break;
				} //end of pull type switch for pin2
				
				case MGPIO_PIN3:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,6);
					CLR_BIT(GPIOB_PUPDR,7);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,6);
					CLR_BIT(GPIOB_PUPDR,7);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,6);
					SET_BIT(GPIOB_PUPDR,7);
				break;
				} //end of pull type switch for pin3
				
				case MGPIO_PIN4:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,8);
					CLR_BIT(GPIOB_PUPDR,9);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,8);
					CLR_BIT(GPIOB_PUPDR,9);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,8);
					SET_BIT(GPIOB_PUPDR,9);
				break;
				} //end of pull type switch for pin4
				
				case MGPIO_PIN5:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,10);
					CLR_BIT(GPIOB_PUPDR,11);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,10);
					CLR_BIT(GPIOB_PUPDR,11);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,10);
					SET_BIT(GPIOB_PUPDR,11);
				break;
				} //end of pull type switch for pin5
				
				case MGPIO_PIN6:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,12);
					CLR_BIT(GPIOB_PUPDR,13);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,12);
					CLR_BIT(GPIOB_PUPDR,13);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,12);
					SET_BIT(GPIOB_PUPDR,13);
				break;
				} //end of pull type switch for pin6
				
				case MGPIO_PIN7:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,14);
					CLR_BIT(GPIOB_PUPDR,15);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,14);
					CLR_BIT(GPIOB_PUPDR,15);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,14);
					SET_BIT(GPIOB_PUPDR,15);
				break;
				} //end of pull type switch for pin7
				
				case MGPIO_PIN8:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,16);
					CLR_BIT(GPIOB_PUPDR,17);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,16);
					CLR_BIT(GPIOB_PUPDR,17);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,16);
					SET_BIT(GPIOB_PUPDR,17);
				break;
				} //end of pull type switch for pin8
				
				case MGPIO_PIN9:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,18);
					CLR_BIT(GPIOB_PUPDR,19);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,18);
					CLR_BIT(GPIOB_PUPDR,19);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,18);
					SET_BIT(GPIOB_PUPDR,19);
				break;
				} //end of pull type switch for pin9
				
				case MGPIO_PIN10:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,20);
					CLR_BIT(GPIOB_PUPDR,21);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,20);
					CLR_BIT(GPIOB_PUPDR,21);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,20);
					SET_BIT(GPIOB_PUPDR,21);
				break;
				} //end of pull type switch for pin10
				
				case MGPIO_PIN11:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,22);
					CLR_BIT(GPIOB_PUPDR,23);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,22);
					CLR_BIT(GPIOB_PUPDR,23);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,22);
					SET_BIT(GPIOB_PUPDR,23);
				break;
				} //end of pull type switch for pin11
				
				case MGPIO_PIN12:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,24);
					CLR_BIT(GPIOB_PUPDR,25);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,24);
					CLR_BIT(GPIOB_PUPDR,25);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,24);
					SET_BIT(GPIOB_PUPDR,25);
				break;
				} //end of pull type switch for pin12
				
				case MGPIO_PIN13:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,26);
					CLR_BIT(GPIOB_PUPDR,27);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,26);
					CLR_BIT(GPIOB_PUPDR,27);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,26);
					SET_BIT(GPIOB_PUPDR,27);
				break;
				} //end of pull type switch for pin13
				
				case MGPIO_PIN14:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,28);
					CLR_BIT(GPIOB_PUPDR,29);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,28);
					CLR_BIT(GPIOB_PUPDR,29);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,28);
					SET_BIT(GPIOB_PUPDR,29);
				break;
				} //end of pull type switch for pin14
				
				case MGPIO_PIN15:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOB_PUPDR,30);
					CLR_BIT(GPIOB_PUPDR,31);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOB_PUPDR,30);
					CLR_BIT(GPIOB_PUPDR,31);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOB_PUPDR,30);
					SET_BIT(GPIOB_PUPDR,31);
				break;
				} //end of pull type switch for pin15
			} //end of pin switch
		break;
		
		case MGPIO_PORTC:
		//switch for pin num
			switch(Copy_uddtPinNum)
			{
				case MGPIO_PIN13:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOC_PUPDR,26);
					CLR_BIT(GPIOC_PUPDR,27);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOC_PUPDR,26);
					CLR_BIT(GPIOC_PUPDR,27);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOC_PUPDR,26);
					SET_BIT(GPIOC_PUPDR,27);
				break;
				} //end of pull type switch for pin13
				
				case MGPIO_PIN14:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOC_PUPDR,28);
					CLR_BIT(GPIOC_PUPDR,29);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOC_PUPDR,28);
					CLR_BIT(GPIOC_PUPDR,29);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOC_PUPDR,28);
					SET_BIT(GPIOC_PUPDR,29);
				break;
				} //end of pull type switch for pin14
				
				case MGPIO_PIN15:
				switch (Copy_u8PullType)
				{
				case MGPIO_PULL_OFF:
					CLR_BIT(GPIOC_PUPDR,30);
					CLR_BIT(GPIOC_PUPDR,31);
				break;
				case MGPIO_PULL_UP:
					SET_BIT(GPIOC_PUPDR,30);
					CLR_BIT(GPIOC_PUPDR,31);
				break;
				case MGPIO_PULL_DOWN:
					CLR_BIT(GPIOC_PUPDR,30);
					SET_BIT(GPIOC_PUPDR,31);
				break;
				} //end of pull type switch for pin15
			} //end of pin switch
		break;
	} //end of port switch
	return Local_ErrState;
}
ES_t MGPIO_errSetPinOutType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinOutType)
{
//TODO
}
ES_t MGPIO_errSetPinOutSpeed(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinOutSpeed)
{
//TODO
}
ES_t MGPIO_errSetPinLock()
{
//TODO
}
ES_t MGPIO_errSetOrResetPinAtomic()
{
//TODO
}
ES_t MGPIO_errSetPinAltFun()
{
//TODO
}




