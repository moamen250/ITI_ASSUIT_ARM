/*************************************************************************************************************/
/* Author :                             Mohamed Yehia El-Greatly                                             */
/* Description :                          HCLCD_Interface.h                                                  */
/*************************************************************************************************************/
/* Version :V1.0.0                                                                                           */
/* Date :     13 May 2023                                                                                    */
/*************************************************************************************************************/

/*###########################################################################################################*/
/* @Description  :                                                                                           */
/*     First : LCD  has 16 pins                                                                              */
/*           - VSS : Ground                                                                                  */
/*           - VDD : Power supply for logic (+5)                                                             */
/*           - V0 : Power supply for LCD                                                                     */
/*           - RS:  Register selection  [ H : Display Data , L : Instruction code                            */
/*           - R/W : Read / Write Selection [  H : Read operation , L : Write operation                      */
/*           - E : Enable signal  [ When E is H : Read Data , Falling edge of E : Write data                 */
/*           - D0 -> D7   :  Bi-directional data bus                                                         */
/*           - LEDA : LED power supply (+5)                                                                  */
/*           - LEDK : LED power supply (0V)                                                                  */
/*     Second : LCD has 2 mode operation                                                                     */
/*           - 8-bit mode : use all data bus  "D0->D7"                                                       */
/*           - 4-bit mode : use only 4 PINs  "D4->D7"                                                        */
/*           - Can configure it using "HCLCD_Config.h                                                        */
/*     Third :  Any API the user will use can take time as delay to initialize the LCD                       */
/*          - After power on wait as a maximum 1 m-seconds : this delay was handled  in initialization API   */
/*          - Any single character  which the user want to print take as a maximum 1 m-seconds               */
/*          - Any String which the user want to print take as a max ( 1 * number of characters ) m-seconds   */
/*     Fourth : Can use this site " https://maxpromer.github.io/LCD-Character-Creator/ "                     */
/*              to create any special character                                                              */
/*###########################################################################################################*/
/*@Features  :                                                                                               */
/*                  - HCLCD_errInit()                                                                        */
/*                  - HCLCD_errClearDisplay()                                                                */
/*                  - HCLCD_errSendCommand()                                                                 */
/*                  - HCLCD_errGoToPostion()                                                                 */
/*                  - HCLCD_errSendData()                                                                    */
/*                  - HCLCD_errSendString()                                                                  */
/*                  - HCLCD_errSendNumber()                                                                  */
/*                  - HCLCD_errSendSpecialChar()                                                             */
/*@Future Update :                                                                                           */
/*                  - Write Some APIs                                                                        */
/*###########################################################################################################*/
/*************************************************************************************************************/
/*  The Architect Give The APIs                                                                              */
/*                   1-  The Name of Function                                                                */
/*                   2-  What is the input                                                                   */
/*                   3-  Return Type  "Error State"                                                          */
/*                   4-  Object Like Macros                                                                  */
/*************************************************************************************************************/


/*************************************************************************************************************/
/*                                  Guard for calling one time in .c files                                   */
/*************************************************************************************************************/

#ifndef HAL_LCD_LCD_INT_H_
#define HAL_LCD_LCD_INT_H_

/*************************************************************************************************************/
/*                                   Define The NULL In Printing Mode                                        */
/*************************************************************************************************************/

#define  NULL_inNumberMode             0x0FFFFFFF /* IF the user print  number  = NULL_inNumberMode   ,  The LCD  will print  '\0'   */

/*************************************************************************************************************/
/*                                   Define The Screen Position                                              */
/*************************************************************************************************************/

typedef enum
{
	HCLCD_UP = 0 ,       //Using any even number  :   " HCLCD_errGoToPostion "  will go to the First row
	HCLCD_DOWN = 1,      //Using any odd number   :  " HCLCD_errGoToPostion "  will go to the Second row
	HCLCD_LEFT  = 0,     //All number like [0 , 16 , 32 ..etc ]  : " HCLCD_errGoToPostion "  will go to the First column
	HCLCD_RIGHT  = 15    //All number like [15 , 16+15 , 32+15 ..etc ]  : " HCLCD_errGoToPostion "  will go to the Last column
}HCLCD_uddtSPosition;

/*************************************************************************************************************/
/*                    Define The Block Number In LCD " CG RAM " To Save Special Character                    */
/*************************************************************************************************************/
typedef enum
{
	HCLCD_BLOCK0 = 0,
	HCLCD_BLOCK1,
	HCLCD_BLOCK2,
	HCLCD_BLOCK3,
	HCLCD_BLOCK4,
	HCLCD_BLOCK5,
	HCLCD_BLOCK6,
	HCLCD_BLOCK7,
	HCLCD_WRONG_BLOCK
}HCLCD_uddtCGRAMBlock;

/*************************************************************************************************************/
/*                                         Function Prototypes                                               */
/*************************************************************************************************************/

ES_t HCLCD_errInit (void);
ES_t  HCLCD_errClearDisplay(void);
ES_t  HCLCD_errSendData( HCLCD_Char  Copy_uddtData );
ES_t HCLCD_errSendString( HCLCD_String Copy_uddtString );
ES_t  HCLCD_errSendCommand( HCLCD_Command Copy_uddtCommand );
ES_t  HCLCD_errSendNumber( HCLCD_SignedNumber Copy_uddtDecimalNumber );
ES_t  HCLCD_errGoToPostion(HCLCD_uddtSPosition Copy_uddtColumn , HCLCD_uddtSPosition Copy_uddtRow);
ES_t  HCLCD_errSendSpecialChar(HCLCD_SpecialCharArr Copy_uddtArr , HCLCD_uddtCGRAMBlock Copy_uddtBlockNumber , HCLCD_uddtSPosition Copy_uddtColumn  ,HCLCD_uddtSPosition Copy_uddtRow  );

/*************************************************************************************************************/
/*                                            The   End                                                      */
/*************************************************************************************************************/
#endif /* HAL_LCD_LCD_INT_H_ */
/*###########################################################################################################*/

