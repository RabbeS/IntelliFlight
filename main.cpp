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
            spi_send(BMP280_MAG_SPI, reg_addr + idx);
            spi_send(BMP280_MAG_SPI, data[idx]);
        }

        gpio_set(BMP280_CSS_PORT, BMP280_CSS_GPIO);   //CSS (disable chip)

        return BMP280_OK;
    };


    bmp280_delay_fptr_t bmp280_delay = [](uint32_t period) -> void {

    };

    bmp280_config conf{
                    // uint8_t os_temp
                    // uint8_t os_pres
                    // uint8_t odr
                    // uint8_t filter
            0,      // Spi3w enable
    };

    bmp280_calib_param calib_param{
            uint16_t dig_t1;
            int16_t dig_t2;
            int16_t dig_t3;
            uint16_t dig_p1;
            int16_t dig_p2;
            int16_t dig_p3;
            int16_t dig_p4;
            int16_t dig_p5;
            int16_t dig_p6;
            int16_t dig_p7;
            int16_t dig_p8;
            int16_t dig_p9;
            int32_t t_fine;
    };

    bmp280_dev dfa{
            0x58,                  // chip id
            0,                  // dev id
            BMP280_SPI_INTF,    // interface selection
            bmp280_com_read,    // read fptr
            bmp280_com_write,   // write fptr
            bmp280_delay,       // delay_ms fptr
            calib_param,        // calib_param struct
            conf,               // conf struct
    };


    uint8_t test = dfa.chip_id;


    while (true) {
    }
}

#endif //INTELLIFLIGHT
