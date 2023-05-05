/*
 ---------------------------------------------------------------------------------------------------------------
File Name : button.c
	Author: Ebraheem Ali
	Version: v1.0
	Description: The file contains all functions implementation of Button module.

	Created on: May 1, 2022
 ---.------------------------------------------------------------------------------------------------------------
 */
#include "../../HELPERS/comman_macro.h"
#include "button.h"
#include "../../MCAL/GPIO/gpio.h"

void Button_init(void)
{
    GPIO_setupPinDirection(BUTTON_RESET_PORT_ID,BUTTON_RESET_PIN_ID,PIN_INPUT);
    GPIO_setupPinDirection(BUTTON_PAUSE_PORT_ID,BUTTON_PAUSE_PIN_ID,PIN_INPUT);
    GPIO_setupPinDirection(BUTTON_RESUME_PORT_ID,BUTTON_RESUME_PIN_ID,PIN_INPUT);

    GPIO_writePin(BUTTON_RESET_PORT_ID,BUTTON_RESET_PIN_ID,LOGIC_HIGH); /* RESET_SW IS PULLUP */
    GPIO_writePin(BUTTON_RESUME_PORT_ID,BUTTON_RESUME_PIN_ID,LOGIC_HIGH); /* RESUME_SW IS PULLUP */
}