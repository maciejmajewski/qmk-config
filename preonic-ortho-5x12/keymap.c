#include QMK_KEYBOARD_H
#include "muse.h"

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _SOUND
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  SOUND
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_preonic_1x2uL(
  KC_GRV,         KC_1,     KC_2,     KC_3,     KC_4,     KC_5,  KC_6,     KC_7,       KC_8,      KC_9,    KC_0,         KC_BSPC,
                                                                                                        /* LT(SOUND, KC_P) */
  KC_TAB,         KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,  KC_Y,     KC_U,       KC_I,      KC_O,    LT(3, KC_P),  KC_BSLS,
  KC_ESC,         KC_A,     KC_S,     KC_D,     KC_F,     KC_G,  KC_H,     KC_J,       KC_K,      KC_L,    KC_SCLN,      KC_QUOT,
  KC_LSFT,        KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,  KC_N,     KC_M,       KC_COMM,   KC_DOT,  KC_SLSH,      RSFT_T(KC_ENT),
  /* MO(LOWER) */                                                          /* LM(RAISE, MOD_LALT) */
  MO(1),          KC_LCTL,  KC_LALT,  KC_LGUI,      KC_SPC,    KC_ENT,     LM(2, MOD_LALT),  KC_LEFT,   KC_UP,   KC_DOWN,      KC_RIGHT
),

[_LOWER] = LAYOUT_preonic_1x2uL(
  LAG(KC_EJCT),  _______,     _______,     _______,     _______,     _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  KC_DEL,
  _______,       _______,     _______,     LCTL(KC_E),  LCTL(KC_R),  _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,       LCTL(KC_A),  _______,     LCTL(KC_D),  _______,     _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,       LCTL(KC_Z),  LCTL(KC_X),  LCTL(KC_C),  LAG(KC_C),   _______,  _______,  _______,  _______,  _______,  _______,  _______,
  _______,       _______,     _______,     _______,            KC_ENT,         _______,  _______,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END
),

[_RAISE] = LAYOUT_preonic_1x2uL(
  _______,  _______,  _______,  _______,  _______,  _______,  _______,        _______,  _______,       _______,       KC_MINS, KC_EQL,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,        _______,  _______,       _______,  _______,   _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,        _______,  _______,       _______,  _______,   _______,
  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,       _______,       _______,   _______,
  _______,  KC_LCTL,  KC_LALT,  KC_LGUI,        KC_SPC,       _______,   _______,  _______,       _______,       _______,   _______
),

[_SOUND] = LAYOUT_preonic_1x2uL(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MUTE,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Ignore ALT modifier when switching to RAISE layer via ALT key
        case KC_MINS:
        case KC_EQL:
            del_mods(MOD_MASK_ALT);
            break;
    }
    return true;
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
