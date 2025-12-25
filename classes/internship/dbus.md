# DBus

## What is DBus

- DBus is an interprocess communication mechanism
- Created in 2002
- Provided a standard for IPC in the Linux environment.

## What are already existing Inter-Process Communicatien mechanisms?

1. Shared memory
2. Memory mapped file
3. Pipe (stdout -> stdin)
4. Sockets

## What does dbus do differently from the other forms of IPC

- DBus uses a socket under the hood
- Provides a system bus like abstraction

## DBus Elements

- DBus Daemon: does the handling of data being transfered between dbus peers
- policy files, enforcing certain rules (what users can own dbus process, etc.)
- LibDBus, low level dbus library

## System vs. Session Bus

- Session bus: There's one bus per user suession
- System bus: one single bus for all users, dedicated for low level events.

## Breakdown of dbus elements

- D-Bus consist of:
    - service: `com.vehicle.Audio`
    - Object: `/Audio`
    - interface: `com.vehicle.Audio.setVolume`

**service**

- A service is what is actually exposes itself to the bus.
- A service consist of objects providing a specific set of features
- A service can be uniquely named on registeration, or you can assign it a unique name, like `com.vehicle.Audio`

**object**

- an object is attached to one service
- it's uniquely identified with a `/`
    - kinda like a webpage
- can implement one or multiple interfaces


**interfaces**

- this contains the actual members, properties and signals.

## Properties

- These are directly written fields
- they could be of different types

| type | character |
| --- | --- |
| byte | `y` |
| boolean | `b` |
| int32 | `i` |
| uint32 | `u` |
| double | `d` |
| string | `s` |
| object-path | `o` |
| array | `a` |
| struct | `()` |
| dict | `{}` |
| variant | `v` |
| array of ints | `ai` |
| array of int32 | `aai` |
| array of struct with 2 ints | `a(ii)` |

## methods

- These are procedures that can be called from one process to another

## signals

- These are messages/notifications
- The server can send these notifications to clients listening to it.

## Policy

- This adds a security mechanism
- Represented by XML file
- Lets us control which users can talk to an interface, who can send messages, own a service, etc.

## library bindings

- `libdbus`: the low level library used by dbus-daemon
    - `"If you use this low-level API directly, you're signing up for some pain."`
- `GDBus`: part of GLib
- `system-dbus`: systemd's dbus library, nice API.
- `QtDbus`: qt module.

## dbus performance

- DBus isn't meant to be a high performance IPC.

    - AKA, you shouldn't send an audiostream through this.
## dbus - behind the scenes, calling a method

- lets say process A calls a method on process B
    - process A will create the message.
    - Process A will send the message to the dbus daemon
    - the dbus-daemon will check if process A is allowed to send messages to proces B, and if process B can own the process.
        - if not, dbus will send an error back.
    - Dbus daemon will proceed to send message to process B
    - Process B will unpack the package, invoke the method, and sends reply message to dbus daemon
    - The dbus daemon will receive the response, and send it back to client.

## dbus - behind the scenes, emmitting a signal

- Lets say process B sends a signal to process A
- Process B will emit the signal to the dbus daemon
- The process can choose what signals it's interested in.
- the dbus daemon looks at the signal, and send it to the processes that are interested in the signal.