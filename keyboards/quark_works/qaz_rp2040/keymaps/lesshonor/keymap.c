// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "lesshonor.h"
#include "wrappers.h"

#define LAYOUT_hhkb_wrap(...) LAYOUT_hhkb(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_base] = LAYOUT_hhkb_wrap(
    BASE_L0__________,  BASE_R0__________,
    BASE_L1__________,  BASE_R1__________,
    BASE_L2__________,  BASE_R2S_________,
    KC_TRNS,  BASE_L3__________,  BASE_R3__________,  KC_TRNS
),

[L_noHRM] = LAYOUT_hhkb_wrap(
    TRNS_5X__________,  TRNS_5X__________,
    NHRM_L1__________,  NHRM_R1__________,
    TRNS_5X__________,  TRNS_4X__________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_symb] = LAYOUT_hhkb_wrap(
    SYMB_L0__________,  SYMB_R0__________,
    SYMB_L1__________,  SYMB_R1__________,
    SYMB_L2__________,  SYMB_R2S_________,
    KC_TRNS,  KC_TRNS,  KC_DEL,   KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_numL] = LAYOUT_hhkb_wrap(
    NUMPL_L0_________,  TRNS_5X__________,
    NUMPL_L1_________,  TRNS_5X__________,
    NUMPL_L2_________,  TRNS_4X__________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_numR] = LAYOUT_hhkb_wrap(
    NUMPR_L0_________,  NUMPR_R0_________,
    TRNS_5X__________,  NUMPR_R1_________,
    NUMPR_L2_________,  NUMPR_R2S________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_fkeyL] = LAYOUT_hhkb_wrap(
    FKEYS_0,  KC_TRNS,  TRNS_5X__________,
    FKEYS_1,  KC_TRNS,  TRNS_5X__________,
    FKEYS_2,  KC_TRNS,  FKEYS_R2S________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_nav] = LAYOUT_hhkb_wrap(
    TRNS_5X__________,  NAV__R0__________,
    TRNS_5X__________,  NAV__R1__________,
    NAV__L2__________,  NAV__R2S_________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_light] = LAYOUT_hhkb_wrap(
    RGB__L0__________,  ETC__R0__________,
    ETC__L1__________,  TRNS_5X__________,
    RGB__LX__________,  TRNS_4X__________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
)

};
// clang-format on
