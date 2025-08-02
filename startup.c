#include <stdint.h>

void Reset_Handler(void);
extern int main(void);
void Default_Handler(void);
void NMI_Handler(void) __attribute__ ((weak, alias("Default_Handler")));

extern unsigned int _estack;

uint32_t vector_table[] __attribute__ ((section(".isr_vector_tbl"))) = {
    (uint32_t)&_estack,
    (uint32_t)&Reset_Handler,
    (uint32_t)&Default_Handler,
};

void Reset_Handler(void){
    main();
}

void Default_Handler(void){
    while(1);
}

