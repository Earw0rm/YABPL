#include "types.h"
#include "GPIO.h"

void gpio_init(void){
    
    // uint32_t gpio_port_mask = 1 << 16;
    uint32_t gpio_led_mask = 1 << 21 | 1 << 19 | 1 << 22;
    // zero gpio
    for(uint32_t * addr = (uint32_t *) GPIO_BASE;
                   addr <=(uint32_t *) GPIO_PASSTHRU_LOW_IE;
                 ++addr) *addr = 0;
    

    // uint32_t * input_enable = (uint32_t *) GPIO_INPUT_EN;
    // *input_enable = gpio_port_mask;

    // uint32_t * pue = (uint32_t *) GPIO_PUE;
    // *pue = gpio_port_mask;

    // uint32_t * fall_interrupt_enable = (uint32_t *) GPIO_FALL_IE;
    // *fall_interrupt_enable = gpio_port_mask;

    uint32_t * output_enable = (uint32_t *) GPIO_OUTPUT_EN;
    *output_enable = gpio_led_mask;

    uint32_t * gpio_output_val = (uint32_t *) GPIO_OUTPUT_VAL;
    *gpio_output_val = gpio_led_mask;


    io_function_enable_1(17); // тк у нас ноль очистили делаем бр бр для uart0
}




void blue_led_on(void){
    uint32_t led_mask_on = ~(1 << 21);
    uint32_t * gpio_output_val = (uint32_t *) GPIO_OUTPUT_VAL;
    *gpio_output_val &= led_mask_on;    
}
void red_led_on(void){
    uint32_t led_mask_on = ~(1 << 22);
    uint32_t * gpio_output_val = (uint32_t *) GPIO_OUTPUT_VAL;
    *gpio_output_val &= led_mask_on;    
}
void green_led_on(void){
    uint32_t led_mask_on = ~(1 << 19);
    uint32_t * gpio_output_val = (uint32_t *) GPIO_OUTPUT_VAL;
    *gpio_output_val &= led_mask_on;  
}

void blue_led_off(void){
    uint32_t led_mask_off = 1 << 21;
    uint32_t * gpio_output_val = (uint32_t *) GPIO_OUTPUT_VAL;
    *gpio_output_val |= led_mask_off;    
}

void red_led_off(void){
    uint32_t led_mask_off = 1 << 22;
    uint32_t * gpio_output_val = (uint32_t *) GPIO_OUTPUT_VAL;
    *gpio_output_val |= led_mask_off;    
}
void green_led_off(void){
    uint32_t led_mask_off = 1 << 19;
    uint32_t * gpio_output_val = (uint32_t *) GPIO_OUTPUT_VAL;
    *gpio_output_val |= led_mask_off;    
}


// #define GPIO_IOF_EN (GPIO_BASE + 0x38)
// #define GPIO_IOF_SEL (GPIO_BASE + 0x3C)

void io_function_enable_1(uint32_t pin_num){
    uint32_t *iof_en = (uint32_t *) GPIO_IOF_EN;
    *iof_en = *iof_en | (1 << pin_num);
}

void io_select_1(uint32_t pin_num){ // todo need a general version
    uint32_t * iof_sel = (uint32_t *) GPIO_IOF_SEL;
    *iof_sel = *iof_sel | (1 << pin_num);  
}