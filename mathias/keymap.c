#include QMK_KEYBOARD_H

#define BASE 0
#define FN   1
#define COLEMAK 2

// Mod keys
#define L_COLE DF(COLEMAK)
#define L_QWERT DF(BASE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*  BASE LAYER
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │ Esc  │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │ Bspc │
   * └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *  │ LCtrl│   A  │   S  │   D  │   F  │   G  │   H  │   J  │   K  │   L  │   ;  │   '  │
   *  └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *   │  Tab │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │ Enter│
   *   └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *    │ Clmk │  B   │ LGUI │ LAlt │LShift│    Space    │  Fn  │ Left │ Down │  Up  │ Right│
   *    └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
   */
  [BASE] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_TAB, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    L_COLE,  KC_B,    KC_LGUI, KC_LALT, KC_LSFT, KC_SPC,  KC_SPC,  MO(FN),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  /*  FN LAYER
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │      │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │      │
   * └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *  │LED H+│  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │   -  │   =  │   [  │   ]  │   \  │
   *  └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *   │LED H-│  F7  │  F8  │   F9 │  F10 │  F11 │  F12 │      │ PgUp │ Home │      │      │
   *   └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *    │LED V+│LED V-│ Reset│ PScr │      │             │      │ PgDn │ End  │      │ Del  │
   *    └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
   */
  [FN]   = LAYOUT(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    RGB_HUI, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    RGB_HUD, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_PGUP, KC_HOME, _______, _______,
    RGB_VAI, RGB_VAD, QK_BOOT,   KC_PSCR, _______, _______, _______, _______, KC_PGDN, KC_END,  _______, KC_DEL
  ),

  /*  COLEMAK-DH LAYER
   * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
   * │ Esc  │   Q  │   W  │   F  │   P  │   B  │   J  │   L  │   U  │   Y  │   ;  │ Bspc │
   * └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *  │ LCtrl│   A  │   R  │   S  │   T  │   G  │   M  │   N  │   E  │   I  │   O  │   '  │
   *  └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *   │ Tab  │   Z  │   X  │   C  │   D  │   V  │   K  │   H  │   ,  │   .  │   /  │ Enter│
   *   └┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴──────┴┬─────┴┬─────┴┬─────┴┬─────┴┬─────┴┐
   *    │ Qwert│      │ LGUI │ LAlt │LShift│    Space    │  Fn  │ Left │ Down │  Up  │ Right│
   *    └──────┴──────┴──────┴──────┴──────┴─────────────┴──────┴──────┴──────┴──────┴──────┘
   */
  [COLEMAK] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
    KC_TAB, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    L_QWERT, KC_B,    KC_LGUI, KC_LALT, KC_LSFT, KC_SPC,  KC_SPC,  MO(FN),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),
};
