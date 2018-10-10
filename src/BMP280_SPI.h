#ifndef _BMP280_SPI_H_
#define _BMP280_SPI_H_

#include <BMP280_memorymap.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/spi.h>

enum mode {
    SLEEP = 0b00,
    FORCED = 0b01,
    NORMAL = 0b11,
};

enum osrs_t {
    skipped = 0b000,
    x1 = 0b001,
    x2 = 0b010,
    x4 = 0b011,
    x8 = 0b100,
    x16 = 0b111,
};

enum osrs_p {
    skipped = 0b000,
    x1 = 0b001,
    x2 = 0b010,
    x4 = 0b011,
    x8 = 0b100,
    x16 = 0b111,
};

enum status {
    measuring = (0x1 << 3),
    im_update = (0x1 << 0),
};

enum t_sb {

};

enum filter {

};

enum spi3w_en {
    spi3w_enable = 0x1;
    spi3_disable = 0x0;
};

enum useCase {
    handheld_device_low_power,
    handheld_device_dynamic,
    weather_monitoring,
    elev_floor_change_detec,
    drop_detec,
    indoor_nav,
};

BEGIN_DECLS
void setMode(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum mode select);
void setOsrs_t(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum osrs_t select);
void setPsrs_t(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum psrs_t select);
void setStatus(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum status select);
void sett_sb(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum t_sb select);
void setFilter(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum filter select);
void setSpi3w(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum spi3w_en select);
void useCase(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum useCase select);
END_DECLS

#endif //_BMP280_SPI_H_
