#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
// #define VENDOR_ID       0xFEED
// #define PRODUCT_ID      0x6060
// #define DEVICE_VER      0x0001
// #define MANUFACTURER    windstudio
// #define PRODUCT         windX

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 18
/* key matrix pins */
#define MATRIX_ROW_PINS { F0, F1, D2, D1, D0 }
#define MATRIX_COL_PINS { C7, C6, B6, E6, F6, D6, D7, B4, B5, F7, B7, F4, F5, D4, B0, B1, B2, B3 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
/*  */

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
//#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
//#define LOCKING_RESYNC_ENABLE

/* key combination for command */
/*
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)
*/

/* prevent stuck modifiers */
//#define PREVENT_STUCK_MODIFIERS

