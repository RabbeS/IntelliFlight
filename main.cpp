#ifndef INTELLIFLIGHT
#define INTELLIFLIGHT

#include <openflightcontroller/board_defines.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include <libopencm3/stm32/dbgmcu.h>
#include <libopencm3/cm3/scs.h>
#include <libopencm3/cm3/tpiu.h>
#include <libopencm3/cm3/itm.h>

static void trace_setup(void) {
    /* Enable trace subsystem (we'll use ITM and TPIU). */
    SCS_DEMCR |= SCS_DEMCR_TRCENA;

    /* Use Manchester code for asynchronous transmission. */
    TPIU_SPPR = TPIU_SPPR_ASYNC_MANCHESTER;
    TPIU_ACPR = 7;

    /* Formatter and flush control. */
    TPIU_FFCR &= ~TPIU_FFCR_ENFCONT;

    /* Enable TRACESWO pin for async mode. */
    DBGMCU_CR = DBGMCU_CR_TRACE_IOEN | DBGMCU_CR_TRACE_MODE_ASYNC;

    /* Unlock access to ITM registers. */
    /* FIXME: Magic numbers... Is this Cortex-M3 generic? */
    *((volatile uint32_t *) 0xE0000FB0) = 0xC5ACCE55;

    /* Enable ITM with ID = 1. */
    ITM_TCR = (1 << 16) | ITM_TCR_ITMENA;
    /* Enable stimulus port 1. */
    ITM_TER[0] = 1;
}

static void gpio_setup(void) {
    /* Set GPIO13 (in GPIO port C) to 'output push-pull'. */
    rcc_periph_clock_enable(RCC_GPIOC);
    gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_OTYPE_PP, GPIO13);
}

static void trace_send_blocking(char c) {
    while (!(ITM_STIM8(0) & ITM_STIM_FIFOREADY));

    ITM_STIM8(0) = c;
}

int main(void) {
    int i, j = 0, c = 0;

    clockSetup();
    gpio_setup();
    trace_setup();

    /* Blink the LED (PC13) on the board with every transmitted byte. */
    while (1) {
        gpio_toggle(GPIOC, GPIO13);    /* LED on/off */
        trace_send_blocking(c + '0');
        c = (c == 9) ? 0 : c + 1;    /* Increment c. */
        if ((j++ % 80) == 0) {        /* Newline after line full. */
            trace_send_blocking('\r');
            trace_send_blocking('\n');
        }
        for (i = 0; i < 800000; i++)    /* Wait a bit. */
                __asm__("nop");
    }

    return 0;
}

#endif //INTELLIFLIGHT
