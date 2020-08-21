# PWM_LL_library

## Detailed information
This code (specifically _PWM_LL_library.c_ and _PWM_LL_library.h_) offers managing PWM on STM32F103RB. 
Available functions:
* enabling PWM,
* disabling PWM,
* initializing PWM with specified frequency,
* setting duty cycle,
* setting frequency,
* setting prescaler.

The code doesn't manage all variations of timers, so before using make sure that registers have proper values set for your needs. 

## Author
* **Emilia Szymańska**
