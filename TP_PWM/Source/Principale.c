


#include "MyTimer.h"
#include "Driver_GPIO.h"
#include <stdlib.h>

int horloge;

int main(void)
{
	char Channel;
	unsigned short CCR;
	MyTimer_Struct_TypeDef Timer;
	MyGPIO_Struct_TypeDef myGPIO;
	
	Timer.Timer = TIM2;
	Timer.ARR = 0x0023;
	Timer.PSC = 0x0013;
	Channel = 2;
	CCR =  0x0007;
	
	myGPIO.GPIO = GPIOA;
	myGPIO.GPIO_Pin = 1;
	myGPIO.GPIO_Conf = AltOut_Ppull;
	 
	MyGPIO_INIT(&myGPIO);
	MyTimer_Base_Init(&Timer);
	MyTimer_PWM(Timer.Timer, Channel);
	SetCCR(Timer.Timer, Channel, CCR);
	while(1) {horloge = TIM2->CNT ;}
}