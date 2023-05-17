/**************************************************************************/
/*Author            : Mariam Ayman                                        */
/*Version           : V1.0.0                                              */
/*Date              : 13 MAY 2023                                         */
/*Description       : H7SEG_Program.c                                     */
/*Features          :                                                     */
/*        - MGPIO_errSetPinMode()                                         */
/*        - MGPIO_errSetPinData()                                         */
/**************************************************************************/

/**************************************************************************/
/*                    Guard for calling one time in .c files              */
/**************************************************************************/

#ifndef H7SEG_PRIVATE_H_
#define H7SEG_PRIVATE_H_

typedef enum
{
	ZERO = 0,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE
}SSD_t;
#endif /* H7SEG_PRIVATE_H_ */
