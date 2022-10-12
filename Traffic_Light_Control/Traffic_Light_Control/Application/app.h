/*------------------------------------------------------------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<APP.H>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <HEADER FILE FOR TRAFFIC_LIGHT_CONTROL APPLICATION>

------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef APP_H_
#define APP_H_
/***********************************************************************************************************************************************************
 * 																	INCLUDES
 ***********************************************************************************************************************************************************/
#include "../Utilities/micro_config.h"
#include <avr/interrupt.h>
#include <stdio.h>
#include "../ECUAL/LED_Module/led.h"
#include "../ECUAL/BUTTON_Module/button.h"
#include "../MCAL/TIMER_Driver/timer.h"
#include "../MCAL/EXTERNAL_INTERRUPT_Driver/external_interrupt.h"
/***********************************************************************************************************************************************************
 * 																	 ENUMERATIONS
 ***********************************************************************************************************************************************************/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_BUTTON_Status_t
	[Enumeration Description]: This enumeration for button status
	[Enumeration Members]:
		1. BUTTON_NOT_PRESSED -> 0
		2. BUTTON_PRESSED -> 1 
------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	BUTTON_NOT_PRESSED, BUTTON_PRESSED
}EN_BUTTON_Status_t;

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_LED_Status_t
	[Enumeration Description]: This enumeration for led status
	[Enumeration Members]:
		1. LED_OFF -> 0
		2. LED_ON -> 1 
------------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	LED_OFF, LED_ON
}EN_LED_Status_t;
/*------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Enumeration Name]: EN_TRAFFIC_States_t
	[Enumeration Description]: This enumeration for led status
	[Enumeration Members]:
		1. CARS_CROSS -> 0
		2. PEDESTRIAN_READY -> 1 
		3. PEDESTRIAN_CROSS -> 2
		4. CARS_READY -> 3
-------------------------------------------------------------------------------------------------------------*/
typedef enum
{
	CARS_CROSS, PEDESTRIAN_READY, PEDESTRIAN_CROSS, CARS_READY
}EN_TRAFFIC_States_t;

/************************************************************************************************************************************************************
 * 																		DEFINITIONS
 ************************************************************************************************************************************************************/
/* Ports and pins Definitions for the used application drivers */
#define PEDESTRIAN_BUTTON_PORT			PORTD_ID
#define PEDESTRIAN_BUTTON_PIN			PIN2_ID

#define CARS_GREEN_LED_PORT				PORTA_ID
#define CARS_GREEN_LED_PIN				PIN0_ID

#define CARS_YELLOW_LED_PORT			PORTA_ID
#define CARS_YELLOW_LED_PIN				PIN1_ID

#define CARS_RED_LED_PORT				PORTA_ID
#define CARS_RED_LED_PIN				PIN2_ID

#define PEDESTRIAN_GREEN_LED_PORT		PORTB_ID
#define PEDESTRIAN_GREEN_LED_PIN		PIN0_ID

#define PEDESTRIAN_YELLOW_LED_PORT		PORTB_ID
#define PEDESTRIAN_YELLOW_LED_PIN		PIN1_ID

#define PEDESTRIAN_RED_LED_PORT			PORTB_ID
#define PEDESTRIAN_RED_LED_PIN			PIN2_ID

#define FAILED	0
#define PASSED	1

/* Number of timer over flows per 5 seconds */
#define NUMBER_OF_OVERFLOWS_PER_5sec	20
/***********************************************************************************************************************************************************
 * 																	FUNCTIONS PROTOTYPES
 ***********************************************************************************************************************************************************/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: APP_init
	[Description]:	 This function is responsible for initialization of the application modules
	[in]:			 Void
	[out]:			 None
	[Return]:		 Void
------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void APP_init(void);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: APP_start
	[Description]:	 This function is responsible for start the application
	[in]:			 Void
	[out]:			 None
	[Return]:		 Void
------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void APP_start(void);

/*------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: TRAFFIC_timeCount
	[Description]:	 This function is responsible for counting 5 seconds and switching between traffic Status
	[in]:			 Void
	[out]:			 None
	[Return]:		 Void
------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void TRAFFIC_timeCount(void);
/*------------------------------------------------------------------------------------------------------------------------------------------------------------	
[Function Name]: PEDESTRIAN_buttonPress
	[Description]:	 This function is responsible for handling the pedestrian button press 
	[in]:			 Void
	[out]:			 None
	[Return]:		 Void
------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void PEDESTRIAN_buttonPress(void);

#endif /* APP_H_ */