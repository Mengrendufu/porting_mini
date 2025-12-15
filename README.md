
# Porting_Mini

Embedded System pre-porting demo.

## Facilities

### SNMTT Debug Printer

This facility is equipped with a frame queue and an internal static memory pool.

Defaultly, it check the transmit frame queue at a presetting frequency, once
the queue is dectected as not empty, it triggers the first byte outside the uart ISR
and finishes the rest inside the uart ISR.

The polling frequency and the size of frame size, queue sto and frame pool sto is also
configurable when the instance is built.

### BSP ticks counter

Circularly counting up the ticks from 0 to 65535 via system tick ISR, the tick output
for noticing the system is running or not is configurable to switch on or off.

## Porting Configurations

### Board Specific

#### Board Register library

The chip library files.

C51:

```c
#include "stc8h.h"
```

STM32F103:

```c
#include "stm32f1xx_hal.h"
```

#### Compiler key code and Reentrant Stack configurations

Make sure the platform supports reentrant function defaultly, if not, define the
key code *REENTRANT* and configurate the local stack with startup file. If needed,
initialize the static stack size at port module to avoid unnecessary faults
caused by compiler optimization (especially when the compiler does not support
reentrant defaultly).

#### Critical Section Protect-Handler

C51:

```c
#define SNMTT_INT_DISABLE()  BITS_RESET_U8(IE, 7)
#define SNMTT_INT_ENABLE()     BITS_SET_U8(IE, 7)
```

STM32F103:

```c
#define SNMTT_INT_DISABLE() do {    \
                                    \
    __disable_irq();                \
                                    \
} while (0)

#define SNMTT_INT_ENABLE() do {     \
                                    \
    __enable_irq();                 \
                                    \
} while (0)
```

#### Standard Types

If the develop environment does not provide the implementation of stdbool and stdint,
do it your way. If does, include them at ports module.
