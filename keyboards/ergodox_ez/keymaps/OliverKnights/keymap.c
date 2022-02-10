#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_uk.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    _______,    _______,  _______,  _______,  _______,        _______,  _______,  _______,  _______,  _______,  _______,    _______,   _______,  _______,
    KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,           KC_T,     _______,  _______,  KC_Y,     KC_U,     KC_I,       KC_O,      KC_P,     KC_BSPACE,
    KC_ESCAPE,  KC_A,     KC_S,     KC_D,     KC_F,           KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCOLON,  KC_ENTER,
    KC_LSFT,    LT(1,KC_Z),    KC_X,     KC_C,           KC_V,     KC_B,     _______,  _______,  KC_N,     KC_M,       KC_COMMA,  KC_DOT,   LT(1,KC_SLASH),  KC_RSFT,
    _______,    _______,  _______,  OSL(2),   KC_LALT,  KC_HYPR, KC_LGUI,  _______,  _______,  _______,
    _______,    _______,  _______,  _______,
    _______,    _______,
    KC_SPC,     _______,  _______,  _______,  _______,        OSM(MOD_RCTL)
  ),
  [1] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, WEBUSB_PAIR,                                    _______, _______, _______, _______, _______, _______, _______,
    _______, KC_EXLM,        UK_AT,          KC_LCBR,        KC_RCBR,        UK_DQUO,        _______,                                 _______, UK_HASH,        UK_PND,           _______,           _______,           KC_ASTR,        _______,
    _______, UK_TILD,        KC_DLR,         KC_LPRN,        KC_RPRN,        KC_QUOTE,                                                                       UK_PIPE,        KC_PLUS,           KC_MINS,           KC_UNDS,           UK_EQL,         _______,
    _______, KC_PERC,        KC_CIRC,        KC_LBRACKET,    KC_RBRACKET,    KC_GRAVE,       _______,                                 _______, KC_AMPR,        _______,           _______,           _______,           UK_BSLS,        _______,
    _______, _______, _______, _______, _______,                                                                                                 _______, _______, KC_0,           _______, _______,
                                                                                                    _______, _______, _______, _______,
                                                                                                                    _______, _______,
                                                                                    _______, _______, _______, _______, _______, _______
  ),
  [2] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, KC_UP, KC_7, KC_8, KC_9, KC_LEFT, _______,
    _______, _______, _______, _______, _______, _______,                                                                 KC_DOWN,        KC_4,        KC_5,          KC_6,       KC_RIGHT, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, KC_1, KC_2, KC_3, _______, _______,
    _______, _______, _______, _______, _______,                                                                                                 _______, _______, KC_0, _______, _______,
                                                                                                    _______, _______, _______, _______,
                                                                                                                    _______, _______,
                                                                                    _______, _______, _______, _______, _______, _______
  ),
  [3] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, ST_MACRO_5,     ST_MACRO_6,     _______,
    _______, _______, ST_MACRO_0,     _______, _______, _______,                                                                 ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    _______, _______,
    _______, ST_MACRO_1,     ST_MACRO_2,     ST_MACRO_3,     ST_MACRO_4,     _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______,
                                                                                                    _______, _______, _______, _______,
                                                                                                                    _______, _______,
                                                                                    _______, _______, _______, _______, _______, _______
  ),
  [4] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                                 _______, _______, _______, _______, _______, _______, _______,
    _______, _______, ST_MACRO_11,    _______, _______, _______,                                                                 ST_MACRO_14,    ST_MACRO_15,    ST_MACRO_16,    ST_MACRO_17,    _______, _______,
    _______, _______, _______, ST_MACRO_12,    ST_MACRO_13,    _______, _______,                                 _______, ST_MACRO_18,    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                                                                                 _______, _______, _______, _______, _______,
                                                                                                    _______, _______, _______, _______,
                                                                                                                    _______, _______,
                                                                                    _______, _______, _______, _______, _______, _______
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_LSFT(SS_TAP(X_2)));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_Z));

    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_X));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_C));

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_RSFT(SS_TAP(X_5)));

    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_LBRACKET));

    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_RBRACKET));

    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_LEFT));

    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_DOWN));

    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_UP));

    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_B)) SS_DELAY(100) SS_TAP(X_RIGHT));

    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_S));

    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_C));

    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_V));

    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_H));

    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_J));

    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_K));

    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_L));

    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_W)) SS_DELAY(100) SS_TAP(X_N));

    }
    break;
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

