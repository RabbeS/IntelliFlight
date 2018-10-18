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
    gpio_mode_setup(SPI_HEADER_MISO_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, SPI_HEADER_MISO_GPIO);
    gpio_mode_setup(SPI_HEADER_MOSI_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, SPI_HEADER_MOSI_GPIO);
    gpio_mode_setup(SPI_HEADER_SCK_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, SPI_HEADER_SCK_GPIO);
    gpio_set_af(SPI_HEADER_MISO_PORT, SPI_HEADER_MISO_AF, SPI_HEADER_MISO_GPIO);
    gpio_set_af(SPI_HEADER_MOSI_PORT, SPI_HEADER_MOSI_AF, SPI_HEADER_MOSI_GPIO);
    gpio_set_af(SPI_HEADER_SCK_PORT, SPI_HEADER_SCK_AF, SPI_HEADER_SCK_GPIO);

    /* Set SCK and MOSI to otype_pp*/
    gpio_set_output_options(SPI_HEADER_MOSI_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, SPI_HEADER_MOSI_GPIO);
    gpio_set_output_options(SPI_HEADER_SCK_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, SPI_HEADER_SCK_GPIO);

    /* Chip select spi header */
    gpio_set(SPI_HEADER_CSS_PORT, SPI_HEADER_CSS_GPIO);
    gpio_mode_setup(SPI_HEADER_CSS_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, SPI_HEADER_CSS_GPIO);

    spi_reset(SPI2);
    rcc_periph_clock_enable(RCC_SPI2);

    spi_set_dff_8bit(SPI2);
    cr_tmp =
            SPI_CR1_BAUDRATE_FPCLK_DIV_32 | SPI_CR1_MSTR | SPI_CR1_SPE | SPI_CR1_CPHA | SPI_CR1_CPOL_CLK_TO_1_WHEN_IDLE;

    SPI_CR2(SPI2) |= SPI_CR2_SSOE;
    SPI_CR1(SPI2) |= cr_tmp;

    /** BMP280_SPI */
    /* Enable the GPIO ports whose pins we are using */
    gpio_mode_setup(BMP280_MISO_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, BMP280_MISO_GPIO);
    gpio_mode_setup(BMP280_MOSI_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, BMP280_MOSI_GPIO);
    gpio_mode_setup(BMP280_SCK_PORT, GPIO_MODE_AF, GPIO_PUPD_PULLDOWN, BMP280_SCK_GPIO);
    gpio_set_af(BMP280_MISO_PORT, BMP280_MISO_AF, BMP280_MISO_GPIO);
    gpio_set_af(BMP280_MOSI_PORT, BMP280_MOSI_AF, BMP280_MOSI_GPIO);
    gpio_set_af(BMP280_SCK_PORT, BMP280_SCK_AF, BMP280_SCK_GPIO);

    /* Set SCK and MOSI to otype_pp*/
    gpio_set_output_options(BMP280_MOSI_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, BMP280_MOSI_GPIO);
    gpio_set_output_options(BMP280_SCK_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_25MHZ, BMP280_SCK_GPIO);

    /* Chip select p+t */
    gpio_set(BMP280_CSS_PORT, BMP280_CSS_GPIO);
    gpio_mode_setup(BMP280_CSS_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, BMP280_CSS_GPIO);

    /* Chip select mag. */
    gpio_set(MAG_CSS_PORT, MAG_CSS_GPIO);
    gpio_mode_setup(MAG_CSS_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, MAG_CSS_GPIO);

    spi_reset(BMP280_MAG_SPI);
    rcc_periph_clock_enable(BMP280_MAG_RCC);

    spi_set_baudrate_prescaler(BMP280_MAG_SPI, 8);
    spi_set_master_mode(BMP280_MAG_SPI);
    spi_set_clock_phase_1(BMP280_MAG_SPI);
    spi_set_clock_polarity_1(BMP280_MAG_SPI);
    spi_send_msb_first(BMP280_MAG_SPI);
    spi_set_dff_8bit(BMP280_MAG_SPI);
    spi_enable(BMP280_MAG_SPI);
}

#endif //INTELLIFLIGHT_SPI_H
