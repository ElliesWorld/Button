#include "bsp.h"
#include "button.h"

static uint8_t button_pin = 0;
static uint8_t current_state = BUTTON_UNINITITIALIZED;


void button_init(uint8_t pin)
{
    button_pin = pin;
    bsp_pin_mode(button_pin, BSP_INPUT_PULLUP);
    current_state = BUTTON_RELEASED;
}

void button_update_state()
{
    if (current_state == BUTTON_UNINITITIALIZED)
    {
        return; 
    }

    static uint8_t counter = 0;
    uint8_t button_state = (BSP_HIGH == bsp_digital_read(button_pin)) ? BUTTON_RELEASED : BUTTON_PRESSED;

    if (button_state == current_state)
    {
        counter = 0;
    }
    else
    {
        counter++;

        if (counter == SAMPLES)
        {
            counter = 0;

            if (current_state == BUTTON_RELEASED)
            {
                current_state = BUTTON_FALLING_EDGE;
            }
            else 
            {
                current_state = BUTTON_RISING_EDGE;
            }
        }
    }
}

uint8_t button_get_state(void)
{

    uint8_t state = current_state;

    if (current_state == BUTTON_FALLING_EDGE)
    {
        current_state = BUTTON_PRESSED;
    }
    else if (current_state == BUTTON_RISING_EDGE)
    {
        current_state = BUTTON_RELEASED;
    }
    else
    {
        ;
    }

    return state;
}
