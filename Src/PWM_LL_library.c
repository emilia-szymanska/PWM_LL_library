#include "PWM_LL_library.h"

void PWM_enable(TIM_handler_t *tim)
{
	tim->Instance->CR1 |= TIM_CR1_CEN;			//Counter enable -> enabled
	tim->Instance->CCER |= TIM_CCER_CC1E;		// Capture/Compare 1 output enable -> enabled

	tim->tim_state = PWM_ON;
}

void PWM_disable(TIM_handler_t *tim)
{
	tim->Instance->CR1 &=~ TIM_CR1_CEN;			//Counter enable -> disabled
	tim->Instance->CCER &=~ TIM_CCER_CC1E;		// Capture/Compare 1 output enable -> disabled
	tim->tim_state = PWM_OFF;
}


void PWM_init(TIM_handler_t *tim, TIM_TypeDef *instance, uint32_t init_frequency)
{
	uint32_t init_prescaler = RCC_PLL_GetFreqDomain_SYS()/init_frequency;

	tim->Instance = instance;
	tim->tim_state = PWM_OFF;
	tim->frequency = init_frequency;
	tim->duty_cycle = 0;
	tim->prescaler = init_prescaler;

	tim->Instance->PSC = init_prescaler;			//Prescaler
	tim->Instance->CCMR1 |= TIM_CCMR1_OC1PE;	 	//Output Compare 1 Preload Enable in Capture/Compare Mode Register
	tim->Instance->CR1 |= TIM_CR1_ARPE;				//Auto-Reload Preload Enable -> is buffered
	tim->Instance->EGR |= TIM_EGR_UG; 				//Update Generation in Event Generation Register
	tim->Instance->CCER &=~ TIM_CCER_CC1P; 			//Polarity
}


void PWM_setDutyCycle(TIM_handler_t *tim, uint32_t DutyCycle)
{
	uint32_t period = tim->Instance->ARR;			//Auto-Reload Register
	tim->duty_cycle = DutyCycle;

	tim->Instance->CCR1 = (DutyCycle*period)/100;	//Capture-Compare Register 1
}

void PWM_setFrequency(TIM_handler_t *tim, uint32_t new_frequency)
{
	uint32_t new_prescaler = RCC_PLL_GetFreqDomain_SYS()/new_frequency;
	tim->frequency = new_frequency;
	tim->prescaler = new_prescaler;
	tim->Instance->PSC = new_prescaler;
}

void PWM_setPrescaler(TIM_handler_t *tim, uint32_t new_prescaler)
{
	tim->prescaler = new_prescaler;
	tim->frequency = RCC_PLL_GetFreqDomain_SYS()/new_prescaler;
	tim->Instance->PSC = new_prescaler;
}
