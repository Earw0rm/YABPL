
.section .text 
.global _entry

_entry:
    la sp, _stack_bot
    la gp, _global_pointer
    jal x0, main
