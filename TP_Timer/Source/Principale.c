#include "Driver_GPIO.h"
#include <stdlib.h>

int main(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->ARR = 0x03E7;	//999
	TIM2->PSC = 0x0F9F;	//3999
	TIM2->CR1 |= 0x01;
	
	while(1);
}
