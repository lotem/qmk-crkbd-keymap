MOUSEKEY_ENABLE     = yes    # Mouse keys
RGBLIGHT_ENABLE     = yes    # Enable WS2812 RGB underlight.
NKRO_ENABLE         = yes
LTO_ENABLE          = yes
VIA_ENABLE          = no     # Enable VIA
STENO_ENABLE        = no
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

USER_CAPS_WORD_ENABLE = yes
USER_KEYBOARD_STENO_ENABLE = yes

ifeq ($(strip $(STENO_ENABLE)), yes)
	SRC += features/steno.c
	MOUSEKEY_ENABLE = no
	VIA_ENABLE = no
endif

ifeq ($(strip $(USER_CAPS_WORD_ENABLE)), yes)
	SRC += features/caps_word.c
	OPT_DEFS += -DUSER_CAPS_WORD_ENABLE
endif

ifeq ($(strip $(USER_KEYBOARD_STENO_ENABLE)), yes)
	SRC += features/steno.c
	OPT_DEFS += -DUSER_KEYBOARD_STENO_ENABLE
	VIA_ENABLE = no
endif
