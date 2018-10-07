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
    uint16_t rawTemperature = 0x00;
    while (true) {
        //TODO: Why does the BMP280 don't accept 0xF1 or 0xF2 in the register F4?
        gpio_clear(GPIOA, GPIO2);
        spi_send(SPI4, 0xF374);
        rawTemperature=spi_read(SPI4);
        gpio_set(GPIOA, GPIO2);

        gpio_clear(GPIOA, GPIO2);
        spi_send(SPI4, 0xF4);
        rawTemperature=spi_read(SPI4);
        gpio_set(GPIOA, GPIO2);

        gpio_clear(GPIOA, GPIO2);
        spi_send(SPI4, 0xD0);
        rawTemperature=spi_read(SPI4);
        gpio_set(GPIOA, GPIO2);


//        gpio_clear(GPIOD, GPIO13);
//        spi_send(SPI2, 0xF511);
//        gpio_set(GPIOD, GPIO13);
    }
}

#endif //INTELLIFLIGHT

//TODO: Add the css clear/set funktion to the spi_send methode in the libopencm3 project (spi_read maybe as well)