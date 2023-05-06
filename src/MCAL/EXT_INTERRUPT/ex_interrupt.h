/*-----------------------------------------------------------------------------

 [Module]: EXTERNAL_INTERRUPT - Macros and Functions prototype

 [File Name]: ext_interrupt.h

 [Author]: Ebraheem Ali

 [Data Created]: May 1, 2022

 [Description]: static and dynamic configuration of EXTERNAL_INTERRUPT.

 -------------------------------------------------------------------------------*/

#ifndef MCAL_EXT_INTERRUPT_EX_INTERRUPT_H_
#define MCAL_EXT_INTERRUPT_EX_INTERRUPT_H_
/***************************************************************
 * 				INCLUDES
 ***************************************************************/
#include "../../HELPERS/Std_types.h"

/***************************************************************
 * 				DEFINITIONS
 ***************************************************************/
#define EX_INTERRUPT2_PORT	DDRB

#define EXT_INT_ENABLE	1
#define EXT_INT_DISABLE 0

#define NUM_OF_EXT_INT	3

#define I_BIT (7)

/*-------------------------------------------------------------------------------------------------
 Name: ExtInt_TriggerType_t
 Type: Enumeration
 Description: Hold the trigger signal type.
 --------------------------------------------------------------------------------------------------*/
typedef enum
{
	FALLING_EDGE,
	RISING_EDGE
}ExtInt_TriggerType_t;

/*-------------------------------------------------------------------------------------------------
 Name: ExtInt_sourceType_t
 Type: Enumeration
 Description: Hold the interrupt source type.
 --------------------------------------------------------------------------------------------------*/
typedef enum
{
	EXT_INTERRUPT_0,
	EXT_INTERRUPT_1,
	EXT_INTERRUPT_2
}ExtInt_sourceType_t;

/*-------------------------------------------------------------------------------------------------
 Name: ExtInt_ConfigParam_t
 Type: Structure
 Description: Hold the run-time configurations of the EXT_INTERRUPT module.
 --------------------------------------------------------------------------------------------------*/
typedef struct
{
	ExtInt_TriggerType_t trigger_type;
	ExtInt_sourceType_t source_type;
	uint8 ExtInt_privilage;
}ExtInt_ConfigParam_t;

/*-------------------------------------------------------------------------------------------------
 Name: ExtInt_ConfigType
 Type: Structure
 Description: Hold the link configurations of the EXT_INTERRUPT module.
 --------------------------------------------------------------------------------------------------*/
typedef struct
{
	ExtInt_ConfigParam_t ExtIntArray[NUM_OF_EXT_INT];
}ExtInt_ConfigType;

extern const ExtInt_ConfigType ExtIntConfigObj;


/*********************************************************************************
 *                  Functions Prototypes
 ********************************************************************************/
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
void ExtInt_init(const ExtInt_ConfigType * InterruptConfig_Ptr);
/*-------------------------------------------------------------------------------------------------
 Function Name: ExtInt_enable
 Function prototype: void ExtInt_enable(ExtInt_sourceType_t a_interruptNum)
 Parameters[in]: [a_interruptNum]-> Indicate the interrupt source.
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to enable a spacfic external interrupt
 --------------------------------------------------------------------------------------------------*/
void ExtInt_enable(ExtInt_sourceType_t a_interruptNum);
/*-------------------------------------------------------------------------------------------------
 Function Name: ExtInt_disable
 Function prototype: void ExtInt_disable(EX_INTERRUPT_sourceType_t a_interruptNum)
 Parameters[in]: [a_interruptNum]-> Indicate the interrupt source.
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to disable a spacfic external interrupt
 --------------------------------------------------------------------------------------------------*/
void ExtInt_disable(ExtInt_sourceType_t a_interruptNum);

/************************************************************************************
				ExtInt Call Back Functions
*************************************************************************************/

void ExtInt_setCallBackInt0(void (*FuncPtr)(void));

void ExtInt_setCallBackInt1(void (*FuncPtr)(void));

void ExtInt_setCallBackInt2(void (*FuncPtr)(void));

#endif /* MCAL_EXT_INTERRUPT_EX_INTERRUPT_H_ */
