

/**************************************************************************/
/*Author            : Amr Wahba                                           */
/*Version           : V1.0.0                                              */
/*Date              : 17 MAY 2023                                         */
/*Description       :HKEYPAD_Program.c                                    */
/*Features          :                                                     */
/*        - HKEYPAD_Int()                                                 */
/*        - HKEYPAD_u8GetPressed()                                        */
/**************************************************************************/

/*########################################################################*/
/*########################################################################*/

/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "../include/LBIT_MATH.h"
#include "../include/LSTD_TYPES.h"
#include "../include/LERROR_STATES.h"

/**************************************************************************/
/*                           INCLUDE MCAL LAYER                           */
/**************************************************************************/
#include "../include/MGPIO_Inteface.h"

/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/
#include "../include/HKEYPAD_Config.h"
#include "../include/HKEYPAD_Private.h"
#include "../include/HKEYPAD_Interface.h"

/**************************************************************************/

/******************************************************************************/
/*                 HKEYPAD Functions implementation                             */
/******************************************************************************/

void HKEYPAD_Int(void)
{

    /**Set Rows to be Input*/


	MGPIO_errSetPinMode(HKEYPAD_PORT,ROW_PIN0,MGPIO_MODE_INPUT);
	MGPIO_errSetPinMode(HKEYPAD_PORT,ROW_PIN1,MGPIO_MODE_INPUT);
	MGPIO_errSetPinMode(HKEYPAD_PORT,ROW_PIN2,MGPIO_MODE_INPUT);
	MGPIO_errSetPinMode(HKEYPAD_PORT,ROW_PIN3,MGPIO_MODE_INPUT);


    /**Enable pull up resistor */

	MGPIO_errSetPullType(HKEYPAD_PORT,ROW_PIN0,MGPIO_PULL_UP);
	MGPIO_errSetPullType(HKEYPAD_PORT,ROW_PIN1,MGPIO_PULL_UP);
	MGPIO_errSetPullType(HKEYPAD_PORT,ROW_PIN2,MGPIO_PULL_UP);
	MGPIO_errSetPullType(HKEYPAD_PORT,ROW_PIN3,MGPIO_PULL_UP);

    /**Set Coloums to be Output*/

	MGPIO_errSetPinMode(HKEYPAD_PORT,COL_PIN4,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(HKEYPAD_PORT,COL_PIN5,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(HKEYPAD_PORT,COL_PIN6,MGPIO_MODE_OUTPUT);
	MGPIO_errSetPinMode(HKEYPAD_PORT,COL_PIN7,MGPIO_MODE_OUTPUT);


    /*Set Coloums pin to PIN_High*/
	MGPIO_errSetPinData(HKEYPAD_PORT,COL_PIN4,MGPIO_PIN_HIGH);
	MGPIO_errSetPinData(HKEYPAD_PORT,COL_PIN5,MGPIO_PIN_HIGH);
	MGPIO_errSetPinData(HKEYPAD_PORT,COL_PIN6,MGPIO_PIN_HIGH);
	MGPIO_errSetPinData(HKEYPAD_PORT,COL_PIN7,MGPIO_PIN_HIGH);

}





u8 HKEYPAD_u8GetPressed(void)
{

    u8 Loca_Coloums_Array[COLOUMS_NUM]= {COL_PIN4,COL_PIN5,COL_PIN6,COL_PIN7};
    u8 Loca_Rows_Array[ROWS_NUM]= {ROW_PIN0,ROW_PIN1,ROW_PIN2,ROW_PIN3};



    u8 Local_u8Coloum_Counter=0;
    u8 Local_u8Rows_Counter=0;
    u8 Local_u8PinState;
    u8 Local_u8PressedKey=NOT_PRESSED;


    u8 Local_u8ButtonAarray[ROWS_NUM][COLOUMS_NUM]=KEYPAD_BUTTON_VALUE;


    /**loop For Coloums*/
    for(Local_u8Coloum_Counter=0; Local_u8Coloum_Counter <COLOUMS_NUM; Local_u8Coloum_Counter++)
    {
    	MGPIO_errSetPinData(HKEYPAD_PORT, Loca_Coloums_Array[Local_u8Coloum_Counter],MGPIO_PIN_LOW);

        for(Local_u8Rows_Counter=0; Local_u8Rows_Counter <ROWS_NUM; Local_u8Rows_Counter++)
        {
            MGPIO_errGetPinData(HKEYPAD_PORT, Loca_Rows_Array[Local_u8Rows_Counter],&Local_u8PinState);//Checking

            if(Local_u8PinState==MGPIO_PIN_LOW)
            {
                Local_u8PressedKey=Local_u8ButtonAarray[Local_u8Rows_Counter][Local_u8Coloum_Counter];

                while(Local_u8PinState==MGPIO_PIN_LOW)
                {

                	MGPIO_errGetPinData(HKEYPAD_PORT,Loca_Rows_Array[Local_u8Rows_Counter],&Local_u8PinState);
                }
                return Local_u8PressedKey;
            }
        }
        MGPIO_errSetPinData(HKEYPAD_PORT,Loca_Coloums_Array[Local_u8Coloum_Counter],MGPIO_PIN_HIGH);

    }



    return Local_u8PressedKey;
}
