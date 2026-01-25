# Section 2: Introduction

## What is a Bootloader?

- A bootloader is a small piece of code stored in the MCU flash or ROM to act as a application loader as well as a mechanism to update the application whenever needed.

- The ATmega328P contains an on chip bootloader.
    - on reset, the bootloader runs first, and used to download arduino sketches to the arduino.

## what are the benefits for using a bootloader

- A bootloader allows for **in-application programming (IAP)**, which means you can update firmware without an external programmer.

## ISP

- ISP is **in-system programming**.
    - here, you use a debugger or programmer, hence you don't need a bootloader.