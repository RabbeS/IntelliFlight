#ifndef INTELLIFLIGHT
#define INTELLIFLIGHT

#include "openflightcontroller/clock.h"
#include "openflightcontroller/gpio.h"
#include "openflightcontroller/timer.h"
#include "openflightcontroller/usart.h"
#include "openflightcontroller/spi.h"

#include "lib/bmp280/include/BMP280_SPI.h"

int main(void) {
    gpioSetup();
    timerSetup();
    spi_setup();
//    uartSetup();

    uint16_t test;
    while (true) {
//TODO: Write the temperature calculation methode
//        BMP280_set_mode(GPIOA, GPIO2, SPI4, NORMAL);
        gpio_clear(GPIOA, GPIO2);
        spi_send(SPI4, 0xF4);
        test = spi_read(SPI4);
        gpio_set(GPIOA, GPIO2);
    }
}

#endif //INTELLIFLIGHT

//TODO: Add the css clear/set funktion to the spi_send methode in the libopencm3 project (spi_read maybe as well)
