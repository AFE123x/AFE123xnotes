# Section 6. General Purpose Timers

## Timers vs. Counters

- Timers are internal clock sources, like a PLL, XTAL
- A Counter is a external clock source fed to the CPU.


## Timer use cases

- We can generate a time base (a time reference)
- We can measure the frequency of an extern event (called **input capture mode**)
- Control an output waveform, o rindicate when a period of time has elapsed (called **output compare mode**)
- **one pulse mode (OPM)** allows the conuter to be started in response to a stimulus and to generate a pulse with programmable length after a certain delay.

## Timer Registers

- **Timer Count Register (TIMx_CNT)**, which shows the current counter value. It could be 32 or 16 bits depending on the timer module used.
- **Timer Auto-Reload register(TIMx_ARR)** timer will raise a flag, and the conuter will restart automatically once the counter reaches the value specified in the auto reload register.
    - when the counter reaches this value, it'll set the flag, and invoke an interrupt.
- **Timer Prescaler Register (TIMx_PSC)**: this will slow down the counting speed of the timer by dividing the input clock of the timer.

## Timer Clock prescaling process

- The SYSCLK is divided alot via many prescalers.

![alt text](image.png)

## vocabulary

- Update event: when timeout occurs, or how long it takes for flag to be raised
- period: value loaded into auto-reload register
- up counter: counts from zero to set value.
- down counter: counts from a set value down to zero.

## calculating time it takes to trigger timer update event

```
update event = (timer clock) / ((prescaler + 1)(period + 1))
```

- we divide the timer clock by the prescaler, then by the period.

## commonly used Timer Registers

- PSC is the prescaler register.
    - we store the timer prescale value.
- ARR is the auto reload register.
    - when the TIM restarts, it'll automatically reload the ARR value.
- CR1 is the control register:
    - it can enable/disable the timer.
- SR is the status register
    - lets us check, set and clear flags of the timer.
- Capture Compare Registers (CCR1, CCR2, CCR3, CCR4)
    - Each channel with have a capture compare register.
    - it lets us readthe captured timer value.
- Capture Compare Mode Register (CCMRx)
    - CCMR1 configures the capture/compare functionality for CH1 and CH2.
    - CCMR2 configures the capture/cmompare functionality for CH3 and CH4.
- Capture Compare Enable Register (CCER):
    - used to enable any of the timer channels as input or output compare.
- Control Register 2 (CR2):
    - enables/disables ADC.

## Timer register - general steps

**initialization**
- enable clock access to TIMx
- set prescaler value (via PSC register)
- set auto reload value (via the ARR register)
- clear the current count (CNT register)
- enable timer

**running**

- if you want to perform an action every x seconds, you can poll the UIF bit in the status register.

**using output compare**

- here, you'll also have to enable output compare toggle mode, enable output compare mode, and select the gpio pin to use alternate function (which you'd then select the correct alternate function.)

**using input capture**

- you'd do the same steps as "running", but you'd need to enable input compare toggle mode, enable the input compare mode, select the gpio pin to use alternate function, then select the correct alternate function.