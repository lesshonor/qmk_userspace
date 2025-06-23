// Copyright 2023 The QMK Community (@qmk)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define COMBO_TERM 30
#define EXTRA_SHORT_COMBOS
#define COMBO_STRICT_TIMER

#define QUICK_TAP_TERM 100

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 150
#endif

#define TAP_CODE_DELAY 10
#define TAP_HOLD_CAPS_DELAY TAP_CODE_DELAY

#define TAPPING_TOGGLE 1

#define PERMISSIVE_HOLD

// I will never bother with these.
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#if defined(UNICODE_COMMON_ENABLE)
    #if !defined(__ASSEMBLER__)
    #include "unicode.h"
    enum input_modes_extended {
        UNICODE_MODE_URXVT = UNICODE_MODE_COUNT,
        UNICODE_MODE_VIM,
        UNICODE_MODE_NEW_COUNT
    };
    #endif

    #define UNICODE_SELECTED_MODES UNICODE_MODE_WINDOWS, UNICODE_MODE_LINUX, UNICODE_MODE_URXVT, UNICODE_MODE_VIM

    #define UNICODE_CYCLE_PERSIST false
#endif

#if defined(OLED_ENABLE)
    #define OLED_SECTION_BREAK ""
    #define OLED_UPDATE_INTERVAL 10
#endif

#if defined(RGB_MATRIX_ENABLE)
    #define RGB_DISABLE_WHEN_USB_SUSPENDED // turn off effects when suspended
    #define INDICATOR_MIN_SAT 120
#endif

#ifdef DYNAMIC_KEYMAP_LAYER_COUNT
    #undef DYNAMIC_KEYMAP_LAYER_COUNT
    #define DYNAMIC_KEYMAP_LAYER_COUNT 9
#endif

/* helpful debug output stuff I want to remember
#define DEBUG_EEPROM_OUTPUT
#define WEAR_LEVELING_DEBUG_OUTPUT
*/
