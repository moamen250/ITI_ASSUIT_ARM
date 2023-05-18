/**************************************************************************/
/*Author            : Kirollos Samir Ayad                                 */
/*Version           : V1.0.0                                              */
/*Date              : 14 MAY 2023                                         */
/*Description       : Interface_File_For_Relay                            */
/*Features          :                                                     */
/*        - HRELAY_voidInit() 										      */
/*        - HRELAY_voidSetState()								          */
/*Future update     :                                                     */
/*       							                                      */
/**************************************************************************/

/**************************************************************************/
/*                    Guard for calling one time in .c files              */
/**************************************************************************/

#ifndef HRELAY_INTERFACE_H_
#define HRELAY_INTERFACE_H_


/**************************************************************************/
/*                          Function Prototypes                           */
/**************************************************************************/
void MRELAY_voidInit(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum);
void MRELAY_voidSetState(MGPIO_uddtPortNum Copy_uddtPortNum,MGPIO_uddtPinNum Copy_uddtPinNum, MGPIO_PinDataType Copy_uddtPinDataType);


#endif /* HRELAY_INTERFACE_H_ */
