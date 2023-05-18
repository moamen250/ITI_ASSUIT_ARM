
/**************************************************************************/
/*Author            : Amr Wahba                                           */
/*Version           : V1.0.0                                              */
/*Date              : 13 MAY 2023                                         */
/*Description       :HKEYPAD_Configration.h                               */

/**************************************************************************/

/**************************************************************************/
/*                    Guard for calling one time in .c files              */
/**************************************************************************/
#ifndef HAL_KEYPAD_KEYPAD_CFG_H_
#define HAL_KEYPAD_KEYPAD_CFG_H_


#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "MGPIO_Inteface.h"

/***********************************************************************************************************/
/*                                Configure The KEYPAD PORT                                                */
/*                                                                                                         */
/***********************************************************************************************************/
#define HKEYPAD_PORT	MGPIO_PORTB


/***********************************************************************************************************/
/*                                Configure The KEYPAD PINS                                                */
/*                                                                                                         */
/***********************************************************************************************************/
#define ROW_PIN0        MGPIO_PIN0
#define ROW_PIN1        MGPIO_PIN1
#define ROW_PIN2        MGPIO_PIN2
#define ROW_PIN3        MGPIO_PIN3

#define COL_PIN4   		MGPIO_PIN4
#define COL_PIN5    	MGPIO_PIN5
#define COL_PIN6   		MGPIO_PIN6
#define COL_PIN7   		MGPIO_PIN7



/***********************************************************************************************************/
/*                                      Object Like Macro Section                                          */
/***********************************************************************************************************/
#define 	ROWS_NUM		4
#define 	COLOUMS_NUM		4


#define NOT_PRESSED		0xff


#define KEYPAD_BUTTON_VALUE 	{{7,8,9,37},{4,5,6,38},{1,2,3,40},{39,0,41,42}}



//39--> Clear Screen
//41--> =
//37--> /
//38--> *
//40--> -
//42--> +


//{{0,1,2,3},{4,5,6,7},{8,9,37,38},{39,40,41,42}}



#endif /* HAL_KEYPAD_KEYPAD_CFG_H_ */
