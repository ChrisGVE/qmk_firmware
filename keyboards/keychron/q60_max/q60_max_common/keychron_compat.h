/* Compatibility shims for Keychron wireless code running on upstream QMK.
 *
 * The Keychron fork adds custom RGB/LED matrix power management functions
 * that don't exist in upstream QMK. These stubs allow the wireless
 * indicator code to compile.
 *
 * Note: rgb_matrix_driver_allow_shutdown / led_matrix_driver_allow_shutdown
 * are defined in indicator.c, not here.
 */

#pragma once

#include "quantum.h"

#ifndef RGB_MATRIX_TIMEOUT_INFINITE
#    define RGB_MATRIX_TIMEOUT_INFINITE 0
#endif

/* debounce_free doesn't exist in upstream QMK */
static inline void debounce_free(void) {
}

#ifdef RGB_MATRIX_ENABLE

static inline void rgb_matrix_disable_timeout_set(uint32_t timeout) {
    (void)timeout;
}

static inline void rgb_matrix_disable_time_reset(void) {
}

static inline bool rgb_matrix_timeouted(void) {
    return false;
}

/* Defined in indicator.c */
bool rgb_matrix_driver_allow_shutdown(void);

static inline void rgb_matrix_driver_shutdown(void) {
}

static inline void rgb_matrix_driver_exit_shutdown(void) {
}

static inline bool rgb_matrix_is_driver_shutdown(void) {
    return false;
}

#endif

#ifdef LED_MATRIX_ENABLE

static inline void led_matrix_disable_timeout_set(uint32_t timeout) {
    (void)timeout;
}

static inline void led_matrix_disable_time_reset(void) {
}

static inline bool led_matrix_timeouted(void) {
    return false;
}

static inline void led_matrix_driver_shutdown(void) {
}

static inline void led_matrix_driver_exit_shutdown(void) {
}

#endif
