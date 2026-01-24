#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "stm32g070xx.h"

#define GPIOA_EN        (1U << 0)
#define ADC_EN          (1U << 20)
#define USART2_EN       (1U << 17)

/* ---------- USART2 Functions ---------- */

void uart2_write_char(char ch) {
    while (!(USART2->ISR & (1U << 7)));
    USART2->TDR = ch;
}

int _write(int file, char *ptr, int len) {
    for (int i = 0; i < len; i++) {
        uart2_write_char(*ptr++);
    }
    return len;
}

void uart2_init(void)
{
    RCC->IOPENR  |= GPIOA_EN;
    RCC->APBENR1 |= USART2_EN;
    RCC->CCIPR &= ~(3U << 2);

    /* PA2 → TX, PA3 → RX */
    GPIOA->MODER &= ~((3U << 4) | (3U << 6));
    GPIOA->MODER |=  ((2U << 4) | (2U << 6));
    GPIOA->AFR[0] &= ~((0xF << 8) | (0xF << 12));
    GPIOA->AFR[0] |=  ((1U << 8) | (1U << 12));

    USART2->CR1 = 0;
    USART2->BRR = 139;
    USART2->CR1 |= (1U << 3) | (1U << 2);  // TE, RE
    USART2->CR1 |= (1U << 0);              // UE
}

/* ---------- ADC Functions ---------- */

void adc_init(void)
{
    /* Enable ADC clock */
    RCC->APBENR2 |= ADC_EN;

    /* Configure PA0 as analog input (ADC_IN0) */
    RCC->IOPENR |= GPIOA_EN;
    GPIOA->MODER |= (3U << 0);  // PA0 analog mode

    /* ADC voltage regulator enable (bit 28) */
    ADC1->CR = 0;
    ADC1->CR |= (1U << 28);  // ADVREGEN - enables the ADC voltage regulator

    /* Wait for voltage regulator startup time (~20us) */
    for(volatile int i = 0; i < 1000; i++);

    /* ADC calibration */
    ADC1->CR |= (1U << 31);  // Start the calibration process
    while(ADC1->CR & (1U << 31)); // once this bit is finished, the ADCAL bit will reset to zero.

    /* Configure ADC */
    ADC1->CFGR1 = 0;
    ADC1->CFGR1 &= ~(3U << 3);   // select the clock resolution
    ADC1->CFGR1 &= ~(1U << 13);  // toggle between single and continuous mode.

    /* Select ADC clock: PCLK/2 */
    ADC1->CFGR2 &= ~(3U << 30); //clear clock mode
    ADC1->CFGR2 |= (1U << 30); //set clock mode to PCLK/2

    /* set the sampling time */
    ADC1->SMPR &= ~(7U << 0);
    ADC1->SMPR |= (6U << 0); //we're setting it to 79.5 ADC clock cycles.

    /**
     * Select channel 0 (PA0) for conversion
     * there are two modes for this: regular and sequential:
     * In the regular mode, you enable the channels you want to read from, and it'll read them in order.
     * In the sequential mode, you set up a sequence of channels to read one after another. TDLR, you can customize the order. 
     */
    ADC1->CHSELR = (1U << 0);  // Channel 0 (PA0)

    /* Enable ADC */
    ADC1->ISR |= (1U << 0);    // Clear ADRDY flag
    ADC1->CR |= (1U << 0);     // ADEN
    while(!(ADC1->ISR & (1U << 0)));  // Wait for ADC ready
}

uint16_t adc_read(void)
{
    /* Start conversion */
    //ADC1->CR |= (1U << 2);  // ADSTART - only needed if single mode is set.

    /* Wait for conversion complete */
    while(!(ADC1->ISR & (1U << 2)));  // Wait for EOC (End of Conversion)

    /* Read and return result */
    return ADC1->DR;
}

float adc_to_voltage(uint16_t adc_value)
{
    // Assuming 3.3V reference and 12-bit ADC (0-4095)
    return (adc_value * 3.3f) / 4095.0f;
}

/* ---------- Simple Delay ---------- */

void delay_ms(uint32_t ms)
{
    for(uint32_t i = 0; i < ms * 1000; i++) {
        __NOP();
    }
}

/* ---------- Main ---------- */

int main(void)
{
    uart2_init();
    adc_init();

    setbuf(stdout, NULL);  // Disable buffering

    printf("STM32G070RB ADC Reading Test\r\n");
    printf("Reading from PA0 (ADC_IN0)\r\n");
    printf("Connect a voltage (0-3.3V) to PA0\r\n\n");

    while (1) {
        uint16_t adc_value = adc_read();
        float voltage = adc_to_voltage(adc_value);
        printf("ADC Value: %4d  |  Voltage: %d V\r\n", adc_value, (int)voltage);

        delay_ms(500);  // Read every 500ms
    }
}
