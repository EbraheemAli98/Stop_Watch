/*
 ---------------------------------------------------------------------------------------------------------------
File Name : button.h
	Author: Ebraheem Ali
	Version: v1.0
	Description: The file contains all functions declarations and definitions of Button module.

	Created on: May 1, 2022
 ---.------------------------------------------------------------------------------------------------------------
 */
#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../HELPERS/Std_types.h"

#define BUTTON_RESET_PORT_ID    3 /* PORTD */
#define BUTTON_RESET_PIN_ID     2 /* PD2 */

#define BUTTON_PAUSE_PORT_ID    3 /* PORTD */
#define BUTTON_PAUSE_PIN_ID     3 /* PD3 */

#define BUTTON_RESUME_PORT_ID   1 /* PORTB */
#define BUTTON_RESUME_PIN_ID    2 /* PB2 */



void Button_init(void);

void Button_reset(void);

void Button_pause(void);

void Button_resume(void);
#endif
