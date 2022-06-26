#include "keymap_uk.h"
#include QMK_KEYBOARD_H

#define FN1_BSPC    LT(1, KC_BSPC)
#define FN2_SPC     LT(2, KC_SPC)
#define FN3_C       LT(3, KC_C)
#define FN4_V       LT(4, KC_V)
#define FN5_B       LT(5, KC_B)
#define CTL_Z       CTL_T(KC_Z)
#define ALT_X       ALT_T(KC_X)
#define ALT_N       ALGR_T(KC_N)
#define CTL_M       RCTL_T(KC_M)
#define SFT_ENT     RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,     KC_J,    KC_K,    KC_L,    KC_ESC,
    CTL_Z,   ALT_X,   FN3_C,   FN4_V,   FN2_SPC, FN1_BSPC, FN5_B,   ALT_N,   CTL_M,   SFT_ENT
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, _______, _______, _______, _______, _______, KC_SCLN, KC_COLN, _______,
    _______, _______, _______, _______, KC_DEL,  _______, _______, KC_BSLS, KC_SLSH, _______
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_TILD, KC_DQUO, KC_LCBR, KC_RCBR, KC_QUOT, KC_PIPE, KC_PLUS, UK_MINS, KC_UNDS, KC_EQL,
    KC_GRV , _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [3] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    KC_TAB,  _______, KC_LBRC, KC_RBRC, _______, _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______
  ),

  [4] = LAYOUT_ortho_3x10(
    _______, _______, _______, _______, _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    KC_TAB,  RESET  , _______, _______, _______, KC_LABK, KC_RABK, KC_QUES, KC_COLN, KC_DQUO,
    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
  ),
};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}
