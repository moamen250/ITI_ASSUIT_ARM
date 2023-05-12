/******************************************************************************/
/* Auther                : Mariam Ayman                                       */
/* Version               : V1.0.0                                             */
/* Date                  : 6 May 2023                                         */
/* Description           : MRCC_Config.h                                      */
/* Features              : Supporting configuration of MRCC driver            */
/******************************************************************************/


/******************************************************************************/
/*              Guard of File with Call on time in .c                         */
/******************************************************************************/

#ifndef MRCC_CONFIG_H_
#define MRCC_CONFIG_H_

/******************************************************************************/
/*                          Clock Source Options                              */
/******************************************************************************/

/*
 *     -CLOCK SOURCE Option:
 *            1) MRCC_HSI
 *            2) MRCC_HSE
 *            3) MRCC_PLL
 */

#define MRCC_CLKSRC      MRCC_HSE


/******************************************************************************/
/*                              Clock HSE Options                             */
/******************************************************************************/

/*
 *     -CLOCK SOURCE Option For HSE:
 *            1) MRCC_HSE_MECH
 *            2) MRCC_HSE_ELEC
 */

#define MRCC_HSETYP      MRCC_HSE_MECH

/******************************************************************************/
/*                         Clock Source OF PLL Options                        */
/******************************************************************************/

/*
 *     -CLOCK SOURCE Option For PLL:
 *            1) MRCC_HSE_SRC
 *            2) MRCC_HSI_SRC
 */

#define MRCC_PLL_SRC      MRCC_HSE_SRC



#endif /* MRCC_CONFIG_H_ */
