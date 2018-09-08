//
// Created by stephan on 26.08.18.
//

#ifndef BOARD_H
#define BOARD_H

#include "lib/gpio/gpio.h"
#include "lib/usart/usart.h"
#include "lib/pwm/pwm.h"

#define LED_0 GPIO{RCC_GPIOC, GPIOC, GPIO_MODE_OUTPUT, GPIO13}
#define GPIO_7 GPIO{RCC_GPIOB, GPIOB, GPIO_MODE_OUTPUT, GPIO2}

#define CD_A GPIO{RCC_GPIOD, GPIOD, GPIO_MODE_INPUT, GPIO0}
#define CD_B GPIO{RCC_GPIOD, GPIOD, GPIO_MODE_INPUT, GPIO1}

namespace board_v05 {

}

#endif //BOARD_H
