#include "src/timer.h"
#include "src/gpio.h"

int main(void) {
    gpioSetup();
    timerSetup();
    while (true) {
        for (int i = 0; i < 50000; i++) {}
        gpio_toggle(GPIOC, GPIO13);
    }
}