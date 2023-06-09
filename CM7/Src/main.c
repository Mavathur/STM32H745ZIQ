/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "STM32H745_GPIO.h"
int main(void)
{

	BlinkInfo _GreeLED = {8, 6};
	BlinkInfo _YellowLED = {8,3};
	BlinkInfo _RedLED = {8,6};


//	vBlinkRedLED(_RedLED);

//	vBlinkYellowLED(_YellowLED);

	vBlinkGreenLED(_GreeLED);

}
