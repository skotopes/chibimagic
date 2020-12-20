#ifndef BOARD_H
#define BOARD_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

#define BOARD_BLACKPILL
#define BOARD_NAME                  "Blackpill STM32F11CE"

#define STM32_LSECLK                32768U
#define STM32_HSECLK                25000000U

#define STM32_VDD                   300U

#define STM32F411xE

#define BUTTON          PAL_LINE(GPIOA, 0)

#define USB_DM          PAL_LINE(GPIOA, 11)
#define USB_DP          PAL_LINE(GPIOA, 12)

#define UART_TX         PAL_LINE(GPIOB, 6)
#define UART_RX         PAL_LINE(GPIOB, 7)

#define ACTIVITY_LED    PAL_LINE(GPIOC, 13)

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* BOARD_H */
