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
	MGPIO_INVALID_PORT
}MGPIO_uddtPortNum;

/**************************************************************************/
/*  Define Target PIN STATE FOR ACCESS IN ATOMIC MOOD SET OR RESET        */
/**************************************************************************/
typedef enum
{
	MGPIO_PIN_SET_ATOMIC = 0 ,
	MGPIO_PIN_RESET_ATOMIC   ,
	WRONG_PIN_STATE
}MGPIO_uddtPinState;
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
    MGPIO_INVALID_PIN
}MGPIO_uddtPinNum;




/**************************************************************************/
/*                          Define Pin Mode                               */
/**************************************************************************/

//#define MGPIO_MODE_INPUT      0
//#define MGPIO_MODE_OUTPUT     1
//#define MGPIO_MODE_ALTF       2
//#define MGPIO_MODE_ANALOG     3

typedef enum
{
	MGPIO_MODE_INPUT ,
	MGPIO_MODE_OUTPUT,
	MGPIO_MODE_ALTF  ,
	MGPIO_MODE_ANALOG
}MGPIO_PinMode;

/**************************************************************************/
/*                          Define Pin PULL type                          */
/**************************************************************************/

//#define MGPIO_PULL_OFF       0
//#define MGPIO_PULL_UP        1
//#define MGPIO_PULL_DOWN      2

typedef enum
{
	MGPIO_PULL_OFF ,
	MGPIO_PULL_UP  ,
	MGPIO_PULL_DOWN
}MGPIO_PinPullType;

/**************************************************************************/
/*                        Define Pin OutSpeed type                        */
/**************************************************************************/

//#define MGPIO_OUTPUT_LOW_SPEED        0
//#define MGPIO_OUTPUT_MEDIUM_SPEED     1
//#define MGPIO_OUTPUT_HIGH_SPEED       2
//#define MGPIO_OUTPUT_VHIGH_SPEED      3

typedef enum
{
	MGPIO_OUTPUT_LOW_SPEED		,
	MGPIO_OUTPUT_MEDIUM_SPEED	,
	MGPIO_OUTPUT_HIGH_SPEED		,
	MGPIO_OUTPUT_VHIGH_SPEED	,
	MGPIO_INVALID_PIN_SPEED
}MGPIO_PinSpeed;

/**************************************************************************/
/*                          Define Pin Data type                          */
/**************************************************************************/

//#define MGPIO_PIN_LOW              0
//#define MGPIO_PIN_HIGH             1

typedef enum
{
	MGPIO_PIN_LOW	,
	MGPIO_PIN_HIGH
}MGPIO_PinDataLogic;

/**************************************************************************/
/*                          Define GPIO OutputCircut                      */
/**************************************************************************/

//#define MGPIO_OUTPUT_PUSHPULL       0
//#define MGPIO_OUTPUT_OPERDRAIN      1

typedef enum
{
	MGPIO_OUTPUT_PUSHPULL	,
	MGPIO_OUTPUT_OPERDRAIN
}MGPIO_OutputCircuit;

/**************************************************************************/
/*                          Define PIN LOCK                               */
/**************************************************************************/

//#define MGPIO_PIN_UNLOCK            0
//#define MGPIO_PIN_LOCK              1

typedef enum
{
	MGPIO_PIN_UNLOCK	,
	MGPIO_PIN_LOCK
}MGPIO_PinLock;

/**************************************************************************/
/*                          Define PIN Alternative Options                */
/**************************************************************************/



//typedef enum
//{
//	// TODO
//}MGPIO_PinALtOptions;

/******************************************************************************/
/*                                    Define Macro Function                                             */
/******************************************************************************/

#define  MGPIO_PINs_From_To(  _FROM_  ,  _TO_  )     ( (u16)( PUT_ONS(  _FROM_  ,  _TO_  ) ) )
//Example : MGPIO PINs From To      5     ->    14       :                   (  0xb0111 1111 1110 0000   )

/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/
#if MGPIO_PIN_APIs          ==          MGPIO_ENABLE
/**************************************************************************/
ES_t MGPIO_errSetPinMode(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinMode);
ES_t MGPIO_errSetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinValue);
ES_t MGPIO_errGetPinData(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 *Copy_pu8PinValue);
ES_t MGPIO_errSetPullType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PullType);
ES_t MGPIO_errSetPinOutType(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,MGPIO_OutputCircuit Copy_u8PinOutType);
ES_t MGPIO_errSetPinOutSpeed(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 Copy_u8PinOutSpeed);
ES_t MGPIO_errSetPinLock( MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum);
ES_t MGPIO_errSetOrResetPinAtomic(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,MGPIO_uddtPinState Copy_uddtPinState);
ES_t MGPIO_errSetPinAltFun(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum,u8 GPIO_AFSelection );

/**************************************************************************/
#endif
/**************************************************************************/
#if MGPIO_GROUP_OF_PINs_APIs          ==          MGPIO_ENABLE
/**************************************************************************/
ES_t MGPIO_errSetPINsGroupMode(MGPIO_uddtPortNum Copy_uddtPortNum,u16 Copy_uddtPINsGroup,MGPIO_PinMode Copy_uddtGroupMode);
ES_t MGPIO_errSetPINsGroupData(MGPIO_uddtPortNum Copy_uddtPortNum,u16 Copy_uddtPINsGroup, u16 Copy_uddtGroupLogic);
/**************************************************************************/
#endif
/**************************************************************************/
#if MGPIO_PORTs_APIs                            ==          MGPIO_ENABLE
/**************************************************************************/
//TODO
ES_t MGPIO_errSetPortData(MGPIO_uddtPortNum Copy_uddtPortNum,u32 Copy_u8PortValue);
/**************************************************************************/
#endif
/**************************************************************************/
#endif /* MGPIO_INTEFACE_H_ */
