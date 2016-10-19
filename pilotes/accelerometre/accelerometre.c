#include "accelerometre.h"

void init_accelero() {
	// Enable clock sur GPIOC
	(RCC->APB2ENR)|= RCC_APB2ENR_IOPCEN;
	// Analog input pour PC0 et PC1
	GPIOC->CRL &= ~(0xF);
	GPIOC->CRL &= ~(0xF<<4);
	//power on de ADC
	ADC1->CR2 |= ADC_CR2_ADON;
	ADC1->SQR1 |= 0b1 << 20; // L = 2
	ADC1->SQR3 |= (1 & 0b11111) << 5; // qs1 = ch0 et qs2 = ch1
	ADC1->CR2 |= ADC_CR2_ADON; // lancement conversion adc
}

float get_angle_accelero() {
	while((ADC1->SR & ADC_SR_EOC) == 0) {
		// bloquant
	}
	// baisse le flag
	ADC1->SR &= ~ADC_SR_EOC;
	u16 x = ADC1->DR & ADC_DR_DATA & 0b11111111;
	u16 y = ADC1->DR & ADC_DR_DATA & 0b11111111 << 8;
	return x*x + y*y;
}