#include "MyTimer.h"
#include "Driver_GPIO.h"
#include <stdlib.h>

//-------------- Reponses aux questions --------------
// 1. Il faut agir sur les bits de 0 a 7  au niveau du registre TIM_DIER pour
//     activer les interruptions.
//2.  Enabler 1 des bits des registres ISER0-ISER2 pour activer interruptions du NVIC
//3.  Apr�s le d�bordement du timer (lorsqu'un �v�nement est d�clench�), un p�riph�rique TIMER �met une demande d'interruption. 
//    La demande est g�r�e par NVIC. Si elle devient prioritaire par le NVIC, le registre PC du Coeur sera d�tourn� et sera
//    plac� � la table d'interruption et un handler plac�e � l'adresse d'interruption sera ex�cut�.

void CallBack(void);

MyGPIO_Struct_TypeDef GPIOStructPtr;

int main(void)
{
	MyTimer_Struct_TypeDef Timer;
	Timer.Timer = TIM1;
	Timer.ARR = 0x9999;
	Timer.PSC = 0x1234;
	
	MyTimer_Base_Init(&Timer);
	MyTimer_ActiveIT(Timer.Timer, 1, CallBack);
	
	
	GPIOStructPtr.GPIO = GPIOD;
	GPIOStructPtr.GPIO_Pin = 2;
	GPIOStructPtr.GPIO_Conf =Out_Ppull;
	MyGPIO_INIT (&GPIOStructPtr);
	
	while(1);
}

void CallBack(void)
{
	
	MyGPIO_Toggle(GPIOStructPtr.GPIO, GPIOStructPtr.GPIO_Pin);
}
