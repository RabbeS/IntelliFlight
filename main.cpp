#ifndef INTELLIFLIGHT
#define INTELLIFLIGHT

#include <bit_utils.h>

#include <bmp280.h>

#include <openflightcontroller/board_defines.h>

int main(void) {
    gpioSetup();
    timerSetup();
    spi_setup();
//    uartSetup();



    bmp280_com_fptr_t bmp280_read = [](uint8_t dev_id, uint8_t reg_addr, uint8_t *data, uint16_t len) -> int8_t {
        auto payload = static_cast<uint16_t>(BIT_CONCAT(*data, 8, reg_addr));

        gpio_clear(BMP280_CSS_PORT, BMP280_CSS_GPIO);   //CSS (enable chip)
        spi_send(BMP280_SPI, payload);

        while (true) {
            uint16_t receive_buffer = spi_read(BMP280_SPI);
            auto address = static_cast<uint8_t>(BIT_GET_SUFFIX(receive_buffer, 8));
            auto retval = static_cast<uint8_t>(BIT_GET_PREFIX(receive_buffer, 8));

            if (address == reg_addr) {
                gpio_set(BMP280_CSS_PORT, BMP280_CSS_GPIO);     //CSS (disable chip)
                return retval;
            }
        }
    };


    bmp280_delay_fptr_t bmp280_write = [](uint32_t period) -> void {

    };


    while (true) {
//TODO: Write the temperature calculation methode
//        BMP280_set_mode(GPIOA, GPIO2, SPI4, NORMAL);
        gpio_clear(GPIOA, GPIO2);
//        spi_send(SPI4, 0xF4);
//        test = spi_read(SPI4);
        gpio_set(GPIOA, GPIO2);
    }
}

#endif //INTELLIFLIGHT

//TODO: Add the css clear/set funktion to the spi_send methode in the libopencm3 project (spi_read maybe as well)
