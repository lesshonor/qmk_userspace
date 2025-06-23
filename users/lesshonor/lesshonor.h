// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "process_combo.h"
#include "led.h"
#include "action_layer.h"
#include "os_detection.h" // os_variant_t
#include "progmem.h"

enum custom_keycodes {
    C_WNDWF = QK_USER,
    C_WNDWB,
    C_LIGHF,
    C_LIGHB,
    C_INDTG,
    C_PAREN,
    C_CBRKT,
    C_SBRAC,
    C_ABRKT,
    C_ENE,
    C_NDASH };

enum unicode_names {
    WIN_EMDASH,
    ENE_CAPS,
    ENE,
    //  ENDASH,
    EMDASH
};

#define LESS_LAYER_ENUM_MACRO(A, B, C, D, E, F, G, H) enum { \
L_ ## A, \
L_ ## B, \
L_ ## C, \
L_ ## D, \
L_ ## E, \
L_ ## F, \
L_ ## G, \
L_ ## H, \
}
/*
enum input_modes_extended {
    UNICODE_MODE_URXVT = UNICODE_MODE_COUNT,
    UNICODE_MODE_VIM
};
*/

// #define UNICODE_SELECTED_MODES UNICODE_MODE_WINDOWS, UNICODE_MODE_LINUX
// #define UNICODE_SELECTED_MODES UNICODE_MODE_WINDOWS, UNICODE_MODE_LINUX, UNICODE_MODE_URXVT, UNICODE_MODE_VIM

LESS_LAYER_ENUM_MACRO(base, noHRM, symb, numL, numR, fkeyL, nav, light);
//LESS_LAYER_ENUM_MACRO(base, noHRM, symb, numL, numR, fkeyL, fkeyR, nav, etc);

extern const uint32_t unicode_map[] PROGMEM;

// TODO: figure out how to not have to specify a length maybe
extern combo_t key_combos[20];

extern bool         window_nav_in_progress;
extern bool         window_nav_cancel;
extern uint16_t     window_timer;
extern os_variant_t current_os;

__attribute__((weak)) bool led_update_keymap(led_t led_state);
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

// TODO: NO, BAD
#if defined(RGB_MATRIX_ENABLE)
__attribute__((weak)) bool rgb_indicators_keymap(void);
#endif

__attribute__((weak)) layer_state_t default_layer_state_set_keymap(layer_state_t state);


uint32_t config_os(uint32_t trigger_time, void *cb_arg);
void force_numlock(void);

// oled
void render_current_input_mode_user(bool singleline);
void render_keylock_status_user(led_t led_state);
void render_layer_status_user(bool singleline);
void render_lighting_mode_user(uint8_t user_lighting_mode);
void render_short_mod_status_user(uint8_t modifiers);
