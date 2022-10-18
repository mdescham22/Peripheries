


#ifndef MYADC_H
#define MYADC_H
#include "stm32f10x.h"

	typedef struct
	{
		ADC_TypeDef * ADC;
		char Mode;
	} MyADC_Struct_Typedef;
	
#define SingleNotContinous		0x01
#define SingleContious				0x02
#define ScanNotContinousDMA		0x03
#define ScanContinousDMA			0x04

void MyADC_Base_Init(MyADC_Struct_Typedef * ADC);

	
#define MyADC_Base_Start(ADC) ADC->ADC->CR2 |= ADC_CR2_SWSTART








#endif