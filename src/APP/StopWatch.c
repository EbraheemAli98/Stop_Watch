/*
 ---------------------------------------------------------------------------------------------------------------
File Name : StopWatch_app.c
	Author: Ebraheem Ali
	Version: v1.0
	Description: Control six 7-segments to keep increasing the time. the segments are controlled using three external
				 switches that also controls the time displayed by the 7-segments (reset, pause, resume).

	Created on: May 1, 2022
 ---------------------------------------------------------------------------------------------------------------
 */
#include "StopWatch.h"
#include "../MCAL/TIMER/timer.h"
#include "../HAL/BUTTON/button.h"
#include "../MCAL/EXT_INTERRUPT/ex_interrupt.h"
#include "../HAL/SEVEN_SEGMENT/seven_segment.h"
#include <avr/io.h>
#include <avr/interrupt.h>

extern volatile uint8 sec1_counter;	/* count the number of seconds displayed on the 1st segment in the left*/
extern volatile uint8 sec2_counter;	/* count the number of seconds displayed on the 2nd segment */
extern volatile uint8 min1_counter;	/* count the number of minites displayed on the 3rd segment */
extern volatile uint8 min2_counter;  /* count the number of minites displayed on the 4th segment */
extern volatile uint8 hour1_counter; /* count the number of hours displayed on the 5th segment */
extern volatile uint8 hour2_counter; /* count the number of hours displayed on the last segment in the right */
extern volatile uint8 flag;

void StopWatch_init(void)
{
	Button_init();
	SevenSegment_init();
	ExtInt_init(&ExtIntConfigObj);
	ExtInt_setCallBackInt0(StopWatch_reset);
	ExtInt_setCallBackInt1(StopWatch_pause);
	ExtInt_setCallBackInt2(StopWatch_resume);
	SREG |= (1<<7);
}

void StopWatch_start(void)
{
	SevenSegment_display();
}

void StopWatch_reset(void)
{
	Timer1_reset();
	sec1_counter = 0;
	sec2_counter = 0;
	min1_counter = 0;
	min2_counter = 0;
	hour1_counter = 0;
	hour2_counter = 0;
}

void StopWatch_pause(void)
{
	Timer1_stop();
}

void StopWatch_resume(void)
{
	Timer1_start();
}

