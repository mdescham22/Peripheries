#include "Driver_GPIO.h"
#include <stdlib.h>

int main(void)
{
	MyGPIO_Struct_TypeDef GPIOStructPtr;
	MyGPIO_Struct_TypeDef GPIOStructPtr2;
	
	GPIOStructPtr.GPIO = GPIOD;
	GPIOStructPtr.GPIO_Pin = 2;
	GPIOStructPtr.GPIO_Conf =In_PullUp ;
	
	GPIOStructPtr2.GPIO = GPIOD;
	GPIOStructPtr2.GPIO_Pin = 3;
	GPIOStructPtr2.GPIO_Conf =Out_Ppull ;
	
	MyGPIO_INIT (&GPIOStructPtr);
	MyGPIO_INIT (&GPIOStructPtr2);
	
	
	MyGPIO_Set(GPIOStructPtr2.GPIO, GPIOStructPtr2.GPIO_Pin);
	MyGPIO_Toggle(GPIOStructPtr2.GPIO, GPIOStructPtr2.GPIO_Pin);
	MyGPIO_Toggle(GPIOStructPtr2.GPIO, GPIOStructPtr2.GPIO_Pin);
	MyGPIO_Reset(GPIOStructPtr2.GPIO, GPIOStructPtr2.GPIO_Pin);
	
	
 while(1);
}
