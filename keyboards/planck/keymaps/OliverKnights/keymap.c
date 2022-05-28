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
  Z_GUI,
  SWITCH_COLN,
  MY_GUI_TOG,
  MY_GUI_TOG_BACK,
  MY_RAISE,
  MY_CTRL_ALT,
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

int lower_should_be_on = 0;
int gui_should_be_active = 0;
int is_shifted = 0;
int is_ctrl = 0;
int is_gui = 0;
int is_alt = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (keycode == KC_LSFT || keycode == KC_RSFT) {
    if (record->event.pressed) {
      is_shifted = 1;
    } else {
      is_shifted = 0;
    }
  }

  if (keycode == KC_RCTL || keycode == KC_LCTL) {
    if (record->event.pressed) {
      is_ctrl = 1;
    } else {
      is_ctrl = 0;
    }
  }

  if (keycode == KC_RGUI || keycode == KC_LGUI) {
    if (record->event.pressed) {
      is_gui = 1;
    } else {
      is_gui = 0;
    }
  }

  if (keycode == KC_LALT || keycode == KC_RALT) {
    if (record->event.pressed) {
      is_alt = 1;
    } else {
      is_alt = 0;
    }
  }

  if (IS_LAYER_ON(_LOWER) && IS_LAYER_ON(_RAISE)) {
    xprintf("KL: col=%02d, row=%02d, pressed=%d layer=ADJUS shift=%d g=%d a=%d c=%d\n", record->event.key.col, record->event.key.row, record->event.pressed, is_shifted, is_gui, is_alt, is_ctrl);
  } else if (IS_LAYER_ON(_LOWER)) {
    xprintf("KL: col=%02d, row=%02d, pressed=%d layer=LOWER shift=%d g=%d a=%d c=%d\n", record->event.key.col, record->event.key.row, record->event.pressed, is_shifted, is_gui, is_alt, is_ctrl);
  } else if (IS_LAYER_ON(_RAISE)) {
    xprintf("KL: col=%02d, row=%02d, pressed=%d layer=RAISE shift=%d g=%d a=%d c=%d\n", record->event.key.col, record->event.key.row, record->event.pressed, is_shifted, is_gui, is_alt, is_ctrl);
  } else {
    xprintf("KL: col=%02d, row=%02d, pressed=%d layer=QWERT shift=%d g=%d a=%d c=%d\n", record->event.key.col, record->event.key.row, record->event.pressed, is_shifted, is_gui, is_alt, is_ctrl);
  }

    switch (keycode) {
    case QMKBEST:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("QMK is the best thing ever!");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case Z_GUI:
        if (record->event.pressed) {
          if (IS_LAYER_ON(_LOWER)) {
            lower_should_be_on = 1;
            layer_off(_LOWER);
            register_code(KC_LGUI);
          } else {
            register_code(KC_Z);
          }
        } else {
          if (lower_should_be_on == 1) {
            layer_on(_LOWER);
            unregister_code(KC_LGUI);
            lower_should_be_on = 0;
          } else {
            unregister_code(KC_Z);
          }
        }
        break;
    case SWITCH_COLN:
        if (record->event.pressed) {
          if (is_shifted == 1) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
            register_code(KC_SCLN);
          } else {
            register_code(KC_RSFT);
            register_code(KC_SCLN);
            unregister_code(KC_RSFT);
          }
        } else {
            unregister_code(KC_SCLN);
        }
        break;
    case MY_GUI_TOG:
        if (record->event.pressed) {
          if (IS_LAYER_ON(_ADJUST)) {
            if (gui_should_be_active == 1) {
            } else {
              register_code(KC_LGUI);
              gui_should_be_active = 1;
            }

            register_code(KC_TAB);
          } else {
          }
        } else {
          unregister_code(KC_TAB);
        }
        break;
    case MY_GUI_TOG_BACK:
        if (record->event.pressed) {
          if (IS_LAYER_ON(_ADJUST)) {
            if (gui_should_be_active == 1) {
            } else {
              register_code(KC_LGUI);
              gui_should_be_active = 1;
            }

            register_code(KC_RSFT);
            register_code(KC_TAB);
          } else {
          }
        } else {
          unregister_code(KC_TAB);
          unregister_code(KC_RSFT);
        }
        break;
    case MY_RAISE:
        if (record->event.pressed) {
          layer_on(_RAISE);
        } else {
          if (gui_should_be_active == 1) {
            unregister_code(KC_LGUI);
            gui_should_be_active = 0;
          } 

          layer_off(_RAISE);
        }
        break;
    case MY_CTRL_ALT:
        if (record->event.pressed) {
            register_code(KC_RCTL);
            register_code(KC_LALT);
        } else {
            unregister_code(KC_RCTL);
            unregister_code(KC_LALT);
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB , KC_Q   , KC_W       , KC_E   , KC_R      , KC_T                , KC_Y   , KC_U     , KC_I   , KC_O       , KC_P       , KC_BSPC,
    KC_ESC , KC_A   , KC_S       , KC_D   , KC_F      , KC_G                , KC_H   , KC_J     , KC_K   , KC_L       , SWITCH_COLN, KC_ENT ,
    KC_LSFT, KC_Z   , KC_X       , KC_C   , KC_V      , KC_B                , KC_N   , KC_M     , KC_COMM, KC_DOT     , KC_SLSH    , KC_RSFT,
    _______, _______, MY_CTRL_ALT, _______, MO(_LOWER), MT(MOD_LALT, KC_SPC), KC_RCTL, MO(_RAISE), KC_RGUI, MY_CTRL_ALT, _______    , _______
),

[_LOWER] = LAYOUT_planck_grid(
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_RAISE] = LAYOUT_planck_grid(
    _______, KC_EXLM, UK_AT  , UK_PND , KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    _______, KC_TILD, UK_DQUO, KC_LCBR, KC_RCBR, KC_QUOT, KC_PIPE, UK_PLUS, UK_MINS, KC_UNDS, KC_EQL , _______,
    _______, KC_GRV , _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______, _______, KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, MY_GUI_TOG_BACK, MY_GUI_TOG, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______        , _______   , _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______        , _______   , _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______        , _______   , _______, _______
)

};
