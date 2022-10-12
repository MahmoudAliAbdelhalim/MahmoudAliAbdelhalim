/* ----------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<TIMER.H>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <HEADER FILE FOR AVR-ATMEGA32 TIMER DRIVER >

-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*************************************************************************************************************************************************
 * 															HEADER FILE GAURD	
 *************************************************************************************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_
 /************************************************************************************************************************************************
 * 																INCLUDES
 *************************************************************************************************************************************************/
#include "../../Utilities/std_types.h"
#include "../../Utilities/common_macros.h"
#include "../../Utilities/micro_config.h"
//#include "../../Utilities/registers.h"
//#include "../../Utilities/interrupts.h"
/*************************************************************************************************************************************************
 * 															 ENUMERATIONS
 *************************************************************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_TIMER_configurationError_t
	[Enumeration Description]: This enumeration for timer configuration errors
	[Enumeration Members]:
		1. TIMER_OK -> 0
		2. TIMER_INVALID -> 1 
		3. TIMER_PRESCALER_INVALID -> 2
		4. TIMER_MODE_INVALID -> 3
		5. WRONG_INIT_VALUE -> 4
		6. WRONG_COMPARE_VALUE -> 5
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	TIMER_OK, TIMER_ID_INVALID, TIMER_PRESCALER_INVALID, TIMER_MODE_INVALID, WRONG_INIT_VALUE, WRONG_COMPARE_VALUE
}EN_TIMER_configurationError_t;
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_TIMER_ID_t
	[Enumeration Description]: This enumeration for Timer IDs
	[Enumeration Members]:
		1. TIMER_0 -> 0
		2. TIMER_1 -> 1
		3. TIMER_2 -> 2
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	TIMER_0,TIMER_1,TIMER_2
}EN_TIMER_ID_t;
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_TIMER_MODE_t
	[Enumeration Description]: This enumeration for Timer Modes
	[Enumeration Members]:
		1. OVF -> 0
		2. CTC -> 1
		3. PWM -> 2
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	OVF,CTC,PWM
}EN_TIMER_MODE_t;
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_TIMER_PRESCALER_t
	[Enumeration Description]: This enumeration for Timer Prescalers
	[Enumeration Members]:
		1. NO_CLOCK -> 0
		2. F_CPU_CLOCK -> 1
		3. F_CPU_8 -> 2
		4. F_CPU_64 -> 3
		5. F_CPU_256 -> 4
		6. F_CPU_1024 -> 5
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}EN_TIMER_PRESCALER_t;

/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_PWM_COMPARE_OUTPUT_MODE_t
	[Enumeration Description]: This enumeration for PWM Compare Output Modes
	[Enumeration Members]:
		1. NON_INVERTING_MODE -> 2
		2. INVERTING_MODE -> 3
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	NON_INVERTING_MODE = 2 , INVERTING_MODE = 3
}EN_PWM_COMPARE_OUTPUT_MODE_t;
/**********************************************************************************************************************************************
 * 															DEFINITIONS
 **********************************************************************************************************************************************/
#define MIN_INIT_VALUE	0
#define MIN_COMPARE_VALUE 0

#define MAX_TIMER0_INIT_VALUE	255
#define MAX_TIMER1_INIT_VALUE	65535
#define MAX_TIMER2_INIT_VALUE	255

#define MAX_TIMER0_COMPARE_VALUE	255
#define MAX_TIMER1_COMPARE_VALUE	65535
#define MAX_TIMER2_COMPARE_VALUE	255
/**********************************************************************************************************************************************
 * 															STRUCTURES
 **********************************************************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------
	[Structure Name]: ST_TIMER_Configuration_t
	[Structure Description]: This structure for maintaining Timer Configurations.
	[Structure Members]:
		1. TIMER_ID ENUM from EN_TIMER_ID_t enumeration type to store Timer ID
		2. TIMER_PRESCALER ENUM from EN_TIMER_PRESCALER_t enumeration type to store Timer Prescaler 
		3. variable from 16-bits unsigned integer to store the Timer initial value
		4. TIMER_MODE ENUM from EN_TIMER_MODE_t enumeration type to store Timer Mode
		5. variable from 16-bits unsigned integer to store the Timer Compare value
-------------------------------------------------------------------------------------------------------------*/
typedef struct
{
	EN_TIMER_ID_t TIMER_ID;
	EN_TIMER_PRESCALER_t TIMER_PRESCALER;
	uint16_t TIMER_INIT_VALUE;
	EN_TIMER_MODE_t TIMER_MODE;
	uint16_t TIMER_COMPARE_VALUE;
}ST_TIMER_Configuration_t;

/**********************************************************************************************************
 * 											FUNCTIONS PROTOTYPES
 **********************************************************************************************************/
/*------------------------------------------------------------------------------------------------------------
	[Function Name]: TIMER_init
	[Description]:	 This function is responsible for initialization of Timer by its configurations that 
					 given to function 
	[Arguments]
	[in]:			 TIMER_configPtr Pointer to structure from ST_TIMER_Configuration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_TIMER_configurationError_t enum type 
-------------------------------------------------------------------------------------------------------------*/
EN_TIMER_configurationError_t TIMER_init(ST_TIMER_Configuration_t *TIMER_configPtr);

/*------------------------------------------------------------------------------------------------------------
	[Function Name]: TIMER_stopClock
	[Description]:	 This function is responsible for stop the clock of the Timer by its ID
	[Arguments]
	[in]:			 TIMER_ID of the Timer from EN_TIMER_ID_t enum type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_TIMER_configurationError_t enum type 
-------------------------------------------------------------------------------------------------------------*/
EN_TIMER_configurationError_t TIMER_stopClock(EN_TIMER_ID_t TIMER_ID);

/*------------------------------------------------------------------------------------------------------------
	[Function Name]: TIMER_DeInit
	[Description]:	 This function is responsible for De-initialization of Timer by its ID			 
	[Arguments]
	[in]:			 TIMER_ID of the Timer from EN_TIMER_ID_t enum type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_TIMER_configurationError_t enum type 
-------------------------------------------------------------------------------------------------------------*/
EN_TIMER_configurationError_t TIMER_DeInit(EN_TIMER_ID_t TIMER_ID);

/*------------------------------------------------------------------------------------------------------------
	[Function Name]: TIMER_setCallBack
	[Description]:	 This function is responsible for call the passed function by Timer interrupt service request
	[Arguments]
	[in1]:			 TIMER_ID of the Timer from EN_TIMER_ID_t enum type.
	[in]:			 func_ptr Pointer to Function that 'll be called back by TIMER ISR
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_TIMER_configurationError_t enum type 
-------------------------------------------------------------------------------------------------------------*/
EN_TIMER_configurationError_t TIMER_setCallBack(EN_TIMER_ID_t TIMER_ID,void(*func_ptr)(void));

#endif /* TIMER_H_ */