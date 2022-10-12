/*------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: APP_start

	[FILE NAME]:	<APP.C>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <C FILE FOR TRAFFIC_LIGHT_CONTROL APPLICATION>

------------------------------------------------------------------------------------------------------------------------------------------------------------*/
 /***********************************************************************************************************************************************************
 * 																		INCLUDES
 ************************************************************************************************************************************************************/
#include "app.h"
 /***********************************************************************************************************************************************************
 * 																	GLOBAL VARIABLES
 ************************************************************************************************************************************************************/
 /* declare pedestrian button configuration structure with initialization parameters */
ST_BUTTON_Cofiguration_t PEDESTRIAN_BUTTON_Config = {PEDESTRIAN_BUTTON_PORT,PEDESTRIAN_BUTTON_PIN};
	
/* declare external interrupt configuration structure with initialization parameters */
ST_EXTERNAL_INTERRUPT_Configuration_t EXTERNAL_INTERRUPT_0_Config = {EXT_INT0,RISING_EDGE};
	
/* declare external interrupt configuration structure with initialization parameters */
ST_TIMER_Configuration_t TIMER_0_Config = {TIMER_0,F_CPU_1024,12,OVF,0};
	
 /* declare cars LEDs configuration structure with initialization parameters */	
ST_LED_Cofiguration_t CARS_GREEN_LED_Config = {CARS_GREEN_LED_PORT,CARS_GREEN_LED_PIN};
ST_LED_Cofiguration_t CARS_YELLOW_LED_Config = {CARS_YELLOW_LED_PORT,CARS_YELLOW_LED_PIN,};
ST_LED_Cofiguration_t CARS_RED_LED_Config = {CARS_RED_LED_PORT,CARS_RED_LED_PIN};

 /* declare pedestrian LEDs configuration structure with initialization parameters */	
ST_LED_Cofiguration_t PEDESTRIAN_GREEN_LED_Config = {PEDESTRIAN_GREEN_LED_PORT,PEDESTRIAN_GREEN_LED_PIN};
ST_LED_Cofiguration_t PEDESTRIAN_YELLOW_LED_Config = {PEDESTRIAN_YELLOW_LED_PORT,PEDESTRIAN_YELLOW_LED_PIN};
ST_LED_Cofiguration_t PEDESTRIAN_RED_LED_Config = {PEDESTRIAN_RED_LED_PORT,PEDESTRIAN_RED_LED_PIN};
/***********************************************************************************************************************************************************
 * 																	GLOBAL VARIABLES
 ***********************************************************************************************************************************************************/
uint8 g_buttonStatus;
uint8 g_tick = 0;
uint8 g_pressFlag = BUTTON_NOT_PRESSED;
uint8 trafficStatus = CARS_CROSS;

EN_BUTTON_configurationError_t button_error_state;
EN_LED_configurationError_t led_error_state;
EN_EXT_INT_configurationError_t ext_int_error_state;
EN_TIMER_configurationError_t timer_error_state;
 /***********************************************************************************************************************************************************
 * 															      FUNCTIONS DEFINITIONS
 ************************************************************************************************************************************************************/
/*------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: APP_start
	[Function Name]: APP_init
	[Description]:	 This function is responsible for initialization of the application modules
	[in]:			 Void
	[out]:			 None
	[Return]:		 Void
------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void APP_init(void)
{

	/************************************************  Pedestrian Button initialization ************************************************/
	button_error_state = BUTTON_init(&PEDESTRIAN_BUTTON_Config);
	/* 1. Test a button driver */
	if(button_error_state == BUTTON_INVALID_PIN)
	{
		printf("Please enter a valid button pin number!");
		return;
	}
	else if(button_error_state == BUTTON_INVALID_PORT)
	{
		printf("Please enter a valid button port number!");
		return;
	}
	/************************************************  External Interrupt 0 initialization ************************************************/
	ext_int_error_state = EXT_INT_init(&EXTERNAL_INTERRUPT_0_Config);
	/* 2. Test a external interrupt driver */	
	if(ext_int_error_state == EXT_INT_INVALID_ID)
	{
		printf("Please enter a valid external interrupt id!");
		return;
	}
	else if(ext_int_error_state == EXT_INT_INVALID_SENSE_CONTROL)
	{
		printf("Please enter a valid external interrupt sense control!");
		return;
	}
	/************************************************* Set PEDESTRIAN_buttonPress function to External Interrupt 0 ISR *************************************************/
	ext_int_error_state = EXT_INT_setCallBack(EXT_INT0,PEDESTRIAN_buttonPress);
	/* 2. Test a external interrupt driver */
	if(ext_int_error_state == EXT_INT_INVALID_ID)
	{
		printf("Please enter a valid external interrupt id!");
		return;
	}		
	
	/* Global Interrupts Enable Setting */
	sei();	
		
	/************************************************  Cars LEDs initialization ************************************************/
	/********** cars Green led initialization **********/
	led_error_state = LED_init(&CARS_GREEN_LED_Config);
	/* 3. Test a led driver */
	if(led_error_state == LED_INVALID_PIN)
	{
		printf("Please enter a valid cars Green led pin number!");
		return;
	}
	else if(led_error_state == LED_INVALID_PORT)
	{
		printf("Please enter a valid cars Green led port number!");
		return;
	}
	/********** cars yellow led initialization **********/
	led_error_state = LED_init(&CARS_YELLOW_LED_Config);
	/* 3. Test a led driver */
	if(led_error_state == LED_INVALID_PIN)
	{
		printf("Please enter a valid cars yellow led pin number!");
		return;
	}
	else if(led_error_state == LED_INVALID_PORT)
	{
		printf("Please enter a valid cars yellow led port number!");
		return;
	}
	/********** cars red led initialization **********/	
	LED_init(&CARS_RED_LED_Config);
	/* 3. Test a led driver */
	if(led_error_state == LED_INVALID_PIN)
	{
		printf("Please enter a valid cars red led pin number!");
		return;
	}
	else if(led_error_state == LED_INVALID_PORT)
	{
		printf("Please enter a valid cars red led port number!");
		return;
	}	
	/************************************************ Pedestrian LEDs initialization ************************************************/
	/********** pedestrians Green led initialization **********/
	LED_init(&PEDESTRIAN_GREEN_LED_Config);
	/* 3. Test a led driver */
	if(led_error_state == LED_INVALID_PIN)
	{
		printf("Please enter a valid pedestrians Green led pin number!");
		return;
	}
	else if(led_error_state == LED_INVALID_PORT)
	{
		printf("Please enter a valid pedestrians Green led port number!");
		return;
	}
	/********** pedestrians yellow led initialization **********/	
	LED_init(&PEDESTRIAN_YELLOW_LED_Config);
	/* 3. Test a led driver */
	if(led_error_state == LED_INVALID_PIN)
	{
		printf("Please enter a valid pedestrians yellow led pin number!");
		return;
	}
	else if(led_error_state == LED_INVALID_PORT)
	{
		printf("Please enter a valid pedestrians yellow led port number!");
		return;
	}
	/********** pedestrians red led initialization **********/	
	LED_init(&PEDESTRIAN_RED_LED_Config);
	/* 3. Test a led driver */
	if(led_error_state == LED_INVALID_PIN)
	{
		printf("Please enter a valid pedestrians red led pin number!");
		return;
	}
	else if(led_error_state == LED_INVALID_PORT)
	{
		printf("Please enter a valid pedestrians red led port number!");
		return;
	}
	
	/************************************************ Timer 0 initialization ************************************************/
	timer_error_state = TIMER_init(&TIMER_0_Config);
	/* 4. Test a timer driver */
	if(timer_error_state == TIMER_ID_INVALID)
	{
		printf("Please enter a valid timer id!");
		return;
	}
	else if(timer_error_state == TIMER_MODE_INVALID)
	{
		printf("Please enter a valid timer mode!");
		return;
	}
	else if(timer_error_state == TIMER_PRESCALER_INVALID)
	{
		printf("Please enter a valid timer prescaler!");
		return;
	}
	else if(timer_error_state == WRONG_INIT_VALUE)
	{
		printf("Please enter a valid timer initial value !");
		return;
	}
	else if(timer_error_state == WRONG_COMPARE_VALUE)
	{
		printf("Please enter a valid timer compare value!");
		return;
	}		
	/************************************************* Set TRAFFIC_timeCount function to Timer 0 ISR *************************************************/
	timer_error_state = TIMER_setCallBack(TIMER_0,TRAFFIC_timeCount);
	/* 4. Test a timer driver */
	if(timer_error_state == TIMER_ID_INVALID)
	{
		printf("Please enter a valid timer id!");
		return;
	}	
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: TRAFFIC_timeCount
	[Description]:	 This function is responsible for counting 5 seconds and switching between traffic Status and handling the button flag status
	[in]:			 Void
	[out]:			 None
	[Return]:		 Void
------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void TRAFFIC_timeCount(void)
{
	g_tick++;									// counter increment
	if(g_tick == NUMBER_OF_OVERFLOWS_PER_5sec)	// check if the count reaches the number of timer over flows per 5 seconds
	{
		if(trafficStatus == CARS_READY)			// check if the traffic Status reaches the final Status 
		{
			trafficStatus = CARS_CROSS;			// return it back to the first Status
		}
		else                                    // if it is still not reached the final Status
		{
			trafficStatus++;					// move to the next Status
		}
		if(g_pressFlag == BUTTON_PRESSED)
		{
			g_pressFlag = BUTTON_NOT_PRESSED;	// return the flag status to the button not pressed again to get the next press	and avoid the double press during the status period	
		}
		else
		{
			/* do nothing */
		}
		g_tick = 0;								// return the counter to start counting a new 5 second from the beginning
	}
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------	
	[Function Name]: PEDESTRIAN_buttonPress
	[Description]:	 This function is responsible for handling the pedestrian button press 
	[in]:			 Void
	[out]:			 None
	[Return]:		 Void	
------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void PEDESTRIAN_buttonPress(void)
{
	button_error_state = BUTTON_getStatus(&PEDESTRIAN_BUTTON_Config,&g_buttonStatus);		// read the pedestrian button pin value to get the button status	
	/* 1. Test a button driver */
	if(button_error_state == BUTTON_INVALID_PIN)
	{
		printf("Please enter a valid button pin number!");
		return;
	}
	else if(button_error_state == BUTTON_INVALID_PORT)
	{
		printf("Please enter a valid button port number!");
		return;
	}
	/****************************/
	if(g_buttonStatus == BUTTON_PRESSED)													// check the button Status once
	{
		_delay_ms(30);																		// delay to 30ms for the button De-bouncing Time
		button_error_state = BUTTON_getStatus(&PEDESTRIAN_BUTTON_Config,&g_buttonStatus);	// read the pedestrian button pin value to get the button status
		/* 1. Test a button driver */
		if(button_error_state == BUTTON_INVALID_PIN)
		{
			printf("Please enter a valid button pin number!");
			return;
		}
		else if(button_error_state == BUTTON_INVALID_PORT)
		{
			printf("Please enter a valid button port number!");
			return;
		}
		/****************************/
		
		if(g_buttonStatus == BUTTON_PRESSED)												// check the button Status again to ensure the press validity
		{
			/* Pedestrian mode */
			if(g_pressFlag == BUTTON_NOT_PRESSED)											// check if the button status change is happened by its global variable for press flag
			{
				if(trafficStatus == CARS_CROSS)												// if the button press comes with in cars cross 
				{
					trafficStatus = PEDESTRIAN_READY;										// change the Status to the wait Status before the pedestrian cross.		
				}
				else if(trafficStatus == PEDESTRIAN_CROSS)									// if the button press comes with in pedestrian cross 
				{
					g_tick = 0;																// reset timer counter for expanding the pedestrian cross to 5 seconds more
				}
				else if(trafficStatus == CARS_READY)										// if the button press comes with in the wait Status before the cars cross 
				{
					trafficStatus = PEDESTRIAN_READY;										// change the wait Status before cars cross to the wait Status before pedestrian cross
				}
				else
				{
					/* do nothing */
				}
				g_pressFlag = BUTTON_PRESSED;							// change the flag Status as the button is pressed and avoiding the button long press
			}
			else
			{
				   /* do nothing */
			}		
		}
		else
		{
				/* do nothing */
		}
	}
	else
	{
		
		/* do nothing */
	}
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------
	[Function Name]: APP_start
	[Description]:	 This function is responsible for start the application
	[in]:			 Void
	[out]:			 None
	[Return]:		 Void
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void APP_start(void)
{	
	/* Normal mode of the traffic lights control system */	
	switch (trafficStatus)
	{
		/* The first status is allow for the cars to cross */
		case CARS_CROSS :
			/* turn the cars green led and the pedestrian red LEDs on and other LEDs off */
			LED_on(&CARS_GREEN_LED_Config);
			LED_off(&CARS_YELLOW_LED_Config);
			LED_off(&CARS_RED_LED_Config);
		
			LED_off(&PEDESTRIAN_GREEN_LED_Config);
			LED_off(&PEDESTRIAN_YELLOW_LED_Config);
			LED_on(&PEDESTRIAN_RED_LED_Config);
		
			break ;
		
		/* The second status is waiting for pedestrians before the pedestrians cross */
		case PEDESTRIAN_READY :
			/* toggle the yellow led for the cars and the pedestrians for 0.5 second and turn other LEDs off */
			LED_off(&CARS_GREEN_LED_Config);
			LED_off(&CARS_RED_LED_Config);
		
			if( (g_tick % 2) == 0)
			{
				LED_toggle(&CARS_YELLOW_LED_Config);
				LED_toggle(&PEDESTRIAN_YELLOW_LED_Config);
			}
		
			LED_off(&PEDESTRIAN_GREEN_LED_Config);
			LED_off(&PEDESTRIAN_RED_LED_Config);

			break;
		/* The third status is allow for the pedestrians to cross */
		case PEDESTRIAN_CROSS :
			/* turn the pedestrian green led and the cars red LEDs on and other LEDs off */
			LED_off(&CARS_GREEN_LED_Config);
			LED_off(&CARS_YELLOW_LED_Config);
			LED_on(&CARS_RED_LED_Config);
		
			LED_on(&PEDESTRIAN_GREEN_LED_Config);
			LED_off(&PEDESTRIAN_YELLOW_LED_Config);
			LED_off(&PEDESTRIAN_RED_LED_Config);
			break ;
			
		/* The forth status is waiting for cars before the cars cross again */
		case CARS_READY :
			/* toggle the yellow led for the cars and the pedestrians for 0.5 second and turn other LEDs off */
			LED_off(&CARS_GREEN_LED_Config);
			LED_off(&CARS_RED_LED_Config);
		
			if( (g_tick % 2) == 0)
			{
				LED_toggle(&CARS_YELLOW_LED_Config);
				LED_toggle(&PEDESTRIAN_YELLOW_LED_Config);
			}
		
			LED_off(&PEDESTRIAN_GREEN_LED_Config);
			LED_off(&PEDESTRIAN_RED_LED_Config);

			break;	

		default:
				/* do nothing */
			break;
	}
}
