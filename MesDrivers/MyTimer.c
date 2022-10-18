


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


void MyTimer_PWM(TIM_TypeDef * Timer, char Channel){
	if (Channel==1){
		Timer->CCMR1 &= ~TIM_CCMR1_OC1M_0; //	0
		Timer->CCMR1 |= TIM_CCMR1_OC1M_1; //	1
		Timer->CCMR1 |= TIM_CCMR1_OC1M_2;	//	1
		Timer->CCER |=TIM_CCER_CC1E ; // 
		
	}
	else if (Channel==2){
		Timer->CCMR1 &= ~TIM_CCMR1_OC2M_0; //	0
		Timer->CCMR1 |= TIM_CCMR1_OC2M_1; //	1
		Timer->CCMR1 |= TIM_CCMR1_OC2M_2;	//	1
		Timer->CCER |=TIM_CCER_CC2E ; // 
	}
	else if (Channel==3){
		Timer->CCMR2 &= ~TIM_CCMR2_OC3M_0; //	0
		Timer->CCMR2 |= TIM_CCMR2_OC3M_1; //	1
		Timer->CCMR2 |= TIM_CCMR2_OC3M_2;	//	1
		Timer->CCER |=TIM_CCER_CC3E ; // 
	}
	else if (Channel==4){
		Timer->CCMR2 &= ~TIM_CCMR2_OC4M_0; //	0
		Timer->CCMR2 |= TIM_CCMR2_OC4M_1; //	1
		Timer->CCMR2 |= TIM_CCMR2_OC4M_2;	//	1
		Timer->CCER |=TIM_CCER_CC4E ; // 
	}
	//Timer->CR1 |= TIM_CR1_ARPE ;// Auto Reload
	Timer->EGR |= TIM_EGR_UG; // Update Generation 
	Timer->CR1 &= ~TIM_CR1_CMS_0;
	Timer->CR1 &= ~TIM_CR1_CMS_1;// Edge aligned mode
	Timer->CR1 &= ~TIM_CR1_DIR; // upcounter
	if (Timer==TIM1){
			Timer->BDTR |= TIM_BDTR_MOE;
	}
}

void SetCCR(TIM_TypeDef * Timer, char Channel, unsigned short CCR)
{
	if (Channel==1){
		Timer->CCR1 = CCR;
	}
	else if (Channel==2){
		Timer->CCR2 = CCR;
	}
	else if (Channel==3){
		Timer->CCR3 = CCR;
	}
	else if (Channel==4){
		Timer->CCR4 = CCR;
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
