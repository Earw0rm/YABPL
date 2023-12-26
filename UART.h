#ifndef UART
#define UART

#include "types.h"

#define UART_INSTANCE_0 0x10013000
#define UART_INSTANCE_1 0x10023000


#define UART_TXDATA_0 (UART_INSTANCE_0)
#define UART_RXDATA_0 (UART_INSTANCE_0 + 0x04)
#define UART_TXCTRL_0 (UART_INSTANCE_0 + 0x08)
#define UART_RXCTRL_0 (UART_INSTANCE_0 + 0x0C)
#define UART_IE_0     (UART_INSTANCE_0 + 0x10)
#define UART_IP_0     (UART_INSTANCE_0 + 0x14)
#define UART_DIV_0    (UART_INSTANCE_0 + 0x18) // 1736 by default

#define UART_TXDATA_1 (UART_INSTANCE_1)
#define UART_RXDATA_1 (UART_INSTANCE_1 + 0x04)
#define UART_TXCTRL_1 (UART_INSTANCE_1 + 0x08)
#define UART_RXCTRL_1 (UART_INSTANCE_1 + 0x0C)
#define UART_IE_1     (UART_INSTANCE_1 + 0x10)
#define UART_IP_1     (UART_INSTANCE_1 + 0x14)  
#define UART_DIV_1    (UART_INSTANCE_1 + 0x18)


void uart_init(void);

bool send_data_throo_uart_0(char data);
void uart_enable_tx(void);
bool write_newline_uart_0(void);
void uart_disable_rx_tx(void);

void uart_enable_tx_interrupt(void);
void uart_disable_tx_interrupt(void);
#endif