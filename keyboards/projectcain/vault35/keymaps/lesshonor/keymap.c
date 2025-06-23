// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "lesshonor.h"
#include "wrappers.h"

#define LAYOUT_full_space_wrap(...) LAYOUT_full_space(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_base] = LAYOUT_full_space_wrap(
    BASE_L0__________,  BASE_R0__________, KC_BSPC,
    BASE_L1__________,  BASE_R1__________,
    BASE_L2__________,  BASE_R2__________,
              BASE_BOTTOM_3KEYS
),

[L_noHRM] = LAYOUT_full_space_wrap(
    TRNS_5X__________,  TRNS_5X__________,  KC_TRNS,
    NHRM_L1__________,  NHRM_R1__________,
    TRNS_5X__________,  TRNS_5X__________,
        KC_TRNS, KC_TRNS, KC_TRNS
),

[L_symb] = LAYOUT_full_space_wrap(
    SYMB_L0__________,  SYMB_R0__________,  KC_DEL,
    SYMB_L1__________,  SYMB_R1__________,
    SYMB_L2__________,  SYMB_R2__________,
        KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_numL] = LAYOUT_full_space_wrap(
    NUMPL_L0_________,  TRNS_5X__________,  KC_TRNS,
    NUMPL_L1_________,  TRNS_5X__________,
    NUMPL_L2_________,  TRNS_5X__________,
        KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_numR] = LAYOUT_full_space_wrap(
    NUMPR_L0_________,  NUMPR_R0_________,  KC_TRNS,
    TRNS_5X__________,  NUMPR_R1_________,
    NUMPR_L2_________,  NUMPR_R2_________,
        KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_fkeyL] = LAYOUT_full_space_wrap(
    FKEYS_0,  KC_TRNS,  TRNS_5X__________,  KC_TRNS,
    FKEYS_1,  KC_TRNS,  TRNS_5X__________,
    FKEYS_2,  KC_TRNS,  FKEYS_R2_________,
        KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_nav] = LAYOUT_full_space_wrap(
    TRNS_5X__________,  NAV__R0__________,  TG(L_noHRM),
    TRNS_5X__________,  NAV__R1__________,
    NAV__L2__________,  NAV__R2__________,
        KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_light] = LAYOUT_full_space_wrap(
    RGB__L0__________,  ETC__R0__________,  RGB_TOG,
    ETC__L1__________,  TRNS_5X__________,
    RGB__LX__________,  TRNS_5X__________,
        KC_TRNS,  KC_TRNS,  KC_TRNS
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(C_WNDWB, C_WNDWF) },
    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    { ENCODER_CCW_CW(UC_PREV, UC_NEXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif
