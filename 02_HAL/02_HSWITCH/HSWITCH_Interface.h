/**************************************************************************/
/* Author     : John Salah Makar                                          */
/* Version    : V1.0.0                                                    */
/*Date        : 13 May 2023                                               */
/*Description : HSWITCH_Interface.h                                       */
/*Features    : -HSWITCH_errInit()                                        */
/*              -HSWITCH_errON()                                          */
/*              -HSWITCH_errOFF()                                         */
/**************************************************************************/
/*#########################################################################*/
/**************************************************************************/
/*    - What i sell To customer ?                                         */
/*               * The Architect Give The APIs                            */
/*                          1-  The Name of Function                      */
/*                          2-  what is the input                         */
/*                          3-  Return Type                               */
/*                          4-  Object Like Macros                        */
/**************************************************************************/
/*#########################################################################*/

/**************************************************************************/
/*                    Guard for calling one time in .c files              */
/**************************************************************************/

#ifndef HSWITCH_INTERFACE_H_
#define HSWITCH_INTERFACE_H_
#include "MGPIO_Inteface.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                    enum for Switch State                               */
/**************************************************************************/
typedef enum
{
	Switch_OFF = 0,
	Switch_ON
}sState_t;
/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/

ES_t HSWITCH_errInit(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum);
u8   HSWITCH_u8GetSwitchState(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum);


#endif /* HSWITCH_INTERFACE_H_ */
