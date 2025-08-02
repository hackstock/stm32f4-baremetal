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
        *(.isr_vector_tbl)
    }> FLASH

    .text : 
    {
        *(.text)
        *(.rodata)
    }> FLASH

    .data : 
    {
        *(.data)
    }> SRAM AT> FLASH

    .bss : 
    {
        *(.bss)
    }>SRAM
}

_estack = ORIGIN(SRAM) + LENGTH(SRAM);