/*
Copyright 2023 YANG <drk@live.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "hal.h"
#include "ch.h"
#include "quantum.h"
#include "timer.h"
#include "wait.h"

extern bool is_ver5020;
extern bool is_sc_leds_mcu;

/* Forward declaration from matrix.c */
void enter_bootloader(void);

/* Single color indicator control (caps lock LED on PB14) */
void single_color_indicator_set(uint8_t index, bool on) {
    if (index == 0) {
        if (on)
            palSetPad(GPIOB, 14);
        else
            palClearPad(GPIOB, 14);
    }
}

/* UF2 bootloader entry */
void enter_bootloader(void) {
    clear_keyboard();
    volatile uint32_t *uf2bl_backup_reg = (uint32_t *)0x20004000;
    *uf2bl_backup_reg                   = 0x9d5bfc2bUL;
    NVIC_SystemReset();
}

/* Command handler: LShift+RShift then B = bootloader, LCtrl+B = UF2 bootloader */
bool command_extra(uint8_t code) {
    uint8_t pressed_mods = get_mods();
    clear_keyboard();
    switch (code) {
        case KC_B:
            wait_us(500 * 1000);
            if (pressed_mods & MOD_BIT(KC_LCTL)) {
                enter_bootloader();
            }
            NVIC_SystemReset();
            break;
        default:
            return false;
    }
    return true;
}

/* Override restart_usb_driver to do a full system reset */
void restart_usb_driver(USBDriver *usbp) {
    NVIC_SystemReset();
}

/* Caps lock LED indicator - replaces old led_set_user() */
bool led_update_kb(led_t led_state) {
    if (!led_update_user(led_state)) {
        return false;
    }
    single_color_indicator_set(0, led_state.caps_lock);
    return true;
}

/* Housekeeping replaces old hook_keyboard_loop() */
void housekeeping_task_kb(void) {
    /* Keep caps lock indicator in sync */
    single_color_indicator_set(0, host_keyboard_led_state().caps_lock);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    /* Handle bootloader keycode if needed */
    if (keycode == QK_BOOTLOADER && record->event.pressed) {
        enter_bootloader();
        return false;
    }
    return true;
}
