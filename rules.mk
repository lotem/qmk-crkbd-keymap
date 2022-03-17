MOUSEKEY_ENABLE     = yes    # Mouse keys
RGBLIGHT_ENABLE     = yes    # Enable WS2812 RGB underlight.
NKRO_ENABLE         = yes
VIA_ENABLE          = yes    # Enable VIA
LTO_ENABLE          = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

ifeq ($(strip $(STENO_ENABLE)), yes)
MOUSEKEY_ENABLE = no
# By default, VIA only supports 4 layers thus conficts with the Steno feature.
VIA_ENABLE = no
endif
