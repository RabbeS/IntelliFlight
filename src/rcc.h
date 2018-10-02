#ifndef INTELLIFLIGHT_RCC_H
#define INTELLIFLIGHT_RCC_H

#include <libopencm3/stm32/rcc.h>

static void clockSetup(void);

static void clockSetup(void) {
    rcc_clock_setup_hse(&rcc_3v3[RCC_CLOCK_3V3_120MHZ], 25);
}

#endif //INTELLIFLIGHT_RCC_H
