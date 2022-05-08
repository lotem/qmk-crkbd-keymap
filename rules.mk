MOUSEKEY_ENABLE     = yes    # Mouse keys
RGBLIGHT_ENABLE     = yes    # Enable WS2812 RGB underlight.
NKRO_ENABLE         = yes
VIA_ENABLE          = yes    # Enable VIA
LTO_ENABLE          = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

ifeq ($(strip $(STENO_ENABLE)), yes)
	SRC += features/steno.c
	MOUSEKEY_ENABLE = no
	VIA_ENABLE = no
endif

ifeq ($(strip $(USER_KEYBOARD_STENO_ENABLE)), yes)
	SRC += features/steno.c
	OPT_DEFS += -DUSER_KEYBOARD_STENO_ENABLE
endif
