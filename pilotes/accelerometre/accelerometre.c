#include "accelerometre.h"
#include "stm32f10x.h"

void init_accelero() {
	// Enable clock sur GPIOC
	(RCC->APB2ENR)|= RCC_APB2ENR_IOPCEN;
	// Analog input pour PC0 et PC1
	GPIOC->CRL &= ~(0xF);
	GPIOC->CRL &= ~(0xF<<4);
	
}

float get_angle_accelero() {
	
	return 0;
}