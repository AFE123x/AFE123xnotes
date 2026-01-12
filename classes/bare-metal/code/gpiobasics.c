/*******************************
*
* lesson one: blinky LED
* @author Arun Felix
*
********************************/
#include <stdint.h>

/* ===============================
   Peripheral base addresses
   =============================== */
#define PERIPHERAL_ADDRESS   0x40000000UL
#define IOPORT_OFFSET        0x10000000UL
#define IOPORT_BASE          (PERIPHERAL_ADDRESS + IOPORT_OFFSET)

/* ===============================
   GPIOA registers
   =============================== */
#define GPIOA_OFFSET         0x0000UL
#define GPIOA_BASE           (IOPORT_BASE + GPIOA_OFFSET)

#define GPIOA_MODER_OFFSET   0x00UL
#define GPIOA_MODER          (*(volatile uint32_t *)(GPIOA_BASE + GPIOA_MODER_OFFSET))

#define GPIOA_ODR_OFFSET     0x14UL
#define GPIOA_ODR            (*(volatile uint32_t *)(GPIOA_BASE + GPIOA_ODR_OFFSET))

/* PA5 mode bits */
#define PA5_MODE_OUTPUT      (1UL << 10)   // MODER5[1:0] = 01

/* ===============================
   RCC registers
   =============================== */
#define RCC_BASE             0x40021000UL

#define RCC_IOPENR_OFFSET    0x34UL
#define RCC_IOPENR           (*(volatile uint32_t *)(RCC_BASE + RCC_IOPENR_OFFSET))

/* RCC IOPENR bits */
#define RCC_IOPENR_GPIOAEN   (1UL << 0)

/* ===============================
   Main
   =============================== */
int main(void)
{
    /* Enable GPIOA clock */
    RCC_IOPENR |= RCC_IOPENR_GPIOAEN;

    /* Configure PA5 as output */
    GPIOA_MODER &= ~(3UL << 10);   // clear MODER5
    GPIOA_MODER |=  PA5_MODE_OUTPUT;

    /* Toggle PA5 */
    for (;;)
    {
        GPIOA_ODR ^= (1UL << 5);
        for (int i = 0; i < 0xFFFF; i++);
    }
}
