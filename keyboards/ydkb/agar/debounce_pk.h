#ifndef DEBOUNCE_PK_H
#define DEBOUNCE_PK_H

#include <stdbool.h>
#include "print.h"

#ifndef DEBOUNCE_DN
#define DEBOUNCE_DN 5
#endif

#ifndef DEBOUNCE_NK
#define DEBOUNCE_NK 1
#endif

#ifndef DEBOUNCE_UP
#define DEBOUNCE_UP 5
#endif

#ifndef DOUBLE_CLICK_FIX_DELAY //default 10
#define DOUBLE_CLICK_FIX_DELAY 10
#endif

#if (DEBOUNCE_DN < 8) && (DEBOUNCE_NK < 8) && (DEBOUNCE_UP < 8)
#define DEBOUNCE_DN_MASK (uint8_t)(~(0x80 >> DEBOUNCE_DN))
#define DEBOUNCE_NK_MASK (uint8_t)(~(0x80 >> DEBOUNCE_NK))
#define DEBOUNCE_UP_MASK (uint8_t)(0x80 >> DEBOUNCE_UP)
#else
#error "DEBOUNCE VALUE must not exceed 7"
#endif

#endif
