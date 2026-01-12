#include <stdint.h>
#include "stm32g070xx.h"

#define GPIOA_EN        (1U << 0)
#define GPIOC_EN        (1U << 2)

#define USART2_EN       (1U << 17)

#define GPIOA5          (1U << 5)

/* ---------- USART2 Functions ---------- */

void uart2_write_char(char c)
{
    /* Wait until TXE is set */
    while (!(USART2->ISR & (1U << 7))); //checks if TX queue is not full. We wait until it's not full.
    USART2->TDR = c;
}

void uart2_write_string(const char *str)
{
    while (*str) {
        uart2_write_char(*str++);
    }
}

void uart2_tx_init(void)
{
    /* Enable clocks */
    RCC->IOPENR  |= GPIOA_EN;
    RCC->APBENR1 |= USART2_EN;

    /* Select SYSCLK for USART2 */
    RCC->CCIPR &= ~(3U << 2);

    /* PA2 → USART2_TX (AF1) */
    GPIOA->MODER &= ~(3U << 4);
    GPIOA->MODER |=  (2U << 4);      // specify we want the alternate function of PA2
    /* clear the alternate function of PA2 */
    GPIOA->AFR[0] &= ~(0xF << 8);
    /* set alternate function for 1. on the datasheet, this is for USART2_TX */
    GPIOA->AFR[0] |=  (1U << 8);      // AF1

    /* USART2 configuration */
    USART2->CR1 = 0;				  //clearing register
    USART2->BRR = 139;                // 16 MHz / 115200 ≈ 139
    USART2->CR1 |= (1U << 3);         // TE enable
    USART2->CR1 |= (1U << 0);         // UE enable
}

/* ---------- Main ---------- */

int main(void)
{
    /* Enable GPIO clocks */
    RCC->IOPENR |= GPIOA_EN | GPIOC_EN;

    /* PA5 output (LED) */
    GPIOA->MODER &= ~(3U << 10);
    GPIOA->MODER |=  (1U << 10);

    /* PC13 input (button) */
    GPIOC->MODER &= ~(3U << 26);
    GPIOC->PUPDR &= ~(3U << 26);

    /* Init USART2 */
    uart2_tx_init();

    uint8_t button_pressed = 0;

    while (1) {
        /* Active-low button */
        if (!(GPIOC->IDR & (1U << 13))) {

            GPIOA->ODR |= GPIOA5;

            if (!button_pressed) {
                uart2_write_string("Button pressed!\r\n");
                button_pressed = 1;
            }

        } else {
            GPIOA->ODR &= ~GPIOA5;
            button_pressed = 0;
        }
    }
}
