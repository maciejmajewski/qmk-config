#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _QMK,
  _LOWER,
  _RAISE,
  _MOUSE,
  _LAYER5,
  _LAYER6,
  _LAYER7,
  _LAYER8,
  _LAYER9,
  _LAYER10,
  _LAYER11,
  _LAYER12,
  _LAYER13,
  _LAYER14,
  _SOUND
};

#define KC_SLEEP LAG(KC_EJCT)
#define MO_QMK MO(1)
#define MO_LOWER MO(2)
#define MO_RAISE MO(3)
#define KC_M_OR_LT_MOUSE LT(4, KC_M)
#define KC_P_OR_LT_SOUND LT(15, KC_P)
#define KC_RSHIFT_OR_ENTER RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_1x2uC(
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,  KC_6,  KC_7,                  KC_8,      KC_9,    KC_0,             KC_BSPC,
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,  KC_Y,  KC_U,                  KC_I,      KC_O,    KC_P_OR_LT_SOUND, KC_BSLASH,
  KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,  KC_H,  KC_J,                  KC_K,      KC_L,    KC_SCLN,          KC_QUOT,
  KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,  KC_N,  KC_M_OR_LT_MOUSE,      KC_COMM,   KC_DOT,  KC_SLSH,          KC_RSHIFT_OR_ENTER,
  MO_QMK,   KC_LCTL,  KC_LALT,  KC_LGUI,  MO_LOWER,    KC_SPC,    MO_RAISE,              KC_LEFT,   KC_UP,   KC_DOWN,          KC_RIGHT
),

[_QMK] = LAYOUT_preonic_1x2uC(
  KC_SLEEP,  KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_DEL,
  _______,   KC_F11,      KC_F12,      LCTL(KC_E),  LCTL(KC_R),  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,   LCTL(KC_A),  _______,     LCTL(KC_D),  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,   LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C),  LAG(KC_C),   _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,   _______,     _______,     KC_ENT,               _______,        _______,  _______,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END
),

[_LOWER] = LAYOUT_preonic_1x2uC(
  _______, LSFT(KC_1),  LSFT(KC_2),  LSFT(KC_3),  LSFT(KC_4),  LSFT(KC_5),  LSFT(KC_6),  LSFT(KC_7),  LSFT(KC_8),  LSFT(KC_9),       LSFT(KC_0),      _______,
  _______, KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,       _______,     _______,     KC_LEFT_BRACKET,  KC_LEFT_BRACKET, _______,
  _______, KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,      _______,     _______,     KC_LCBR,          KC_RCBR,         _______,
  _______, _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,          _______,         _______,
  _______, _______,     _______,     _______,     _______,            KC_ENT,            _______,     _______,     _______,          _______,         _______
),

[_RAISE] = LAYOUT_preonic_1x2uC(
  _______,  _______,     _______,     _______,     _______,  _______,  _______,    _______,  _______,  KC_MINS,     KC_EQL,    _______,
  _______,  _______,     _______,     RALT(KC_E),  _______,  _______,  _______,    _______,  _______,  RALT(KC_O),  _______,  _______,
  _______,  RALT(KC_A),  RALT(KC_S),  _______,     _______,  _______,  _______,    _______,  _______,  RALT(KC_L),  _______,  KC_ENT,
  _______,  RALT(KC_Z),  RALT(KC_X),  RALT(KC_C),  _______,  _______,  RALT(KC_N), _______,  _______,  _______,     _______,  _______,
  _______,  _______,     _______,     _______,     _______,       _______,         _______,  _______,  _______,     _______,  _______
),

[_MOUSE] = LAYOUT_preonic_1x2uC(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
),

[_SOUND] = LAYOUT_preonic_1x2uC(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
)

};

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        // "NO_AUTO_SHIFT_SPECIAL" disables all below plus KC_TAB,
        // so here reverting NO_AUTO_SHIFT_SPECIAL, but without TAB that we don't want
        case KC_MINUS ... KC_SLASH:
        case KC_NONUS_BACKSLASH:
            return true;
        default:
            return false;
    }
}
