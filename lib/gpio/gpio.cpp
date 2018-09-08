//
// Created by stephan on 26.08.18.
//

#include "gpio.h"

bool GPIO::get() const {
  if (mode == GPIO_MODE_INPUT) {
    if (gpio_get(gpioport, gpios)) {
      return 1;
    } else {
      return 0;
    }
  }
}

void GPIO::set(const bool value) {
  if (mode == GPIO_MODE_OUTPUT) {
    if (value == 1) {
      gpio_clear(gpioport, gpios);
    } else {
      gpio_set(gpioport, gpios);
    }
  }
}

void GPIO::toggle() const {
  if (mode == GPIO_MODE_OUTPUT) {
    gpio_toggle(gpioport, gpios);
  }
}