#include <stdint.h>

void Reset_Handler(void);
extern int main(void);

extern unsigned int _estack;

uint32_t vector_table[] __attribute__ ((section(".isr_vector_tbl"))) = {
    (uint32_t)&_estack,
    (uint32_t)&Reset_Handler,
};

void Reset_Handler(void){
    main();
}

