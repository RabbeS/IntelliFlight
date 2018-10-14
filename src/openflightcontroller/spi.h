#ifndef INTELLIFLIGHT_SPI_H
#define INTELLIFLIGHT_SPI_H

#include <openflightcontroller/board_defines.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/spi.h>

uint32_t cr_tmp;

static void spi_setup(void);

uint16_t read_reg(int reg);

static void write_reg(uint8_t reg, uint8_t value);

uint8_t read_xyz(int16_t vecs[3]);

struct spi_port {
    uint32_t gpioport;
    uint16_t gpios;
    uint32_t spi;
};

static void spi_setup(void) {
    /** SPI1 */
    /* Enable the GPIO ports whose pins we are using */
    rcc_periph_clock_enable(RCC_GPIOA);

    gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, GPIO5 | GPIO6 | GPIO7);
    gpio_set_af(GPIOA, GPIO_AF5, GPIO5 | GPIO6 | GPIO7);
    /* Set SCK and MOSI to otype_pp*/
    gpio_set_output_options(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, GPIO5 | GPIO7);

    /* Chip select line */
    gpio_set(GPIOA, GPIO4);
    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO4);

    rcc_periph_clock_enable(RCC_SPI1);

    cr_tmp = SPI_CR1_BAUDRATE_FPCLK_DIV_8 | SPI_CR1_MSTR | SPI_CR1_SPE | SPI_CR1_CPHA | SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE;

    SPI_CR2(SPI1) |= SPI_CR2_SSOE;
    SPI_CR1(SPI1) = cr_tmp;

    /** SPI2 */
    /* Enable the GPIO ports whose pins we are using */
    rcc_periph_clock_enable(RCC_GPIOB);
    rcc_periph_clock_enable(RCC_GPIOD);

    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, GPIO14 | GPIO15);
    gpio_mode_setup(GPIOD, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, GPIO3);
    gpio_set_af(GPIOB, GPIO_AF5, GPIO14 | GPIO15);
    gpio_set_af(GPIOD, GPIO_AF5, GPIO3);
    /* Set SCK and MOSI to otype_pp*/
    gpio_set_output_options(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, GPIO15);
    gpio_set_output_options(GPIOD, GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, GPIO3);

    /* Chip select line */
    gpio_set(GPIOD, GPIO13);
    gpio_mode_setup(GPIOD, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);

    rcc_periph_clock_enable(RCC_SPI2);

    spi_set_dff_16bit(SPI2);
    cr_tmp =
            SPI_CR1_BAUDRATE_FPCLK_DIV_32 | SPI_CR1_MSTR | SPI_CR1_SPE | SPI_CR1_CPHA | SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE;

    SPI_CR2(SPI2) |= SPI_CR2_SSOE;
    SPI_CR1(SPI2) = cr_tmp;

    /** BMP280_SPI */
    /* Enable the GPIO ports whose pins we are using */
    rcc_periph_clock_enable(RCC_GPIOA);
    rcc_periph_clock_enable(RCC_GPIOE);

    gpio_mode_setup(GPIOE, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, GPIO2 | GPIO5 | GPIO6);
    gpio_set_af(GPIOE, GPIO_AF5, GPIO2 | GPIO5 | GPIO6);
    /* Set SCK and MOSI to otype_pp*/
    gpio_set_output_options(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, GPIO2 | GPIO6);

    /* Chip select p+t */
    gpio_set(GPIOA, GPIO2);
    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO2);

    /* Chip select mag. */
    gpio_set(GPIOA, GPIO3);
    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO3);

    rcc_periph_clock_enable(RCC_SPI4);

//    spi_set_dff_16bit(BMP280_SPI);
    cr_tmp = SPI_CR1_BAUDRATE_FPCLK_DIV_8 | SPI_CR1_MSTR | SPI_CR1_SPE | SPI_CR1_CPHA | SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE;
    cr_tmp |= SPI_CR1_MSBFIRST;

    SPI_CR2(BMP280_SPI) |= SPI_CR2_SSOE;
    SPI_CR1(BMP280_SPI) = cr_tmp;
}

#endif //INTELLIFLIGHT_SPI_H
