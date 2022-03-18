/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "keymap_uk.h"


enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  QMKBEST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QMKBEST:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("QMK is the best thing ever!");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    _______, KC_Q   , KC_W   , KC_E   , KC_R , KC_T   , KC_Y   , KC_U , KC_I   , KC_O   , KC_P   , _______,
    KC_ESC , KC_A   , KC_S   , KC_D   , KC_F , KC_G   , KC_H   , KC_J , KC_K   , KC_L   , KC_SCLN, KC_ENT ,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B   , KC_N   , KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    _______, _______, _______, KC_LALT, RAISE, KC_SPC , KC_RCTL, LOWER, KC_LGUI, _______, _______, _______
),

[_LOWER] = LAYOUT_planck_grid(
    _______, KC_EXLM, UK_AT  , KC_LCBR, KC_RCBR, UK_DQUO, _______, UK_PND , _______, _______, KC_ASTR, _______,
    _______, KC_TILD, KC_DLR , KC_LPRN, KC_RPRN, KC_QUOT, KC_PIPE, UK_PLUS, UK_MINS, KC_UNDS, KC_EQL , _______,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_GRV , KC_AMPR, KC_TILD, _______, _______, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    _______, KC_0   , KC_7   , KC_8   , KC_9   , _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_4   , KC_5   , KC_6   , _______, _______, _______, KC_ESC , KC_TAB , KC_BSPC, _______,
    _______, _______, KC_1   , KC_2   , KC_3   , _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, _______, _______, _______, _______, _______,
    _______, _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
    _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
