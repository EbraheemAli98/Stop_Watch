# Stop_Watch
### Project Description:
  #### 1) Three push buttons:
      - reset button: used to reset the stop-watch and connects to the Atmega16 with a pull-down resistor.
      - pause button: used to stop the stop-watch from counting and connects to the ATmega16 with a pull-up resistor.
      - resume button: used to restart the stop-watch after pausing it and connects to ATmega16 with a pull-up resistor.
  #### 2) 7-segment display screen:
      - Used to display the time in seconds, minutes and hours.
  #### Project Senario:
      - In the foreground/super-loop the 7-segment display screen will continue to display the time using Round-Robin method
        (this means it will display each segment alone for a small fraction of time (x) sequentially).
      - The time will continue increase each second and the API that increases the timer value will be called back for Timer module
        each second when the ISR is triggered.
      - 
### Video explains the project
  Link: https://drive.google.com/file/d/1nkU1p-iotGjHEJOgFTpBKsMZqi0eycjN/view?usp=sharing
