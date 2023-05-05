/*------------------------------------------------------------------------------------

 [Module]: EXTERNAL_INTERRUPT - Global and static variables - Functions definitions

 [File Name]: ext_interrupt.c

 [Author]: Ebraheem Ali

 [Data Created]: May 1, 2022

 [Description]: This File contains definitions of EXTERNAL_INTERRUPT and global ,static variables.

 ------------------------------------------------------------------------------------*/
#include "../../HELPERS/Std_types.h"
#include "../../HELPERS/comman_macro.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "ex_interrupt.h"

/*********************************************************************************
 *                  Globale Variables Definition
 ********************************************************************************/
/*-------------------------------------------------------------------------------------------------
 Name: ExtInt_ConfigType
 Type: Structure
 Description: Hold the link configurations of the EXT_INTERRUPT module.
 --------------------------------------------------------------------------------------------------*/
const ExtInt_ConfigType ExtIntConfigObj = 
{{
	{FALLING_EDGE, EXT_INTERRUPT_0},
	{RISING_EDGE, EXT_INTERRUPT_1},
	{FALLING_EDGE, EXT_INTERRUPT_2}
}};

/*********************************************************************************
 *               Static Globale Variables Declaration
 ********************************************************************************/
static volatile void(*g_EX_INT0_CallBack_Ptr)(void) = NULL_PTR;
static volatile void(*g_EX_INT1_CallBack_Ptr)(void) = NULL_PTR;
static volatile void(*g_EX_INT2_CallBack_Ptr)(void) = NULL_PTR;

/*********************************************************************************
 *               Private Functions' Prototypes
 ********************************************************************************/
static void ExtInt0_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr);
static void ExtInt1_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr);
static void ExtInt2_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr);

/*********************************************************************************
 *                  Functions' Definitions
 ********************************************************************************/
/*-------------------------------------------------------------------------------------------------
 Function Name: ExtInt0_init
 Function prototype: static void ExtInt0_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr)
 Parameters[in]: [InterruptConfig_Ptr]-> Pointer to sturcture containing the INT0 configurations.
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to configure INT0.
 --------------------------------------------------------------------------------------------------*/
static void ExtInt0_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr)
{
	/* set the callbak function address of INT0 to the global pointer to function called in its ISR */
	g_EX_INT0_CallBack_Ptr = InterruptConfig_Ptr->callBack_Ptr;
	/* enable the INT0 interrupt */
	SET_BIT(GICR,EX_INTERRUPT0_PIN);
	switch(InterruptConfig_Ptr->trigger_type)
	{
	case FALLING_EDGE:
		CLEAR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01); break;
	case RISING_EDGE:
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01); break;
	}
}
/*-------------------------------------------------------------------------------------------------
 Function Name: ExtInt0_init
 Function prototype: static void ExtInt0_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr)
 Parameters[in]: [InterruptConfig_Ptr]-> Pointer to sturcture containing the INT0 configurations.
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to configure INT0.
 --------------------------------------------------------------------------------------------------*/
static void ExtInt1_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr)
{
	/* set the callbak function address of INT1 to the global pointer to function called in its ISR */
	g_EX_INT1_CallBack_Ptr = InterruptConfig_Ptr->callBack_Ptr;
	/* enable the INT0 interrupt */
	SET_BIT(GICR,EX_INTERRUPT1_PIN);
	switch(InterruptConfig_Ptr->trigger_type)
	{
	case FALLING_EDGE:
		CLEAR_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01); break;
	case RISING_EDGE:
		SET_BIT(MCUCR,ISC00);
		SET_BIT(MCUCR,ISC01); break;
	}
}
/*-------------------------------------------------------------------------------------------------
 Function Name: ExtInt0_init
 Function prototype: static void ExtInt0_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr)
 Parameters[in]: [InterruptConfig_Ptr]-> Pointer to sturcture containing the INT0 configurations.
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to configure INT0.
 --------------------------------------------------------------------------------------------------*/
static void ExtInt2_init(EX_INTERRUPT_Config_t *InterruptConfig_Ptr)
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
/*-------------------------------------------------------------------------------------------------
 Function Name: ExtInt_init
 Function prototype: void ExtInt_init(const ExtInt_ConfigType * InterruptConfig_Ptr)
 Parameters[in]: [InterruptConfig_Ptr]-> Pointer to array of sturcture containing the ExT_INTERRUPT 
	Module configurations.
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to configure ExT_INTERRUPT module.
 --------------------------------------------------------------------------------------------------*/
void ExtInt_init(const ExtInt_ConfigType * InterruptConfig_Ptr)
{
	uint8 IntNum;
	for(IntNum=0; IntNum<NUM_OF_EXT_INT;++IntNum)
	{
		/* Implement the function if only number of interrupt between 0-2 and number of trigger type 0-3 */
		if(InterruptConfig_Ptr->ExtIntArray[IntNum].source_type <= 2 && InterruptConfig_Ptr->ExtIntArray[IntNum].trigger_type <= 3)
		{
			switch(InterruptConfig_Ptr->ExtIntArray[IntNum].source_type)
			{
			case EXT_INTERRUPT_0:
				ExtInt0_init(InterruptConfig_Ptr->ExtIntArray[IntNum]);
				break;
			case EXT_INTERRUPT_1:
				ExtInt1_init(InterruptConfig_Ptr->ExtIntArray[IntNum]);
				break;
			case EXT_INTERRUPT_2:
				ExtInt2_init(InterruptConfig_Ptr->ExtIntArray[IntNum]);
				break;
			}
		}
	}
}
/*-------------------------------------------------------------------------------------------------
 Function Name: ExtInt_enable
 Function prototype: void ExtInt_enable(ExtInt_sourceType_t a_interruptNum)
 Parameters[in]: [a_interruptNum]-> Indicate the interrupt source.
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to enable a spacfic external interrupt
 --------------------------------------------------------------------------------------------------*/
void ExtInt_enable(ExtInt_sourceType_t a_interruptNum)
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
/*-------------------------------------------------------------------------------------------------
 Function Name: ExtInt_disable
 Function prototype: void ExtInt_disable(EX_INTERRUPT_sourceType_t a_interruptNum)
 Parameters[in]: [a_interruptNum]-> Indicate the interrupt source.
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to disable a spacfic external interrupt
 --------------------------------------------------------------------------------------------------*/
void ExtInt_disable(ExtInt_sourceType_t a_interruptNum)
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

/************************************************************************************
						ExtInt Call Back Functions
*************************************************************************************/
void ExtInt_setCallBackInt0(void (*FuncPtr)(void))
{
	if(g_EX_INT0_CallBack_Ptr != NULL_PTR)
		g_EX_INT0_CallBack_Ptr = FuncPtr;
}

void ExtInt_setCallBackInt1(void (*FuncPtr)(void))
{
	if(g_EX_INT1_CallBack_Ptr != NULL_PTR)
		g_EX_INT1_CallBack_Ptr = FuncPtr;
}

void ExtInt_setCallBackInt2(void (*FuncPtr)(void))
{
	if(g_EX_INT2_CallBack_Ptr != NULL_PTR)
		g_EX_INT2_CallBack_Ptr = FuncPtr;
}
/************************************************************************************
						ExtInt ISPs Functions
*************************************************************************************/
/* INTERRUPT OF RESET_SWITCH */
ISR(INT0_vect)
{
	if(g_EX_INT0_CallBack_Ptr != NULL_PTR)
		(*g_EX_INT0_CallBack_Ptr)();
}

/* INTERRUPT OF PAUSE_SWITCH */
ISR(INT1_vect)
{
	if(g_EX_INT0_CallBack_Ptr != NULL_PTR)
		(*g_EX_INT1_CallBack_Ptr)();
}

/* INTERRUPT OF RESUME_SWITCH */
ISR(INT2_vect)
{
	if(g_EX_INT0_CallBack_Ptr != NULL_PTR)
		(*g_EX_INT2_CallBack_Ptr)();
}
