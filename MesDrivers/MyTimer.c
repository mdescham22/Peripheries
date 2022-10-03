#include "MyTimer.h"

void (MyTimer_Base_Init(MyTimer_Struct_TypeDef * Timer)
{
	if (Timer == TIM1)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM1EN;
	}
	else if (Timer == TIM2)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
		
	}
	else if (Timer == TIM3)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
		
	}
	else if (Timer == TIM4)
	{
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	TIM1->ARR = Timer->ARR;
	TIM1->PSC = Timer->PSC;
	TIM1->CR1 |= 0x80;
}