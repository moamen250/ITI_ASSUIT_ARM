/**************************************************************************/
/*Author            : Kirollos Samir Ayad                                 */
/*Version           : V1.0.0                                              */
/*Date              : 6 MAY 2023                                          */
/*Description       : Interface_File_For_GPIO                             */
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

#ifndef MGPIO_INTEFACE_H_
#define MGPIO_INTEFACE_H_

/**************************************************************************/
/*                          Define Target Port                            */
/**************************************************************************/

//#define MGPIO_PORTA   0
//#define MGPIO_PORTB   1
//#define MGPIO_PORTC   2

typedef enum
{
	MGPIO_PORTA = 0 ,
	MGPIO_PORTB     ,
	MGPIO_PORTC     ,
    MGPOI_INVALID_PORT
}MGPIO_uddtPortNum;


/**************************************************************************/
/*                          Define Target PIN                             */
/**************************************************************************/

typedef enum
{
	MGPIO_PIN0 = 0 ,
	MGPIO_PIN1     ,
	MGPIO_PIN2     ,
	MGPIO_PIN3     ,
	MGPIO_PIN4     ,
	MGPIO_PIN5     ,
	MGPIO_PIN6     ,
	MGPIO_PIN7     ,
	MGPIO_PIN8     ,
	MGPIO_PIN9     ,
	MGPIO_PIN10    ,
	MGPIO_PIN11    ,
	MGPIO_PIN12    ,
	MGPIO_PIN13    ,
	MGPIO_PIN14    ,
	MGPIO_PIN15    ,
    MGPOI_INVALID_PIN
}MGPIO_uddtPinNum;




/**************************************************************************/
/*                          Define Pin Mode                               */
/**************************************************************************/

#define MGPIO_MODE_INPUT      0
#define MGPIO_MODE_OUTPUT     1
#define MGPIO_MODE_ALTF       2
#define MGPIO_MODE_ANALOG     3

/**************************************************************************/
/*                          Define Pin Mode                               */
/**************************************************************************/

#define MGPIO_MODE_INPUT      0
#define MGPIO_MODE_OUTPUT     1
#define MGPIO_MODE_ALTF       2
#define MGPIO_MODE_ANALOG     3


/**************************************************************************/
/*                          Define Pin PULL type                          */
/**************************************************************************/

#define MGPIO_PULL_OFF       0
#define MGPIO_PULL_UP        1
#define MGPIO_PULL_DOWN      2

/**************************************************************************/
/*                          Define Pin OutSpeed type                      */
/**************************************************************************/

#define MGPIO_OUTPUT_LOW_SPEED        0
#define MGPIO_OUTPUT_MEDIUM_SPEED     1
#define MGPIO_OUTPUT_HIGH_SPEED       2
#define MGPIO_OUTPUT_VHIGH_SPEED      3


/**************************************************************************/
/*                          Define Pin Data type                          */
/**************************************************************************/

#define MGPIO_PIN_LOW              0
#define MGPIO_PIN_HIGH             1

/**************************************************************************/
/*                          Define GPIO OutputCircut                      */
/**************************************************************************/

#define MGPIO_OUTPUT_PUSHPULL       0
#define MGPIO_OUTPUT_OPERDRAIN      1

/**************************************************************************/
/*                          Define PIN LOCK                               */
/**************************************************************************/

#define MGPIO_PIN_UNLOCK            0
#define MGPIO_PIN_LOCK              1



/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/
ES_t MGPIO_errSetPinMode(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinMode)            ;
ES_t MGPIO_errSetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinValue)            ;
ES_t MGPIO_errGetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 *Copy_pu8PinMode)            ;
ES_t MGPIO_errSetPullType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PullType)           ;
ES_t MGPIO_errSetPinOutType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinOutType)         ;
ES_t MGPIO_errSetPinOutSpeed(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinOutSpeed)        ;
ES_t MGPIO_errSetPinLock()            ;
ES_t MGPIO_errSetOrResetPinAtomic()   ;
ES_t MGPIO_errSetPinAltFun()          ;

#endif /* MGPIO_INTEFACE_H_ */
