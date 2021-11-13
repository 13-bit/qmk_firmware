#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _RAISE,
    _LOWER,
};

// Readability keycodes
#define LOWER   LT(_LOWER, KC_DOT)
#define RAISE   LT(_RAISE, KC_ENT)

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//   [_MAIN] = LAYOUT(
//   KC_0,     KC_1,    KC_4,    KC_7,
//   LOWER,    KC_2,    KC_5,    KC_8,
//   RAISE,    KC_3,    KC_6,    KC_9
//   ),
//   [_RAISE] = LAYOUT(
//     _______, KC_EXLM, KC_DLR,  KC_AMPR,
//     _______, KC_AT,   KC_PERC, KC_ASTR,
//     _______, KC_HASH, KC_CIRC, RESET
//   ),
//   [_LOWER] = LAYOUT(
//     _______, _______, _______, _______,
//     _______, _______, _______, _______,
//     _______, _______, _______, _______
//   )

// };

enum custom_keycodes {
    DB = SAFE_RANGE,
    DRL,
    DP,
    DCL,
    GBG,
    GBH
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case DB:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("db"SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case DRL:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("drl"SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case DP:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("dp"SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case DCL:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("dcl"SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case GBG:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("gbg"SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case GBH:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("gbh"SS_TAP(X_ENT));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_MAIN] = LAYOUT(
  KC_MUTE,    DB,     DCL,    _______,
  KC_VOLD,    DRL,    GBG,    _______,
  KC_VOLU,    DP,     GBH,    _______
  )

};
