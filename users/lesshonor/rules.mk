SRC += lesshonor.c

BOOTMAGIC_ENABLE = yes
OS_DETECTION_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

UNICODEMAP_ENABLE = yes
SRC += unicode_override.c

COMBO_ENABLE = yes
SRC += combo_list.c

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled_override.c
    SRC += lib/lib8tion/lib8tion.c
endif

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
    SRC += rgb_matrix_override.c
    BACKLIGHT_ENABLE = no # making a guess here
    RGBLIGHT_ENABLE = no
endif

ifeq ($(strip $(CONSOLE_ENABLE)), yes)
    ifneq ($(filter $(MCU),STM32F401 STM32F411),)
        # Not enough USB endpoints
        KEYBOARD_SHARED_EP = yes
        #OPT_DEFS += -DPRINTF_SUPPORT_DECIMAL_SPECIFIERS=1
    endif
endif

# features I just never use
GRAVE_ESC_ENABLE = no
SPACE_CADET_ENABLE = no
MAGIC_ENABLE = no
