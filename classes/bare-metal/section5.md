# Section 5. The System Tick (SysTick) Timer

## what is the SYSTICK timer

- this is in all arm microcontrollers.
- this is usually used for taking actions periodically.
    - often used as time-base for real-time operating systems.
- The Systick uses a 24-bit down counter driven by the processor clock.
    - it'll count from `0xFFFFFF` down to 0, but you can set the initial value to whatever you want.

## systick registers

- Systick Current Value Register (STCVR): holds the current systick count value.
- Systick Control and Status Register (STCSR): lets us configure the systick clock source.
    - we can enable/disable interrupts and systick counter.
- systick reload value register (STRVR): where the initial count value is placed.


## calculating time value with systick count

- You need to look at the clock speed.
    - for the STM32G070RB, it's 16 MHz, or `16,000,000` cycles/second.

- Doing some math, you can deduce that each cycle will take 1/1,600,000 seconds.
    - you can use this for the actual calculation.

## systick documentation

- Since systick is a standard for arm, you can use the `Cortex-M4 Generic User Guide`.