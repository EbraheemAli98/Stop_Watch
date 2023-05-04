/*-----------------------------------------------------------------------------

 [Module]: EXTERNAL_INTERRUPT - Macros and Functions prototype

 [File Name]: ext_interrupt.h

 [Author]: Ebraheem Ali

 [Data Created]: May 1, 2022

 [Description]: static and dynamic configuration of EXTERNAL_INTERRUPT.

 -------------------------------------------------------------------------------*/

#ifndef MCAL_EXT_INTERRUPT_EX_INTERRUPT_H_
#define MCAL_EXT_INTERRUPT_EX_INTERRUPT_H_

#  define ISR(vector)            \
    void vector (void) __attribute__ ((signal));\
    void vector (void)

#define EX_INTERRUPT0_PIN	INT0
#define EX_INTERRUPT1_PIN 	INT1

#define EX_INTERRUPT2_PORT	DDRB
#define EX_INTERRUPT2_PIN	INT2

#define NUM_OF_EXT_INT	3

#define I_BIT (7)

typedef enum
{
	FALLING_EDGE,
	RISING_EDGE
}ExtInt_TriggerType_t;

typedef enum{
	EXT_INTERRUPT_0,
	EXT_INTERRUPT_1,
	EXT_INTERRUPT_2
}ExtInt_sourceType_t;

typedef struct
{
	EX_INTERRUPT_TriggerType_t trigger_type;
	EX_INTERRUPT_sourceType_t source_type;
	volatile void (*callBack_Ptr)(void);
}ExtInt_ConfigParam_t;

typedef struct
{
	ExtInt_ConfigParam_t ExtIntArray[NUM_OF_EXT_INT];
}ExtInt_ConfigType;

extern const ExtInt_ConfigType ExtIntConfigObj;

void ExtInt_init(EX_INTERRUPT_Config_t* InterruptConfig_Ptr);
void ExtInt_enable(EX_INTERRUPT_sourceType_t a_interruptNum);
void ExtInt_disable(EX_INTERRUPT_sourceType_t a_interruptNum);

#endif /* MCAL_EXT_INTERRUPT_EX_INTERRUPT_H_ */
