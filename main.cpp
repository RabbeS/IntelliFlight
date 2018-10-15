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
            BMP280_OS_2X,
            BMP280_OS_16X,
            BMP280_ODR_125_MS,
            BMP280_FILTER_COEFF_16,
            BMP280_SPI3_WIRE_DISABLE,
    };

    //TODO: Check if I used the correct calib param!
    bmp280_calib_param calib_param{
            BMP280_DIG_T1_MSB_POS,
            BMP280_DIG_T2_MSB_POS,
            BMP280_DIG_T3_MSB_POS,
            BMP280_DIG_P1_MSB_POS,
            BMP280_DIG_P3_MSB_POS,
            BMP280_DIG_P4_MSB_POS,
            BMP280_DIG_P5_MSB_POS,
            BMP280_DIG_P6_MSB_POS,
            BMP280_DIG_P7_MSB_POS,
            BMP280_DIG_P8_MSB_POS,
            BMP280_DIG_P9_MSB_POS,
            BMP280_CALIB_DATA_SIZE,
    };

#define BMP280_dev_id 58

    bmp280_dev dfa{
            BMP280_CHIP_ID3,
            BMP280_dev_id,
            BMP280_SPI_INTF,
            bmp280_com_read,
            bmp280_com_write,
            bmp280_delay,
            calib_param,
            conf,
    };


    uint8_t test = dfa.chip_id;


    while (true) {
    }
}

#endif //INTELLIFLIGHT
