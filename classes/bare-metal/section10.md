# Section 10: Serial Peripheral Interface (SPI)

## What is the SPI Protocol

- SPI is a Synchronous and Full duplex communication between a master and slave device.
- there are a total of four pins:
    - two for data transfer (SDIN and SDO)
    - a clock pin for synchronization
    - chip enable pin to initiate and terminate data transfer.

## SPI - Pin Functions

- MOSI: Master Out Slave In, sends data from master to slave.
- MISO: Master In Slave Out, sends data from slave device to master.
- SCK: Serial clock, generate a clock signal to synchronize datta transfer between the master and slave device
- SS: Slave Select, used to select a particular slave in the SPI multiple slaves configuration.

## SPI Protocol - Steps

1. Transaction is started by enabling Serial Clock.
2. The master sets the SS line of the slave low.
3. The master and the slave has an internal register, where bits are exchanged between the two. 
    - if more data needs to be transmitted, the master and slave will reload a value, and begin the exchange again.
4. Once the exchange is done, the master will stop sending the clock, and diselect the slave device.

## SPI Protocol - Clock Phase and Polarity

- The Master and Slave device must agree on clock phase and polarity.

- There are two paremeters that need to be configured:
    - CPOL: Clock Polarity
    - CPHA: Clock Phase
- the combination of CPOL and CPHA are known as SPI bus modes.

| mode | CPOL | CPHA |
| --- | --- | --- |
| mode0 | 0 | 0 |
| mode1 | 0 | 1 |
| mode2 | 1 | 0 |
| mode3 | 1 | 1 |

- we configure the modes based on CPOL
- if we set CPOL to 0:
    - the active state of clock is 1, and idle state is 0.
    - If CPHA = 0:
        - data is captures on the rising edge
        - data is output on the falling edge
    - If CPHA = 1:
        - data is captured on the falling edge
        - data is output on the rising edge.
- If We set CPOL to 1:
    - the active state of clock is 0, and idle state of clock is 1.
    - if CPHA = 0:
        - data is captured on the falling edge.
        - data is output on the rising edge.
    - if CPHA = 1:
        - data is captured on the rising edge.
        - data is output on the falling edge.

- To summarize:
    - CPOL = 0 means sampling on the first edge.
    - CPOL = 1 means sampling on the second edge.

## SPI - NSS management

- There are two NSS modes:
    - NSS software mode:  SS line is driven internally by firmware
    - NSS hardware mode: a dedicated GPIO pin is used to drive the SS line.
        - NSS output enabled: used only when device operates in master mode.
        - NSS output disabled: allows multi master capability for devices operating is master mode.

## SPI - TI Mode

- Texas Instrument has an SPI protocol requirement.
- To comply with this, you need to use the NSS hardware mode.
    - aka, CPHA and CPOL are forced to conform to TI protocol.
- Here, the NSS signal pulses at the end of every transmitted byte.