#include "girouette.h"

void init_timer_girouette (void){
	(RCC->APB1ENR)|= RCC_APB1ENR_TIM3EN;
	//Select Encoder interface mode : TI1 edge 001 ? TI2 edge 010 ? both ? 011
	TIM3->SMCR &= ~TIM_SMCR_SMS;
	TIM3->SMCR |= TIM_SMCR_SMS_0; //Counting on TI1
	//Select the TI1 and TI2 polarity by programming the CC1P and CC2P bits in the TIMx_CCER
	TIM3->CCER &= ~TIM_CCER_CC1P; /* CC1 channel configured as input: 
				0: non-inverted: capture is done on a rising edge of IC1. When used as external */
	TIM3->CR1 |= TIM_CR1_CEN;
	//Select Nbre de pistes par tour
	TIM3->ARR = 360;
	
}

void init_girouette(void) {
	init_timer_girouette();
}