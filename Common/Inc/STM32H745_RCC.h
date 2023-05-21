/*
 * STM32H745_RCC.h
 *
 *  Created on: May 6, 2023
 *      Author: MPV3KOR
 */

#ifndef STM32H745_RCC_H_
#define STM32H745_RCC_H_
#include "STM32H745_ZIQ_HAL_defines.h"

#define RCC_D3AMR_OFFSET 0x0A
#define RCC_BASE PERIPHERAL_BASE + D3_BASE + 0x24400UL
#define RCC_AHB4ENR *((volatile unsigned int*)(RCC_BASE + RCC_AHB4ENR_OFFSET ))
#define RCC_AHB1ENR *((volatile unsigned int*)(PERIPHERAL_BASE + 22000UL + 0x0D8))
#define RCC_APB2ENR *((volatile unsigned int*)(RCC_BASE + RCC_APB2ENR_OFFSET ))
#define RCC_D3AMR *((volatile unsigned int*)(RCC_BASE + RCC_D3AMR_OFFSET ))



#endif /* STM32H745_RCC_H_ */
