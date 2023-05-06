/*
 ---------------------------------------------------------------------------------------------------------------
File Name : button.c
	Author: Ebraheem Ali
	Version: v1.0
	Description: The file contains all functions implementation of Button module.

	Created on: May 1, 2022
 ---.------------------------------------------------------------------------------------------------------------
 */
#include "button.h"
#include "../../MCAL/TIMER/timer.h"
#include "../../MCAL/EXT_INTERRUPT/ex_interrupt.h"
#include "../../MCAL/GPIO/gpio.h"

extern volatile uint8 g_sec1_counter;	/* count the number of seconds displayed on the 1st segment in the left*/
extern volatile uint8 g_sec2_counter;	/* count the number of seconds displayed on the 2nd segment */
extern volatile uint8 g_min1_counter;	/* count the number of minites displayed on the 3rd segment */
extern volatile uint8 g_min2_counter;  /* count the number of minites displayed on the 4th segment */
extern volatile uint8 g_hour1_counter; /* count the number of hours displayed on the 5th segment */
extern volatile uint8 g_hour2_counter; /* count the number of hours displayed on the last segment in the right */

void Button_init(void)
{
    GPIO_setupPinDirection(BUTTON_PAUSE_PORT_ID,BUTTON_PAUSE_PIN_ID,PIN_INPUT);
    GPIO_setupPinDirection(BUTTON_RESET_PORT_ID,BUTTON_RESET_PIN_ID,PIN_INPUT);
    GPIO_setupPinDirection(BUTTON_RESUME_PORT_ID,BUTTON_RESUME_PIN_ID,PIN_INPUT);

    GPIO_writePin(BUTTON_PAUSE_PORT_ID,BUTTON_PAUSE_PIN_ID,LOGIC_HIGH);	  /* PAUSE_SW IS PULLUP */
    GPIO_writePin(BUTTON_RESUME_PORT_ID,BUTTON_RESUME_PIN_ID,LOGIC_HIGH); /* RESUME_SW IS PULLUP */

	ExtInt_setCallBackInt0(Button_pause);
	ExtInt_setCallBackInt1(Button_reset);
	ExtInt_setCallBackInt2(Button_resume);

	ExtInt_init(&ExtIntConfigObj);
}

void Button_reset(void)
{
	Timer1_reset();
	g_sec1_counter = 0;
	g_sec2_counter = 0;
	g_min1_counter = 0;
	g_min2_counter = 0;
	g_hour1_counter = 0;
	g_hour2_counter = 0;
}

void Button_pause(void)
{
	Timer1_stop();
}

void Button_resume(void)
{
	Timer1_start();
}
