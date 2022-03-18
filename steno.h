
#ifdef STENO_ENABLE
#include "keymap_steno.h"
#define STN_ON TO(_STENO)
#define STN_OFF TO(_ALPHA)
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

#define LAYOUT_split_3x6_3_include(...) LAYOUT_split_3x6_3(__VA_ARGS__)

#define STENO_LAYER \
    /*,-----------------------------------------------------.                    ,-----------------------------------------------------.*/ \
        XXXXXXX,  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,                      STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR, STN_DR,    \
    /*|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|*/ \
        XXXXXXX,  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2,                      STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR, STN_ZR,    \
    /*|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|*/ \
        STN_OFF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   \
    /*|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|*/ \
    /**/                                      STN_A,   STN_O,  STN_NB,     STN_NC,   STN_E,   STN_U \
    /*                                    `--------------------------'  `--------------------------'*/

void matrix_init_user_steno(void) {
#ifdef STENO_ENABLE
    steno_set_mode(STENO_MODE_GEMINI);
#endif
}

bool process_record_user_keyboard_steno(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
