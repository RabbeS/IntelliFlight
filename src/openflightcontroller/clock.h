#ifndef INTELLIFLIGHT_RCC_H
#define INTELLIFLIGHT_RCC_H

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/cm3/systick.h>

static void clockSetup(void);

static void clockSetup(void) {
    /* Setup the hse as main clock and the internal clock frequency to 168 MHz */
    rcc_clock_setup_hse(&rcc_3v3[RCC_CLOCK_3V3_168MHZ], 25);

    /* Enable all gpio ports */
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOB);
    rcc_periph_clock_enable(RCC_GPIOC);
    rcc_periph_clock_enable(RCC_GPIOD);
    rcc_periph_clock_enable(RCC_GPIOE);
}

#endif //INTELLIFLIGHT_RCC_H
