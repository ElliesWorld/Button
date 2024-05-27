#include "bsp.h"
#include "button.h"

void setup()
{
    button_init(GPIO_NUM_34);
    Serial.begin(9600);

    hw_timer_t *button_timer = NULL;

    constexpr uint16_t DIVIDER{80};

    constexpr uint32_t INTERVAL{2000};

    button_timer = timerBegin(0, DIVIDER, true);
    timerAttachInterrupt(button_timer, &button_update_state, true);
    timerAlarmWrite(button_timer, INTERVAL, true);
    timerAlarmEnable(button_timer);
}

void loop()
{
    if (BUTTON_FALLING_EDGE == button_get_state())
    {
        Serial.println("Falling edge");
    }
}