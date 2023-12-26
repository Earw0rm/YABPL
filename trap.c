#include "RISCV.h"
#include "types.h"
#include "PLIC.h"
#include "GPIO.h"
#include "UART.h"

void machine_trap(void){
    intr_off();

    int cause = r_mcause();
    if(cause <= -1){
        // blue led
        uint32_t counter = 0;
        blue_led_on();
        uint32_t interrupt_id = plic_claim();
        while(counter < 10000){
            ++counter;
        }

        if(interrupt_id == 3){ // uart tx
            uart_disable_tx();
            uart_disable_tx_interrupt();
        }

        plic_complete(interrupt_id);
        blue_led_off();
    }else{ // green led 
        green_led_on();
        uint32_t counter = 0;
        while(counter < 10000){
            ++counter;
        }
        green_led_on();
    }


    intr_on();
}