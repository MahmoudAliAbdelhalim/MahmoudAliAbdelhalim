 /* -----------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<REGISTERS.H>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <HEADER FILE FOR AVR_ATMEGA32 REGISTERS>

-------------------------------------------------------------------------------------------------------------*/
 /*************************************************************************************************************************************************
 * 															 	 HEADER FILE GAURD	
 *************************************************************************************************************************************************/
#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "std_types.h"
/*************************************************************************************************************************************************
																	ENUMERATIONS
 *************************************************************************************************************************************************/

/*************************************************************
	SREG register bits –> AVR Status Register Bits
*************************************************************/
typedef enum
{
	C, Z, N, V, S, H, T, I
	
}SREG_REGISTER;
/********************************************************************
	GICR register bits –> General Interrupt Control Register Bits
*********************************************************************/
typedef enum
{
	IVCE, IVSEL, INT2=5, INT0, INT1
	
}GICR_REGISTER;

/***************************************************************
	GIFR register bits –> General Interrupt Flag Register Bits
****************************************************************/
typedef enum
{
	INTF2=5, INTF0, INTF1
	
}GIFR_REGISTER;

/***********************************************************************
	TIMSK register bits -> Timer/Counter Interrupt Mask Register Bits
************************************************************************/
typedef enum
{
	TOIE0, OCIE0, TOIE1, OCIE1B, OCIE1A, TICIE1, TOIE2, OCIE2
	
}TIMSK_REGISTER;

/*********************************************************************
	TIFR register bits -> Timer/Counter Interrupt Flag Register Bits
**********************************************************************/
typedef enum
{
	TOV0, OCF0, TOV1, OCF1B, OCF1A, ICF1, TOV2, OCF2
	
}TIFR_REGISTER;

/*************************************************************
	MCUCR register bits –> MCU Control Register Bits
*************************************************************/
typedef enum
{
	ISC00, ISC01, ISC10, ISC11, SM0, SM1, SM2, SE
	
}MCUCR_REGISTER;

/*****************************************************************
	MCUCSR register bits –> MCU Control and Status Register Bits
******************************************************************/
typedef enum
{
	PORF, EXTRF, BORF, WDRF, JTRF , ISC2=6, JTD
	
}MCUCSR_REGISTER;

/*****************************************************************
	TCCR0 register bits -> Timer/Counter0 Control Register Bits
******************************************************************/
typedef enum
{
	CS00, CS01, CS02, WGM01, COM00, COM01, WGM00, FOC0
	
}TCCR0_REGISTER;

/********************************************************************
	TCCR1A register bits -> Timer/Counter1 Control Register A Bits
*********************************************************************/ 
typedef enum
{
	WGM10, WGM11, FOC1B, FOC1A, COM1B0, COM1B1, COM1A0, COM1A1
	
}TCCR1A_REGISTER;

/*******************************************************************
	TCCR1B register bits -> Timer/Counter1 Control Register B Bits
********************************************************************/
typedef enum
{
	CS10, CS11, CS12, WGM12, WGM13, ICES1=6, ICNC1
	
}TCCR1B_REGISTER;

/******************************************************************
	TCCR2 register bits -> Timer/Counter2 Control Register Bits
*******************************************************************/
typedef enum
{
	CS20, CS21,	CS22, WGM21, COM20, COM21, WGM20, FOC2
	
}TCCR2_REGISTER;

/***************************************************************
	 SFIOR register bits –> Special Function I/O Register Bits
****************************************************************/
typedef enum
{
	PSR10, PSR2, PUD, ACME, ADTS0=5, ADTS1, ADTS2
	
}SFIOR_REGISTER;

/**************************************************************************************************************************************************
																AVR GENERAL REGISTERS
 *************************************************************************************************************************************************/

/******************** SREG – AVR Status Register Dereference by its location address ***********************************/
#define SREG		*((volatile uint8*) 0x5F)

/******************* SFIOR – Special Function I/O Register Dereference by its location address **************************/
#define SFIOR		*((volatile uint8*) 0x50)

/*************************************************************************************************************************************************
																		DIO 
 *************************************************************************************************************************************************/

/***************************** PORT D Registers Dereference by its location address ***************************************/
#define PORTA		*((volatile uint8*) 0x3B)		// dereference PORTA register -> Data register (The Port Output Register)
#define DDRA		*((volatile uint8*) 0x3A)		// dereference DDRA register -> Control/Configuration register (The Data Direction Register)
#define PINA		*((volatile uint8*) 0x39)		// dereference PINA register -> Status register (The Port Input Register)

/***************************** PORT D Registers Dereference by its location address ****************************************/
#define PORTB		*((volatile uint8*) 0x38)		// dereference PORTB register -> Data register (The Port Output Register)
#define DDRB		*((volatile uint8*) 0x37)		// dereference DDRB register -> Control/Configuration register (The Data Direction Register)
#define PINB		*((volatile uint8*) 0x36)		// dereference PINB register -> Status register (The Port Input Register)

/***************************** PORT D Registers Dereference by its location address ****************************************/
#define PORTC		*((volatile uint8*) 0x35)		// dereference PORTC register -> Data register (The Port Output Register)
#define DDRC		*((volatile uint8*) 0x34)		// dereference DDRC register -> Control/Configuration register (The Data Direction Register)
#define PINC		*((volatile uint8*) 0x33)		// dereference PINC register -> Status register (The Port Input Register)

/***************************** PORT D Registers Dereference by its location address ****************************************/
#define PORTD		*((volatile uint8*) 0x32)		// dereference PORTD register -> Data register (The Port Output Register)
#define DDRD		*((volatile uint8*) 0x31)		// dereference DDRD register -> Control/Configuration register (The Data Direction Register)
#define PIND		*((volatile uint8*) 0x30)		// dereference PIND register -> Status register (The Port Input Register)

/*************************************************************************************************************************************************
																	TIMERS
 *************************************************************************************************************************************************/

/***************************** TIMER 0 (8-bits) Registers Dereference by its location address ****************************/
#define TCCR0		*((volatile uint8*) 0x53)		// dereference TCCR0 register Timer/Counter0 Control Register
#define TCNT0		*((volatile uint8*) 0x52)		// dereference TCNT0 register Timer/Counter0 Register
#define OCR0		*((volatile uint8*) 0x5C)		// dereference OCR0 register Timer/Counter0 Output Compare Register

/*************************** TIMER 1 (16-bits) Registers Dereference by its location address ****************************/
#define TCCR1A		*((volatile uint8*) 0x4F)		// dereference TCCR1A -> Timer/Counter1 Control Register A
#define TCCR1B		*((volatile uint8*) 0x4E)		// dereference TCCR1B -> Timer/Counter1 Control Register B

#define TCNT1H		*((volatile uint8*) 0x4D)		// dereference TCNT1H -> Timer/Counter1 Register High Byte
#define TCNT1L		*((volatile uint8*) 0x4C)		// dereference TCNT1L -> Timer/Counter1 Register Low Byte

#define OCR1AH		*((volatile uint8*) 0x4B)		// dereference OCR1AH -> Timer/Counter1 – Output Compare Register A High Byte
#define OCR1AL		*((volatile uint8*) 0x4A)		// dereference OCR1AL -> Timer/Counter1 – Output Compare Register A Low Byte 

#define OCR1BH		*((volatile uint8*) 0x49)		// dereference OCR1BH -> Timer/Counter1 – Output Compare Register B High Byte
#define OCR1BL		*((volatile uint8*) 0x48)		// dereference OCR1BL -> Timer/Counter1 – Output Compare Register B Low Byte

#define ICR1H		*((volatile uint8*) 0x47)		// dereference ICR1H ->	Timer/Counter1 – Input Capture Register High Byte
#define ICR1L		*((volatile uint8*) 0x46)		// dereference ICR1L -> Timer/Counter1 – Input Capture Register Low Byte

/***************************** TIMER 2 (8-bits) Registers Dereference by its location address ****************************/
#define TCCR2		*((volatile uint8*) 0x45)		// dereference TCCR2 register Timer/Counter2 Control Register
#define TCNT2		*((volatile uint8*) 0x44)		// dereference TCNT2 register Timer/Counter2 Register
#define OCR2		*((volatile uint8*) 0x43)		// dereference OCR2 register Timer/Counter2 Output Compare Register

/******************* TIMSK – Timer/Counter Interrupt Mask Register Dereference by its location address *******************/
#define TIMSK		*((volatile uint8*) 0x59)		

/******************* TIFR – Timer/Counter Interrupt Flag Register Dereference by its location address ********************/
#define TIFR		*((volatile uint8*) 0x58)	


/*************************************************************************************************************************************************
																EXTERNAL INTERRUPTS
 *************************************************************************************************************************************************/

/******************** MCUCR – MCU Control Register Dereference by its location address **********************************/
#define MCUCR		*((volatile uint8*) 0x55)

/******************** MCUCSR – MCU Control and Status Register Dereference by its location address **********************/
#define MCUCSR		*((volatile uint8*) 0x54)

/******************** GICR – General Interrupt Control Register Dereference by its location address *********************/
#define GICR		*((volatile uint8*) 0x5B)		

/******************** GIFR – General Interrupt Flag Register Dereference by its location address ************************/
#define GIFR		*((volatile uint8*) 0x5A)	
	

#endif /* REGISTERS_H_ */