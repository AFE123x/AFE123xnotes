# Section 22: ARM Design Philosophy and RISC Architecture

## ARM introduction

- ARM is a design firm, hence doesn't manufacture processors.

## RISC

- RISC means Reduced Instruction Set Computer
    - there are fewer instructions: the compiler will put together the fewer instructions, rather than implementing a complex instruction.
        - each instruction must be executed in a single clock cycle.
    - instructions are executed in parallel by pipelines.
    - have large general purpose register set, and are very flexible for usage.
    - load/store: processor operated on data held in registers.

## ARM Design Philosophy

- ARM processors are designed to be small to reduce power consumption and extend battery.
    - mainly seen in mobile phones and other embedded devices.
- ARM isn't purely RISC, but has RISC traits.

ARM's goal is to have the RISC aspects, high code density, and power efficiency.
    - high code density means programs doesn't take up too much memory, which is important for things with low memory, like phones.

- For RISC, complexity is put on the compiler, as it has fewer instructions to work with.

## Arm Bus Technology & AMBA Bus Protocol

- There are two classes of devices:
    - Bus Master - ARM processor core.
        - these devices are able to initialize data transfer.
    - Bus Slave - Peripherals


- Two bus architecture levels:
    - physical level: electrical characteristics, bus width, etc.
    - protocol level: rules the bus master and slave use to communicate.

## Types of memory 

| memory | description |
| --- | --- |
| ROM (Read-Only Memory) | cannot be reprogrammed |
| Flash ROM | Can be written and read |
| DRAM  (Dynamic RAM) | lowest cost per megabyte |
| SRAM (Static RAM) | faster than DRAM |
| SDRAM (Synchronous Dynamic RAM) | runs at much higher clock rate |
| EEPROM | can be written to and read |