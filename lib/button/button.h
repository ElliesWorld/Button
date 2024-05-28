#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

#define BUTTON_UNINITIALIZED (0U)
#define BUTTON_FALLING_EDGE (1U)
#define BUTTON_RISING_EDGE (2U)
#define BUTTON_RELEASED (3U)
#define BUTTON_PRESSED (4U)

#define SAMPLES 5

void button_init(uint8_t pin);

void button_update_state(void);

uint8_t button_get_state(void);

#endif /* BUTTON_H */
