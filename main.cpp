#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/gpio.h>

static void clockSetup();
static void gpioInit();
static void timerInit();
void tim2_isr();

int main(void) {
  clockSetup();
  gpioInit();
  timerInit();

  while (true) {
  }
}

static void clockSetup() {
  rcc_clock_setup_hsi(&rcc_3v3[RCC_CLOCK_3V3_72MHZ]);
}

static void gpioInit() {
  rcc_periph_clock_enable(RCC_GPIOE);
  gpio_mode_setup(GPIOE, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO13);
  gpio_set_af(GPIOE, GPIO_AF1, GPIO13);
  gpio_set_output_options(GPIOE, GPIO_OTYPE_PP, GPIO_OSPEED_100MHZ, GPIO13);
}

void timerInit() {
  rcc_periph_clock_enable(RCC_TIM1);
  rcc_periph_reset_pulse(RST_TIM1);

  timer_set_mode(
      TIM1,
      TIM_CR1_CKD_CK_INT,
      TIM_CR1_CMS_EDGE,
      TIM_CR1_DIR_UP
  );
//  timer_direction_up(TIM1);
//  timer_set_clock_division(TIM1, 0);

  timer_set_prescaler(TIM1, ((rcc_apb1_frequency * 2) / 5000));

  timer_disable_preload(TIM1);
  timer_continuous_mode(TIM1);

  timer_set_period(TIM1, 65535); // Periodendauer
  timer_set_oc_value(TIM1, TIM_OC3, 32767); // Ausschlag: Schwellenwert

//  timer_set_repetition_counter(TIM1, 0);
//  timer_enable_compare_control_update_on_trigger(TIM1_CCR3);

  /*There is some code about oc preloade etc.*/

  timer_enable_counter(TIM1);

  timer_enable_irq(TIM1, TIM_DIER_CC3IE);
}

void tim2_isr(){
  if(timer_get_flag(TIM1, TIM_SR_CC3IF)){
    timer_clear_flag(TIM1, TIM_SR_CC3IF);
    gpio_toggle(GPIOE, GPIO13);
  }
}