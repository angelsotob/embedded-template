#ifndef GPIO_H
#define GPIO_H

typedef enum
{
    GPIO_LOW = 0,
    GPIO_HIGH = 1
} gpio_state_t;

void gpio_set(int pin, gpio_state_t state);

#endif
