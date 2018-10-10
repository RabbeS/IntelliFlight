#include "BMP280_SPI.h"


//TODO: Use memorymap to read/write a register of the BMP280

//TODO: How to reduce the number methode elemnts (uint32_t gpioport, uint16_t gpios, uint32_t spi)
void setMode(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum mode select) {
    gpio_clear(gpioport, gpios);
    uint16_t retVal;
    spi_send(spi, 0xF4);
    retVal = spi_read(spi);
    retVal = retVal >> 4;
    retVal = retVal & ~(0b11);
    retVal |= select;
    retVal = retVal << 4;
    retVal |= 0x74;
    spi_send(spi, retVal)
    gpio_set(gpioport, gpios);
}

void setOsrs_t(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum osrs_t select) {

}

void setPsrs_t(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum psrs_t select) {

}

void setStatus(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum status select) {

}

void sett_sb(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum t_sb select) {

}

void setFilter(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum filter select) {

}

void setSpi3w(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum spi3w_en select) {

}

void useCase(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum useCase select) {
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