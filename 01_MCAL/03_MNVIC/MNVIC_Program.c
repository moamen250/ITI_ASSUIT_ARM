/**************************************************************************/
/* Auther                : Peter Essam                                    */
/* Version               : V1.0.0                                         */
/* Date                  : 19-5-2023                                      */
/* Description           : MNVIC_                              */
/* Features              :                                                */
/*           1- MNVIC_errInitSoftwareSystemPriority()                     */
/*           2- MNVIC_errEnablePerInterrupt()                             */
/*           3- MNVIC_errDisablePerInterrupt()                            */
/*           4- MNVIC_errSetPendingInterrupt()                            */
/*           5- MNVIC_errClearPeningInterrupt()                           */
/*           6- MNVIC_errIsInterruptActive()                              */
/*           7- MNVIC_errSetInterruptPriority()                           */
/**************************************************************************/

/**************************************************************************/
/*                       Standard Types                                   */
/**************************************************************************/

#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"
#include "LERROR_STATES.h"

/**************************************************************************/
/*                            Peripherals Files                           */
/**************************************************************************/

#include "MNVIC_Private.h"
#include "MNVIC_Config.h"
#include "MNVIC_Interface.h"

/**************************************************************************/
/*                 MNVIC Functions implementation                         */
/**************************************************************************/


static MNVIC_SysPriority_t GLB_uddtSysPriority ;
/*****************************************************************************************************************************************/
/****************************************************************************************/
/* @brief : This Function Used To Initialize Software Priority                          */
/* @param : Copy_uddtPriorityOption -> This Parameter Make User Choose Priority Option  */
/* @return: This Function Return Error State                                            */
/****************************************************************************************/
ES_t MNVIC_errInitSoftwareSystemPriority(MNVIC_SysPriority_t Copy_uddtPriorityOption)
{
	ES_t LOC_uddtState = ES_OK;
	if((u8)Copy_uddtPriorityOption < MNVIC_INVALID_Priority)
	{
	GLB_uddtSysPriority  = Copy_uddtPriorityOption ;
	MSCB_AIRCR = VECTKEY |((u32)Copy_uddtPriorityOption << 8);
	}
	else{
		LOC_uddtState = ES_WRONG_MODE_VALUE ;
	}
	return LOC_uddtState;
}

/*****************************************************************************************************************************************/
ES_t MNVIC_errEnablePerInterrupt(u8 Copy_u8IntIndex)
{
	ES_t LOC_uddtState = ES_OK;
	if(Is_Valid_Intrrupt_Number(Copy_u8IntIndex))
	{
		MNVIC->ISER[Copy_u8IntIndex / 32]  = (1U << (Copy_u8IntIndex %32) )  ;
	}
	else
	{
		LOC_uddtState = ES_OUT_OF_RANGE_PRE_INT;
	}
	return LOC_uddtState;
}
/*****************************************************************************************************************************************/
ES_t MNVIC_errDisablePerInterrupt(u8 Copy_u8IntIndex)
{
	ES_t LOC_uddtState = ES_OK;
	if(Is_Valid_Intrrupt_Number(Copy_u8IntIndex))
	{
		MNVIC->ICER[Copy_u8IntIndex / 32]  = (1U << (Copy_u8IntIndex %32) )  ;
	}
	else 
	{
		LOC_uddtState = ES_OUT_OF_RANGE_PRE_INT;
	}
	return LOC_uddtState;
}
/*****************************************************************************************************************************************/
ES_t MNVIC_errSetPendingInterrupt(u8 Copy_u8IntIndex)
{
	ES_t LOC_uddtState = ES_OK;
	if(Is_Valid_Intrrupt_Number(Copy_u8IntIndex))
	{
		MNVIC->ISPR[Copy_u8IntIndex / 32]  = (1U << (Copy_u8IntIndex %32) )  ;
	}
	else 
	{
		LOC_uddtState = ES_OUT_OF_RANGE_PRE_INT;
	}
	return LOC_uddtState;
}
/*****************************************************************************************************************************************/
ES_t MNVIC_errClearPeningInterrupt(u8 Copy_u8IntIndex)
{
	ES_t LOC_uddtState = ES_OK;
	if(Is_Valid_Intrrupt_Number(Copy_u8IntIndex))
	{
		MNVIC->ICPR[Copy_u8IntIndex / 32]  = (1U << (Copy_u8IntIndex %32) )  ;
	}
	else
	{
		LOC_uddtState = ES_OUT_OF_RANGE_PRE_INT;
	}
	return LOC_uddtState;
}
/*****************************************************************************************************************************************/
ES_t MNVIC_errIsInterruptActive(u8 Copy_u8IntIndex , u8* Copy_pu8ActiveStatus)
{
	*Copy_pu8ActiveStatus=((MNVIC->IABR[Copy_u8IntIndex / 32])  >>( (Copy_u8IntIndex %32))&1);
}


  /*****************************************************************************************************************************************/
  /*                                    07- MNVIC_errSetInterruptPriority                                                                  */
  /*                                    Wtitten By : MINA NABIL BADEE                                                                      */
  /*****************************************************************************************************************************************/
  /* 1- Function Description                                                                                                               */
  /*                        @brief:set the interrupt priority by setting prephiral index from 0 - 239                                      */
  /*                       and num of group from 0 - 15 and num of subgroup from 0 -15                                                     */
  /* 2- Function Input                                                                                                                     */
  /*               @param : Copy_u8IntIndex prephiral index                                                                                */                     
  /*               @param : Copy_uddtGPriority  number groups          @ref : MNVIC_GPriority_t                                            */
  /*               @param :Copy_uddtSubGPriority number of subgroups   @ref :    MNVIC_SUBPriority_t                                       */
  /* 3- Function Return                                                                                                                    */
  /*               @return Error status of the function                                                                                    */
  /*                              (E_OK) : The function done successfully                                                                  */
  /*                              (ES_OUT_OF_RANGE_PRE_INT) : The user enter invalid prephiral index < 0 and >239                          */
  /*                              (MNVIC_INVALID_Priority)  : The user enter invalid priority < MNVIC_G16_S0 = 3 and > MNVIC_G0_S16=7      */
  /*                              (MNVIC_GROUP_INVALID) : The user enter number of group > 15                                              */
  /*                              (MNVIC_SUBGROUP_INVALID) : The user enter number of group > 15                                           */
  /*****************************************************************************************************************************************/


ES_t MNVIC_errSetInterruptPriority(u8 Copy_u8IntIndex ,MNVIC_GPriority_t Copy_uddtGPriority ,MNVIC_SUBPriority_t  Copy_uddtSubGPriority )

{
	ES_t LOC_uddtState = ES_OK;

	if((u8)(GLB_uddtSysPriority) > (MNVIC_G0_S16)){LOC_uddtState=ES_WRONG_MODE_VALUE;}
		

	else
	{
	    if( Copy_u8IntIndex >= BITS_PER_INT_MASK){LOC_uddtState=ES_OUT_OF_RANGE_PRE_INT;}
		else {
		MNVIC->IPR[Copy_u8IntIndex]=0;
		switch(GLB_uddtSysPriority){
			//in case of GLB_uddtSysPriority =MNVIC_G16_S0 -->   G=16   SG=0
			case MNVIC_G16_S0:
			
			if( (u8)Copy_uddtGPriority > MNVIC_GROUP_PRI15) {LOC_uddtState=ES_WRONG_MODE_VALUE;}
			else{ MNVIC->IPR[Copy_u8IntIndex] =(Copy_uddtGPriority)<<4;}
			break;
			//in case of GLB_uddtSysPriority =MNVIC_G8_S2 -->   G=8   SG=2
			case MNVIC_G8_S2:
			
			if((u8)(Copy_uddtGPriority) > MNVIC_GROUP_PRI7){LOC_uddtState=ES_WRONG_MODE_VALUE;}
            else if( (u8)(Copy_uddtSubGPriority) > MNVIC_SUBGROUP_PRI1){LOC_uddtState=ES_WRONG_MODE_VALUE;}
			else{MNVIC->IPR[Copy_u8IntIndex] =((Copy_uddtGPriority<<1) | (Copy_uddtSubGPriority))<<4;}
			break;
			
			//in case of GLB_uddtSysPriority =MNVIC_G4_S4 -->   G=4   SG=4

			case MNVIC_G4_S4:
			
			if((u8)(Copy_uddtGPriority) > MNVIC_GROUP_PRI3){LOC_uddtState=ES_WRONG_MODE_VALUE;}
		    else if((u8)(Copy_uddtSubGPriority) > MNVIC_SUBGROUP_PRI3){LOC_uddtState=ES_WRONG_MODE_VALUE ;}
			else {MNVIC->IPR[Copy_u8IntIndex] =((Copy_uddtGPriority<<2) | (Copy_uddtSubGPriority))<<4;}
			break;
			
			//in case of GLB_uddtSysPriority =MNVIC_G2_S8 -->   G=2   SG=8
			case MNVIC_G2_S8:
			
			if((u8)(Copy_uddtGPriority) > MNVIC_GROUP_PRI1){LOC_uddtState=ES_WRONG_MODE_VALUE;}
			else if((u8)(Copy_uddtSubGPriority) > MNVIC_SUBGROUP_PRI7){LOC_uddtState=ES_WRONG_MODE_VALUE;}
			else {MNVIC->IPR[Copy_u8IntIndex] =((Copy_uddtGPriority<<3) | (Copy_uddtSubGPriority))<<4;}
			break;
			//in case of GLB_uddtSysPriority =MNVIC_G0_S16 -->   G=0   SG=16
			case MNVIC_G0_S16:
			if((u8)(Copy_uddtSubGPriority) > MNVIC_SUBGROUP_PRI15) {LOC_uddtState=ES_WRONG_MODE_VALUE;}
			else {MNVIC->IPR[Copy_u8IntIndex] =(Copy_uddtSubGPriority)<<4;}
			break;
			default :
			LOC_uddtState =ES_WRONG_MODE_VALUE;
			return LOC_uddtState;
			break;
			
		}
		
		}
	}
	
	return LOC_uddtState;
}
