#include <stdint.h>

void turnOnLED3(void);

int main(void){
    turnOnLED3();
    while(1);

    return 0;
}

void turnOnLED3(void){
    uint32_t *pRCC_AHB1ENR = (uint32_t*)0x40023830;
    uint32_t *pGPIOD_MODER = (uint32_t*)0x40020c00;
    uint32_t *pGPIOD_ODR = (uint32_t*)0x40020c14;

    // enables clock access to GPIOD
    *pRCC_AHB1ENR |= (1UL << 3);
    // set PD13 as output
    *pGPIOD_MODER &= !(0b11 << 26);
    *pGPIOD_MODER |= (0b01 << 26);
    // turn on LED
    *pGPIOD_ODR |= (1 << 13);
}
