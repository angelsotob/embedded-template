#include "unity.h"
#include "control.h"

void setUp(void) {}
void tearDown(void) {}

void test_control_clamp_limits_lower_bound(void)
{
    int result = control_clamp(-10);
    TEST_ASSERT_EQUAL(0, result);
}

void test_control_clamp_limits_upper_bound(void)
{
    int result = control_clamp(120);
    TEST_ASSERT_EQUAL(100, result);
}

void test_control_clamp_inside_range(void)
{
    int result = control_clamp(50);
    TEST_ASSERT_EQUAL(50, result);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_control_clamp_limits_lower_bound);
    RUN_TEST(test_control_clamp_limits_upper_bound);
    RUN_TEST(test_control_clamp_inside_range);
    return UNITY_END();
}
