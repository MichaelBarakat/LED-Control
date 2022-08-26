/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_H_
#define MCU_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Platform_Types.h"
#include "Std_Types.h"
#include "Mcu_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef uint8 Mcu_ClockType;


typedef enum
{
	MCU_CLOCK_SOURCE_MOSC,
	MCU_CLOCK_SOURCE_PIOSC,
	MCU_CLOCK_SOURCE_PIOSC_DIV4,
	MCU_CLOCK_SOURCE_LFIOSC,
	MCU_CLOCK_SOURCE_HIOSC
}Mcu_ClockSourceType;

typedef uint32 Mcu_FreqType;

typedef struct
{
	Mcu_ClockSourceType ClockSource;
	Mcu_FreqType Freq_KHz;
	
}Mcu_ConfigType;

typedef uint8 Mcu_StatusType;
#define MCU_NOT_INITIALIZED 	0
#define MCU_INITIALIZED 			1
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern uint8 Mcu_ActivatedClockGates[MCU_ACTIVATED_CLOCK_GATES_SIZE];
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
void Mcu_Init ( const Mcu_ConfigType* ConfigPtr );

/******************************************************************************
* \Syntax          : Mcu_HwResetCause Mcu_GetResetHwValue( void )        
* \Description     : The service reads the reset type from the hardware, if supported.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                            
* \Parameters (out): None                                                      
* \Return value:   : Mcu_HwResetType   Reset Hw value
*******************************************************************************/
Mcu_HwResetCause Mcu_GetResetHwValue( void );

/******************************************************************************
* \Syntax          : void Mcu_PerformReset( void )        
* \Description     : The service performs a microcontroller reset.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                           
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/
#if (MCU_PERFORM_RESET==STD_ON)
void Mcu_PerformReset( void );
#endif
/******************************************************************************
* \Syntax          : void Mcu_Init ( const Mcu_ConfigType* ConfigPtr )        
* \Description     : This service initializes the PLL and other MCU specific clock options.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ClockSetting       ClockSetting.                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType 

*******************************************************************************/
Std_ReturnType Mcu_InitClock( Mcu_ClockType ClockSetting );

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
Std_ReturnType Mcu_SupplyPllClock( void );

/******************************************************************************
* \Syntax          : Mcu_PllStatusType Mcu_GetPllStatus        
* \Description     : This service indicates status PLL(Locked - Unlocked - Unknown)                                                                                                                
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : Mcu_PllStatusType  PLL Status
*******************************************************************************/
Mcu_PllStatusType Mcu_GetPllStatus( void );


#endif  /* MCU_H */
/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

