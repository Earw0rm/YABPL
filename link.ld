OUTPUT_ARCH("riscv")

ENTRY(_entry)

MEMORY
{
    ram(wxa!ri) : ORIGIN = 0x80000000, LENGTH = 0x4000
}

SECTIONS
{
    

   .text :
    {   
        *(._trap_vec)
        *(.text)
    }
    > ram 
    . = ALIGN(4);
    
    _global_pointer = .;
    . = ALIGN(4);

    .data :
    {
        *(.data)
    }
    > ram 
    . = ALIGN(4);

    .bss : 
    {
        *(.bss)
    } > ram 
    . = ALIGN(4);

    _stack_top = .;
    . += 4096;
    _stack_bot = .;
}