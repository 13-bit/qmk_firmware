#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _MACOS,
    _LIN_WIN,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_MACOS = SAFE_RANGE,
    KC_LINWIN
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define VSC_TERM LCTL(KC_GRAVE)
#define REG_TERM LGUI(KC_ENT)
#define MAC_TERM LGUI(KC_ENT)
#define LNCH LGUI(KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK MacOS
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  | RGUI |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Enter  /       \Space \  |RAISE | Lnch | VS Code | Mac  |
 *            |      |      |      |      |/       /         \      \ |      |      | Term    | Term |
 *            `----------------------------------'           '------''-------------------------------'
 */
[_MACOS] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,  KC_7, KC_8,     KC_9,   KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                        KC_J,  KC_L, KC_U,     KC_Y,   KC_SCLN, KC_DEL,
  KC_ESC,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                        KC_H,  KC_N, KC_E,     KC_I,   KC_O,    KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  XXXXXXX,     XXXXXXX, KC_K,  KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RGUI,
                    KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_ENT,      KC_SPC,  RAISE, LNCH, VSC_TERM, MAC_TERM
),

/*
 * COLEMAK Linux/Windows
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  | RCTR |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LGUI |LOWER | /Enter  /       \Space \  |RAISE | Lnch | VS Code | Rego |
 *            |      |      |      |      |/       /         \      \ |      |      | Term    | Term |
 *            `----------------------------------'           '------''-------------------------------'
 */
[_LIN_WIN] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,  KC_7, KC_8,     KC_9,   KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                        KC_J,  KC_L, KC_U,     KC_Y,   KC_SCLN, KC_DEL,
  KC_ESC,   KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                        KC_H,  KC_N, KC_E,     KC_I,   KC_O,    KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  XXXXXXX,     XXXXXXX, KC_K,  KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
                    KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_ENT,      KC_SPC,  RAISE, LNCH, VSC_TERM, REG_TERM
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| Left | Down | Up   |Right |   |  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |     | /       /       \       \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''----------------------------'
 */
[_LOWER] = LAYOUT(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE, _______,
                    _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
),

/* RAISE
 * ,------------------------------------------.                    ,-----------------------------------------.
 * | VolUp |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | VolDn |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |-------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Mute  |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |-------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |       | Undo |  Cut | Copy | Paste|      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''----------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______,  _______,                         _______, _______, _______, _______, _______ ,_______,
  KC_VOLU, _______, _______, _______, _______,  _______,                         _______, _______, _______, _______, _______, _______,
  KC_VOLD, _______, _______, _______, _______,  _______,                         _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  KC_MUTE, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, _______, _______,       _______, KC_HOME, _______, _______, KC_END,  KC_BSLS, _______,
                    _______, _______, _______,  _______, _______,       _______, _______, _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |MACOS |LINUX |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''----------------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,                       RGB_TOG, RGB_RMOD, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_MACOS,  KC_LINWIN,  XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, RGB_HUD,  RGB_HUI, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, RGB_SAD,  RGB_SAI, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,   XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, RGB_VAD,  RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,
                      _______,    _______, _______, _______, _______,     _______, _______, _______,  _______, _______
  )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);

    switch (get_highest_layer(default_layer_state)) {
        case _MACOS:
            oled_write_ln_P(PSTR("MacOS"), false);
            break;
        case _LIN_WIN:
            oled_write_ln_P(PSTR("Linux"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _MACOS:
        case _LIN_WIN:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n\n"), false);
    oled_write_ln_P(PSTR("13bit"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MACOS:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MACOS);
            }
            return false;
        case KC_LINWIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_LIN_WIN);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_UP);
        } else {
            tap_code(KC_DOWN);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RIGHT);
        }
    }
    return false;
}

#endif
