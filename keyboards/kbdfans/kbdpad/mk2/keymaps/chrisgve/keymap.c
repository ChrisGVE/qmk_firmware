/* Copyright 2019 Ryota Goto
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum ortho_6x4_layers {
    _NUMPAD,
    _FN,
    _OPER,
};

#define FN      TG(_FN)
#define OPER    MO(_OPER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_NUMPAD] = LAYOUT_ortho_6x4(  /* Base */
    KC_ESC,  KC_INS,  KC_DEL,  KC_BSPC, \
	FN,      KC_PSLS, KC_PAST, KC_PMNS, \
	KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
	KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
	KC_P1,   KC_P2,   KC_P3,   KC_PENT, \
	KC_P0,   KC_P0,   KC_PDOT, KC_PENT  \
  ),

  [_FN] = LAYOUT_ortho_6x4(  /* Function */
    OPER,     _______,  _______,  _______, \
	_______,  _______,  _______,  _______, \
	KC_HOME,  KC_UP,    KC_PGUP,  _______, \
	KC_LEFT,  _______,  KC_RGHT,  _______, \
	KC_END,   KC_DOWN,  KC_PGDN,  _______, \
	_______,  _______,  _______,  _______\
  ),

  [_OPER] = LAYOUT_ortho_6x4(  /* Function */
    _______,  QK_BOOT,  DB_TOGG,  _______, \
	_______,  _______,  _______,  _______, \
	_______,  _______,  _______,  _______, \
	_______,  _______,  _______,  _______, \
	_______,  _______,  _______,  _______, \
	_______,  _______,  _______,  _______\
  ),

};
