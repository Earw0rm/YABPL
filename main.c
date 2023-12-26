#include "types.h"
#include "GPIO.h"
#include "RISCV.h"
#include "PLIC.h"
#include "UART.h"

extern void _trap_vec(void);


void main(void) {
    plic_init();
    gpio_init();
    uart_init();

    w_mtvec((uint32_t) &_trap_vec);
    w_mie(MIE_MEIE);
    intr_on();



    char simbol_to_send = '5';
    while(1){
        bool sending_res = send_data_throo_uart_0_repeat(simbol_to_send, 7);
                    
    }

}