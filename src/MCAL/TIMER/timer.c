/*------------------------------------------------------------------------------------

 [Module]: TIMER - Global and static variables - Functions definitions

 [File Name]: timer.c

 [Author]: Ebraheem Ali

 [Data Created]: May 1, 2022

 [Description]: This File contains definitions of Timer1 and global ,static variables.

 ------------------------------------------------------------------------------------*/

 #include "../../HELPERS/comman_macro.h"
 #include <avr/interrupt.h>
 #include <avr/io.h>
 #include "timer.h"


 static void (*g_Call_Back_Ptr)(void) = NULL_PTR;

 /*****************************************************************************************
  *              Timer Functions' Definitions
  *****************************************************************************************/
 /*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_init
 Function prototype:  void Timer1_init(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to initialize Timer1.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_init(void)
 {
    /* DISABLE PWM FOC1A=1 , FOC1B=1 */
    TCCR1A = FOC1A | FOC1B;
    TCNT1 = 0;
    OCR1A = TIMER1_VALUE;
    /*ENABLE CTC MODE, PRESCALER 1024 */
    TCCR1B = (1<<WGM12)|(1<<CS12)|(1<<CS10);
 }
 /*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_DeInit
 Function prototype:  void Timer1_DeInit(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to de-initialize Timer1.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_DeInit(void)
 {
    TCCR1A = 0;
    TCCR1B = TIMER1_STOP;
 }
 /*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_stop
 Function prototype:  void Timer1_stop(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to stop Timer1 from counting.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_stop(void)
 {
   TCCR1B &=~ ((1<<CS10)|(1<<CS11)|(1<<CS12));
 }
 /*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_start
 Function prototype:  void Timer1_start(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to start Timer1.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_start(void)
 {
   TCCR1B = (TCCR1B & 0xF8)|TIEMR1_1024_PRESCALER;
 }
 /*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_InterruptEnable
 Function prototype:  void Timer1_InterruptEnable(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to enable interrupt for Timer1.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_InterruptEnable(void)
 {
    SET_BIT(TIMSK,OCIE1A); /*ENABLE TIMER1 INTERRUPT */
 }
/*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_InterruptDisable
 Function prototype:  void Timer1_InterruptDisable(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to Disable interrupt for Timer1.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_InterruptDisable(void)
 {
    CLEAR_BIT(TIMSK,OCIE1A); /*ENABLE TIMER1 INTERRUPT */
 }
/*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_reset
 Function prototype:  void Timer1_reset(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to reset Timer1 to start count from zero.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_reset(void)
 {
    TCNT1 = 0;
 }
/*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_setCallBack
 Function prototype:  void Timer1_setCallBack(void (*FuncPtr)(void))
 Parameters[in]: [FuncPtr]-> Pointer to a function that the processor should implement when the 
   interrupt comes.
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Pass the call back function from the upper layer to the ISR.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_setCallBack(void (*FuncPtr)(void))
 {
    if (FuncPtr != NULL_PTR)
    {
        g_Call_Back_Ptr = FuncPtr;
    }
 }
/***************************************************************************************************/
 ISR(TIMER1_COMPA_vect)
 {
    if (g_Call_Back_Ptr != NULL_PTR)
    {
        (*g_Call_Back_Ptr)();
    }
 } 
