#include "control.h"
#include "gpio.h"

#define LED_PIN 1

static int clamp(int input)
{
    if (input < 0)
        return 0;
    if (input > 100)
        return 100;
    return input;
}

void control_update(int value)
{
    int v = clamp(value);

    if (v >= 50)
    {
        gpio_set(LED_PIN, GPIO_HIGH);
    }
    else
    {
        gpio_set(LED_PIN, GPIO_LOW);
    }
}
