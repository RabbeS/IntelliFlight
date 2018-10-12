#ifndef INTELLIFLIGHT_RCC_H
#define INTELLIFLIGHT_RCC_H

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/cm3/systick.h>

static void clockSetup(void);

static void clockSetup(void) {
    rcc_clock_setup_hse(&rcc_3v3[RCC_CLOCK_3V3_168MHZ], 25);
}

#endif //INTELLIFLIGHT_RCC_H
