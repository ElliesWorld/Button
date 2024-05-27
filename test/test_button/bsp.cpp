#include "bsp.h"

#define INVALID 0xFF

static uint8_t pin_state = BSP_HIGH;
static uint8_t pin_num = INVALID;
static uint8_t pin_mode = INVALID;

void bsp_pin_mode(uint8_t pin, uint8_t mode)
{
    pin_num = pin;
    pin_mode = mode;
}

int bsp_digital_read(uint8_t pin)
{
    pin_num = pin;
    return pin_state;
}

uint8_t bsp_get_pin_num(void)
{
    return pin_num;
}

uint8_t bsp_get_pin_mode(void)
{
    return pin_mode;
}

void bsp_set_pin_state(uint8_t state)
{
    pin_state = state;
}
