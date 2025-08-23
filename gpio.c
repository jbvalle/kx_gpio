#include "gpio.h"
#include "stm32f401re_regs.h"

#define MODER_WIDTH 2

void gpio_init(const GpioPinConfigType * config, uint8_t count){

    for(uint8_t i = 0; i < count; i++){

        RCC->AHB1ENR |= (1 << config[i].port);
        GpioPorts[config[i].port]->MODER &= ~(3 << (config[i].pin * MODER_WIDTH));
        GpioPorts[config[i].port]->MODER |=  (config[i].mode << (config[i].pin * MODER_WIDTH));
    }
}

void gpio_write(uint8_t port, uint8_t pin, GpioLevelType level){

    GpioPorts[port]->ODR &= ~(1 << pin);
    GpioPorts[port]->ODR |= ~(level << pin);
}

void gpio_toggle(uint8_t port, uint8_t pin){

    GpioPorts[port]->ODR ^= (1 << pin);
}

GpioLevelType gpio_read(uint8_t port, uint8_t pin){

    return GpioPorts[port]->IDR;
}
