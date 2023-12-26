#include "types.h"
#include "PLIC.h"

void plic_init(void){
    // equals priority 
    for(uint32_t * i = (uint32_t *) PLIC_SRC_PRIORITY_1;
                   i <= (uint32_t *) PLIC_SRC_PRIORITY_52; 
                   ++i) *i = 1;
    

    uint32_t gpio_src_mask = (1 << PLIC_SOURCE_GPIO16 | 1 << PLIC_SOURCE_GPIO17 |
                              1 << PLIC_SOURCE_GPIO18 | 1 << PLIC_SOURCE_GPIO19 | 
                              1 << PLIC_SOURCE_GPIO20 | 1 << PLIC_SOURCE_GPIO22 | 1 << PLIC_SOURCE_GPIO23);
    
    uint32_t uart_0_src_mask = 1 << PLIC_SOURCE_UART_0;

    uint32_t * intr_src_fst_vec = (uint32_t *) PLIC_START_INTERRUPT_ENABLES;
    *intr_src_fst_vec = gpio_src_mask | uart_0_src_mask;

    uint32_t * intr_src_snd_vec = (uint32_t *) PLIC_END_INTERRUPT_ENABLES;
    *intr_src_snd_vec = 0;
    
    uint32_t * priority_thr = (uint32_t *) PLIC_PRIORITY_THRESHOLD;
    *priority_thr = 0;
}

uint32_t plic_claim(void){
    uint32_t * claim = (uint32_t *) PLIC_CLAIM_COMPLETE;
    return *claim;
}

void plic_complete(uint32_t intr_id){
    uint32_t * complete = (uint32_t *) PLIC_CLAIM_COMPLETE;
    *complete = intr_id;
}
