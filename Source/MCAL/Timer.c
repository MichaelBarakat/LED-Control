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
#include "Timer_Cfg.h"
#include "Timer.h"
#include "mcu_hw.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define MAX_NUMBER_OF_GPIO_GPT 		12u
#define TAEN 		0
#define TBEN 		8
#define TACDIR	4
#define PREDEF_TIMER					GPT_32_64_BIT_WIDE_TIMER4
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
GptNotification	locGptNotification[MAX_NUMBER_OF_GPIO_GPT];

static const Gpt_ConfigType*			globalGptConfig;
static volatile uint32 gptPredefTimer_1USPrescale;
static volatile uint32 gptPredefTimer_100US_32BitPrescale;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern volatile uint32 GlobalSystemClock;
static const uint32 Gpt_BaseAddress[MAX_NUMBER_OF_GPIO_GPT] = {GPT_16_32_BIT_TIMER0_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER1_BASE_ADDRESS,		
	                                                           GPT_16_32_BIT_TIMER2_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER3_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER4_BASE_ADDRESS,			
	                                                           GPT_16_32_BIT_TIMER5_BASE_ADDRESS,			
	                                                           GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS,
	                                                           GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS};
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
* \Syntax          : void Gpt_Init( const Gpt_ConfigType* ConfigPtr)        
* \Description     : Initializes the GPT driver.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr   Pointer to a selected configuration structure                     
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_Init( const Gpt_ConfigType* ConfigPtr)
{
	
}

/******************************************************************************
* \Syntax          : Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )       
* \Description     : Returns the time remaining until the target time is reached.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : Gpt_ValueType  uint32                                 
*******************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining( Gpt_ChannelType Channel )
{
	
}


/******************************************************************************
* \Syntax          : void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value );        
* \Description     : Starts a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant(but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel. 
*										 Value		 Target time in number of ticks.
* \Parameters (out): None                                                      
* \Return value:   : None                                 
*******************************************************************************/
void Gpt_StartTimer( Gpt_ChannelType Channel, Gpt_ValueType Value )
{

}

/******************************************************************************
* \Syntax          : void Gpt_StopTimer( Gpt_ChannelType Channel )       
* \Description     : Stops a timer channel.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant (but not for the same timer channel)                                             
* \Parameters (in) : Channel   Numeric identifier of the GPT channel.                     
* \Parameters (out): None                                                      
* \Return value:   : None                           
*******************************************************************************/
void Gpt_StopTimer( Gpt_ChannelType Channel )
{

}



void TIMER0A_Handler(void)
{
	
}

void TIMER1A_Handler(void)
{
	
}

void TIMER2A_Handler(void)
{
	
}

void TIMER3A_Handler(void)
{
	
}

void TIMER4A_Handler(void)
{
	
}

void TIMER5A_Handler(void)
{
	
}

void WTIMER0A_Handler(void)
{
	
}

void WTIMER1A_Handler(void)
{
	
}

void WTIMER2A_Handler(void)
{
	
}

void WTIMER3A_Handler(void)
{
	
}

void WTIMER4A_Handler(void)
{
	
}

void WTIMER5A_Handler(void)
{
	
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
