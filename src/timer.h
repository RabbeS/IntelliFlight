#ifndef INTELLIFLIGHT_TIMER_H
#define INTELLIFLIGHT_TIMER_H

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

static void timerSetup(void);
static void timerEnable(void);
static void timerDisable(void);
static void setPeriod(void);
static void setCompareVal(void);
static void getCompareVal(void);

static void timerSetup(void) {
    /** Timer 1 (Ch 1234) Setup */
    /*Setup GPIO pins used by the timer*/
    rcc_periph_clock_enable(RCC_GPIOE);
    gpio_mode_setup(GPIOE, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO9 | GPIO11 | GPIO13 | GPIO14);
    gpio_set_af(GPIOE, GPIO_AF1, GPIO9 | GPIO11 | GPIO13 | GPIO14);
    gpio_set_output_options(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO9 | GPIO11 | GPIO13 | GPIO14);

    rcc_periph_clock_enable(RCC_TIM1);
    timer_set_mode(TIM1, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1,
                   TIM_CR1_DIR_UP);

    timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_PWM1);
    timer_set_oc_mode(TIM1, TIM_OC2, TIM_OCM_PWM1);
    timer_set_oc_mode(TIM1, TIM_OC3, TIM_OCM_PWM1);
    timer_set_oc_mode(TIM1, TIM_OC4, TIM_OCM_PWM1);
    timer_enable_oc_output(TIM1, TIM_OC1);
    timer_enable_oc_output(TIM1, TIM_OC2);
    timer_enable_oc_output(TIM1, TIM_OC3);
    timer_enable_oc_output(TIM1, TIM_OC4);
    timer_enable_break_main_output(TIM1);

    /*The timer_set_oc_value function can be omitted here*/
//    timer_set_oc_value(TIM1, TIM_OC1, 2000);
//    timer_set_oc_value(TIM1, TIM_OC2, 2000);
//    timer_set_oc_value(TIM1, TIM_OC3, 2000);
//    timer_set_oc_value(TIM1, TIM_OC4, 2000);
    timer_set_period(TIM1, ((rcc_apb1_frequency * 2) / 500000));
    timer_enable_counter(TIM1);

    /** Timer 2 (Ch34) Setup */
    /*Setup GPIO pins used by the timer*/
    rcc_periph_clock_enable(RCC_GPIOB);
    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO10 | GPIO11);
    gpio_set_af(GPIOB, GPIO_AF1, GPIO10 | GPIO11);
    gpio_set_output_options(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO10 | GPIO11);


    rcc_periph_clock_enable(RCC_TIM2);
    timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1,
                   TIM_CR1_DIR_UP);

    timer_set_oc_mode(TIM2, TIM_OC3, TIM_OCM_PWM1);
    timer_set_oc_mode(TIM2, TIM_OC4, TIM_OCM_PWM1);
    timer_enable_oc_output(TIM2, TIM_OC3);
    timer_enable_oc_output(TIM2, TIM_OC4);
    timer_enable_break_main_output(TIM2);

    /*The timer_set_oc_value function can be omitted here*/
//    timer_set_oc_value(TIM2, TIM_OC3, 2000);
//    timer_set_oc_value(TIM2, TIM_OC4, 2000);
    timer_set_period(TIM2, ((rcc_apb1_frequency * 2) / 500000));
    timer_enable_counter(TIM2);

    /** Timer 3 (Ch34) Setup */
    /*Setup GPIO pins used by the timer*/
    rcc_periph_clock_enable(RCC_GPIOB);
    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO0 | GPIO1);
    gpio_set_af(GPIOB, GPIO_AF2, GPIO0 | GPIO1);
    gpio_set_output_options(GPIOB, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO0 | GPIO1);


    rcc_periph_clock_enable(RCC_TIM3);
    timer_set_mode(TIM3, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1,
                   TIM_CR1_DIR_UP);

    timer_set_oc_mode(TIM3, TIM_OC3, TIM_OCM_PWM1);
    timer_set_oc_mode(TIM3, TIM_OC4, TIM_OCM_PWM1);
    timer_enable_oc_output(TIM3, TIM_OC3);
    timer_enable_oc_output(TIM3, TIM_OC4);
    timer_enable_break_main_output(TIM3);

    /*The timer_set_oc_value function can be omitted here*/
//    timer_set_oc_value(TIM3, TIM_OC3, 2000);
//    timer_set_oc_value(TIM3, TIM_OC4, 2000);
    timer_set_period(TIM3, ((rcc_apb1_frequency * 2) / 500000));
    timer_enable_counter(TIM3);

    /** Timer 4 (Ch34) Setup */
    /*Setup GPIO pins used by the timer*/
    rcc_periph_clock_enable(RCC_GPIOD);
    gpio_mode_setup(GPIOD, GPIO_MODE_AF, GPIO_OTYPE_PP, GPIO14 | GPIO15);
    gpio_set_af(GPIOD, GPIO_AF2, GPIO14 | GPIO15);
    gpio_set_output_options(GPIOD, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, GPIO14 | GPIO15);


    rcc_periph_clock_enable(RCC_TIM4);
    timer_set_mode(TIM4, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1,
                   TIM_CR1_DIR_UP);

    timer_set_oc_mode(TIM4, TIM_OC3, TIM_OCM_PWM1);
    timer_set_oc_mode(TIM4, TIM_OC4, TIM_OCM_PWM1);
    timer_enable_oc_output(TIM4, TIM_OC3);
    timer_enable_oc_output(TIM4, TIM_OC4);
    timer_enable_break_main_output(TIM4);

    /*The timer_set_oc_value function can be omitted here*/
//    timer_set_oc_value(TIM4, TIM_OC3, 2000);
//    timer_set_oc_value(TIM4, TIM_OC4, 2000);
    timer_set_period(TIM4, ((rcc_apb1_frequency * 2) / 500000));
    timer_enable_counter(TIM4);
}

#endif //INTELLIFLIGHT_TIMER_H
