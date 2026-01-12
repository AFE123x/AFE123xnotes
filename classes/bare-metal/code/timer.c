/*
 * timer.c
 *
 *  Created on: Jan 17, 2026
 *      Author: afe123x
 */

#include "timer.h"
#include "stm32g070xx.h"

#define TIM1EN (1U << 11)
#define CEN (1U << 0)
#define GPIOA_EN (1U << 0)
#define GPIOA4 (2U << 8)
#define GPIOA4ALT (4U << 16)

#define OC1M (1U << 6) | (1U << 5)  // PWM mode 1 (bits 6:4 = 110)
#define OC1PE (1U << 3)  // Output compare preload enable
#define CC1E (1U << 0)   // Capture/Compare 1 output enable
#define TIM14EN (1U << 15)  // Add this at the top with other defines

int tim1_init(void)
{
    /* enable timer 1 clock */
    RCC->APBENR2 |= TIM1EN;

    /* set prescaler: 16MHz / 1600 = 10kHz */
    TIM1->PSC = 1599;  // (1600 - 1)

    /* set autoload: 10kHz / 10000 = 1Hz (1 second) */
    TIM1->ARR = 9999;  // (10000 - 1)

    /* clear current count */
    TIM1->CNT = 0;

    /* enable counter */
    TIM1->CR1 |= CEN;

    return 0;
}

int tim14_init(void) //our output counter2
{
    /* enable GPIOA clock */
    RCC->IOPENR |= GPIOA_EN;

    /* Set pin mode of GPIOA, pin 4 to alternate function */
    GPIOA->MODER &= ~(3U << 8);  // Clear both bits for PA4
    GPIOA->MODER |= (2U << 8);   // Set to alternate function mode (10)

    /* Configure GPIOA4 to use TIM14 CH1 function (AF4) */
    GPIOA->AFR[0] &= ~(0xFU << 16);  // Clear AF bits for PA4
    GPIOA->AFR[0] |= GPIOA4ALT;      // Set AF4

    /* enable the TIM14 clock */
    RCC->APBENR2 |= TIM14EN;

    /* Set prescaler and auto-reload */
    TIM14->PSC = 495;
    TIM14->ARR = 64515;

    /* Set compare value for 50% duty cycle - THIS WAS MISSING! */
    TIM14->CCR1 = 31758;  // 50% of 64516

    /* Configure CH1 as PWM mode 1 */
    TIM14->CCMR1 |= (6U << 4);  // OC1M = 110 (PWM mode 1)

    /* enable prload register, meaning read/write operations to TIMx_CCR1 registers will not be loaded until the update event happens.*/
    TIM14->CCMR1 |= OC1PE;      // Enable preload

    /* Enable CH1 output */
    TIM14->CCER |= CC1E;

    /* Clear counter */
    TIM14->CNT = 0;

    /* Enable counter */
    TIM14->CR1 |= CEN;

    return 0;
}
