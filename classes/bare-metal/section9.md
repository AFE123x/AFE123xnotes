## Section 9: Inter-Integrated Circuit (I2C)

## I2C lines

- SCL: Serial Clock
    - synchronizing data transfer between master and slave
- SDA: Serial Data
    - data line

## I2C - Operation modes

- master transmitter
- master receiver
- slave transmitter
- slave receiver


## I2C protocols

- Transactions are initiated and completed by master.
- All messages have an address frame and data frame.
- Data is placed on the SDA line after SCL goes low, and is sampled after the SCL line goes high.


**start/stop condition**

- all i2c transactions will have a start/stop condition.
- high to low on the SDA line while SCL is high is a start condition
- low to high on the SDA line while SCL is high defines a stop condition.
- the bus is free after a stop condition


**byte format**

- information transmitted on the SDA line must be 8 bits long.
- there's no limit on number of bytes to transmit
- each byte will follow an acknowledge bit.
- data's transferred with the MSB first.

**address frame**

- The first thing we send via i2c is the slave address.
    - we send the address first, then the R/W bit.
- Next, we send the data

## I2C - clock speed

- speed of I2C interface.

- I2C specification has the following modes:
    - standard: 100 KHz max
    - fast-mode: 400 KHz max
    - fast-mode plus: 1 MHz
    - high-speed mode: 3.4 MHz

## I2C duty cycle

- we can specify a ratio between $t_{low}$ and $t_{high}$ of the I2C SCL line