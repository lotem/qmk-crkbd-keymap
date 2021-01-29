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

#define ALT_ESC LALT_T(KC_ESC)
#define SFT_QUO RSFT_T(KC_QUOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      ALT_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, SFT_QUO, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   LOWER, KC_LCTL,     KC_SPC,   RAISE, KC_RALT \
                                      //`--------------------------'  `--------------------------'
  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_CAPS, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_PIPE,                       KC_GRV, KC_AMPR, KC_ASTR, KC_QUOT,  KC_DQT,  KC_DEL, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_TAB,                      KC_BSPC, KC_MINS, KC_PLUS,  KC_EQL, KC_COLN,  KC_INS, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BSLS,                      KC_TILD, KC_UNDS, KC_LABK, KC_RABK, KC_QUES, _______, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_CAPS, KC_SLEP, KC_HOME,   KC_UP,  KC_END, KC_PGUP,                      KC_PLUS,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,  KC_APP, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                      KC_COLN,    KC_4,    KC_5,    KC_6,  KC_DOT,  KC_INS, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, KC_FIND,                      KC_MINS,    KC_1,    KC_2,    KC_3, KC_SLSH, _______, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       STN_ON,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      KC_VOLU, KC_WH_D, KC_MS_U, KC_WH_U, KC_MPRV,   RESET, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LALT,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_MUTE, KC_MS_L, KC_MS_D, KC_MS_R, KC_MPLY, KC_RCTL, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, KC_PSCR, KC_SLCK, KC_PAUS,                      KC_VOLD, KC_BTN1, KC_BTN3, KC_BTN2, KC_MNXT, KC_RSFT, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    KC_BTN1, _______, _______ \
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

int RGB_current_mode;

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

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
  RGB_current_mode = rgblight_config.mode;
#endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED
  iota_gfx_init(!has_usb());   // turns on the display
#endif

#ifdef STENO_ENABLE
  steno_set_mode(STENO_MODE_GEMINI);
#endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

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
