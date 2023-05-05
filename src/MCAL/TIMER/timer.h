/*-----------------------------------------------------------------------------

 [Module]: TIMER - Macros and Functions prototype

 [File Name]: timer.h

 [Author]: Ebraheem Ali

 [Data Created]: May 1, 2022

 [Description]: static and dynamic configuration of Timer module.

 -------------------------------------------------------------------------------*/

  #include "../../HELPERS/Std_types.h"
 /*****************************************************************************************
  *              Timer Macros Definitions
  *****************************************************************************************/
  #define TIMER1_VALUE    1000

  #define TIMER1_NORMAL_MODE    0x00
  #define TIMER1_CTC_MODE       0x08
 
  #define TIMER1_STOP           0x00
  #define TIMER1_NO_PRESCALER   0x01
  #define TIMER1_8_PRESCALER    0x02
  #define TIMER1_64_PRESCALER   0x03
  #define TIMER1_256_PRESCALER  0x04
  #define TIEMR1_1024_PRESCALER 0x05
  
 /*****************************************************************************************
  *              Timer Functions' Declaration
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
 void Timer1_init(void);
/*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_DeInit
 Function prototype:  void Timer1_DeInit(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to de-initialize Timer1.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_DeInit(void);
/*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_start
 Function prototype:  void Timer1_start(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to start Timer1.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_start(void);
/*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_stop
 Function prototype:  void Timer1_stop(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to stop Timer1 from counting.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_stop(void);
/*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_reset
 Function prototype:  void Timer1_reset(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to reset Timer1 to start count from zero.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_reset(void);
/*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_InterruptEnable
 Function prototype:  void Timer1_InterruptEnable(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to enable interrupt for Timer1.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_InterruptEnable(void);
/*-------------------------------------------------------------------------------------------------
 Function Name: Timer1_InterruptDisable
 Function prototype:  void Timer1_InterruptDisable(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to Disable interrupt for Timer1.
 --------------------------------------------------------------------------------------------------*/
 void Timer1_InterruptDisable(void);
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
 void Timer1_setCallBack(void (*FuncPtr)(void));