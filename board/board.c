#include "hal.h"
#include "stm32_gpio.h"

static void stm32_gpio_init(void) {
  rccResetAHB1(STM32_GPIO_EN_MASK);
  rccEnableAHB1(STM32_GPIO_EN_MASK, true);
  // Button
  palSetLineMode(BUTTON, PAL_MODE_INPUT);
  // USB
  palSetLineMode(USB_DM, PAL_MODE_ALTERNATE(10) | PAL_STM32_OSPEED_HIGHEST);
  palSetLineMode(USB_DP, PAL_MODE_ALTERNATE(10) | PAL_STM32_OSPEED_HIGHEST);
  // Serial
  palSetLineMode(UART_TX, PAL_MODE_ALTERNATE(7));
  palSetLineMode(UART_RX, PAL_MODE_ALTERNATE(7));
  // LED
  palSetLineMode(ACTIVITY_LED, PAL_MODE_OUTPUT_OPENDRAIN);
}

/**
 * @brief   Early initialization code.
 * @details GPIO ports and system clocks are initialized before everything
 *          else.
 */
void __early_init(void) {
  stm32_gpio_init();
  stm32_clock_init();
}

#if HAL_USE_SDC || defined(__DOXYGEN__)
/**
 * @brief   SDC card detection.
 */
bool sdc_lld_is_card_inserted(SDCDriver *sdcp) {

  (void)sdcp;
  /* CHTODO: Fill the implementation.*/
  return true;
}

/**
 * @brief   SDC card write protection detection.
 */
bool sdc_lld_is_write_protected(SDCDriver *sdcp) {

  (void)sdcp;
  /* CHTODO: Fill the implementation.*/
  return false;
}
#endif /* HAL_USE_SDC */

#if HAL_USE_MMC_SPI || defined(__DOXYGEN__)
/**
 * @brief   MMC_SPI card detection.
 */
bool mmc_lld_is_card_inserted(MMCDriver *mmcp) {

  (void)mmcp;
  /* CHTODO: Fill the implementation.*/
  return true;
}

/**
 * @brief   MMC_SPI card write protection detection.
 */
bool mmc_lld_is_write_protected(MMCDriver *mmcp) {

  (void)mmcp;
  /* CHTODO: Fill the implementation.*/
  return false;
}
#endif

/**
 * @brief   Board-specific initialization code.
 * @note    You can add your board-specific code here.
 */
void boardInit(void) {

}
