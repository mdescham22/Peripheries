#include "MyTimer.h"
#include "Driver_GPIO.h"
#include <stdlib.h>

//-------------- Reponses aux questions --------------
// 1. Il faut agir sur les bits de 0 a 7  au niveau du registre TIM_DIER pour
//     activer les interruptions.
//2.  Enabler 1 des bits des registres ISER0-ISER2 pour activer interruptions du NVIC
//3.  Lorsqu'il y a débordement 

void CallBack(void);


int main(void)
{
	MyTimer_Struct_TypeDef Timer;
	Timer.Timer = TIM1;
	Timer.ARR = 0x9999;
	Timer.PSC = 0x1234;
	
	MyTimer_Base_Init(&Timer);
	
	MyTimer_ActiveIT(Timer.Timer, 1, &CallBack);

	while(1);
}

void CallBack(void)
{
	
	
	
	
	
	
}