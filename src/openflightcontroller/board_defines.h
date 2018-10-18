
#ifndef INTELLIFLIGHT_BOARD_DEFINES_H
#define INTELLIFLIGHT_BOARD_DEFINES_H

#include "openflightcontroller/clock.h"
#include "openflightcontroller/gpio.h"
#include "openflightcontroller/timer.h"
#include "openflightcontroller/usart.h"
#include <libopencm3/stm32/rcc.h>

/***************************** BMP280 & AK8963N *****************************/

#define BMP280_CSS_PORT GPIOA
#define BMP280_CSS_GPIO GPIO2

#define MAG_CSS_PORT GPIOA
#define MAG_CSS_GPIO GPIO3

#define BMP280_SCK_PORT GPIOE
#define BMP280_SCK_GPIO GPIO2
#define BMP280_SCK_AF GPIO_AF5

#define BMP280_MISO_PORT GPIOE
#define BMP280_MISO_GPIO GPIO5
#define BMP280_MISO_AF GPIO_AF5

#define BMP280_MOSI_PORT GPIOE
#define BMP280_MOSI_GPIO GPIO6
#define BMP280_MOSI_AF GPIO_AF5

//TODO: RCC_SPI4 und SPI werden warschnlich nicht richtig erkannt! Warum?
#define BMP280_MAG_RCC RCC_SPI4
#define BMP280_MAG_SPI SPI4

/**************************** SPI2 (PIN HEADER) *****************************/

#define SPI_HEADER_CSS_PORT GPIOD
#define SPI_HEADER_CSS_GPIO GPIO13

#define SPI_HEADER_SCK_PORT GPIOD
#define SPI_HEADER_SCK_GPIO GPIO3
#define SPI_HEADER_SCK_AF GPIO_AF5

#define SPI_HEADER_MISO_PORT GPIOB
#define SPI_HEADER_MISO_GPIO GPIO14
#define SPI_HEADER_MISO_AF GPIO_AF5

#define SPI_HEADER_MOSI_PORT GPIOB
#define SPI_HEADER_MOSI_GPIO GPIO15
#define SPI_HEADER_MOSI_AF GPIO_AF5

#define SPI_HEADER_RCC RCC_SPI2
#define SPI_HEADER_SPI SPI2

#endif //INTELLIFLIGHT_BOARD_DEFINES_H
