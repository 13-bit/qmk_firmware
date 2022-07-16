#include QMK_KEYBOARD_H

enum layers {
    _MAIN,
    _RAISE,
    _LOWER,
};

// Readability keycodes
#define LOWER LT(_LOWER, KC_DOT)
#define RAISE LT(_RAISE, KC_ENT)

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

enum custom_keycodes { BA = SAFE_RANGE, BS, BC };

#define LFT LCTL(LALT(KC_D))
#define LFTT LCTL(LALT(KC_E))

#define CT LCTL(LALT(KC_F))
#define MAX LCTL(LALT(KC_ENTER))

#define RT LCTL(LALT(KC_G))
#define RTT LCTL(LALT(KC_T))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT(KC_MUTE, BA, LFTT, LFT, KC_VOLD, BS, MAX, CT, KC_VOLU, BC, RTT, RT)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BA:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("ba" SS_TAP(X_ENT));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case BS:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("bs" SS_TAP(X_ENT));
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case BC:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("bc" SS_TAP(X_ENT));
            } else {
                // when keycode QMKBEST is released
            }
            break;
    }
    return true;
};
