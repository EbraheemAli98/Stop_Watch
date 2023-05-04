/*------------------------------------------------------------------------------------

 [Module]: ADC - Global and static variables - Functions definitions

 [File Name]: adc.c

 [Author]: Ebraheem Ali

 [Data Created]: May 23, 2022

 [Description]: This File contains definitions of ADC and global ,static variables.

 ------------------------------------------------------------------------------------*/
#include "../../MCAL/EXT_INTERRUPT/ex_interrupt.h"
#include "../../HELPERS/comman_macros.h"
#include <avr/io.h>

static volatile void(*g_EX_INT0_CallBack_Ptr)(void) = NULL_PTR;
static volatile void(*g_EX_INT1_CallBack_Ptr)(void) = NULL_PTR;
static volatile void(*g_EX_INT2_CallBack_Ptr)(void) = NULL_PTR;

static void EX_INTERRUPT0_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr);
static void EX_INTERRUPT1_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr);
static void EX_INTERRUPT2_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr);

static void EX_INTERRUPT0_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr)
{
	/* set the callbak function address of INT0 to the global pointer to function called in its ISR */
	g_EX_INT0_CallBack_Ptr = InterruptConfig_Ptr->callBack_Ptr;
	/* enable the INT0 interrupt */
	SET_BIT(GICR,EX_INTERRUPT0_PIN);
	switch(InterruptConfig_Ptr->trigger_type)
	{
	case LOW_LEVEL:
		CLEAR_BIT(MCUCR,ISC00);
		CLEAR_BIT(MCUCR,ISC01); break;
	case ANY_LOGIC_CHANGE:
		CLEAR_BIT(MCUCR,ISC01);
		SET_BIT(MCUCR,ISC00); break;
	case FALLING_EDGE:
		CLEAR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01); break;
	case RISING_EDGE:
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01); break;
	}
}

static void EX_INTERRUPT1_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr)
{
	/* set the callbak function address of INT1 to the global pointer to function called in its ISR */
	g_EX_INT1_CallBack_Ptr = InterruptConfig_Ptr->callBack_Ptr;
	/* enable the INT0 interrupt */
	SET_BIT(GICR,EX_INTERRUPT1_PIN);
	switch(InterruptConfig_Ptr->trigger_type)
	{
	case LOW_LEVEL:
		CLEAR_BIT(MCUCR,ISC00);
		CLEAR_BIT(MCUCR,ISC01); break;
	case ANY_LOGIC_CHANGE:
		CLEAR_BIT(MCUCR,ISC01);
		SET_BIT(MCUCR,ISC00); break;
	case FALLING_EDGE:
		CLEAR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01); break;
	case RISING_EDGE:
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01); break;
	}
}

static void EX_INTERRUPT2_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr)
{
	/* set the callbak function address of INT0 to the global pointer to function called in its ISR */
	g_EX_INT2_CallBack_Ptr = InterruptConfig_Ptr->callBack_Ptr;
	/* enable the INT0 interrupt */
	SET_BIT(GICR,EX_INTERRUPT2_PIN);
	switch(InterruptConfig_Ptr->trigger_type)
	{
	case FALLING_EDGE:
		CLEAR_BIT(MCUCSR,ISC2);
		break;
	case RISING_EDGE:
		SET_BIT(MCUCSR,ISC2);
		break;
	}
}

void EX_INTERRUPT_config(EX_INTERRUPT_Config_t* InterruptConfig_Ptr)
{
	/* Implement the function if only number of interrupt between 0-2 and number of trigger type 0-3 */
	if(InterruptConfig_Ptr->source_type <= 2 && InterruptConfig_Ptr->trigger_type <= 3)
	{
		switch(InterruptConfig_Ptr->source_type)
		{
		case EXT_INTERRUPT_0:
			EX_INTERRUPT0_init(InterruptConfig_Ptr);
			break;
		case EXT_INTERRUPT_1:
			EX_INTERRUPT1_init(InterruptConfig_Ptr);
			break;
		case EXT_INTERRUPT_2:
			EX_INTERRUPT2_init(InterruptConfig_Ptr);
			break;
		}
	}
}
void EX_INTERRUPT_enable(EX_INTERRUPT_sourceType_t a_interruptNum)
{
	switch(a_interruptNum)
	{
	case EXT_INTERRUPT_0:
		SET_BIT(GICR,EX_INTERRUPT0_PIN); /* Enable INT0 interrupt */
		break;
	case EXT_INTERRUPT_1:
		SET_BIT(GICR,EX_INTERRUPT1_PIN); /* Enable INT1 interrupt */
		break;
	case EXT_INTERRUPT_2:
		SET_BIT(GICR,EX_INTERRUPT2_PIN); /* Enable INT2 interrupt */
		break;
	}
	SET_BIT(SREG,I_BIT); /* Enable global interrupts */
}

void EX_INTERRUPT_disable(EX_INTERRUPT_sourceType_t a_interruptNum)
{
	switch(a_interruptNum)
	{
	case EXT_INTERRUPT_0:
		CLEAR_BIT(GICR,EX_INTERRUPT0_PIN); /* Enable INT0 interrupt */
		break;
	case EXT_INTERRUPT_1:
		CLEAR_BIT(GICR,EX_INTERRUPT1_PIN); /* Enable INT1 interrupt */
		break;
	case EXT_INTERRUPT_2:
		CLEAR_BIT(GICR,EX_INTERRUPT2_PIN); /* Enable INT2 interrupt */
		break;
	}
}

ISR(INT0_vect)
{
	SET_BIT(SREG,I_BIT);
	if(g_EX_INT0_CallBack_Ptr != NULL_PTR)
		(*g_EX_INT0_CallBack_Ptr)();
}

ISR(INT1_vect)
{
	if(g_EX_INT0_CallBack_Ptr != NULL_PTR)
		(*g_EX_INT1_CallBack_Ptr)();
}

ISR(INT2_vect)
{
	if(g_EX_INT0_CallBack_Ptr != NULL_PTR)
		(*g_EX_INT2_CallBack_Ptr)();
}
