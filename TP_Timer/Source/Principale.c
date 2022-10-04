


#include <stdlib.h>
#include "MyTimer.h"

int main(void)
{
	/*
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->ARR = 0x03E7;	//999
	TIM2->PSC = 0x0F9F;	//3999
	TIM2->CR1 |= 0x01;
	*/
	
	MyTimer_Struct_TypeDef Timer;
	Timer.ARR = 0x03E7;
	Timer.PSC = 0x0F9F;
	Timer.Timer = TIM1;
	
	MyTimer_Base_Init(&Timer);
	while(1);
}
