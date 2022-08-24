/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *			File	:	Mcu_Hw.h
			Author	:	Michael Barakat
 *
 *  Description:  MCU Registers Assignations 
 *  
 *********************************************************************************************************************/


#ifndef Mcu_Hw_H
#define Mcu_Hw_H


/****Includes****/
#include "Platform_Types.h" 


/****GLOBAL CONSTANT MACROS****/

														
/****Application Interrupt and Reset Control (APINT) REGISTER****/
															
 // CORTEX_M4 Core Peripherals base address
#define CORE_PER_BASE_ADDR				0xE000E000
#define APINT							*((volatile uint32*)CORE_PER_BASE_ADDR+0xD0C) //"0xD0C" is APINT Offset from CORE_PER_BASE_ADDR "0xE000E000"
#define NVIC_BASE_ADDR					0xE000E100
#define NVIC_PRI_BASE_ADDRESS			0xE000E400

/**************************************
*   SYSTEM CONTROL REGISTERS
***************************************/
#define SYSCTR_BASE_ADDRESS             0x400FE000
#define RESC							*((volatile uint32*)0xE01C) //00000000000000001110000000011100
#define RCGCGPIO_OFFSET                 0x608	//Clock Gating offset in Run mode for GPIO P.234 
#define RCGCGPIO                        *((volatile uint32*)(SYSCTR_BASE_ADDRESS+RCGCGPIO_OFFSET)

// Run-Mode Clock Configuration (RCC) number of bit fields assgined to each register
typedef struct 
{
	uint32 MOSCDIS  :1;		//must be set prior to reselecting the MOSC or an undefined system clock configuration can sporadically occur
	uint32          :3;		//empty means Reserved or not used
	uint32 OSCSRC   :2;		//Oscillator Source
	uint32 XTAL     :5;		//Crystal Value
	uint32 BYPASS   :1;		//PLL Bypass
	uint32          :1;		
	uint32 PWRDN    :1;		//PLL Power Down
	uint32          :3;
	uint32 PWMDIV   :3;		//PWM Unit Clock Divisor
	uint32 USEPWMDIV:1;		//Enable PWM Clock Divisor
	uint32          :1;
	uint32 USESYSDIV:1;		//Enable System Clock Divider
	uint32 SYSDIV   :4;		//System Clock Divisor
	uint32 ACG      :1;		//Auto Clock Gating
	uint32          :4;	
}Mcu_StructBitField;

//For memory allocation related to compiler(Fragmentation prevention)
typedef union 
{
	uint32  R;
	Mcu_StructBitField B;
}RCC_VAL;

#define RCC								(*((volatile RCC_VAL*)0x400FE060))	
#define PLLSTAT							*((volatile uint32*)0x400FE168)
#define RCGC_SYSCTRL_BASE_ADDR			0x400FE600	 //Run-Mode Clock Gating Control					


/**************************************
*   GPIO REGISTERS
***************************************/


/**************************************
*   WatchDog timer REGISTERS
***************************************/

/**************************************
*   Genenral Purpose Timer (GPT) REGISTERS
***************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS (Casting & Optimization)
 *********************************************************************************************************************/
				  				

//Genenral Purpose Timer (GPT) Base addresses


//WatchDog timer Base addresses


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/

