# Section 23: The ARM Programmer's Model

## Processor Modes

| mode | meaning |
| --- | --- |
| Supervisor (SVC) | entered on reset, and when software interrupt occurs |
| FIQ | entered on reset and when software interrupt occurs |
| IRQ | entered when normal interrupt is raised |
| Abort | memory access violation |
| Undef | undefined instructions |
| system | priviledged mode using the same registers as user mode |
| User | normal application run mode |

- depending on the program mode, you'll have access to specific registers.