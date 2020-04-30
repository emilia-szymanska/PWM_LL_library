#ifndef PWM_LL_LIBRARY_H
#define PWM_LL_LIBRARY_H

#include <stm32f103xb.h>

typedef enum
{
	PWM_OFF,
	PWM_ON
} PWM_State;

typedef struct
{
	TIM_TypeDef *Instance;
	PWM_State tim_state;
	uint32_t frequency;
	uint32_t duty_cycle;
	uint32_t prescaler;
} TIM_handler_t;


/* enabling PWM */
void PWM_enable(TIM_handler_t *tim);

/*disabling PWM*/
void PWM_disable(TIM_handler_t *tim);

/*initializing PWM with frequency [Hz] */
void PWM_init(TIM_handler_t *tim, TIM_TypeDef *instance, uint32_t frequency);

/*setting duty cycle - value in % */
void PWM_setDutyCycle(TIM_handler_t *tim, uint32_t DutyCycle);

/*setting frequency [Hz]*/
void PWM_setFrequency(TIM_handler_t *tim, uint32_t new_frequency);

/*setting prescaler */
void PWM_setPrescaler(TIM_handler_t *tim, uint32_t new_prescaler);

#endif
