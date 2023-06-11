COMMAND_ENABLE   = no
BACKLIGHT_ENABLE = no
RGBLIGHT_ENABLE  = yes
VIA_ENABLE       = yes
# TRI_LAYER_ENABLE = yes     # OLKB "Tri Layer" style - It is enabled by default with VIA
CAPS_WORD_ENABLE = yes     # Enable Caps Word
LTO_ENABLE       = yes

SWAP_MINUS_AND_EQUAL := no
ifeq ($(strip $(SWAP_MINUS_AND_EQUAL)), yes)
    OPT_DEFS += -DSWAP_MINUS_AND_EQUAL
endif

ATREUS44_ARROW_STYLE := no
ifeq ($(strip $(ATREUS44_ARROW_STYLE)), yes)
    OPT_DEFS += -DATREUS44_ARROW_STYLE
endif
