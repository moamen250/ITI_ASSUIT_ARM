/**************************************************************************/
/*       Author             : MOAMEN MAMDOUH THABET                       */
/*       Version            : V1.0.0                                      */
/*       Date               : 16 May 2023                                 */
/*       Description        : HBUZ_Private.h                              */
/**************************************************************************/

/**************************************************************************/
/*                  Guard for calling one time in .c files                */
/**************************************************************************/

#ifndef HBUZ_PRIVATE_H_
#define HBUZ_PRIVATE_H_

/**************************************************************************/
/*                  Enum for Error Type for Buzzer                        */
/**************************************************************************/
typedef enum
{
	HBUZ_ES_NOK      =0          ,
	HBUZ_ES_OK                   ,
	HBUZ_ES_PIN_Invalid          ,
	HBUZ_ES_PORT_Invalid
}HBUZ_ErrStatus_t;


#endif /* HBUZ_PRIVATE_H_ */
