 /* ---------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<EXTERNAL_INTERRUPT.H>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <HEADER FILE FOR AVR EXTERNAL INTERRUPTS>

-------------------------------------------------------------------------------------------------------------------------------------------------*/
/*************************************************************************************************************************************************
 * 															HEADER FILE GAURD	
 *************************************************************************************************************************************************/
#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
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
	[Enumeration Name]: EN_EXT_INT_ID_t
	[Enumeration Description]: This enumeration for External Interrupt IDs
	[Enumeration Members]:
		1. EXT_INT0 -> 0
		2. EXT_INT1 -> 1
		3. EXT_INT2 -> 2
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	EXT_INT0, EXT_INT1, EXT_INT2
}EN_EXT_INT_ID_t;
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_EXT_INT_SENSE_CONTROL_t
	[Enumeration Description]: This enumeration for External Interrupt Sense Control
	[Enumeration Members]:
		1. LOW_LEVEL -> 0
		2. ANY_LOGICAL_CHANGE -> 1
		3. FALLING_EDGE -> 2
		4. RISING_EDGE -> 3		
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	LOW_LEVEL, ANY_LOGICAL_CHANGE, FALLING_EDGE, RISING_EDGE
}EN_EXT_INT_SENSE_CONTROL_t;
/*-------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_EXT_INT_configurationError_t
	[Enumeration Description]: This enumeration for external interrupt configuration errors
	[Enumeration Members]:
		1. EXT_INT_OK -> 0
		2. EXT_INT_INVALID_ID -> 1 
		3. EXT_INT_INVALID_SENSE_CONTROL -> 2
-------------------------------------------------------------------------------------------------------------*/
typedef enum 
{
	EXT_INT_OK, EXT_INT_INVALID_ID, EXT_INT_INVALID_SENSE_CONTROL
}EN_EXT_INT_configurationError_t;
/**********************************************************************************************************************************************
 * 															STRUCTURES
 **********************************************************************************************************************************************/
/*-------------------------------------------------------------------------------------------------------------
	[Structure Name]: ST_EXTERNAL_INTERRUPT_Configuration_t
	[Structure Description]: This structure for maintaining external interrupt Configurations.
	[Structure Members]:
		1. ID ENUM from EN_EXT_INT_ID_t enumeration type to store External Interrupt ID.
		2. EXT_INT_SENSE_CONTROL ENUM from EN_EXT_INT_SENSE_CONTROL_t enumeration type to store External Interrupt Sense Control.
-------------------------------------------------------------------------------------------------------------*/
typedef struct
{
	EN_EXT_INT_ID_t EXT_INT_ID;
	EN_EXT_INT_SENSE_CONTROL_t EXT_INT_SENSE_CONTROL;
}ST_EXTERNAL_INTERRUPT_Configuration_t;
/*********************************************************************************************************************************************
 * 											FUNCTIONS PROTOTYPES
 *********************************************************************************************************************************************/
/*------------------------------------------------------------------------------------------------------------
	[Function Name]: EXT_INT_init
	[Description]:	 This function is responsible for initialization of External Interrupt by its configurations that 
					 given to function 
	[Arguments]
	[in]:			 EXT_INT_configPtr Pointer to structure from ST_EXTERNAL_INTERRUPT_Configuration_t structure type.
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_EXT_INT_configurationError_t enum type
-------------------------------------------------------------------------------------------------------------*/
EN_EXT_INT_configurationError_t EXT_INT_init(ST_EXTERNAL_INTERRUPT_Configuration_t *EXT_INT_configPtr);

/*------------------------------------------------------------------------------------------------------------
	[Function Name]: EXT_INT_setCallBack
	[Description]:	 This function is responsible for call the passed function by External Interrupt Service Request
	[Arguments]
	[in1]:			 EXT_INT_ID of the Timer from EN_EXT_INT_ID_t enum type.
	[in]:			 func_ptr Pointer to Function that 'll be called back by EXTERNAL INTERRUPT ISR
	[out]:			 None
	[Return]:		 Enumeration member of configuration errors from EN_EXT_INT_configurationError_t enum type
-------------------------------------------------------------------------------------------------------------*/
EN_EXT_INT_configurationError_t EXT_INT_setCallBack(EN_EXT_INT_ID_t EXT_INT_ID,void(*func_ptr)(void));

#endif /* EXTERNAL_INTERRUPT_H_ */