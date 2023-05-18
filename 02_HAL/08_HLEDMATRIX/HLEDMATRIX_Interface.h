/**************************************************************************/
/*Author            : Ahmed Reda Morsi                                    */
/*Version           : V1.0.0                                              */
/*Date              : 17 MAY 2023                                         */
/*Description       :  interface file of LED matrix                       */
/*Features          :                                                     */
/*        -HLEDMATRIX_errInit(void) 									  */
/* 		  -HLEDMATRIX_SetPattern(u8* Copy_u8pPattern)                     */

/**************************************************************************/



/**************************************************************************/
/*                    Guard for calling one time in .c files              */
/**************************************************************************/

#ifndef HLEDMATRIX_INTEFACE_H_
#define HLEDMATRIX_INTEFACE_H_


/**************************************************************************/
/*                          Define HLEDMATRIX PIN                         */
/**************************************************************************/
typedef enum
{
	HLEDMATRIX_COLUMN_0 =0,
	HLEDMATRIX_COLUMN_1 =1,
	HLEDMATRIX_COLUMN_2 =2,
	HLEDMATRIX_COLUMN_3 =3,
	HLEDMATRIX_COLUMN_4 =4,
	HLEDMATRIX_COLUMN_5 =5,
	HLEDMATRIX_COLUMN_6 =6,
	HLEDMATRIX_COLUMN_7 =7,

	HLEDMATRIX_ROW_0 	=0,
	HLEDMATRIX_ROW_1    =1,
	HLEDMATRIX_ROW_2    =2,
	HLEDMATRIX_ROW_3    =3,
	HLEDMATRIX_ROW_4    =4,
	HLEDMATRIX_ROW_5    =5,
	HLEDMATRIX_ROW_6    =6,
	HLEDMATRIX_ROW_7    =7,
    HLEDMATRIX_INVALID_PIN
}HLEDMATRIX_uddtPinNum;



/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/
ES_t HLEDMATRIX_errInit(void);
ES_t HLEDMATRIX_SetPattern(u8* Copy_u8pPattern);


/**************************************************************************/
#endif /* HLEDMATRIX_INTEFACE_H_ */
