/* Copyright 2020 Joshua Rubin
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
#include "joshuarubin.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN,
    _DIRECTION,
};

#define FN MO(_FN)
#define DIR(X) LT(_DIRECTION, X)

#ifndef BLUETOOTH_ENABLE
#    define BT_UNPAIR KC_NO
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_60_tsangan_hhkb(
	KC_ESC,        KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,         KC_MINS,  KC_EQL,   KC_BSLS,  KC_GRV,
	KC_TAB,        KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,         KC_LBRC,  KC_RBRC,  KC_BSPC,
	CTL_T(KC_ESC), KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     DIR(KC_SCLN), KC_QUOT,            KC_ENT,
	KC_LSFT,                 KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,       KC_SLSH,  KC_RSFT,  FN,
	KC_LCTL,       KC_LALT,  KC_LGUI,                                KC_SPC,                                               KC_RGUI,  KC_RALT,  KC_RCTL
),

[_FN] = LAYOUT_60_tsangan_hhkb(
	BT_UNPAIR,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,  KC_DEL,
	KC_CAPS,    RESET,    _______,  _______,  _______,  _______,  _______,  UC_MOD,   KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_UP,    _______,  _______,
	RGB_RMOD,   KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_EJCT,  _______,  KC_ASTR,  KC_SLSH,  KC_HOME,  KC_PGUP,  KC_LEFT,  KC_RGHT,            _______,
	RGB_MOD,              RGB_HUD,  RGB_HUI,  RGB_SAD,  RGB_SAI,  _______,  KC_PLUS,  KC_MINS,  KC_END,   KC_PGDN,  KC_DOWN,  BL_STEP,  _______,
	RGB_TOG,    RGB_VAD,  RGB_VAI,                                _______,                                          AG_TOGG,  AG_TOGG,  BL_TOGG
),

[_DIRECTION] = LAYOUT_60_tsangan_hhkb(
	_______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
	_______,  _______,  _______,  KC_ELIP,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
	_______,  XXXXXXX,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END,   KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,            _______,
	_______,            _______,  _______,  _______,  _______,  _______,  KC_NDSH,  KC_MDSH,  _______,  _______,  SHRUG,    _______,  _______,
	_______,  _______,  _______,                                _______,                                          _______,  _______,  _______
),

};
// clang-format on
