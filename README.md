# Stop_Watch
### Project Description:
  #### Three push buttons:
      - reset button: used to reset the stop-watch and connects to the Atmega16 with a pull-down resistor.
      - pause button: used to stop the stop-watch from counting and connects to the ATmega16 with a pull-up resistor.
      - resume button: used to restart the stop-watch after pausing it and connects to ATmega16 with a pull-up resistor.
  #### 7-segment display screen:
      - Used to display the time in seconds, minutes and hours.
  #### Project Senario:
      - In the foreground/super-loop the 7-segment display screen will continue to display the time using Round-Robin method
        (this means it will display each segment alone for a small fraction of time (x) sequentially).
      - The time will continue to increase and the API that increases the timer value will be called back for Timer module
        each second when the Timer's ISR is triggered.
      - Each puch-button is attached to an external interrupt pin when the button is pressed its ISR will triggered causing a call
        back to its spacefic API to execute.
  #### Project Future Modifications:
      - use an extra timer channel to implement the API task (7-segment display time task) by setting this timer to fire an interrupt 
        each spacefic fraction on time and build a call back function that manage this task.
### Video explains the project in details:
 _ Link: https://drive.google.com/file/d/1nkU1p-iotGjHEJOgFTpBKsMZqi0eycjN/view?usp=sharing _
