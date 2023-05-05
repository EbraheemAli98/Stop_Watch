#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

/*********************************************************************************
 *                  MACROS Definitions
 ********************************************************************************/
#define SEC1   0x01	/* Left seconds 7-segment */
#define SEC2   0x02 /* Right seconds 7-segment */
#define MIN1   0x04	/* Left minutes 7-segment */
#define MIN2   0x08	/* Right minutes 7-segment */
#define HOURS1 0x10	/* Left hours 7-segment */
#define HOURS2 0x20	/* Right hours 7-segment */


#define SEVEN_SEGMENT_DATA_REG     PORTC /* PORTC is the port displays the data on the segments and it is connected with its decoder */
#define SEVEN_SEGMENT_DIR_REG      DDRC

#define SEVEN_SEGMENT_DATA_DISPLAY_REG PORTA  /* PORTA contains the pins that controls the display of the segments */
#define SEVEN_SEGMENT_DIR_DISPLAY_REG  DDRA

/*********************************************************************************
 *                  Functions' Prototypes
 ********************************************************************************/
/*-------------------------------------------------------------------------------------------------
 Function Name: SevenSegment_init
 Function prototype: void SevenSegment_init(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Descript)ion: Function to initialize the 7-segment.
 --------------------------------------------------------------------------------------------------*/
void SevenSegment_init(void);
/*-------------------------------------------------------------------------------------------------
 Function Name: SevenSegment_display
 Function prototype: void SevenSegment_display(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function to display the time on 7-segments using Round-robin technique
 --------------------------------------------------------------------------------------------------*/
void SevenSegment_display(void); 
/*-------------------------------------------------------------------------------------------------
 Function Name: SevenSegment_check
 Function prototype: void SevenSegment_check(void)
 Parameters[in]: None
 Parameters[out]: None
 Parameters[in/out]: None
 Return : void
 Description: Function computes time and implements an algorithm to control the stop-watch counters
 --------------------------------------------------------------------------------------------------*/
void SevenSegment_check(void);  

#endif