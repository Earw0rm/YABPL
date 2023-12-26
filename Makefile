main:
	riscv64-unknown-elf-as -march=rv32imac -mno-arch-attr -g entry.S    -o riscv_asm.o
	riscv64-unknown-elf-as -march=rv32imac -mno-arch-attr -g trap_vec.S -o trap_vec.o
	riscv64-unknown-elf-gcc -march=rv32imac -mabi=ilp32   -g -c main.c  -o main.o
	riscv64-unknown-elf-gcc -march=rv32imac -mabi=ilp32   -g -c trap.c  -o trap.o
	riscv64-unknown-elf-gcc -march=rv32imac -mabi=ilp32   -g -c GPIO.c  -o GPIO.o
	riscv64-unknown-elf-gcc -march=rv32imac -mabi=ilp32   -g -c PLIC.c  -o PLIC.o
	riscv64-unknown-elf-gcc -march=rv32imac -mabi=ilp32   -g -c UART.c  -o UART.o
	riscv64-unknown-elf-gcc -march=rv32imac -mabi=ilp32   -g -c RISCV.c -o RISCV.o

	riscv64-unknown-elf-ld  -melf32lriscv -T link.ld RISCV.o UART.o PLIC.o GPIO.o main.o riscv_asm.o trap_vec.o trap.o -o out.elf
	riscv64-unknown-elf-objdump -D out.elf > dbug.txt
	gdb-multiarch out.elf