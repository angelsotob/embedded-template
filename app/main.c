#include "control.h"
#include "gpio.h"

/* Implementación real mínima de HAL
 * (stub: mañana se mejorará o moverá)
 */
void gpio_set(int pin, gpio_state_t state)
{
    (void)pin;
    (void)state;
    /* Aquí iría el acceso real a hardware */
}

int main(void)
{
    /* Simulación de valores de entrada */
    control_update(30);  /* LED OFF */
    control_update(80);  /* LED ON */

    return 0;
}
