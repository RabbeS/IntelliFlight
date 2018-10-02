#ifndef INTELLIFLIGHT
#define INTELLIFLIGHT

#include "src/rcc.h"
#include "src/gpio.h"
#include "src/timer.h"
#include "src/usart.h"

int main(void) {
    gpioSetup();
    timerSetup();
//    uartSetup();
    while (true) {
        for (int i = 0; i < 500000; i++) {}
        gpio_toggle(GPIOC, GPIO13);
    }
}

#endif //INTELLIFLIGHT

