/*
 ---------------------------------------------------------------------------------------------------------------
File Name : main.c
	Author: Ebraheem Ali
	Version: v1.0
	Description: Control six 7-segments to keep increasing the time. the segments are controlled using three external
				 switches that also controls the time displayed by the 7-segments (reset, pause, resume).

	Created on: May 1, 2022
 ---------------------------------------------------------------------------------------------------------------
 */

#include "APP/StopWatch.h"

int main(void)
{
    StopWatch_init();
    for(;;)
    {
        StopWatch_start();
    }
}