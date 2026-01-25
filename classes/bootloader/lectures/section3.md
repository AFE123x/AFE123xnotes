# Section 3: MCU memory, reset sequence and boot config
## memory organization

- It's important to understand this, and to figure out the needed base addresses

## components of memory

- There are various components:
    - internal flash memory (also known as on-chip flash)
    - SRAM: static ram.
    - system memory: read only memory (primarily used by st to store st's native bootloader)
    - OTP (one time programmable) memory: you can only write to this once.
    - Option bytes memory: has flags containing access rules for flash memory
    - backup ram: you can backup ram using battery.

## internal flash memory

- this is used to store application code, vector table, and read only data of the program
- it's non volatile

## SRAM

- will be used to store application global data, static variables.
- also used for stack and heap purpose
- volatile.
- you can execute code from this memory.

## system memory (ROM)

- ST MCUs store bootloader in this memory.
- this is read only.
- the MCU will not execute code from this memory, but you can configure MCU to boot or execute bootloader from this memory.
    - when you reset your microcontroller, the microcontroller will not care about the bootloader, unless you change the boot configuration on the microcontroller.

## flash organization

- the memory is broken down into "sectors", of varying sizes.

## reset sequence

1. when you reset the MCU, the PC is loaded with the value 0x0000_0000
2. the processor will store the value in memory location 0x0000_0000 in the Main Stack Pointer register (MSP)
3. processor reads value at memory location 0x0000_0004, which contains the address of the reset handler, then the PC will jump to the reset hanlder.
4. the reset handler is a function that carries out initialization.
5. from reset, you call your main function.

## Memory Aliasing

- this is basically the ability of mirroring an address at one location to another location.
    - on the stm32, depending on the configuration.

## Boot configuration

- we can configure the boot mode to decide where in memory to start the program:
    - aka, alias the region to which memory peripheral.
