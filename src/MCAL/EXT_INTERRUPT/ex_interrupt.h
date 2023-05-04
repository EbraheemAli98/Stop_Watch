/*-----------------------------------------------------------------------------

 [Module]: ADC - Macros and Functions prototype

 [File Name]: adc.h

 [Author]: Ebraheem Ali

 [Data Created]: May 23, 2022

 [Description]: static and dynamic configuration of ADC.

 -------------------------------------------------------------------------------*/

#ifndef MCAL_EXT_INTERRUPT_EX_INTERRUPT_H_
#define MCAL_EXT_INTERRUPT_EX_INTERRUPT_H_

#include "../../HELPERS/Std_types.h"
#  define ISR(vector)            \
    void vector (void) __attribute__ ((signal));\
    void vector (void)

#define EX_INTERRUPT0_PIN	INT0
#define EX_INTERRUPT1_PIN 	INT1

#define EX_INTERRUPT2_PORT	DDRB
#define EX_INTERRUPT2_PIN	INT2

#define I_BIT (7)

typedef enum
{
	LOW_LEVEL,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}EX_INTERRUPT_TriggerType_t;

typedef enum{
	EXT_INTERRUPT_0,
	EXT_INTERRUPT_1,
	EXT_INTERRUPT_2
}EX_INTERRUPT_sourceType_t;

typedef struct
{
	EX_INTERRUPT_TriggerType_t trigger_type;
	EX_INTERRUPT_sourceType_t source_type;
	volatile void (*callBack_Ptr)(void);
}EX_INTERRUPT_Config_t;

void EX_INTERRUPT_config(EX_INTERRUPT_Config_t* InterruptConfig_Ptr);
void EX_INTERRUPT_enable(EX_INTERRUPT_sourceType_t a_interruptNum);
void EX_INTERRUPT_disable(EX_INTERRUPT_sourceType_t a_interruptNum);

#endif /* MCAL_EXT_INTERRUPT_EX_INTERRUPT_H_ */
