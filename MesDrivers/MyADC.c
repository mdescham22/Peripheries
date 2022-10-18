


#include "MyADC.h"

void MyADC_Base_Init(MyADC_Struct_Typedef * ADC)
{
	if (ADC->ADC==ADC1){													//
		RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;					//Activation de l'ADC1
	}
	else if (ADC->ADC==ADC2){											//
		RCC->APB2ENR |= RCC_APB2ENR_ADC2EN;					//Activation de l'ADC2
	}
	ADC->ADC->CR2 |= ADC_CR2_CAL;									//Calibration de l'ADC
	ADC->ADC->CR1 |= ADC_CR1_DISCEN;							//Conversion de l'ADC en mode regulier
	
	if(ADC->Mode==SingleNotContinous){
		
	}
	
	if(ADC->Mode==SingleContious){
		
	}
	
	if(ADC->Mode==ScanNotContinousDMA){
		
	}
	
	if(ADC->Mode==ScanContinousDMA){
		
	}
}