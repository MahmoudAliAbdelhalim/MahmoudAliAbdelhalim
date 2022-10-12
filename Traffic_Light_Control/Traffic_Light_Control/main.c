 /* -----------------------------------------------------------------------------------------------------------

	[FILE NAME]:	<MAIN.C>

	[AUTHOR(S)]:	<MAHMOUD ALI ABDELHALIM ALI>

	[DATE CREATED]:	<10/9/2022>

	[DESCRIPTION]: <C FILE FOR MAIN FUNCTION THAT CALLS TRAFFIC_LIGHT_CONTROL APPLICATION>

-------------------------------------------------------------------------------------------------------------*/
#include "Application/app.h"


int main(void)
{
	/* Initialization of the application modules by calling the APP_init function */
	APP_init();

    while (1) 
    {
		/* Start the application by calling the APP_start function */
		APP_start();
    }
}

