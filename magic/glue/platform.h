#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "timing.h"

uint8_t jtagtap_next(uint8_t dTMS, uint8_t dTDI);

bool swdptap_bit_in(void);

void swdptap_bit_out(bool val);

void platform_buffer_flush(void);

#define SET_IDLE_STATE(x)
#define SET_RUN_STATE(x)

