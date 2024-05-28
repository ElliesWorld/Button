#include "bsp.h"
#include "button.h"
#include "unity.h"

#ifndef DEVENV
#include <Arduino.h>
#endif

void setUp(void)
{
}

void tearDown(void)
{
}

void test_button_uninitialized(void)
{
    TEST_ASSERT_EQUAL_UINT8(BUTTON_UNINITIALIZED, button_get_state());
}

void test_button_initialized(void)
{
    button_init(34); 
    TEST_ASSERT_EQUAL_UINT8(BUTTON_RELEASED, button_get_state());
}

void test_button_released(void)
{
    bsp_set_pin_state(BSP_HIGH);
    button_update_state();
    TEST_ASSERT_EQUAL_UINT8(BUTTON_RELEASED, button_get_state());
}

void test_button_pressed(void)
{
    bsp_set_pin_state(BSP_LOW);
    for (int i = 0; i < 4; i++)
    {
        button_update_state();
        TEST_ASSERT_EQUAL_UINT8(BUTTON_RELEASED, button_get_state());
    }

    button_update_state();
    TEST_ASSERT_EQUAL_UINT8(BUTTON_FALLING_EDGE, button_get_state());

    TEST_ASSERT_EQUAL_UINT8(BUTTON_PRESSED, button_get_state());
}

#ifdef DEVENV
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_button_uninitialized);
    RUN_TEST(test_button_initialized);
    RUN_TEST(test_button_released);
    RUN_TEST(test_button_pressed);
    return UNITY_END();
}
#else
void loop() {}
void setup()
{
    UNITY_BEGIN();
    RUN_TEST(test_button_uninitialized);
    RUN_TEST(test_button_initialized);
    RUN_TEST(test_button_released);
    RUN_TEST(test_button_pressed);
    UNITY_END();
}
#endif
