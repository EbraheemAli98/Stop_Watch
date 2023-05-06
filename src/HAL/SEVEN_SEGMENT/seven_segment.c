#include "../../MCAL/GPIO/gpio.h"
#include "../../MCAL/TIMER/timer.h"
#include "seven_segment.h"
#include <util/delay.h>

volatile uint8 g_sec1_counter=0;	/* count the number of seconds displayed on the 1st segment in the left*/
volatile uint8 g_sec2_counter=0;	/* count the number of seconds displayed on the 2nd segment */
volatile uint8 g_min1_counter=0;	/* count the number of minites displayed on the 3rd segment */
volatile uint8 g_min2_counter=0;  /* count the number of minites displayed on the 4th segment */
volatile uint8 g_hour1_counter=0; /* count the number of hours displayed on the 5th segment */
volatile uint8 g_hour2_counter=0; /* count the number of hours displayed on the last segment in the right */


/*********************************************************************************
 *                  Functions' Definitions
 ********************************************************************************/
/*-------------------------------------------------------------------------------------------------
 Function Name: SevenSegment_init
 Function prototype: void SevenSegment_init(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to initialize the 7-segment.
 --------------------------------------------------------------------------------------------------*/
void SevenSegment_init(void)
{
	/*SET BITS PC0-PC3 AS OUTPUT DISPLAY OF SEVEN_SEGMENT DECODER */
	GPIO_setupPortDirection(SEVEN_SEGMENT_DIR_REG,0x0F);
	/* SET PA0-PA5 AS OUTPUT DISPLAY OF SEVEN_SEGMENT */
	GPIO_setupPortDirection(SEVEN_SEGMENT_DIR_DISPLAY_REG,0x3F);

	Timer1_init();
	Timer1_setCallBack(SevenSegment_check);
	Timer1_InterruptEnable();
}
/*-------------------------------------------------------------------------------------------------
 Function Name: SevenSegment_display
 Function prototype: void SevenSegment_display(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to display the time on 7-segments using Round-robin technique.
 --------------------------------------------------------------------------------------------------*/
void SevenSegment_display(void)
{
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,SEC1);    /* Set HIGH for SEC1 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,g_sec1_counter);	/* Display value of sec1_counter */
	_delay_ms(4);
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,SEC2); /* Set HIGH for SEC2 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,g_sec2_counter);	/* Display value of sec2_counter */
	_delay_ms(4);
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,MIN1); /* Set HIGH for MIN1 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,g_min1_counter);	/* Display value of min1_counter */
	_delay_ms(4);
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,MIN2); /* Set HIGH for MIN2 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,g_min2_counter);	/* Display value of min2_counter */
	_delay_ms(4);
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,HOURS1); /* Set HIGH for HOURS1 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,g_hour1_counter);	/* Display value of hour1_counter */
	_delay_ms(4);
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,HOURS2); /* Set HIGH for HOURS2 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,g_hour2_counter);	/* Display value of hour2_counter */
	_delay_ms(4);
}

/*-------------------------------------------------------------------------------------------------
 Function Name: SevenSegment_check
 Function prototype: void SevenSegment_check(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function computes time and implements an algorithm to control the stop-watch counters
 --------------------------------------------------------------------------------------------------*/
void SevenSegment_check(void)
{
	g_sec1_counter++;
	if(g_sec1_counter == 10) /* return the LHS seven segment of the two that displays seconds to 0 after it reaches 9 */
	{
		g_sec1_counter = 0;
		g_sec2_counter++;		/* increase the RHS seven segment of the two segments that displays seconds by 1*/
	}
	if(g_sec1_counter == 0 && g_sec2_counter == 6)/* reset sec1 7-segments after 59 second and increase min1 by 1*/
	{
		g_min1_counter++;
		g_sec2_counter = 0;
	}/* end if */
	if(g_min1_counter == 10) /* return the LHS seven segment of the two that displays minutes to 0 after it reaches 9 */
	{
		g_min1_counter = 0;
		g_min2_counter++;		/* increase the RHS seven segment of the two segments that displays minutes by 1*/
	}/* end if */
	if(g_min1_counter == 0 && g_min2_counter == 6) /* reset min1 7-segments after 59 minute and increase hours by 1*/
	{
		g_min2_counter = 0;
		g_hour1_counter++;
	}
	if(g_hour1_counter == 10) /* return the LHS seven segment of the two that displays hours to 0 after it reaches 9 */
	{
		g_hour1_counter = 0;
		g_hour2_counter++;    /* increase the RHS seven segment of the two segments that displays hours by 1*/
	}
	if(g_hour2_counter == 2 && g_hour1_counter == 4) /* reset stop watch after 24 hours*/
	{
		g_hour1_counter = 0;
		g_hour2_counter = 0;
	}
}
