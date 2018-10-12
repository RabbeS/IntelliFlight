#include "../inc/BMP280_SPI.h"

//TODO: Use memorymap to read/write a register of the BMP280
//TODO: How to reduce the number methode elemnts (uint32_t gpioport, uint16_t gpios, uint32_t spi)

uint8_t BMP280_set_mode(uint8_t BMP280_register, enum mode select) {
    BMP280_register &= ~(0b11);
    BMP280_register |= select;
    return BMP280_register;
}

uint8_t BMP280_set_osrs_p(uint8_t BMP280_register, enum osrs select) {
    BMP280_register &= ~(0b111 << 2);
    BMP280_register |= (select << 2);
    return BMP280_register;
}

uint8_t BMP280_set_osrs_t(uint8_t BMP280_register, enum osrs select) {
    retVal &= ~(0b111 << 5);
    retVal |= (select << 5);
    return BMP280_register;
}

uint8_t BMP280_set_t_sb(uint8_t BMP280_register, enum t_sb select) {
    retVal &= ~(0b111 << 5);
    retVal |= (select << 5);
    BMP280_register
}

uint8_t BMP280_set_filter(uint8_t BMP280_register, enum filter select) {
    gpio_clear(gpioport, gpios);
    uint16_t retVal;
    spi_send(spi, 0xF5);
    retVal = spi_read(spi);
    retVal = retVal >> 8;
    retVal &= ~(0b111 << 2);
    retVal |= (select << 2);
    retVal = retVal << 8;
    retVal |= 0x75;
    spi_send(spi, retVal);
    gpio_set(gpioport, gpios);
}

uint8_t BMP280_set_spi3w(uint8_t BMP280_register, enum spi3w_en select) {
    gpio_clear(gpioport, gpios);
    uint16_t retVal;
    spi_send(spi, 0xF5);
    retVal = spi_read(spi);
    retVal = retVal >> 8;
    retVal &= ~(0b1);
    retVal |= select;
    retVal = retVal << 8;
    retVal |= 0x75;
    spi_send(spi, retVal);
    gpio_set(gpioport, gpios);
}

void BMP280_reset(uint32_t gpioport, uint16_t gpios, uint32_t spi) {
    gpio_clear(gpioport, gpios);
    spi_send(spi, 0xB6E0);
    gpio_set(gpioport, gpios);
}

void BMP280_useCase(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum useCase select) {
    switch (select) {
        case handheld_device_low_power:
            break;
        case handheld_device_dynamic:
            break;
        case weather_monitoring:
            break;
        case elev_floor_change_detec:
            break;
        case drop_detec:
            break;
        case indoor_nav:
            break;
    }
}


/**
 *
 *
 * @param conn
 * @param mode
 * @param oversampling
 * @param pressure
 * @param temperature
 * @param rms_noise_filter
 */
void BMP280_setup(spi_port conn,
                  mode mode,
                  osrs pressure,
                  osrs temperature,
                  rms_noise_filter
) {
    switch (select) {
        case handheld_device_low_power:
            break;
        case handheld_device_dynamic:
            break;
        case weather_monitoring:
            break;
        case elev_floor_change_detec:
            break;
        case drop_detec:
            break;
        case indoor_nav:
            break;
    }
}