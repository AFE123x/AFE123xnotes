#include <stdint.h>
#include <stdio.h>
#include "stm32g070xx.h"

#define GPIOA_EN        (1U << 0)
#define USART2_EN       (1U << 17)

/* ---------- USART2 Functions ---------- */

void uart2_write_char(char ch) {
    while (!(USART2->ISR & (1U << 7)));  // Wait for TXE
    USART2->TDR = ch;
}

char uart2_read_char(void) {
    while (!(USART2->ISR & (1U << 5)));  // Wait for RXNE (bit 5)
    return USART2->RDR;
}

// Check if data is available to read
uint8_t uart2_available(void) {
    return (USART2->ISR & (1U << 5)) ? 1 : 0;
}

void uart2_print(const char *str) {
    while (*str) {
        uart2_write_char(*str++);
    }
}

// For printf support
int _write(int file, char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        uart2_write_char(*ptr++);
    }
    return len;
}

void uart2_init(void)
{
    /* Enable clocks */
    RCC->IOPENR  |= GPIOA_EN;
    RCC->APBENR1 |= USART2_EN;

    /* Select SYSCLK for USART2 */
    RCC->CCIPR &= ~(3U << 2);

    /* PA2 → USART2_TX (AF1), PA3 → USART2_RX (AF1) */
    // Configure PA2 and PA3 as alternate function
    GPIOA->MODER &= ~((3U << 4) | (3U << 6));
    GPIOA->MODER |=  ((2U << 4) | (2U << 6));

    // Set AF1 for both PA2 and PA3
    GPIOA->AFR[0] &= ~((0xF << 8) | (0xF << 12));
    GPIOA->AFR[0] |=  ((1U << 8) | (1U << 12));

    /* USART2 configuration */
    USART2->CR1 = 0;
    USART2->BRR = 139;                // 16 MHz / 115200 ≈ 139
    USART2->CR1 |= (1U << 3);         // TE enable
    USART2->CR1 |= (1U << 2);         // RE enable (receiver)
    USART2->CR1 |= (1U << 0);         // UE enable
}

/* ---------- Main ---------- */

int main(void)
{
    uart2_init();

    // Disable stdout buffering for immediate output
    setbuf(stdout, NULL);

    uart2_print("STM32G070RB UART Echo Test\r\n");
    uart2_print("Type something and press Enter:\r\n");

    char buffer[100];
    uint8_t index = 0;

    while (1) {
        if (uart2_available()) {
            char received = uart2_read_char();

            // Echo the character back
            uart2_write_char(received);

            // Store in buffer until Enter is pressed
            if (received == '\r' || received == '\n') {
                buffer[index] = '\0';  // Null terminate

                if (index > 0) {
                    uart2_print("\r\nYou typed: ");
                    uart2_print(buffer);
                    uart2_print("\r\n");

                    // Or using printf:
                    // printf("\r\nYou typed: %s\r\n", buffer);
                }

                index = 0;  // Reset buffer
                uart2_print("> ");
            }
            else if (received == 127 || received == 8) {  // Backspace
                if (index > 0) {
                    index--;
                    uart2_print("\b \b");  // Erase character on terminal
                }
            }
            else if (index < 99) {
                buffer[index++] = received;
            }
        }
    }
}
