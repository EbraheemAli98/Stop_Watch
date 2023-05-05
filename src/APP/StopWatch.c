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


void StopWatch_init(void)
{
	Timer1_init();
	Timer1_setCallBack(SevenSegment_check);
	ExtInt_init(&ExtIntConfigObj);
	ExtInt_setCallBackInt0(StopWatch_reset);
	ExtInt_setCallBackInt1(StopWatch_pause);
	ExtInt_setCallBackInt2(StopWatch_resume);
	Button_init();
	SevenSegment_init();
	Timer1_InterruptEnable();
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

