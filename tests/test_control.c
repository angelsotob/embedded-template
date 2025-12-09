#include "unity.h"
#include "cmock.h"
/* ESTE include será mockeado */
#include "mocks/Mockgpio.h"

#include "control.h"

/* Requerido por CMock: DEFINICIONES reales, no solo extern */
int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/* Unity las llama alrededor de cada test si usas el runner clásico;
   aquí nosotros controlamos qué hace cada test, así que las dejamos vacías
   o con setup/teardown si quieres más adelante. */
void setUp(void) {}
void tearDown(void) {}

/* input >= 50 → LED ON */
void test_control_turns_led_on(void)
{
    gpio_set_Expect(1, GPIO_HIGH);
    control_update(80);
}

/* input < 50 → LED OFF */
void test_control_turns_led_off(void)
{
    gpio_set_Expect(1, GPIO_LOW);
    control_update(20);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_control_turns_led_on);
    RUN_TEST(test_control_turns_led_off);
    return UNITY_END();
}
