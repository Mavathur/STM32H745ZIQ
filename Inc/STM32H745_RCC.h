/*
 * STM32H745_RCC.h
 *
 *  Created on: May 6, 2023
 *      Author: MPV3KOR
 */

#ifndef STM32H745_RCC_H_
#define STM32H745_RCC_H_
#include "STM32H745_ZIQ_HAL_defines.h"

#define RCC_BASE PERIPHERAL_BASE + 0x18024400UL
#define RCC_AHB4ENR *((volatile unsigned int*)(RCC_BASE + RCC_AHB4ENR_OFFSET ))




#endif /* STM32H745_RCC_H_ */
