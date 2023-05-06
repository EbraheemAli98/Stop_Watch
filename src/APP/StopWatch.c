/*
 --------------------------------------------------------------------------------------------------------------------
File Name : StopWatch_app.c
	Author: Ebraheem Ali
	Version: v1.0
	Description: Control six 7-segments to keep increasing the time. the segments are controlled using three external
				 switches that also controls the time displayed by the 7-segments (reset, pause, resume).

	Created on: May 1, 2022
 --------------------------------------------------------------------------------------------------------------------
 */
#include "StopWatch.h"
#include "../HAL/BUTTON/button.h"
#include "../HAL/SEVEN_SEGMENT/seven_segment.h"
#include <avr/interrupt.h>



void StopWatch_init(void)
{
	Button_init();
	SevenSegment_init();
	sei();
}

void StopWatch_start(void)
{
	SevenSegment_display();
}

