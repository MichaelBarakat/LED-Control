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

#define APINT_VECTKEY 											0x05FA 	/**This field is used to guard against accidental writes to this register**/
#define APINT_VECTKEY_BITFIELD			    			16u
#define SYSTEM_RESET_REQUEST_BITFIELD					2u 			/*System RESET Request*/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const Mcu_ConfigType* Mcu_ConfigPtr = NULL_PTR;
static Mcu_StatusType Mcu_Status = MCU_NOT_INITIALIZED;
volatile uint32 GlobalSystemClock;
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
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the MCU driver.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr       Pointer to MCU driver configuration set.                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )
{
	Mcu_Status = MCU_INITIALIZED;
	Mcu_ConfigPtr = ConfigPtr;
}

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
	/*Clears RESET Cause Register*/
	RESC = 0x00;
	
	/* perform RESET */
	APINT = (APINT_VECTKEY << APINT_VECTKEY_BITFIELD)
					|(1 << SYSTEM_RESET_REQUEST_BITFIELD);
}
#endif /*Perform RESET==STD_ON*/

/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the PLL and other MCU specific clock options.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting       ClockSetting.                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 

*******************************************************************************/



/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
