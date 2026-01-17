# Section 2: General Purpose Input/Output (GPIO)

## GPIO vs. SPIO

- GPIO is general purpose Input/Output
- GPIO pins can also be used for other purposes, like UART, I2C, etc.

## common GPIO registers

- Direction Register: defines Input vs. Output
- Data Register: write/read from/to pin.

## MCU: clock sources

- on-chip RC oscillator: least precise clock
- Externally connected Crystal: most precise
- Phase Locked Loop: programmable clock.
    - PLL takes an input clock, then reconfigures it to an output clock, faster or slower than the source.

## how to perform gpio?

- step one: enable gpio clock with `IOPENR` pin
- step two: define gpio port input/output type: is a pin doing input or output?
- step three: write to the ODR (output data register) or read from IDR (input data register) pin.
