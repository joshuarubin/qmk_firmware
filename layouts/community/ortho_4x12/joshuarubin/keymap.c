/* Copyright 2019 Joshua Rubin
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

enum layers {
    _QWERTY,
    _LOWER,  // NUMERIC
    _RAISE,  // SYMBOL
    _DIRECTION,
    _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE(X) LT(_RAISE, X)
#define DIR(X) LT(_DIRECTION, X)

#ifdef ENCODER_ENABLE
#    define BOT_LEFT KC_MUTE
#else
#    define BOT_LEFT KC_LALT
#endif

#ifndef BLUETOOTH_ENABLE
#    define BT_UNPAIR KC_NO
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
  // 0            1        2        3        4      5       6       7               8        9        10            11
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,           KC_I,    KC_O,    KC_P,         KC_MINS,
  LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,           KC_K,    KC_L,    DIR(KC_SCLN), KC_QUOT,
  KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,           KC_COMM, KC_DOT,  KC_SLSH,      KC_SFTENT,
  BOT_LEFT,       XXXXXXX, KC_LALT, KC_LGUI, LOWER, KC_ENT, KC_SPC, RAISE(KC_BSPC), KC_LBRC, KC_RBRC, KC_MINS,      KC_EQL
),

[_LOWER] = LAYOUT_ortho_4x12(
  // 0     1        2        3        4        5        6        7              8        9        10       11
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,         KC_F8,   KC_F9,   KC_F10,  KC_BSLS,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,          KC_8,    KC_9,    KC_0,    _______,
  _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, RAISE(KC_DEL), _______, KC_MUTE, KC_VOLD, KC_VOLU
),

[_RAISE] = LAYOUT_ortho_4x12(
  // 0     1        2        3        4        5        6        7        8        9        10       11
  KC_TILD, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_PIPE,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DQUO,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LT,   KC_GT,   KC_QUES, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS
),

[_DIRECTION] = LAYOUT_ortho_4x12(
  // 0     1        2        3        4        5        6        7        8         9        10       11
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
  _______, XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT, _______, _______,
  _______, _______, _______, _______, _______, _______, KC_NDSH, KC_MDSH, _______,  _______, SHRUG,   _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),

[_ADJUST] =  LAYOUT_ortho_4x12(
  // 0      1        2        3        4        5        6        7        8         9        10       11
  BT_UNPAIR, RESET,   DEBUG,   _______, _______, _______, _______, UC_MOD,  KC_INS,   _______, KC_PSCR, _______,
  RGB_MOD,   RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______,  _______, _______, _______,
  RGB_RMOD,  RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, AU_TOG,  MU_TOG,  MU_MOD,   _______, _______, _______,
  RGB_TOG,   _______, _______, AG_TOGG, _______, _______, _______, _______, KC_SLCK,  KC_PAUS, MUV_DE,  MUV_IN
)

};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }
