#ifndef _BMP280_SPI_H_
#define _BMP280_SPI_H_

#include "BMP280_memorymap.h"

enum mode {
    BMP280_SLEEP = 0b00,
    BMP280_FORCED = 0b01,
    BMP280_NORMAL = 0b11,
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
void setMode(enum mode select);
void setOsrs_t(enum osrs_t select);
void setPsrs_t(enum psrs_t select);
void setStatus(enum status select);
void sett_sb(enum t_sb select);
void setFilter(enum filter select);
void setSpi3w(enum spi3w_en select);
void useCase(enum useCase select);
END_DECLS

#endif //_BMP280_SPI_H_
