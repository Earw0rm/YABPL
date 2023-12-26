#ifndef GPIO
#define GPIO

#include "types.h"

#define GPIO_BASE 0x10012000
#define GPIO_INPUT_VAL (GPIO_BASE)
#define GPIO_INPUT_EN (GPIO_BASE + 0x04)
#define GPIO_OUTPUT_EN (GPIO_BASE + 0x08)
#define GPIO_OUTPUT_VAL (GPIO_BASE + 0x0C)
#define GPIO_PUE (GPIO_BASE + 0x10)
#define GPIO_DS (GPIO_BASE + 0x14)

#define GPIO_FALL_IE (GPIO_BASE + 0x20)
#define GPIO_FALL_IP (GPIO_BASE + 0x24)

#define GPIO_IOF_EN (GPIO_BASE + 0x38)
#define GPIO_IOF_SEL (GPIO_BASE + 0x3C)

#define GPIO_OUTPUT_XOR (GPIO_BASE + 0x40)
#define GPIO_PASSTHRU_LOW_IE (GPIO_BASE + 0x48)
#define GPIO_LAST_ADDR (GPIO_PASSTHRU_LOW_IE)



void gpio_init(void);
void blue_led_on(void);
void red_led_on(void);
void green_led_on(void);

void blue_led_off(void);
void red_led_off(void);
void green_led_off(void);


void io_function_enable_1(uint32_t);
void io_select_1(uint32_t);

#endif