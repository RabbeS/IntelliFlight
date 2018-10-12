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

enum osrs {
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
    t_sb_0 = 0b000, //Standbytime: 0.5ms
    t_sb_1 = 0b001, //Standbytime: 62.5ms
    t_sb_2 = 0b010, //Standbytime: 125ms
    t_sb_3 = 0b011, //Standbytime: 250ms
    t_sb_4 = 0b100, //Standbytime: 500ms
    t_sb_5 = 0b101, //Standbytime: 1000ms
    t_sb_6 = 0b110, //Standbytime: 2000ms
    t_sb_7 = 0b111, //Standbytime: 4000ms
};

enum filter {

};

enum spi3w_en {
    spi3w_enable = 0x1,
    spi3_disable = 0x0,
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
uint8_t BMP280_setMode(uint8_t BMP280_register, enum mode select);
uint8_t BMP280_setOsrs_p(uint8_t BMP280_register, enum osrs select);
uint8_t BMP280_setOsrs_t(uint8_t BMP280_register, enum osrs select);
uint8_t BMP280_sett_sb(uint8_t BMP280_register, enum t_sb select);
uint8_t BMP280_setFilter(uint8_t BMP280_register, enum filter select);
uint8_t BMP280_setSpi3w(uint8_t BMP280_register, enum spi3w_en select);
void BMP280_reset(uint32_t gpioport, uint16_t gpios, uint32_t spi);
void BMP280_useCase(uint32_t gpioport, uint16_t gpios, uint32_t spi, enum useCase select);
END_DECLS

#endif //_BMP280_SPI_H_
