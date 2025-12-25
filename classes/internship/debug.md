https://bootlin.com/doc/training/debugging/debugging-slides.pdf

# Linux Debugging, Profiling and Tracing

## Debugging

- Debugging is the act of finding and fixing bugs that may exist in your software/system.
- There are various tools for this:
    - interactive debugging (GDB)
    - postmortem analysis (using coredump)
    - control flow analysis (tracing tools)
    - testing (targeted tests)

## tracing

- this is following the execution flow of an application to understand bottlenecks.
- you ca nuse tracers like LTTng, trace-cmd or SystemTap.
- it lets you identify functions and parameters used when the application executes.

## profiling

- Profiling is the analysis of program runtime to assist performance optimizations.
    - there are tools, libraries and OS features to measure performance. For example, using perf.
- the first step is extracting data from the program execution, then parsing the data
    - data can include cpu/memory usage, function call count, cache miss, etc.

## memory terminology in linux tools

- `VSS/VSZ`: virtual set size
- `RSS`: resident set size (total physical memory usage, shared libraries used)
- `PSS`: Proportional Set Size (actual physical memory used, divided by number of times it was mapped)
- `USS`: Unique Set sized (physical memory occupied by process, shared mapping memory excluded.)


## Pseudo filesystems

- There are virtual file systems, that provide information on the system. for example:
    - Procfs: contains information about processes and system information.
    - sysfs: provides information about hardware/logical devices.
    - debugfs: information related to debugging.


## procfs

- this exposes information about processes and system.
- important process information includes:
    - `/proc/<pid>/status` provides basic process information
    - `/proce/<pid>/maps` provides the process's memory map
    - `/proc/<pid>/fd` provides the file descriptors with the process
    - `/proc/<pid>/task` provides descriptors of the threads belonging to the process

## sysfs

- sysfs provides information about the kernel subsystems, hardware devices associated with drivers.
- you can also do tracing control with files in sysfs.

## debugfs

- this is a ram basde filesystem rpoviding dubegging information.
    - you can look at kernel internals here.

## ELF files

- This is **Executable and Linkable Format**
- An elf file consists of the following:
    - `.text` section: contains code
    - `.data` section: contains Data
    - `.rodata` section: read only data
    - `.debug_info`: contains debug information.

- there are sections in an elf, which are segments that are loadable in memory. 

## elf analysis tools

- binutils are utilities to deal with binary files

- `readelf` will display information about elf files
- `objdump` lets you display information and disassemble ELF files
- `objcopy` can convert ELF files, or extract/translate parts of it.
- `nm` displays list of symbols embedded in ELF files
- `addr2line` finds the source code line/file pair from an address using ELF file with debug information


## `ldd` utility

- this utility lets you see the shared libraries the ELF file uses.
- it'll show the libraries linked at runtime.

## cpu/memory monitoring tools

- there are alot of useful programs to monitor various parts of the system.

- there are CLI programs:
    - ps
    - top
    - htop
- For memory, you can use free or vmstat


## `mpstat`

- this can display multiprocess statistics.
- you can use it to display unbalanced CPU workload, bad IRQ affinity, etc.

## `iostat`

- you can use this to display information about IOs per device on the system.

## `iotop`

- this is like `top` for I/O


## remote debugging with gdb

- you can debug wtih gdb remotely:
    - to run gdbserver: `gdbserver --atach :<port> <pid>`

- to run on host:

```bash
$ gdb <executable>
gdb> set sysroot <library-path>
gdb> target remote <ip-addr>:<port>
```

## coredump analysis

- When a program crashes, it'll generate a core file you can then use to diagnose.
- when the core file is generated, you can run gdb using `gdb -c <core-file> <application-binary>`


## ltrace

- this utility traces shared libraries function calls and signals emitted from the shared library.

## shared libraries

- these are `.so` files which are either:
    - loaded at startup with `ld.so` (dynamic loader).
    - loaded at runtime using `dlopen()` in your code.
- when starting a ELF binary, the kerel will parse, and load the interpreter that needs to be invoked.
    - This will be in the PT_INTERP program header.
    - ld.so will resolve all the symbols in the dynamic library.

## `LD_PRELOAD` variable

- you can overlide shared library locations using the `LD_PRELOAD` environment variable.

## heap profiling

- you can use valgrind's `Massif` tool which does heap profiling.
    - it creates a. .out file, which can be displayed with ms_print.
- `heaptrack` is another option.
- `memusage`, which can profile heap, stack and mmap memory usage.
