/*
 * STM32H745_GPIO.h
 *
 *  Created on: May 6, 2023
 *      Author: MPV3KOR
 */

#ifndef STM32H745_GPIO_H_
#define STM32H745_GPIO_H_

#include "STM32H745_ZIQ_HAL_defines.h"
#include "STM32H745_RCC.h"
#include "pthread.h"
#include <unistd.h>

typedef struct
{
	uint8_t blinkTime;
	uint8_t blinkCount;
}BlinkInfo;

void vBlinkRedLED(BlinkInfo ts);
void vBlinkOrangeLED(BlinkInfo ts);
void vBlinkYellowLED(BlinkInfo ts);


#define GPIOB_MODER     *((volatile unsigned int*)(GPIO_B_BASE + 0x00UL))
#define GPIOB_ODR       *((volatile unsigned int*)(GPIO_B_BASE + 0x14UL))
#define GPIOB_BSRR      *((volatile unsigned int*)(GPIO_B_BASE + 0x18UL))

#define GPIOE_MODER     *((volatile unsigned int*)(GPIO_E_BASE + 0x00UL))
#define GPIOE_ODR       *((volatile unsigned int*)(GPIO_E_BASE + 0x14UL))
#define GPIOE_BSRR      *((volatile unsigned int*)(GPIO_E_BASE + 0x18UL))

void vBlinkYellowLED(BlinkInfo ts)
{
	RCC_AHB4ENR |= (1U<<4);

    GPIOE_MODER |= (1U<<2);
    GPIOE_MODER &= ~(1U<<3);

    GPIOE_ODR  |= PIN1;

    for(uint8_t count=0;count< ts.blinkCount;count++)
    {
    	GPIOE_BSRR  &= ~RESETPIN1;
    	GPIOE_BSRR  |= PIN1;
		for(int a=0;a<100000*ts.blinkTime;a++){}
		GPIOE_BSRR  &= ~PIN1;
		GPIOE_BSRR  |=  RESETPIN1;
		for(int a=0;a<100000*ts.blinkTime;a++){}
    }
}

void vBlinkGreenLED(BlinkInfo ts)
{
	RCC_AHB4ENR |= (1U<<1);

    GPIOB_MODER |= (1U<<0);
    GPIOB_MODER &= ~(1U<<1);

    GPIOB_ODR  |= PIN0;
    for(uint8_t count=0;count< ts.blinkCount;count++)
    {
    	GPIOB_BSRR  &= ~(1U<<16);
    	GPIOB_BSRR  |= PIN0;

    	for(int a=0;a<100000*ts.blinkTime;a++){}

    	GPIOB_BSRR  &= ~PIN0;
    	GPIOB_BSRR  |= RESETPIN0;

    	for(int a=0;a<100000*ts.blinkTime;a++){}
    }
}

void vBlinkRedLED(BlinkInfo ts)
{
	RCC_AHB4ENR |= (1U<<1);

    GPIOB_MODER |= (1U<<28);
    GPIOB_MODER &= ~(1U<<29);

    GPIOB_ODR  |= PIN14;

    for(uint8_t count=0;count<ts.blinkCount;count++)
    {
    	GPIOB_BSRR  &= ~RESETPIN14;
    	GPIOB_BSRR  |= PIN14;
    	for(int a=0;a<100000*ts.blinkTime;a++){}
    	GPIOB_BSRR  &= ~PIN14;
    	GPIOB_BSRR  |= RESETPIN14;
    	for(int a=0;a<100000*ts.blinkTime;a++){}
    }
}

#endif /* STM32H745_GPIO_H_ */
