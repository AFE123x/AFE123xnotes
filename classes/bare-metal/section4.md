# Section 4: Analog to Digital Conversion (ADC)

## What is ADC?

- An Analog-to-Digital Converter (ADC) is a hardware device used to convert analog (continuous) signals into digital (discrete) values.
- ADCs are among the most widely used components in data acquisition systems, especially in embedded and microcontroller-based designs.
- Digital computers and microcontrollers operate using binary values, while most real-world phenomena are analog in nature.

## analog vs. digital signals

- Analog signals are continuous values (temperature, pressure, humidity, velocity).
- To interface analog signals with digital systems, we need to perform a conversion.

## Transducer and sensors

- A transducer is a device that converts a physical quantity into an electric signal.
    - transducers can produce either: voltage or current output.
- transducers that generate electrical signals for measurement purposes are called **sensors**
- the electrical outputs need to be digitalized before processing.

## ADC - purpose

- Microcontrollers cannot directly read analog voltages/current.
- We need an ADC to translate the electric signal into digital numbers.

## ADC - resolution

- The ADC resolution defines how finely an anolog signal can be measured.
    - higher the bits, the more precise.
- more bits = step size is smaller
    - step size is the different between two values.

## ADC - Reference Voltage

- This is the voltage used as a reference for ADC conversion.
    - the reference voltage will determine the step size and measurement precision.

## ADC Independent modes

- there are various independent modes on the ADC
    - if you have a single ADC, you'll have one ADC mode.
- there you have two ADC, you may have dual modes.

- within an ADC module, you can have multiple channels.
    - This means we can connect multiple sensors.

## ADC independent mode, five channels

- single channels, single conversion mode
- multi channel, single conversion mode
- single channel, continuous conversion mode
- multi channel, continuous conversion mode
- injected continuous conversion mode.

## single channel, single conversion mode

- This is the simplest approach, where the ADC will perform one conversion of one channel, then stop.

## multi channel, single conversion mode

- convert multiple channels sequentially, each once, then stop.

## single channel, continuous conversion

- You'll convert a single channel, continuously.
    - The ADC will do this in the background without the CPU interfering.

## multi channel, continuous conversion

- you'll sequentially convert multiple channels, continuously.

## injected continuous conversion mode

- here, an external or software invoked event can inject a conversion.
    - this will have priority over the other ADC modes.

## ADC Voltage Regulator

- The ADC has an internal voltage regulator that needs to be enabled/stable before using the ADC.
    - This is done by setting the ADVREGEN bit.
    - you'll need to wait for the voltage regulator to fully startup before enabling the ADC.

## ADC - general steps

**initialization**

- step one: enable ADC clock.
- step two: enable GPIO pin, then set it to use analog mode.
- step three: enable ADC voltage regulator (needed for ADC to function).
    - wait for the regulator to startup (time is in datasheet).
- step four: initiate calibration process, and wait for calibration to finish.
- step five: configuration:
    - set the clock resolution.
    - set single vs. continuous mode.
    - set clock mode.
    - set sampling time
    - configure what channels to read, or the sequence of channels to read
    - clear ADC ready flag, enable ADC, then wait until the ADC is ready.

**reading**

- start the conversion (if using single mode)
- check the status register to see if conversion is completed
- read value from data register.

