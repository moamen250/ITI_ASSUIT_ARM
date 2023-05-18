/**************************************************************************/
/*       Author             : MOAMEN MAMDOUH THABET                       */
/*       Version            : V1.0.0                                      */
/*       Date               : 15 May 2023                                 */
/*       Description        : HBUZ_Interface.h                            */
/*       Feature            : Register Definitions                        */
/*========================================================================*/
/* APIS                                                                   */
/*        - HBUZZ_errInt()                                                */
/*        - HBUZZ_errOn()                                                 */
/*        - HBUZZ_errvOf()                                                */
/*        - HBUZZ_errFlip()                                               */
/*Future update     :                                                     */
/*        - Write Some APIs or PORT                                       */
/**************************************************************************/



/**************************************************************************/
/*                    Guard for calling one time in .c files              */
/**************************************************************************/


#ifndef HBUZ_INTERFACE_H_
#define HBUZ_INTERFACE_H_

/**************************************************************************/
/*                           Define HBUZZ PINS                            */
/**************************************************************************/
typedef enum
{
	HBUZZ_1_PIN   =   MGPIO_PIN0     ,
	HBUZZ_2_PIN   =   MGPIO_PIN1     ,
	HBUZZ_3_PIN   =   MGPIO_PIN2     ,
	HBUZZ_4_PIN   =   MGPIO_PIN3
}BUZZ_NUM_t;
/**************************************************************************/
/*                           Define HBUZZ PORT                            */
/**************************************************************************/
typedef enum
{
	HBUZZ_PORTA   =  MGPIO_PORTA    ,
	HBUZZ_PORTB   =  MGPIO_PORTB    ,
	HBUZZ_PORTC   =  MGPIO_PORTC
}BUZZ_PORT_t;
/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/

HBUZ_ErrStatus_t HBUZZ_errInt(BUZZ_PORT_t Copy_uddtPortNum,BUZZ_NUM_t Copy_uddtBuzzNum);

HBUZ_ErrStatus_t HBUZZ_errOn(BUZZ_PORT_t Copy_uddtPortNum,BUZZ_NUM_t Copy_uddtBuzzNum);

HBUZ_ErrStatus_t HBUZZ_errvOff(BUZZ_PORT_t Copy_uddtPortNum,BUZZ_NUM_t Copy_uddtBuzzNum);

HBUZ_ErrStatus_t HBUZZ_errFlip(BUZZ_PORT_t Copy_uddtPortNum,BUZZ_NUM_t Copy_uddtBuzzNum,u8 copy_u8NumTone);


#endif /* HBUZ_INTERFACE_H_ */
