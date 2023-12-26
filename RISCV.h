#ifndef RISCV
#define RISCV

#include "types.h"
#define MSTATUS_MIE 1 << 3
// Machine-mode Interrupt Enable
#define MIE_MEIE (1 << 11) // external
#define MIE_MTIE (1 << 7)  // timer
#define MIE_MSIE (1 << 3)  // software


void w_mstatus(uint32_t x);
uint32_t r_mstatus();
uint32_t r_mcause();
uint32_t r_mie();
void w_mtvec(uint32_t x);
void w_mie(uint32_t x);
void intr_on();
void intr_off();




#endif