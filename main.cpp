#ifndef INTELLIFLIGHT
#define INTELLIFLIGHT

#include <bit_utils.h>

//#include <bmp280.h>
//#include "lib/BMP280_driver/bmp280.h"
//#include "lib/BMP280_driver/bmp280.c"
//#include "lib/BMP280_driver/bmp280_defs.h"

#include <openflightcontroller/board_defines.h>
#include <openflightcontroller/spi.h>

//TODO: outsource the handler to new file clock.c
void sys_tick_handler(void) {
    system_millis++;
}


//bmp280_com_fptr_t bmp280_com_read = [](uint8_t dev_id, uint8_t reg_addr, uint8_t *data, uint16_t len) -> int8_t {
//    gpio_clear(BMP280_CSS_PORT, BMP280_CSS_GPIO);   //CSS (enable chip)
//
//    spi_send(SPI4/*BMP280_MAG_SPI*/, 0xF4/*reg_addr*/); // request data
//
//    // write data to receive buffer
//    for (int idx = 0; idx < len; idx++) {
////TODO: here is a problem, this funktion is waiting to get an answer from the spi receive methode!
//        data[idx] = static_cast<uint8_t>(BIT_GET_SUFFIX(spi_read(/*BMP280_MAG_SPI*/SPI4), 8));
//    }
//
//    gpio_set(BMP280_CSS_PORT, BMP280_CSS_GPIO);   //CSS (disable chip)
//
//    return BMP280_OK;
//};
//
//bmp280_com_fptr_t bmp280_com_write = [](uint8_t dev_id, uint8_t reg_addr, uint8_t *data, uint16_t len) -> int8_t {
//    gpio_clear(BMP280_CSS_PORT, BMP280_CSS_GPIO);   //CSS (enable chip)
//
//    // write data beginning with register `reg_addr`
//    for (uint8_t idx = 0; idx < len; idx++) {
//        spi_send(BMP280_MAG_SPI, static_cast<uint16_t> (reg_addr + idx));
//        spi_send(BMP280_MAG_SPI, data[idx]);
//    }
//
//    gpio_set(BMP280_CSS_PORT, BMP280_CSS_GPIO);   //CSS (disable chip)
//
//    return BMP280_OK;
//};
//
//
//bmp280_delay_fptr_t bmp280_delay = [](uint32_t period) -> void {
//    msleep(period);
//};

int main(void) {
    gpioSetup();
    timerSetup();
    spi_setup();
//    uartSetup();
//
//    gpio_clear(GPIOD, GPIO13);
//    spi_send(SPI2, 0xFF);
//    gpio_set(GPIOD, GPIO13);
//
//
//
//    int8_t rslt;
//    bmp280_dev bmp;
//
///* Sensor interface over SPI with native chip select line */
//    bmp.dev_id  =  0;
//    bmp.intf = BMP280_SPI_INTF;
//    bmp.read = bmp280_com_read;
//    bmp.write = bmp280_com_write;
//    bmp.delay_ms = bmp280_delay;
//
//    bmp280_config conf;
//    conf.spi3w_en = BMP280_SPI3_WIRE_DISABLE;
//    conf.os_pres = BMP280_OS_16X;
//    conf.os_temp = BMP280_OS_2X;
//    conf.filter = BMP280_FILTER_COEFF_16;
//    conf.odr = BMP280_ODR_0_5_MS;
//
//    rslt = bmp280_init(&bmp);
//    rslt = bmp280_set_config(&conf, &bmp);

    while (true) {
        gpio_toggle(GPIOC, GPIO13);
        for (int i = 0; i < 500000; i++) {}
        gpio_clear(GPIOD, GPIO12);
        spi_send(SPI2, 0x54);
        spi_read(SPI2);
        spi_send(SPI2, 0xFF);
        spi_read(SPI2);
        gpio_set(GPIOD, GPIO12);
    }
}

#endif //INTELLIFLIGHT
