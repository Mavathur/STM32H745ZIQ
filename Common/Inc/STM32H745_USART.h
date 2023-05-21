/*
 * STM32H745_USART.h
 *
 *  Created on: May 6, 2023
 *      Author: MPV3KOR
 */

#ifndef STM32H745_USART_H_
#define STM32H745_USART_H_

#include "STM32H745_ZIQ_HAL_defines.h"
#include "STM32H745_GPIO.h"
//D2, APB2
#define USART_CR1_OFFSET 0x00
#define USART_CR2_OFFSET 0x04
#define USART_ISR_OFFSET 0x1C
#define USART_TDR_OFFSET 0x28
#define USART_RDR_OFFSET 0x24

#define USART1_CR1 *((volatile unsigned int*)(USART1 + USART_CR1_OFFSET))
#define USART_ENABLE (0x01UL << 0)
#define USART_TRANSMIT_ENABLE (0x01UL << 3)
#define USART_RECEIVE_ENABLE  (0x01UL << 2)
#define USART_FIFO_ENABLE  (0x01UL << 29)
#define SYSCLK_FREQ  16000000
#define USART_BAUDRATE 115200
#define USART_BRR_OFFSET 0x0CUL

#define GPIOA_AFRH *((volatile unsigned int*)(GPIO_A_BASE + GPIO_AFRH_OFFSET))

#define USART_CR2  *((volatile unsigned int*)(USART1 + USART_CR2_OFFSET))
#define USART_ISR  *((volatile unsigned int*)(USART1 + USART_ISR_OFFSET))
//#define USART_RQR
//#define USART_ICR

#define USART_TDR  *((volatile unsigned int*)(USART1 + USART_TDR_OFFSET))
#define USART_RDR  *((volatile unsigned int*)(USART1 + USART_RDR_OFFSET))
#define USART_BRR  *((volatile unsigned int*)(USART1 + USART_BRR_OFFSET))
//#define USART_BRR
//#define USART_PRESC
//static uint16_t compute_uart_div(uint32_t periph_clk, uint32_t BaudRate);


void USART_INIT(void)
{

    RCC_AHB4ENR |= (0x01UL <<0);

    GPIOA_MODER &= ~(0x01UL <<18);
    GPIOA_MODER |= (0x01UL <<19);

    GPIOA_MODER &= ~(0x01UL <<20);
    GPIOA_MODER |= (0x01UL <<21);

    RCC_APB2ENR |= (0x01UL <<4);

    GPIOA_AFRH |= 0x01UL<<4;
    GPIOA_AFRH |= 0x01UL<<5;
    GPIOA_AFRH |= 0x01UL<<6;
    GPIOA_AFRH &= ~(0x01UL<<7);

    GPIOA_AFRH |= 0x01UL<<8;
    GPIOA_AFRH |= 0x01UL<<9;
    GPIOA_AFRH |= 0x01UL<<10;
    GPIOA_AFRH &= ~(0x01UL<<11);

    USART_BRR  = (uint16_t)((8000000)/115200);

    USART1_CR1 = USART_TRANSMIT_ENABLE;
//    USART1_CR1 |= USART_FIFO_ENABLE;

//    USART1_CR1 |= USART_RECEIVE_ENABLE;

	USART1_CR1 |= USART_ENABLE;

}

void writeToUSART(int ch)
{
	while(0 != (USART_ISR & (0x01UL<<7)))
	{
		USART_TDR |= (ch & 0xFF);
	}
}

//static uint16_t compute_uart_div(uint32_t periph_clk, uint32_t BaudRate)
//{
//	return ((periph_clk + (BaudRate/2U))/BaudRate);
//}


#endif /* STM32H745_USART_H_ */
