//
// Created by stephan on 27.08.18.
//

#ifndef OPENFLIGHTCONTROLLER_USART_H
#define OPENFLIGHTCONTROLLER_USART_H

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>

class usart {
 public:
  /**
  * @brief Enable clocks for usart
  * @param clken    RCC_USARTx
  */
  void clock_setup(rcc_periph_clken clken) {
    // Enable clock for UART
    rcc_periph_clock_enable(clken);
  }
  /**
 * @brief Setup usart parameters and enable the usart
 * @param usart       USARTx
 * @param baud        9600, 115200, ...
 * @param bits        8, ...
 * @param stopbits    USART_STOPBITS_x
 * @param mode        USART_MODE_x
 * @param parity      USART_PARITY_x
 * @param flowcontrol USART_FLOWCONTROL_x
 */
  void usart_setup(uint32_t usart,
                   uint32_t baud,
                   uint32_t bits,
                   uint32_t stopbits,
                   uint32_t mode,
                   uint32_t parity,
                   uint32_t flowcontrol) {
    // Setup USART2 parameters
    usart_set_baudrate(usart, baud);
    usart_set_databits(usart, bits);
    usart_set_stopbits(usart, stopbits);
    usart_set_mode(usart, mode);
    usart_set_parity(usart, parity);
    usart_set_flow_control(usart, flowcontrol);

    // Finally enable the USART
    usart_enable(usart);
  }
  /**
 * @brief Setup GPIO pins for uasrt
 * @param gpioport       GPIOA, ...
 * @param alt_func_num    GPIO_AFx
 * @param gpios           GPIOx
 */
  void gpio_setup(uint32_t gpioport, uint8_t alt_func_num, uint16_t gpios) {
    // Setup GPIO pins for USART2 transmit
    gpio_mode_setup(gpioport, GPIO_MODE_AF, GPIO_PUPD_NONE, gpios);

    // Setup USART2 TX pin as alternate function
    gpio_set_af(gpioport, alt_func_num, gpios);
  }
};

#endif //OPENFLIGHTCONTROLLER_USART_H


//int main(void) {
//  int i, j = 0, c = 0;
//
//
///* Blink the LED (PD12) on the board with every transmitted byte. */
//  while (1) {
//    gpio_toggle(GPIOA, GPIO5);  /* LED on/off */
//    usart_send_blocking(USART2, c + '0'); /* USART2: Send byte. */
//    c = (c == 9) ? 0 : c + 1;  /* Increment c. */
//    if ((j++ % 80) == 0) {    /* Newline after line full. */
//      usart_send_blocking(USART2, '\r');
//      usart_send_blocking(USART2, '\n');
//    }
//    for (i = 0; i < 300000; i++) {  /* Wait a bit. */
//      __asm__("NOP");
//    }
//  }
//
//  return 0;
//}