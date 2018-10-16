#ifndef INTELLIFLIGHT
#define INTELLIFLIGHT

#include <bit_utils.h>

#include <bmp280.h>

#include <openflightcontroller/board_defines.h>
#include <openflightcontroller/spi.h>

int main(void) {
    gpioSetup();
    timerSetup();
    spi_setup();
//    uartSetup();



    bmp280_com_fptr_t bmp280_com_read = [](uint8_t dev_id, uint8_t reg_addr, uint8_t *data, uint16_t len) -> int8_t {
        gpio_clear(BMP280_CSS_PORT, BMP280_CSS_GPIO);   //CSS (enable chip)

        spi_send(BMP280_MAG_SPI, reg_addr); // request data

        // write data to receive buffer
        for (int idx = 0; idx < len; idx++) {
            data[idx] = static_cast<uint8_t>(BIT_GET_SUFFIX(spi_read(BMP280_MAG_SPI), 8));
        }

        gpio_set(BMP280_CSS_PORT, BMP280_CSS_GPIO);   //CSS (disable chip)

        return BMP280_OK;
    };

    bmp280_com_fptr_t bmp280_com_write = [](uint8_t dev_id, uint8_t reg_addr, uint8_t *data, uint16_t len) -> int8_t {
        gpio_clear(BMP280_CSS_PORT, BMP280_CSS_GPIO);   //CSS (enable chip)

        // write data beginning with register `reg_addr`
        for (uint8_t idx = 0; idx < len; idx++) {
            spi_send(BMP280_MAG_SPI, static_cast<uint16_t> (reg_addr + idx));
            spi_send(BMP280_MAG_SPI, data[idx]);
        }

        gpio_set(BMP280_CSS_PORT, BMP280_CSS_GPIO);   //CSS (disable chip)

        return BMP280_OK;
    };


    bmp280_delay_fptr_t bmp280_delay = [](uint32_t period) -> void {

    };


    //TODO: Check the bmp280_init methode this inclusion is correct (Bosch Sensortec), but it doesn't find the methode
    int8_t rslt;
    bmp280_dev bmp;

/* Sensor interface over SPI with native chip select line */
    bmp.dev_id  =  0;
    bmp.intf = BMP280_SPI_INTF;
    bmp.read = bmp280_com_read;
    bmp.write = bmp280_com_write;
    bmp.delay_ms = bmp280_delay;

    rslt = bmp280_init(&bmp);

    while (true) {

    }
}

#endif //INTELLIFLIGHT
