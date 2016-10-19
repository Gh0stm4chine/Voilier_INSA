#include "accelerometre.h"
#include <math.h>

void init_accelero() {
	// Enable clock sur GPIOC
	(RCC->APB2ENR)|= RCC_APB2ENR_IOPCEN;
	// Analog input pour PC0 et PC1
	GPIOC->CRL &= ~(0xF);
	GPIOC->CRL &= ~(0xF<<4);
	//power on de ADC
	RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
	ADC1->CR2 |= ADC_CR2_ADON;
	// L = 1
	// qs1 = ch0
	ADC1->CR2 |= ADC_CR2_ADON; // lancement conversion adc
}

float get_angle_accelero() {
	while((ADC1->SR & ADC_SR_EOC) == 0) {
		// bloquant
	}
	// baisse le flag
	ADC1->SR &= ~ADC_SR_EOC;
	int x = ADC1->DR & ADC_DR_DATA;
	
	ADC1->SQR3 |= 0b1; // qs1 = ch1
	ADC1->CR2 |= ADC_CR2_ADON; // lancement conversion adc
	while((ADC1->SR & ADC_SR_EOC) == 0) {
		// bloquant
	}
	// baisse le flag
	ADC1->SR &= ~ADC_SR_EOC;
	int y = ADC1->DR & ADC_DR_DATA;
	ADC1->SQR3 &= ~(0b1);  // qs1 = ch0
	ADC1->CR2 |= ADC_CR2_ADON; // lancement conversion adc
	return sqrt(x*x + y*y);
}