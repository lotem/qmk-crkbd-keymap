#include QMK_KEYBOARD_H

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _STENO 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  PLON,
  PLOFF,
};

#ifdef STENO_ENABLE
#include "keymap_steno.h"
#define STN_ON TO(_STENO)
#define STN_OFF TO(_QWERTY)
#else
#define STN_ON PLON
#define STN_OFF PLOFF
#define STN_N1 KC_1
#define STN_N2 KC_2
#define STN_N3 KC_3
#define STN_N4 KC_4
#define STN_N5 KC_5
#define STN_N6 KC_6
#define STN_N7 KC_7
#define STN_N8 KC_8
#define STN_N9 KC_9
#define STN_NA KC_0
#define STN_NB KC_MINS
#define STN_NC KC_EQL
#define STN_S1 KC_Q
#define STN_S2 KC_A
#define STN_TL KC_W
#define STN_KL KC_S
#define STN_PL KC_E
#define STN_WL KC_D
#define STN_HL KC_R
#define STN_RL KC_F
#define STN_ST1 KC_T
#define STN_ST2 KC_G
#define STN_ST3 KC_Y
#define STN_ST4 KC_H
#define STN_FR KC_U
#define STN_RR KC_J
#define STN_PR KC_I
#define STN_BR KC_K
#define STN_LR KC_O
#define STN_GR KC_L
#define STN_TR KC_P
#define STN_SR KC_SCLN
#define STN_DR KC_LBRC
#define STN_ZR KC_QUOT
#define STN_A KC_C
#define STN_O KC_V
#define STN_E KC_N
#define STN_U KC_M
#endif

#define OS_CMD OSM(MOD_LGUI)
#define ALT_ESC LALT_T(KC_ESC)
#define ALT_QUO RALT_T(KC_QUOT)
#define SFT_CAP RSFT_T(KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       OS_CMD,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, ALT_QUO, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SFT_CAP, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            LOWER, KC_LCTL, ALT_ESC,     KC_ENT,  KC_SPC,   RAISE \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_INS,  KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_PIPE,                       KC_GRV, KC_AMPR, KC_ASTR, KC_TILD, KC_SLSH,  KC_DEL, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCMD, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_TAB,                      KC_QUOT, KC_MINS, KC_PLUS,  KC_EQL, KC_COLN, KC_RALT, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BSLS,                       KC_DQT, KC_UNDS, KC_LABK, KC_RABK, KC_QUES, KC_RSFT, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_INS,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCMD,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_DOT, KC_RALT, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_FIND,                      KC_HOME,  KC_END, KC_PGUP, KC_PGDN, KC_SLSH, KC_RSFT, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       STN_ON,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_VOLU, KC_WH_D, KC_MS_U, KC_WH_U, KC_MPRV,   RESET, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCMD,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_MUTE, KC_MS_L, KC_MS_D, KC_MS_R, KC_MPLY, KC_RALT, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, KC_PSCR, KC_SLCK, KC_PAUS,                      KC_VOLD, KC_BTN1, KC_BTN3, KC_BTN2, KC_MNXT, KC_RSFT, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_STENO] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,                      STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2,                      STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      STN_OFF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           STN_NB,   STN_A,   STN_O,      STN_E,   STN_U,  STN_NC \
                                      //`--------------------------'  `--------------------------'
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
#endif // OLED_ENABLE

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_QWERTY);
            }
            return false;
        case LOWER:
            if (record->event.pressed) {

                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case PLON:
            if (record->event.pressed) {
                layer_on(_STENO);
                // send PHRO*PB - plover on
                SEND_STRING(
                    SS_DOWN(X_E) SS_DOWN(X_R) SS_DOWN(X_F) SS_DOWN(X_V)
                    SS_DOWN(X_Y) SS_DOWN(X_I) SS_DOWN(X_K)
                    SS_UP(X_E) SS_UP(X_R) SS_UP(X_F) SS_UP(X_V)
                    SS_UP(X_Y) SS_UP(X_I) SS_UP(X_K));
            }
            return false;
        case PLOFF:
            if (record->event.pressed) {
                layer_off(_STENO);
                // send PHRO*F - plover off
                SEND_STRING(
                    SS_DOWN(X_E) SS_DOWN(X_R) SS_DOWN(X_F) SS_DOWN(X_V)
                    SS_DOWN(X_Y) SS_DOWN(X_U)
                    SS_UP(X_E) SS_UP(X_R) SS_UP(X_F) SS_UP(X_V)
                    SS_UP(X_Y) SS_UP(X_U));
            }
            return false;
    }
    return true;
}
