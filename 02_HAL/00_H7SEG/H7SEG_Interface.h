/**************************************************************************/
/*Author            : Mariam Ayman                                        */
/*Version           : V1.0.0                                              */
/*Date              : 13 MAY 2023                                         */
/*Description       : H7SEG_Program.c                                     */
/*Features          :                                                     */
/*        - H7SEG_Init()                                                  */
/*        - H7SEG_Display_Number()                                        */
/**************************************************************************/

/*########################################################################*/
/*########################################################################*/

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

#ifndef H7SEG_INTEFACE_H_
#define H7SEG_INTEFACE_H_

#include "LERROR_STATES.h"
#include "LSTD_TYPES.h"

/**************************************************************************/
/*         Define H7SEG configuration for COMMON CATHODE                  */
/**************************************************************************/
#if     H7SEG_TYPE  ==  COM_CATHODE

#define NUMBER_ZERO  	0x003F
#define NUMBER_ONE  	0x0006
#define NUMBER_TWO	    0x005B
#define NUMBER_THREE	0x004F
#define NUMBER_FOUR	    0x0066
#define NUMBER_FIVE 	0x006D
#define NUMBER_SIX  	0x007D
#define NUMBER_SEVEN	0x0007
#define NUMBER_EIGHT	0x007F
#define NUMBER_NINE  	0x006F

/**************************************************************************/
/*         Define H7SEG configuration for COMMON ANODE                    */
/**************************************************************************/
#elif   H7SEG_TYPE  ==  COM_ANODE

#define NUMBER_ZERO  	0x00C0
#define NUMBER_ONE  	0x00F9
#define NUMBER_TWO	    0x00A4
#define NUMBER_THREE	0x00B0
#define NUMBER_FOUR	    0x0099
#define NUMBER_FIVE 	0x0092
#define NUMBER_SIX  	0x0082
#define NUMBER_SEVEN	0x00F8
#define NUMBER_EIGHT	0x0080
#define NUMBER_NINE  	0x0090

#endif

/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/
ES_t H7SEG_Init (void);
ES_t H7SEG_Display_Number(u8 Copy_u8Number);

#endif /* H7SEG_INTERFACE_H_ */
