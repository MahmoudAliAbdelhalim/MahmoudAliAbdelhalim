 /* ---------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<INTERRUPTS.H>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <HEADER FILE FOR AVR INTERRUPTS LIBRARY>

-------------------------------------------------------------------------------------------------------------------------------------------------*/ 
/*************************************************************************************************************************************************
 * 															HEADER FILE GAURD	
 *************************************************************************************************************************************************/
#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
/*************************************************************************************************************************************************
 * 															Interrupt vectors	
 *************************************************************************************************************************************************/
/*************************************************************
				External Interrupts Vectors 
*************************************************************/ 
/************* External Interrupt Request 0 *****************/
#define EXT_INT_0	__vector_1
/************* External Interrupt Request 1 *****************/
#define EXT_INT_1	__vector_2
/************* External Interrupt Request 2 *****************/
#define EXT_INT_2	__vector_3

/* Set the Global Interrupts Enable Bit, set the I-bit in status register to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")
/* Clear the Global Interrupts Enable Bit, set the I-bit in status register to 0 */ 
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* ISR Definition */
#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used)); \
void INT_VECT (void)


#endif /* INTERRUPTS_H_ */