#ifndef INTELLIFLIGHT
#define INTELLIFLIGHT

#include "clock.h"
#include "src/gpio.h"
#include "src/timer.h"
#include "src/usart.h"
#include "src/spi.h"

unsigned short dig_T1;
signed short dig_T2;
signed short dig_T3;

// Returns temperature in DegC, resolution is 0.01 DegC. Output value of “5123” equals 51.23 DegC.
// t_fine carries fine temperature as global value
uint16_t bmp280_compensate_T_int32(uint16_t adc_T) {
    uint16_t t_fine;
    uint16_t var1, var2, T;
    var1 = ((((adc_T >> 3) - ((uint16_t) dig_T1 << 1))) * ((uint16_t) dig_T2)) >> 11;
    var2 = (((((adc_T >> 4) - ((uint16_t) dig_T1)) * ((adc_T >> 4) - ((uint16_t) dig_T1))) >> 12) * ((uint16_t) dig_T3))
            >> 14;
    t_fine = var1 + var2;
    T = (t_fine * 5 + 128) >> 8;
    return T;
}

int main(void) {
    gpioSetup();
    timerSetup();
    spiSetup();
//    uartSetup();

        gpio_clear(GPIOA, GPIO2);
        spi_send(SPI4, 0xEB74);
//    rawTemperature=spi_read(SPI4);
        gpio_set(GPIOA, GPIO2);

        gpio_clear(GPIOA, GPIO2);
        spi_send(SPI4, 0x3C75);
//    rawTemperature=spi_read(SPI4);
        gpio_set(GPIOA, GPIO2);

    uint16_t rawTemperature = 0x0;
    uint16_t temperature = 0x0;

    while (true) {
//TODO: Write the temperature calculation methode
//        gpio_clear(GPIOA, GPIO2);
//        spi_send(SPI4, 0x89);
//        dig_T1 = spi_read(SPI4);
//        gpio_set(GPIOA, GPIO2);
//
//        gpio_clear(GPIOA, GPIO2);
//        spi_send(SPI4, 0x8B);
//        dig_T2 = spi_read(SPI4);
//        gpio_set(GPIOA, GPIO2);
//
//        gpio_clear(GPIOA, GPIO2);
//        spi_send(SPI4, 0x8D);
//        dig_T3 = spi_read(SPI4);
//        gpio_set(GPIOA, GPIO2);

        gpio_clear(GPIOA, GPIO2);
        spi_send(SPI4, 0xFA);
        rawTemperature = spi_read(SPI4);
        gpio_set(GPIOA, GPIO2);

//        temperature = bmp280_compensate_T_int32(rawTemperature);
    }
}

#endif //INTELLIFLIGHT

//TODO: Add the css clear/set funktion to the spi_send methode in the libopencm3 project (spi_read maybe as well)
