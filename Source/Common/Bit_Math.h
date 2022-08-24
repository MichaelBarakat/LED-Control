/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *			File	:	Bit_Math.h
			Author	:	Michael Barakat
 *
 *  Description:  Contains bitwise logic and math operations   
 *  
 *********************************************************************************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H



//Setting  a bit means that if the bit is 0, then set it to 1 and if it is 1 then leave it unchanged.
//Clearing a bit means that if the bit is 1, then clear it to 0 and if it is 0 then leave it unchanged.
//Toggling a bit means that if the bit is 1, then change it to 0 and if it is 0 then change it to 1.
//Get      a bit check whether bit number n is set (1) or not (0).

#define SetBit(REG,BIT)		REG |= (1<<BIT)				//Set
#define ClrBit(REG,BIT) 	REG &= (~(1<<BIT))			//Clear
#define TogBit(REG,BIT) 	REG ^= (1<<BIT)				//Invert
#define GetBit(REG,BIT) 	((REG>>BIT)&(0x01))			//Check status
#define SetBits(REG,MSK)	REG |= MSK					//Set specific number of bits 
#define ClrBits(REG,MSK)	REG &= (~MSK)				//Clear specific number of bits 
#define TogBits(REG,MSK)	REG ^= MSK					//Invert specific number of bits
#define SetAllBits(REG)		REG = 0xFF					//All ones
#define ClrAllBits(REG)		REG = 0x00					//All zeros
#define TogAllBits(REG)		REG ^= 0xFF					//Invert all

#endif