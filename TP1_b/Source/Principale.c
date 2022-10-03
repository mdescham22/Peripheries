#include "Driver_GPIO.h"
#include <stdlib.h>

int main(void)
{
	MyGPIO_Struct_TypeDef * GPIOStructPtr = malloc(sizeof(MyGPIO_Struct_TypeDef));
	MyGPIO_Struct_TypeDef * GPIOStructPtr2 = malloc(sizeof(MyGPIO_Struct_TypeDef));
	
	GPIOStructPtr->GPIO = GPIOD;
	GPIOStructPtr->GPIO_Pin = 2;
	GPIOStructPtr->GPIO_Conf =In_PullDown ;
	
	GPIOStructPtr2->GPIO = GPIOD;
	GPIOStructPtr2->GPIO_Pin = 3;
	GPIOStructPtr2->GPIO_Conf =Out_Ppull ;
	
	MyGPIO_INIT (GPIOStructPtr);
	MyGPIO_INIT (GPIOStructPtr2);
	
	
	MyGPIO_Set(GPIOStructPtr2->GPIO, GPIOStructPtr2->GPIO_Pin);
	MyGPIO_Toggle(GPIOStructPtr2->GPIO, GPIOStructPtr2->GPIO_Pin);
	MyGPIO_Toggle(GPIOStructPtr2->GPIO, GPIOStructPtr2->GPIO_Pin);
	MyGPIO_Reset(GPIOStructPtr2->GPIO, GPIOStructPtr2->GPIO_Pin);
	
	
 while(1);
}
