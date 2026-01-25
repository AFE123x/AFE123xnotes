# Section 8 - Exploring STM32 Native Bootloader

## pin configuration

- there are two boot pins that you use to configure where to start the program on reset.

## Bootloader - configurations

- you can choose the peripheral the bootloader communicates with.
    - For example, you can communicate with the host with USART, CAN, I2C, etc.