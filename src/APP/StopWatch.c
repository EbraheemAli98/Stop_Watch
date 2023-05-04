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
#include "STOP_WATCH_MODULE/StopWatch.h"

unsigned char one_sec_flag = 0;
button_state_t state = DISPLAY;

int main(void)
{
	SET_LOW_NIBBLES(SEVEN_SEGMENT_DIR_REG,0x0F); /*SET BITS PC0-PC3 AS OUTPUT DISPLAY OF SEVEN_SEGMENT DECODER */
	SET_MASK_PORT(SEVEN_SEGMENT_DIR_DISPLAY_REG,0x3F); /* SET PA0-PA5 AS OUTPUT DISPLAY OF SEVEN_SEGMENT */
	INT0_reset_switch_init();
	INT1_pause_switch_init();
	INT2_resume_switch_init();
	TIMER1_init();
	SET_BIT(SREG,7); /* ENABLE GLOBAL INTERRUPT */

	while(1)
	{
		if(one_sec_flag == 1)  /* If one second is coming */
		{
			one_sec_flag = 0;
			SevenSegment_check();
		}
		SevenSegment_display();
		switch(state)  /* check if which interrupt occurs and implement its function */
		{
		default:
			break;
		case RESET:
			Reset();
			state = DISPLAY;
			break;
		case PAUSE:
			Pause();
			state = DISPLAY;
			break;
		case RESUME:
			Resume();
			state = DISPLAY;
			break;
		}
	}
}
/* INTERRUPT OF RESET_SWITCH */
ISR(INT0_vect)
{
	state = RESET;
}
/* INTERRUPT OF PAUSE_SWITCH */
ISR(INT1_vect)
{
	state = PAUSE;
}
/* INTERRUPT OF RESUME_SWITCH */
ISR(INT2_vect)
{
	state = RESUME;
}

ISR(TIMER1_COMPA_vect)
{
	one_sec_flag = 1; /* one _sec_flag is set every one second */

}/*END ISR */
