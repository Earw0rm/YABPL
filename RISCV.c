#include "types.h"
#include "RISCV.h"

void w_mstatus(uint32_t x){
    asm volatile("csrw mstatus, %0" : : "r" (x));
}

uint32_t r_mstatus(){
  uint32_t x;
  asm volatile("csrr %0, mstatus" : "=r" (x) );
  return x;
}


uint32_t r_mcause(){
  uint32_t x;
  asm volatile("csrr %0, mcause" : "=r" (x) );
  return x;
}



uint32_t r_mie(){
  uint32_t x;
  asm volatile("csrr %0, mie" : "=r" (x) );
  return x;
}

void w_mie(uint32_t x){
  asm volatile("csrw mie, %0" : : "r" (x));
}


void w_mtvec(uint32_t x){
  asm volatile("csrw mtvec, %0" : : "r" (x));
}

void intr_on(){
  w_mstatus(r_mstatus() | MSTATUS_MIE);
}

// disable device interrupts
void intr_off(){
  w_mstatus(r_mstatus() & ~MSTATUS_MIE);
}