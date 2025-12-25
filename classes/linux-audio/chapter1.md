# Chapter 1 - Basic Concepts of Sound

## What is audio?

- Audio is an analog signal.
- We can analyze sound looking at it's spectrum.


## sampling, sample rate

- To digitize analog signals, we'll taking samples at regular intervals, and place them on a discrete scale.
- the sample rate determines how many samples we capture in a second.

## sample format

- The sample format describes how many bits we use to digitalize the sample.

## frames

- A frame holds samples from a one time instance.
    - This means a stereo device holds two samples
    - A 5 speaker device will hold five samples


## Pulse Code Modulation

- This is how digitalized analog signals are represented.
    - this is standard in computers, blue ray, dvd, etc.

## Overrun vs. Underrun

- When a sound device is active, it needs data continuously transferred between the hardware and application buffer.
    - overrun is when the application buffer grows faster than the hardware consumes samples
    - underrun is when the application doesn't pass enough data into the buffer quickly for the hardware to consume.

## Latency

- Latency is the amount of time that elapses from when a signal enter the system, vs. leaves the system.

## Jitter

- Ideally, sampling analog signals is done at regular intervals.
    - Most noticable in network systems, there are occurences of jitter.

## mixing

- Mixing means taking inputs from one or more sources, doing processing on the signal, then sending it to an output.