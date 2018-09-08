//
// Created by stephan on 26.08.18.
//

#ifndef OPENFLIGHTCONTROLLER_GPIO_H
#define OPENFLIGHTCONTROLLER_GPIO_H

#include "libopencm3/stm32/rcc.h"
#include "libopencm3/stm32/gpio.h"

class GPIO {
 private:
  rcc_periph_clken clken;
  uint32_t gpioport;
  uint8_t mode;
  uint16_t gpios;

 public:
  /**
   * @brief
   * @param clken       z.B: RCC_GPIOA
   * @param gpioport    z.B: GPIOA
   * @param mode        GPIO_MODE_OUTPUT, GPIO_MODE_INPUT
   * @param gpios       z.B: GPIO1
   */
  GPIO(rcc_periph_clken clken, uint32_t gpioport, uint8_t mode, uint16_t gpios)
      : clken(clken), gpioport(gpioport), mode(mode), gpios(gpios) {
    rcc_periph_clock_enable(clken);
    gpio_mode_setup(gpioport, mode, GPIO_PUPD_NONE, gpios);
  }

  virtual ~GPIO() {};

  bool get() const;

  void set(const bool value);

  void toggle() const;
};

#endif //OPENFLIGHTCONTROLLER_GPIO_H
