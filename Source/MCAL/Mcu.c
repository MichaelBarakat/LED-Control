/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Mcu.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define APINT_VECTKEY 						0x05FA //This field is used to guard against accidental writes to this register
#define APINT_VECTKEY_BITFIELD			    16u
#define SYSRESREQ_BITFIELD					2u 		//System RESET Request
#define MCU_PLL_OUTPUT_DIV2         		200

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Mcu_PerformReset( void )        
* \Description     : The service performs a microcontroller reset.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
#if (MCU_PERFORM_RESET==STD_ON)
void Mcu_PerformReset(void)
{
	/* clear reset cause reester*/
	RESC = 0x00;
	/* perform reset */
	APINT = (APINT_VECTKEY << APINT_VECTKEY_BITFIELD)
					|(1 << SYSRESREQ_BITFIELD);
	
}
#endif/*MCU_PERFORM_RESET_API==STD_ON*/
/******************************************************************************
* \Syntax          : Mcu_HwResetType Mcu_GetResetHwValue( void )        
* \Description     : The service reads the reset type from the hardware, if supported.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Mcu_HwResetType   Reset Hardware value
*******************************************************************************/
Mcu_HwResetType Mcu_GetResetHwValue(void)
{
	Mcu_HwResetType ResetCause = RESC;
	RESC = 0x0;
	return ResetCause;
}

/******************************************************************************
* \Syntax          : Std_ReturnType Mcu_SupplyPllClock( void )        
* \Description     : This service activates the PLL clock to the MCU clock distribution.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 
*                    Pending: Command has been accepted
*                    Refused: Command has not been accepted
*******************************************************************************/
Std_ReturnType Mcu_SupplyPllClock( void)
{
	Std_ReturnType ret = Pending;
	/* check if PLL is enabled */
	if(RCC.B.PWRDN == 0)
	{
			/* check if Pll is locked  */
			if(Mcu_GetPllStatus() == MCU_PLL_STATUS_LOCKED)
			{
				/* distribute PLL */
				RCC.B.BYPASS = 1;
				ret = Refused;
			}
	}
	return ret;
	
}
/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the PLL and other MCU specific clock options.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting       ClockSetting.                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 

*******************************************************************************/
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting)
{
	

	if(Mcu_Status == MCU_INITIALIZED)
	{
	   
	
}
/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus        
* \Description     : This service provides the lock status of the PLL.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : Mcu_PllStatusType  PLL Status
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus(void)
{
	return PLLSTAT;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
