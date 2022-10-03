

#include "stm32f10x.h"
int main(void)
{
	//Init
	RCC->APB2ENR |= (0x01 << 2) | (0x01 << 3) | (0x01 << 4);
	
	GPIOA->CRH &= ~(0xF<<8);
	GPIOA->CRH |= (1<<8);
	
	GPIOB->CRL &= ~(0xF<<20);
	GPIOB->CRL |= (1<<22);
	
	do
	{
		//Loop
		if(GPIOB->IDR & (1<<5))
		{
			GPIOA->ODR |=(1<<10);
		}
		else
		{
			GPIOA->ODR &= ~(1<<10);
		}
		
	}while(1);
}
