#pragma once

#include "quantum.h"

#ifdef STENO_ENABLE

#include "keymap_steno.h"
#define STN_ON TO(_STENO)
#define STN_OFF TO(_ALPHA)

#else

#ifdef USER_KEYBOARD_STENO_ENABLE
#define STN_ON PLON
#define STN_OFF PLOFF
#else
#define STN_ON KC_TRNS
#define STN_OFF KC_TRNS
#endif

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

#define STENO_ROW_1 \
    STN_OFF,  STN_S1,  STN_TL,  STN_PL,  STN_HL, STN_ST1,                      STN_ST3,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR

#define STENO_ROW_2 \
    XXXXXXX,  STN_S2,  STN_KL,  STN_WL,  STN_RL, STN_ST2,                      STN_ST4,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR

#define STENO_ROW_3 \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#define STENO_ROW_4 \
    /**/                                  STN_A,   STN_O,  STN_NB,     STN_NC,   STN_E,   STN_U

#define STENO_LAYER  \
        STENO_ROW_1, \
        STENO_ROW_2, \
        STENO_ROW_3, \
        STENO_ROW_4

void matrix_init_steno(void);

bool process_record_keyboard_steno(uint16_t keycode,
                                   keyrecord_t *record,
                                   uint8_t steno_layer,
                                   uint16_t keycode_steno_on,
                                   uint16_t keycode_steno_off);
