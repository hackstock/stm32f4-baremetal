#include <stdint.h>

void Reset_Handler(void);
extern int main(void);
void Default_Handler(void);
void NMI_Handler(void) __attribute__ ((weak, alias("Default_Handler")));

extern unsigned int _estack;
extern unsigned int _etext;
extern unsigned int _sdata;
extern unsigned int _edata;
extern unsigned int _sbss;
extern unsigned int _ebss;

uint32_t vector_table[] __attribute__ ((section(".isr_vector_tbl"))) = {
    (uint32_t)&_estack,
    (uint32_t)&Reset_Handler,
    (uint32_t)&Default_Handler,
};

void Reset_Handler(void){
    uint32_t data_mem_size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint32_t bss_mem_size = (uint32_t)&_ebss - (uint32_t)&_sbss;

    // copy data from FLASH to SRAM
    uint32_t *p_src = (uint32_t *)&_etext;
    uint32_t *p_dest = (uint32_t *)&_sdata;
    for(uint32_t i =0; i < data_mem_size; i++){
        *p_dest++ = *p_src++;
    }

    // initialize bss to zeros in SRAM
    p_dest = (uint32_t *)&_sbss;
    for(uint32_t i =0; i < bss_mem_size; i++){
        *p_dest++ = 0;
    }

    // invoke main function
    main();
}

void Default_Handler(void){
    while(1);
}

