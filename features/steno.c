#include "quantum.h"

#ifdef STENO_ENABLE
#include "keymap_steno.h"
#endif

void matrix_init_steno(void) {
#ifdef STENO_ENABLE
    steno_set_mode(STENO_MODE_GEMINI);
#endif
}

bool process_record_keyboard_steno(uint16_t keycode,
                                   keyrecord_t *record,
                                   uint8_t steno_layer,
                                   uint16_t keycode_steno_on,
                                   uint16_t keycode_steno_off) {
#ifdef USER_KEYBOARD_STENO_ENABLE
    if (keycode == keycode_steno_on) {
        if (record->event.pressed) {
            layer_on(steno_layer);
            // send PHRO*PB - plover on
            SEND_STRING(
                SS_DOWN(X_E) SS_DOWN(X_R) SS_DOWN(X_F) SS_DOWN(X_V)
                SS_DOWN(X_Y) SS_DOWN(X_I) SS_DOWN(X_K)
                SS_UP(X_E) SS_UP(X_R) SS_UP(X_F) SS_UP(X_V)
                SS_UP(X_Y) SS_UP(X_I) SS_UP(X_K));
        }
        return false;
    } else if (keycode == keycode_steno_off) {
        if (record->event.pressed) {
            layer_off(steno_layer);
            // send PHRO*F - plover off
            SEND_STRING(
                SS_DOWN(X_E) SS_DOWN(X_R) SS_DOWN(X_F) SS_DOWN(X_V)
                SS_DOWN(X_Y) SS_DOWN(X_U)
                SS_UP(X_E) SS_UP(X_R) SS_UP(X_F) SS_UP(X_V)
                SS_UP(X_Y) SS_UP(X_U));
        }
        return false;
    }
#endif
    return true;
}
