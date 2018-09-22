#include "src/timer.h"
#include "src/gpio.h"

//TODO: Add UART_RX interrupt

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/lm4f/nvic.h>   //Nvic is from the wrong controller, missing stm32

static void uartSetup(void);

int main(void) {
    gpioSetup();
    timerSetup();
    uartSetup();
    while (true) {
        for (int i = 0; i < 50000; i++) {}
        gpio_toggle(GPIOC, GPIO13);
        usart_send(UART7, 0xEA);
    }
}

static void uartSetup(void) {
    /** Uart 4 Setup */
    /*Setup GPIO pins used by uart*/
    rcc_periph_clock_enable(RCC_GPIOA);
    gpio_mode_setup(GPIOA, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO0 | GPIO1);
    gpio_set_af(GPIOA, GPIO_AF8, GPIO0 | GPIO1);
    gpio_set_output_options(GPIOA, GPIO_OTYPE_PP, GPIO_OSPEED_100MHZ, GPIO0 | GPIO1);

    /*Setup of the uart it selve*/
    rcc_periph_clock_enable(RCC_UART4);
    usart_set_baudrate(UART4, 115200);
    usart_set_databits(UART4, 8);
    usart_set_stopbits(UART4, USART_STOPBITS_1);
    usart_set_mode(UART4, USART_MODE_TX_RX);
    usart_set_parity(UART4, USART_PARITY_NONE);
    usart_set_flow_control(UART4, USART_FLOWCONTROL_NONE);
    usart_enable_halfduplex(UART4);     //Only used by the satellites
    usart_enable(UART4);

    /*Configuring interrupts*/
    usart_enable_rx_interrupt(UART4);
    nvic_enable_irq(NVIC_UART4_IRQ);

    /** Uart 5 Setup */
    /*Setup GPIO pins used by uart*/
    rcc_periph_clock_enable(RCC_GPIOB);
    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO12 | GPIO13);
    gpio_set_af(GPIOB, GPIO_AF8, GPIO12 | GPIO13);
    gpio_set_output_options(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_100MHZ, GPIO12 | GPIO13);

    /*Setup of the uart it selve*/
    rcc_periph_clock_enable(RCC_UART5);
    usart_set_baudrate(UART5, 115200);
    usart_set_databits(UART5, 8);
    usart_set_stopbits(UART5, USART_STOPBITS_1);
    usart_set_mode(UART5, USART_MODE_TX_RX);
    usart_set_parity(UART5, USART_PARITY_NONE);
    usart_set_flow_control(UART5, USART_FLOWCONTROL_NONE);
    usart_enable(UART5);

    /** Uart 7 Setup */
    /*Setup GPIO pins used by uart*/
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO7 | GPIO8);
    gpio_set_af(GPIOE, GPIO_AF8, GPIO7 | GPIO8);
    gpio_set_output_options(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_100MHZ, GPIO7 | GPIO8);

    /*Setup of the uart it selve*/
    rcc_periph_clock_enable(RCC_UART7);     //Change libopencm3 RCC_SPI7 -> RCC_UART7
    usart_set_baudrate(UART7, 115200);
    usart_set_databits(UART7, 8);
    usart_set_stopbits(UART7, USART_STOPBITS_1);
    usart_set_mode(UART7, USART_MODE_TX_RX);
    usart_set_parity(UART7, USART_PARITY_NONE);
    usart_set_flow_control(UART7, USART_FLOWCONTROL_NONE);
    usart_enable(UART7);

    /** Uart 8 Setup */
    /*Setup GPIO pins used by uart*/
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO0 | GPIO1);
    gpio_set_af(GPIOE, GPIO_AF8, GPIO0 | GPIO1);
    gpio_set_output_options(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_100MHZ, GPIO0 | GPIO1);

    /*Setup of the uart it selve*/
    rcc_periph_clock_enable(RCC_UART8);     //Change libopencm3 RCC_SPI8 -> RCC_UART8
    usart_set_baudrate(UART8, 115200);
    usart_set_databits(UART8, 8);
    usart_set_stopbits(UART8, USART_STOPBITS_1);
    usart_set_mode(UART8, USART_MODE_TX_RX);
    usart_set_parity(UART8, USART_PARITY_NONE);
    usart_set_flow_control(UART8, USART_FLOWCONTROL_NONE);
    usart_enable_halfduplex(UART8);     //Only used by the satellites
    usart_enable(UART8);
}

void uart7_isr(){
//    uart_clear_interrupt_flag(UART0, serviced_irqs); //TODO: implement missing method, correct the nvic
}