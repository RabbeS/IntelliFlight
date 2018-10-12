#ifndef INTELLIFLIGHT
#define INTELLIFLIGHT

#include "clock.h"
#include "src/gpio.h"
#include "src/timer.h"
#include "src/usart.h"
#include "src/spi.h"

#include "src/BMP280_SPI.h"

int main(void) {
    gpioSetup();
    timerSetup();
    spiSetup();
//    uartSetup();

    uint16_t test;
    while (true) {
//TODO: Write the temperature calculation methode
        BMP280_setMode(GPIOA, GPIO2, SPI4, NORMAL);
        gpio_clear(GPIOA, GPIO2);
        spi_send(SPI4, 0xF4);
        test = spi_read(SPI4);
        gpio_set(GPIOA, GPIO2);
    }
}

#endif //INTELLIFLIGHT

//TODO: Add the css clear/set funktion to the spi_send methode in the libopencm3 project (spi_read maybe as well)
