#ifndef INTELLIFLIGHT
#define INTELLIFLIGHT

#include "clock.h"
#include "src/gpio.h"
#include "src/timer.h"
#include "src/usart.h"
#include "src/spi.h"

int main(void) {
    gpioSetup();
    timerSetup();
    spiSetup();
//    uartSetup();
    while (true) {
        for (int i = 0; i < 500000; i++) {}
        gpio_toggle(GPIOC, GPIO13);

        gpio_clear(GPIOD, GPIO13);
        spi_send(SPI2, 15);
        gpio_set(GPIOD, GPIO13);
    }
}

#endif //INTELLIFLIGHT

//TODO: Add the css clear/set funktion to the spi_send methode in the libopencm3 project (spi_read maybe as well)