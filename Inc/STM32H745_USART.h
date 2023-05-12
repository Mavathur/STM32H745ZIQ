/*
 * STM32H745_USART.h
 *
 *  Created on: May 6, 2023
 *      Author: MPV3KOR
 */

#ifndef STM32H745_USART_H_
#define STM32H745_USART_H_

#include "STM32H745_ZIQ_HAL_defines.h"
//D2, APB2
#define USART1_CR1_OFFSET 0x00
#define USART1_CR1 *((volatile unsigned int*)(USART1 + USART1_CR1_OFFSET))
#define USART_ENABLE (0x01UL << 0)
#define USART_TRANSMIT_ENABLE (0x01UL << 3)
#define USART_RECEIVE_ENABLE  (0x01UL << 2)

#define USART_CR2
#define USART_ISR
#define USART_RQR
#define USART_ICR

#define USART_TDR
#define USART_RDR
#define USART_BRR
#define USART_PRESC 

void USART_INIT(void)
{
    USART1_CR1 |= USART_TRANSMIT_ENABLE;
    USART1_CR1 |= USART_RECEIVE_ENABLE;
    USART1_CR1 |= USART_ENABLE;
}



#endif /* STM32H745_USART_H_ */
