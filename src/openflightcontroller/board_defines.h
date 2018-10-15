
#ifndef INTELLIFLIGHT_BOARD_DEFINES_H
#define INTELLIFLIGHT_BOARD_DEFINES_H

#include "openflightcontroller/clock.h"
#include "openflightcontroller/gpio.h"
#include "openflightcontroller/timer.h"
#include "openflightcontroller/usart.h"

#define BMP280_CSS_PORT GPIOA
#define BMP280_CSS_GPIO GPIO2

#define MAG_CSS_PORT GPIOA
#define MAG_CSS_GPIO GPIO3

#define BMP280_MISO_PORT GPIOE
#define BMP280_MISO_GPIO GPIO5
#define BMP280_MISO_AF GPIO_AF5

#define BMP280_MOSI_PORT GPIOE
#define BMP280_MOSI_GPIO GPIO6
#define BMP280_MOSI_AF GPIO_AF5

#define BMP280_SCK_PORT GPIOE
#define BMP280_SCK_GPIO GPIO2
#define BMP280_SCK_AF GPIO_AF5

#define BMP280_MAG_RCC RCC_SPI4
#define BMP280_MAG_SPI SPI4


#endif //INTELLIFLIGHT_BOARD_DEFINES_H
