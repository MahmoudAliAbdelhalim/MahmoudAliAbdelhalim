 /* ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<TIMER.C>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <C FILE FOR AVR-ATMEGA32 TIMER DRIVER >

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 /*******************************************************************************************************************************************************************************
 * 																				INCLUDES
 ********************************************************************************************************************************************************************************/
#include "timer.h"
/********************************************************************************************************************************************************************************
 *                      													Global Variables
 *******************************************************************************************************************************************************************************/
/* Global variables to hold the address of the call back function in the application */
static void (*g_Timer0_callBackPtr)(void) = NULL_PTR;
static void (*g_Timer1_callBackPtr)(void) = NULL_PTR;
static void (*g_Timer2_callBackPtr)(void) = NULL_PTR;

/******************************************************************************************************************************************************************************
 *                      												Interrupt Service Routines
 ******************************************************************************************************************************************************************************/

/************************************ TIMER 0 ************************************************/
ISR(TIMER0_OVF_vect)
{
	if(g_Timer0_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_Timer0_callBackPtr)();
	}
}
ISR(TIMER0_COMP_vect)
{
	if(g_Timer0_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_Timer0_callBackPtr)();
	}
}

/************************************ TIMER 1 ************************************************/
ISR(TIMER1_OVF_vect)
{
	if(g_Timer1_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_Timer1_callBackPtr)();
	}
}

ISR(TIMER1_COMPA_vect)
{
	if(g_Timer1_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_Timer1_callBackPtr)();
	}
}

/************************************ TIMER 2 ************************************************/
ISR(TIMER2_OVF_vect)
{
	if(g_Timer2_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_Timer2_callBackPtr)();
	}
}

ISR(TIMER2_COMP_vect)
{
	if(g_Timer2_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_Timer2_callBackPtr)();
	}
}
/*******************************************************************************************************************************************************************************
 * 																				Functions Definition
 *******************************************************************************************************************************************************************************/
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: TIMER_init
	[Description]:	 This function is responsible for initialization of Timer by its configurations that are
					 given to function 
	[Arguments]
	[in]:			 TIMER_configPtr Pointer to structure from ST_TIMER_Configuration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_TIMER_configurationError_t enum type 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_TIMER_configurationError_t TIMER_init(ST_TIMER_Configuration_t *TIMER_configPtr)
{
	/*********** Test 1 for checking the given timer id if it exists between EN_TIMER_ID_t enum members (0 -> 2) **************/
	switch(TIMER_configPtr->TIMER_ID)
	{
		/************************************************************** TIMER 0 *********************************************************************/		
		case TIMER_0:
			/*********** Test 2 for checking the given prescaler number if it exists between EN_TIMER_PRESCALER_t enum members **************/
			switch(TIMER_configPtr->TIMER_PRESCALER)
			{
				case NO_CLOCK:
				case F_CPU_CLOCK:
				case F_CPU_8:
				case F_CPU_64:
				case F_CPU_256:
				case F_CPU_1024:
					// Set Timer/Counter 0 Prescaler Selection Bits CS0:2 at Timer/Counter0 Control Register TCCR0
					TCCR0 = (TCCR0 & 0xF8) | (TIMER_configPtr->TIMER_PRESCALER);
					break;
			
				default:
					return TIMER_PRESCALER_INVALID;
			}
			/*********** Test 3 for checking the given initial value if it exists between MIN_INIT_VALUE & MAX_TIMER0_INIT_VALUE (0 -> 255) **************/
			if( ((TIMER_configPtr->TIMER_INIT_VALUE) >=  MIN_INIT_VALUE) && ((TIMER_configPtr->TIMER_INIT_VALUE) <=  MAX_TIMER0_INIT_VALUE) )
			{
				// Set Timer/Counter 0 start Value at TCNT0 Register
				TCNT0 =  TIMER_configPtr->TIMER_INIT_VALUE;			
			}
			else
			{
				return WRONG_INIT_VALUE;
			}
			/*********** Test 4 for checking the given timer mode if it exists between EN_TIMER_MODE_t enum members **************/
			switch(TIMER_configPtr->TIMER_MODE)
			{
				/*************************************	TIMER MODE -> OVF	********************************************/
				case OVF :
					// Non PWM, Set FOC0=1 in case of OVF Mode at Timer/Counter0 Control Register TCCR0
					SET_BIT(TCCR0,FOC0);
					// Normal Mode (overflow mode) WGM00=0 WGM01=0
					CLEAR_BIT(TCCR0,WGM00);
					CLEAR_BIT(TCCR0,WGM01);
					// Timer0 OVF Interrupt Enable
					SET_BIT(TIMSK,TOIE0);
					break;
				/*************************************	TIMER MODE -> CTC	********************************************/
				case CTC :
					//Non PWM, Set FOC0=1 in case of CTC Mode at Timer/Counter0 Control Register TCCR0
					SET_BIT(TCCR0,FOC0);
					// Compare Mode WGM00=0 WGM01=1
					CLEAR_BIT(TCCR0,WGM00);
					SET_BIT(TCCR0,WGM01);
					// Enable Timer0 compare match interrupt
					SET_BIT(TIMSK,OCIE0);
					/*********** Test 5 for checking the given compare value if it exists between MIN_COMPARE_VALUE & MAX_TIMER0_COMPARE_VALUE (0 -> 255) **************/
					if( ((TIMER_configPtr->TIMER_COMPARE_VALUE) >=  MIN_COMPARE_VALUE) && ((TIMER_configPtr->TIMER_INIT_VALUE) <=  MAX_TIMER0_COMPARE_VALUE) )
					{
						// Set Timer/Counter 0 duty cycle Value at OCR0 Register
						OCR0 = TIMER_configPtr->TIMER_COMPARE_VALUE;
					}
					else
					{
						return WRONG_COMPARE_VALUE;
					}
					break;
				/*************************************	TIMER MODE -> PWM	********************************************/
				case  PWM :
					// Set FOC0=0 in case of PWM Mode at Timer/Counter0 Control Register TCCR0
					CLEAR_BIT(TCCR0,FOC0);
					// Fast PWM Mode WGM00=1 WGM01=1
					SET_BIT(TCCR0,WGM00);
					SET_BIT(TCCR0,WGM01);
					// Compare Match Output Mode, Fast PWM Mode COM00=1 COM01=1
					TCCR0 = (TCCR0 & 0xCF) | (NON_INVERTING_MODE<<4);
					/*********** Test 5 for checking the given compare value if it exists between MIN_COMPARE_VALUE & MAX_TIMER0_COMPARE_VALUE (0 -> 255) **************/
					if( ((TIMER_configPtr->TIMER_COMPARE_VALUE) >=  MIN_COMPARE_VALUE) && ((TIMER_configPtr->TIMER_INIT_VALUE) <=  MAX_TIMER0_COMPARE_VALUE) )
					{
						// Set Timer/Counter 0 duty cycle Value at OCR0 Register
						OCR0 = TIMER_configPtr->TIMER_COMPARE_VALUE;
					}
					else
					{
						return WRONG_COMPARE_VALUE;
					}
					break;
					/*************************************	TIMER MODE INVALID	********************************************/
					default:
						return TIMER_MODE_INVALID;
			}
			return TIMER_OK;
		/************************************************************** TIMER 1 *********************************************************************/
		case TIMER_1:
				/*********** Test 2 for checking the given prescaler number if it exists between EN_TIMER_PRESCALER_t enum members **************/
				switch(TIMER_configPtr->TIMER_PRESCALER)
				{
					case NO_CLOCK:
					case F_CPU_CLOCK:
					case F_CPU_8:
					case F_CPU_64:
					case F_CPU_256:
					case F_CPU_1024:
					// Set Timer/Counter 1 Prescaler Selection Bits CS0:2 at Timer/Counter1 Control Register TCCR1B
					TCCR1B = (TCCR1B & 0xF8) | (TIMER_configPtr->TIMER_PRESCALER);
					break;
					
					default:
					return TIMER_PRESCALER_INVALID;
				}
				/*********** Test 3 for checking the given initial value if it exists between MIN_INIT_VALUE & MAX_TIMER1_INIT_VALUE (0 -> 65535) **************/
				if( ((TIMER_configPtr->TIMER_INIT_VALUE) >=  MIN_INIT_VALUE) && ((TIMER_configPtr->TIMER_INIT_VALUE) <=  MAX_TIMER1_INIT_VALUE) )
				{
					// Set Timer/Counter 1 start Value at TCNT1 Register
					TCNT1L =  (TCCR1B & 0xF0) | (0x0F & TIMER_configPtr->TIMER_INIT_VALUE);
					TCNT1H =  (TCCR1B & 0x0F) |	(0xF0 & TIMER_configPtr->TIMER_INIT_VALUE);
				}
				else
				{
					return WRONG_INIT_VALUE;
				}
				/*********** Test 4 for checking the given timer mode if it exists between EN_TIMER_MODE_t enum members **************/
				switch(TIMER_configPtr->TIMER_MODE)
				{
					/*************************************	TIMER MODE -> OVF	********************************************/
					case OVF :
						// Non PWM, Set FOC1A=1 FOC1B=1 in case of OVF Mode at Timer/Counter1 Control Register TCCR1A
						SET_BIT(TCCR1A,FOC1A);
						SET_BIT(TCCR1A,FOC1B);
						// Normal Mode (overflow mode) WGM10=0 WGM11=0 WGM12=0 WGM13=0
						CLEAR_BIT(TCCR1A,WGM10);
						CLEAR_BIT(TCCR1A,WGM11);
						CLEAR_BIT(TCCR1A,WGM12);
						CLEAR_BIT(TCCR1A,WGM13);
						// Timer1 OVF Interrupt Enable
						SET_BIT(TIMSK,TOIE1);
						break;
					/*************************************	TIMER MODE -> CTC	********************************************/
					case CTC :
						// Non PWM, Set FOC1A=1 FOC1B=1 in case of CTC Mode at Timer/Counter1 Control Register TCCR1A
						SET_BIT(TCCR1A,FOC1A);
						SET_BIT(TCCR1A,FOC1B);
						// Compare Mode WGM10=0 WGM11=0 WGM12=1 WGM13=0
						CLEAR_BIT(TCCR1A,WGM10);
						CLEAR_BIT(TCCR1A,WGM11);
						SET_BIT(TCCR1A,WGM12);
						CLEAR_BIT(TCCR1A,WGM13);
						// Enable Timer1 compare match interrupt
						SET_BIT(TIMSK,OCIE1A);
						/*********** Test 5 for checking the given compare value if it exists between MIN_COMPARE_VALUE & MAX_TIMER1_COMPARE_VALUE (0 -> 65535) **************/
						if( ((TIMER_configPtr->TIMER_COMPARE_VALUE) >=  MIN_COMPARE_VALUE) && ((TIMER_configPtr->TIMER_INIT_VALUE) <=  MAX_TIMER1_COMPARE_VALUE) )
						{
							// Set Timer/Counter 1 Compare Value at OCR1A Register
							OCR1AL =  (TCCR1B & 0xF0) | (0x0F & TIMER_configPtr->TIMER_COMPARE_VALUE);
							OCR1AH =  (TCCR1B & 0x0F) |	(0xF0 & TIMER_configPtr->TIMER_COMPARE_VALUE);
						}
						else
						{
							return WRONG_COMPARE_VALUE;
						}
						break;
					/*************************************	TIMER MODE -> PWM	********************************************/
					case  PWM :
						// Set FOC1A=0 in case of PWM Mode at Timer/Counter1 Control Register TCCR1A
						CLEAR_BIT(TCCR1A,FOC1A);
						// Fast PWM Mode WGM10=1 WGM11=1 WGM12=1 WGM13=1
						SET_BIT(TCCR1A,WGM10);
						SET_BIT(TCCR1A,WGM11);
						SET_BIT(TCCR1A,WGM12);
						SET_BIT(TCCR1A,WGM13);
						// Compare Match Output Mode, Fast PWM Mode COM1A1=1 COM1A0=0
						TCCR1A = (TCCR1A & 0x3F) | (NON_INVERTING_MODE<<6);
						/*********** Test 5 for checking the given compare value if it exists between MIN_COMPARE_VALUE & MAX_TIMER1_COMPARE_VALUE (0 -> 65535) **************/
						if( ((TIMER_configPtr->TIMER_COMPARE_VALUE) >=  MIN_COMPARE_VALUE) && ((TIMER_configPtr->TIMER_INIT_VALUE) <=  MAX_TIMER1_COMPARE_VALUE) )
						{
							// Set Timer/Counter 1 duty cycle Value at OCR1A Register
							OCR1A = TIMER_configPtr->TIMER_COMPARE_VALUE;
						}
						else
						{
							return WRONG_COMPARE_VALUE;
						}
						break;
					/*************************************	TIMER MODE INVALID	********************************************/
					default:
						return TIMER_MODE_INVALID;
				}
				return TIMER_OK;
			/************************************************************** TIMER 2 *********************************************************************/
			case TIMER_2:
					/*********** Test 2 for checking the given prescaler number if it exists between EN_TIMER_PRESCALER_t enum members **************/
					switch(TIMER_configPtr->TIMER_PRESCALER)
					{
						case NO_CLOCK:
						case F_CPU_CLOCK:
						case F_CPU_8:
						case F_CPU_64:
						case F_CPU_256:
						case F_CPU_1024:
							// Set Timer/Counter 2 Prescaler Selection Bits CS0:2 at Timer/Counter 2 Control Register TCCR2
							TCCR2 = (TCCR2 & 0xF8) | (TIMER_configPtr->TIMER_PRESCALER);
						break;
						
						default:
						return TIMER_PRESCALER_INVALID;
					}
					/*********** Test 3 for checking the given initial value if it exists between MIN_INIT_VALUE & MAX_TIMER2_INIT_VALUE (0 -> 255) **************/
					if( ((TIMER_configPtr->TIMER_INIT_VALUE) >=  MIN_INIT_VALUE) && ((TIMER_configPtr->TIMER_INIT_VALUE) <=  MAX_TIMER2_INIT_VALUE) )
					{
						// Set Timer/Counter 2 start Value at TCNT2 Register
						TCNT2 =  TIMER_configPtr->TIMER_INIT_VALUE;
					}
					else
					{
						return WRONG_INIT_VALUE;
					}
					/*********** Test 4 for checking the given timer mode if it exists between EN_TIMER_MODE_t enum members **************/
					switch(TIMER_configPtr->TIMER_MODE)
					{
						/*************************************	TIMER MODE -> OVF	********************************************/						
						case OVF :
							// Non PWM, Set FOC2=1 in case of OVF Mode at Timer/Counter2 Control Register TCCR2
							SET_BIT(TCCR2,FOC2);
							// Normal Mode (overflow mode) WGM20=0 WGM21=0
							CLEAR_BIT(TCCR2,WGM20);
							CLEAR_BIT(TCCR2,WGM21);
							// Timer2 OVF Interrupt Enable
							SET_BIT(TIMSK,TOIE2);
							break;
						/*************************************	TIMER MODE -> CTC	********************************************/
						case CTC :
							//Non PWM, Set FOC2=1 in case of CTC Mode at Timer/Counter2 Control Register TCCR2
							SET_BIT(TCCR2,FOC2);
							// Compare Mode WGM20=0 WGM21=1
							CLEAR_BIT(TCCR2,WGM20);
							SET_BIT(TCCR0,WGM21);
							// Enable Timer2 compare match interrupt
							SET_BIT(TIMSK,OCIE2);
							/*********** Test 5 for checking the given compare value if it exists between MIN_COMPARE_VALUE & MAX_TIMER2_COMPARE_VALUE (0 -> 255) **************/
							if( ((TIMER_configPtr->TIMER_COMPARE_VALUE) >=  MIN_COMPARE_VALUE) && ((TIMER_configPtr->TIMER_INIT_VALUE) <=  MAX_TIMER1_COMPARE_VALUE) )
							{
								// Set Timer/Counter 2 compare cycle Value at OCR2 Register
								OCR2 = TIMER_configPtr->TIMER_COMPARE_VALUE;
							}
							else
							{
								return WRONG_COMPARE_VALUE;
							}							
							break;
						/*************************************	TIMER MODE -> PWM	********************************************/
						case  PWM :
							// Set FOC2=0 in case of PWM Mode at Timer/Counter2 Control Register TCCR2
							CLEAR_BIT(TCCR2,FOC2);
							// Fast PWM Mode WGM20=1 WGM21=1
							SET_BIT(TCCR0,WGM20);
							SET_BIT(TCCR0,WGM21);
							// Compare Match Output Mode, Fast PWM Mode COM20=1 COM21=1
							TCCR2 = (TCCR2 & 0xCF) | (NON_INVERTING_MODE<<4);
							/*********** Test 5 for checking the given compare value if it exists between MIN_COMPARE_VALUE & MAX_TIMER2_COMPARE_VALUE (0 -> 255) **************/
							if( ((TIMER_configPtr->TIMER_COMPARE_VALUE) >=  MIN_COMPARE_VALUE) && ((TIMER_configPtr->TIMER_INIT_VALUE) <=  MAX_TIMER1_COMPARE_VALUE) )
							{
								// Set Timer/Counter 2 duty cycle Value at OCR2 Register
								OCR2 = TIMER_configPtr->TIMER_COMPARE_VALUE;
							}
							else
							{
								return WRONG_COMPARE_VALUE;
							}
							break;
						/*************************************	TIMER MODE INVALID	********************************************/				
						default:
							return TIMER_MODE_INVALID;
					}
					return TIMER_OK;
				/************************************************************** TIMER INVALID *********************************************************************/
				default:
					return TIMER_ID_INVALID;
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: TIMER_stopClock
	[Description]:	 This function is responsible for stop the Timer by clear clock bits of Timer Control 
					 Register by Timer ID
	[Arguments]
	[in]:			 TIMER_ID of the Timer from EN_TIMER_ID_t enum type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_TIMER_configurationError_t enum type 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_TIMER_configurationError_t TIMER_stopClock(EN_TIMER_ID_t TIMER_ID)
{
	/*********** Test 1 for checking the given timer id if it exists between EN_TIMER_ID_t enum members (0 -> 2) **************/	
	switch(TIMER_ID)
	{
		/*************************************	TIMER 0	********************************************/		
		case TIMER_0:
			/* To stop Timer/Counter 0 from generating clock, Set its Control Register TCCR0 to 0. */
			TCCR0 = TCCR0 & 0xF8;
			return TIMER_OK;
		/*************************************	TIMER 1	********************************************/	
		case TIMER_1:
			/* To stop Timer/Counter 1 from generating clock, Set its Control Register TCCR1A and
			 * TCCR1B to 0.
			 */
			TCCR1B = TCCR1B & 0xF8;
			return TIMER_OK;
		/*************************************	TIMER 2	********************************************/	
		case TIMER_2:
			/* To stop Timer/Counter 2 from generating clock, Set its Control Register TCCR2 to 0. */
			TCCR2 = TCCR2 & 0xF8;
			return TIMER_OK;
		/*************************************	TIMER INVALID	********************************************/	
		default:
			return TIMER_ID_INVALID;
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: TIMER_DeInit
	[Description]:	 This function is responsible for De-initialization of Timer Control Register by Timer ID
	[Arguments]
	[in]:			 TIMER_ID of the Timer from EN_TIMER_ID_t enum type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_TIMER_configurationError_t enum type 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_TIMER_configurationError_t TIMER_DeInit(EN_TIMER_ID_t TIMER_ID)
{
	/*********** Test 1 for checking the given timer id if it exists between EN_TIMER_ID_t enum members (0 -> 2) **************/
	switch(TIMER_ID)
	{
		/*************************************	TIMER 0	********************************************/
		case TIMER_0:
			/* To de_init Timer/Counter 0, Clear its Registers. */
			CLEAR_PORT(TCCR0);
			CLEAR_PORT(TCNT0);
			CLEAR_PORT(OCR0);
			CLEAR_PORT(TIMSK);
			return TIMER_OK;
		/*************************************	TIMER 1	********************************************/
		case TIMER_1:
			/* To de_init Timer/Counter 1, Clear its Registers. */
			CLEAR_PORT(TCCR1A);
			CLEAR_PORT(TCCR1B);
			CLEAR_PORT(TCNT1L);
			CLEAR_PORT(TCNT1H);
			CLEAR_PORT(OCR1AL);
			CLEAR_PORT(OCR1AH);
			CLEAR_PORT(OCR1BL);
			CLEAR_PORT(OCR1BH);
			CLEAR_PORT(TIMSK);
			return TIMER_OK;
		/*************************************	TIMER 2	********************************************/
		case TIMER_2:
			/* To de_init Timer/Counter 2, Clear its Registers. */
			CLEAR_PORT(TCCR2);
			CLEAR_PORT(TCNT2);
			CLEAR_PORT(OCR2);
			CLEAR_PORT(TIMSK);
		return TIMER_OK;
		/*************************************	TIMER INVALID	********************************************/
		default:
			return TIMER_ID_INVALID;
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: TIMER_setCallBack
	[Description]:	 This function is responsible for  set call back function for each timer by Timer ID
	[Arguments]
	[in1]:			 TIMER_ID of the Timer from EN_TIMER_ID_t enum type.
	[in]:			 func_ptr Pointer to Function that 'll be called back by TIMER ISR
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_TIMER_configurationError_t enum type 
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
EN_TIMER_configurationError_t TIMER_setCallBack(EN_TIMER_ID_t TIMER_ID,void(*func_ptr)(void))
{
	/*********** Test 1 for checking the given timer id if it exists between EN_TIMER_ID_t enum members (0 -> 2) **************/
	switch(TIMER_ID)
	{
		/*************************************	TIMER 0	********************************************/
		case TIMER_0:
			/* Save the address of the Call back function in a global variable */
			g_Timer0_callBackPtr = func_ptr;
			return TIMER_OK;
		/*************************************	TIMER 1	********************************************/
		case TIMER_1:
			/* Save the address of the Call back function in a global variable */
			return TIMER_OK;
		/*************************************	TIMER 2	********************************************/
		case TIMER_2:
			/* Save the address of the Call back function in a global variable */
			g_Timer2_callBackPtr = func_ptr;
			return TIMER_OK;
		/*************************************	TIMER INVALID	********************************************/
		default:
			return TIMER_ID_INVALID;
	}
}
