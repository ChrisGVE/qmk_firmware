#pragma once

/* Matrix size - 14 rows x 8 cols for shift register scanning */
#define MATRIX_ROWS 14
#define MATRIX_COLS 8


/* Debounce */
#define DEBOUNCE_DN 5
#define DEBOUNCE_NK 1
#define DEBOUNCE_UP 5

/* Custom bootloader */
#define SOFTWARE_ESC_BOOTLOADER

/* RGB default mode: RAINBOW_MOOD */
#define RGBLIGHT_DEFAULT_MODE (RGBLIGHT_MODE_RAINBOW_MOOD)

/* RGB Indicator */
#define PHY_INDICATOR_NUM 1
#define INDICATOR_FUNCT {(1 << USB_LED_CAPS_LOCK)}
#define RGB_EXTRA_PROCESS_ENABLE

/* Key combination for command */
#define IS_COMMAND() ( \
    (get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) || \
    (get_mods() == (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_RSFT))) \
)
