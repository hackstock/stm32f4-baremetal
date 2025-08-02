ENTRY(Reset_Handler)

MEMORY
{
    FLASH (rx) : ORIGIN = 0x08000000 , LENGTH = 1024K
    SRAM (rw) : ORIGIN = 0x20000000, LENGTH = 128K
}

SECTIONS
{
    .isr_vector : 
    {
        . = ALIGN(4);
        *(.isr_vector_tbl)
        . = ALIGN(4);
    }> FLASH

    .text : 
    {
        . = ALIGN(4);
        *(.text)
        *(.rodata)
        . = ALIGN(4);
    }> FLASH

    .data : 
    {
        . = ALIGN(4);
        *(.data)
        . = ALIGN(4);
    }> SRAM AT> FLASH

    .bss : 
    {
        . = ALIGN(4);
        *(.bss)
        . = ALIGN(4);
    }>SRAM
}

_estack = ORIGIN(SRAM) + LENGTH(SRAM);