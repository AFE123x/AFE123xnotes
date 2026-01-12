# Section 3: Universal Asynchronous Receiver-Transmitter

## parallel vs. serial communication

- let say we need to transfer 8 bits:
    - in parallel, the 8 bits are transferred simultaneously.
    - in serial, the a bits are transferred one bit at a time.

## synchronous vs. Asynchronous communication

- Synchronous means the clock is transmitted with the data
- Asynchronous means the clock isn't transmitted, and the transmitter/receiver agree on the clock speed for data transmission (baud rate).

## UART/USART

- UART: Universal Asynchronous Receiver/Transmitter.
- USART: Universal Synchronouse Asynchronous Receiver/Transmitter.

## Transmission modes

- There are four main transmission mode
    - duplex: Data can be transmitted and received.
    - Simplex: data can only be transmitted or received, not both.
    - Half duplex: data can be transmitted in only one way at a time.
    - Full duplex: data can be transmitted in both ways at the same time.

```
+-------------+                  +----------+
| transmitter | ---------------> | receiver |  simplex
+-------------+                  +----------+

+-------------+                   +-------------+
| transmitter |--\         /------| transmitter |
+-------------+   \       /       +-------------+
                   -------                              half-duplex
+----------+      /       \       +----------+
| receiver |-----/         \------| receiver |
+----------+                      +----------+

+-------------+                  +----------+
| transmitter | ---------------> | receiver | 
+-------------+                  +----------+
                                                     full-duplex
+----------+                  +-------------+
| receiver | <--------------- | transmitter |
+----------+                  +-------------+
```

## UART - bit summary

- You send bytes via uart.
    - There's a 1 bit start, it's always 0
    - There's a 1 or 2 bit stop, the stop bits is always 1.

```
11 0100 0001 0 <-start bit
^
|- stop bit.
```

## UART configuration parameters

- Baudrate: connection speed expressed in bits per second
- Stop bit: number of stop bits transmitted, can be one or two
- parity: indicate the parity mode, whether we want odd or even.
- mode: whether RX or TX is enabled/disabled
- word length: the number of data bits transmitted or received, can be 8 or 9 bits.
- hardware flow control: do we want to enable or disable this option.

## steps for tx - usart

**configuration**

- step one: configure clock to support USART and GPIO
    - on the nucleo, the USART2 is responsible for the serial to usb built in.
- step two: select a clock configuration for USART2 using `CCIPR`
    - you can use the system, external, or the PLL.
- step three: configure PA2 to use alternate setting, using `MODER` register, then configure the alternate function to use USART2_TX, using the `AFRL` register.
- step four: configure baud rate
    - you do this with the `BRR` register.
- step five: enable TX and USART2
    - this is done with the `CR1` register.

**using USART**
- poll the `USART2_ISR` register to see when TX queue is not full.
- send your character using the USART2_TDR register.

## overwriting printf

- Underneath, printf using the write syscall.
    - you can over write the function `int _write(int file, char* ptr, int len)`, and implement your uart interface here instead.
- advice: add `\r` at the end of your print statement for cleanliness. I think it's for flushing?

## steps for rx - usart

**configuration**
- the configuration is similar to tx, but you need to do the following:
    - step one: enable USART2 and GPIO clock.
    - step two: select the clock source for USART
    - step three: set PA3 PIN to alternate function with the `MODER` register
    - step four: define alternate function to USART2_RX (with the AFR register).
    - step five: define the baud rate of the USART using the `BRR`
    - step six: enable RE bit and USART2 bits on the `CR1` register.

**usage**

- read the `RXNE` bit on the USARRT `ISR` register to see if there's a byte to read.
- read the byte from the `RDR` register.
