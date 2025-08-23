#ifndef GPIO_H
#define GPIO_H

#include "cfg_gpio.h"

void gpio_init(const GpioPinConfigType * config, uint8_t count);
void gpio_write(uint8_t port, uint8_t pin, GpioLevelType level);
void gpio_toggle(uint8_t port, uint8_t pin);
GpioLevelType gpio_read(uint8_t port, uint8_t pin);

#endif
