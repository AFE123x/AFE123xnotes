/*
 * systick.c
 *
 *  Created on: Jan 16, 2026
 *      Author: afe123x
 */

#include "systick.h"
#include "stm32g070xx.h"

#define SAMPLE_VALUE 16000
#define SYSTICK_ENABLE (1U << 0)
#define SYSTICK_CLKSRC (1U << 2)
#define SYSTICK_COUNTFLAG (1U << 16)
void delayMs(int ms)
{
	/* step one: load SAMPLE_VALUE in SysTick Reload Value Register */
	SysTick->LOAD = SAMPLE_VALUE;
	/* reset the value in the current value register to 0*/
	SysTick->VAL = 0;
	/* enable systick timer and use system clock*/
	SysTick->CTRL = SYSTICK_ENABLE | SYSTICK_CLKSRC;
	int i = 0;
	for (i = 0; i < ms; i++) {
		/* the countflag register returns 1 if the timer counted to 0. */
		while((SysTick->CTRL & SYSTICK_COUNTFLAG) == 0);
	}
	SysTick->CTRL = 0;
}
