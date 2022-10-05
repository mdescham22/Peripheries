


#include "MyTimer.h"

void MyTimer_Base_Init(MyTimer_Struct_TypeDef * Timer)
{
	if (Timer->Timer == TIM1){
		RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	}
	
	else if (Timer->Timer == TIM2){
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;	
	}
	
	else if (Timer->Timer == TIM3){
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;	
	}
	
	else if (Timer->Timer == TIM4){
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	}
	
	Timer->Timer->ARR = Timer->ARR;
	Timer->Timer->PSC = Timer->PSC;
	MyTimer_Base_Start(Timer->Timer);
}

void (*pt1_function) (void);
void (*pt2_function) (void);
void (*pt3_function) (void);
void (*pt4_function) (void);

void MyTimer_ActiveIT (TIM_TypeDef * Timer, char Prio, void (*IT_function) (void))
{
	Timer->DIER |= TIM_DIER_UIE;
	if (Timer == TIM1){
		NVIC_SetPriority(TIM1_UP_IRQn,Prio);
		NVIC_EnableIRQ(TIM1_UP_IRQn);
		
		pt1_function = IT_function;
		
	}
	
	else if (Timer == TIM2){
		NVIC_SetPriority(TIM2_IRQn,Prio);
		NVIC_EnableIRQ(TIM2_IRQn);
		
		pt2_function = IT_function;
		
	}
	
	else if (Timer == TIM3){
		NVIC_SetPriority(TIM3_IRQn,Prio);
		NVIC_EnableIRQ(TIM3_IRQn);
		
		pt3_function = IT_function;
		
	}
	
	else if (Timer == TIM4){
		NVIC_SetPriority(TIM4_IRQn,Prio);
		NVIC_EnableIRQ(TIM4_IRQn);
		
		pt4_function = IT_function;
		
	}
	
}


void TIM1_UP_IRQHandler(void)
{
	TIM1->SR &= ~TIM_SR_UIF;
	pt1_function();
}

void TIM2_IRQHandler(void)
{
	TIM2->SR &= ~TIM_SR_UIF;
	pt2_function();
}

void TIM3_IRQHandler(void)
{
	TIM3->SR &= ~TIM_SR_UIF;
	pt3_function();
}

void TIM4_IRQHandler(void)
{
	TIM4->SR &= ~TIM_SR_UIF;
	pt4_function();
}
