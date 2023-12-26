#include "types.h"
#include "UART.h"

void uart_init(void){
    uint32_t * uart_div_0 = (uint32_t *) UART_DIV_0;
    *uart_div_0 = 139;
    
    uint32_t * txctrl = (uint32_t *) UART_TXCTRL_0;
    *txctrl = (1 << 16); 
    
}

void uart_enable_tx_interrupt(void){
    uint32_t * tx_watermark_ie = (uint32_t *) UART_IE_0;
    *tx_watermark_ie |= 1;
}

void uart_disable_tx_interrupt(void){
    uint32_t * tx_watermark_ie = (uint32_t *) UART_IE_0;
    *tx_watermark_ie &= ~1;
}

void uart_enable_tx(void){
    uint32_t * txctrl = (uint32_t *) UART_TXCTRL_0;    
    *txctrl |= 1;
}

void uart_disable_tx(void){
    uint32_t * txctrl = (uint32_t *) UART_TXCTRL_0;    
    *txctrl &= ~1;
}

bool write_newline_uart_0(void){
    uint32_t * uart_txdata_0 = (uint32_t *) UART_TXDATA_0; // it is the same as txdata reg
    
    bool is_full = (*uart_txdata_0) & (1 << 31); // TODO тут нужно атомарное чтение - заепись (amoor.w)
    if(is_full){
        return false;
    }else{
        char newline = '\n';
        uint32_t mask = 0b11111111;
        uint32_t tmp_data = (*uart_txdata_0 & (~ mask)) | newline;
        *uart_txdata_0 =  tmp_data;
    }
    return true;
}

bool send_data_throo_uart_0(char data){
    uint32_t * uart_txdata_0 = (uint32_t *) UART_TXDATA_0; // it is the same as txdata reg
    bool is_full = (*uart_txdata_0) & (1 << 31); // TODO тут нужно атомарное чтение - заепись (amoor.w)
    if(is_full){
        return false;
    }else{
        uint32_t mask = 0b11111111;
        uint32_t tmp_data = (*uart_txdata_0 & (~ mask)) | data;
        *uart_txdata_0 =  tmp_data;
    }
    uart_enable_tx();
    uart_enable_tx_interrupt();
    return true;
}

bool send_data_throo_uart_0_repeat(char data, uint32_t rep){
    uint32_t * uart_txdata_0 = (uint32_t *) UART_TXDATA_0; // it is the same as txdata reg
    bool is_full = (*uart_txdata_0) & (1 << 31); // TODO тут нужно атомарное чтение - заепись (amoor.w)
    while(rep > 0){
        if(is_full){
            return false;
        }else{
            uint32_t mask = 0b11111111;
            uint32_t tmp_data = (*uart_txdata_0 & (~ mask)) | data;
            *uart_txdata_0 =  tmp_data;
        }
        --rep;
    }
    uart_enable_tx();
    uart_enable_tx_interrupt();
    return true;
}