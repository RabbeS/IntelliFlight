#ifndef _BMP280_SPI_H_
#define _BMP280_SPI_H_

#include "BMP280_memorymap.h"
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/spi.h>

void bmp280_send_register(uint8_t register_addr, uint8_t data);

uint8_t bmp280_recv_register(uint8_t register_addr);

enum mode {
    SLEEP = 0b00,
    FORCED = 0b01,
    NORMAL = 0b11,
};

enum osrs {
    OVERSAMPLING_OFF = 0b000,
    OVERSAMPLING_X1 = 0b001,
    OVERSAMPLING_X2 = 0b010,
    OVERSAMPLING_X4 = 0b011,
    OVERSAMPLING_X8 = 0b100,
    OVERSAMPLING_X16 = 0b111,
};

enum status {
    MEASURING = (0x1 << 3),
    IMAGEREGISTERS_UPDATE = (0x1 << 0),
};

enum t_sb {
    STANDBYTIM_MS_0_5 = 0b000, ///< Standbytime: 0.5ms
    STANDBYTIM_MS_62_5 = 0b001, ///< Standbytime: 62.5ms
    STANDBYTIM_MS_125 = 0b010, ///< Standbytime: 125ms
    STANDBYTIM_MS_250 = 0b011, ///< Standbytime: 250ms
    STANDBYTIM_MS_500 = 0b100, ///< Standbytime: 500ms
    STANDBYTIM_MS_1000 = 0b101, ///< Standbytime: 1000ms
    STANDBYTIM_MS_2000 = 0b110, ///< Standbytime: 2000ms
    STANDBYTIM_MS_4000 = 0b111, ///< Standbytime: 4000ms
};

enum filter {
    FILTER_OFF = 0b000,
//  TODO!
//  FILTER_X1 = 0b001,
};

enum spi3w_en {
    SPI_3W_SIMPLEX = 0x1,
    SPI_4W_DUPLEX = 0x0,
};


BEGIN_DECLS
uint8_t BMP280_set_mode(uint8_t BMP280_register, mode select);
uint8_t BMP280_set_osrs_p(uint8_t
BMP280_register,
enum osrs select
);
uint8_t BMP280_set_osrs_t(uint8_t
BMP280_register,
enum osrs select
);
uint8_t BMP280_set_t_sb(uint8_t
BMP280_register,
enum t_sb select
);
uint8_t BMP280_set_filter(uint8_t
BMP280_register,
enum filter select
);
uint8_t BMP280_set_spi3w(uint8_t
BMP280_register,
enum spi3w_en select
);

void BMP280_reset(uint32_t gpioport, uint16_t gpios, uint32_t spi);

void BMP280_setup(uint32_t gpioport, uint16_t gpios, uint32_t spi);

END_DECLS


#endif //_BMP280_SPI_H_
