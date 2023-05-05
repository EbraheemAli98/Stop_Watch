#include "../../MCAL/GPIO/gpio.h"
#include "seven_segment.h"
#include <avr/io.h>

volatile uint8 sec1_counter=0;	/* count the number of seconds displayed on the 1st segment in the left*/
volatile uint8 sec2_counter=0;	/* count the number of seconds displayed on the 2nd segment */
volatile uint8 min1_counter=0;	/* count the number of minites displayed on the 3rd segment */
volatile uint8 min2_counter=0;  /* count the number of minites displayed on the 4th segment */
volatile uint8 hour1_counter=0; /* count the number of hours displayed on the 5th segment */
volatile uint8 hour2_counter=0; /* count the number of hours displayed on the last segment in the right */

/*-------------------------------------------------------------------------------------------------
 Function Name: SevenSegment_display
 Function prototype: void SevenSegment_display(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to display the time on the seven-segment.
 --------------------------------------------------------------------------------------------------*/
void SevenSegment_display(void)
{
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,SEC1);    /* Set HIGH for SEC1 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,sec1_counter);	/* Display value of sec1_counter */
	_delay_ms(2);
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,SEC2); /* Set HIGH for SEC2 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,sec2_counter);	/* Display value of sec2_counter */
	_delay_ms(2);
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,MIN1); /* Set HIGH for MIN1 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,min1_counter);	/* Display value of min1_counter */
	_delay_ms(2);
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,MIN2); /* Set HIGH for MIN2 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,min2_counter);	/* Display value of min2_counter */
	_delay_ms(2);
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,HOURS1); /* Set HIGH for HOURS1 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,hour1_counter);	/* Display value of hour1_counter */
	_delay_ms(2);
	GPIO_writePort(SEVEN_SEGMENT_DATA_DISPLAY_REG,HOURS2); /* Set HIGH for HOURS2 only */
	GPIO_writePort(SEVEN_SEGMENT_DATA_REG,hour2_counter);	/* Display value of hour2_counter */
	_delay_ms(2);
}

/*-------------------------------------------------------------------------------------------------
 Function Name: SevenSegment_check
 Function prototype: void SevenSegment_check(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to count and tracking the time.
 --------------------------------------------------------------------------------------------------*/
void SevenSegment_check(void)
{
	sec1_counter++;
	if(sec1_counter == 10) /* return the LHS seven segment of the two that displays seconds to 0 after it reaches 9 */
	{
		sec1_counter = 0;
		sec2_counter++;		/* increase the RHS seven segment of the two segments that displays seconds by 1*/
	}
	if(sec1_counter == 0 && sec2_counter == 6)/* reset sec1 7-segments after 59 second and increase min1 by 1*/
	{
		min1_counter++;
		sec2_counter = 0;
	}/* end if */
	if(min1_counter == 10) /* return the LHS seven segment of the two that displays minutes to 0 after it reaches 9 */
	{
		min1_counter = 0;
		min2_counter++;		/* increase the RHS seven segment of the two segments that displays minutes by 1*/
	}/* end if */
	if(min1_counter == 0 && min2_counter == 6) /* reset min1 7-segments after 59 minute and increase hours by 1*/
	{
		min2_counter = 0;
		hour1_counter++;
	}
	if(hour1_counter == 10) /* return the LHS seven segment of the two that displays hours to 0 after it reaches 9 */
	{
		hour1_counter = 0;
		hour2_counter++;    /* increase the RHS seven segment of the two segments that displays hours by 1*/
	}
	if(hour2_counter == 2 && hour1_counter == 4) /* reset stop watch after 24 hours*/
	{
		hour1_counter = 0;
		hour2_counter = 0;
	}
}