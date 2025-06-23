// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "lesshonor.h"
#include "wrappers.h"

#define LAYOUT_2u_wrap(...) LAYOUT_2u(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_base] = LAYOUT_2u_wrap(
    KC_ESC,          BASE_L0__________,  BASE_R0__________,  KC_BSPC,
    LCTL_T(KC_TAB),  BASE_L1__________,  BASE_R1__________,  KC_QUOT,
    KC_LSFT,         BASE_L2__________,  BASE_R2__________,  KC_RSFT,
    TG(L_nav),       BASE_L3__________,  BASE_R3__________,  RCTL_T(KC_CAPS)
),

[L_noHRM] = LAYOUT_2u_wrap(
    KC_TRNS,  TRNS_5X__________,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  NHRM_L1__________,  NHRM_R1__________,  KC_TRNS,
    KC_TRNS,  TRNS_5X__________,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_symb] = LAYOUT_2u_wrap(
    KC_TRNS,  SYMB_L0__________,  SYMB_R0__________,  KC_DEL,
    KC_TRNS,  SYMB_L1__________,  SYMB_R1__________,  KC_TRNS,
    KC_TRNS,  SYMB_L2__________,  SYMB_R2__________,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_DEL,   KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_numL] = LAYOUT_2u_wrap(
    KC_TRNS,  NUMPL_L0_________,  TRNS_5X__________,  KC_DEL,
    KC_TRNS,  NUMPL_L1_________,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  NUMPL_L2_________,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_numR] = LAYOUT_2u_wrap(
    KC_TRNS,  NUMPR_L0_________,  NUMPR_R0_________,  KC_DEL,
    KC_TRNS,  TRNS_5X__________,  NUMPR_R1_________,  KC_TRNS,
    KC_TRNS,  NUMPR_L2_________,  NUMPR_R2_________,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_fkeyL] = LAYOUT_2u_wrap(
    KC_TRNS,  FKEYS_0,  KC_TRNS,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  FKEYS_1,  KC_TRNS,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  FKEYS_2,  KC_TRNS,  FKEYS_R2_________,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_nav] = LAYOUT_2u_wrap(
    KC_TRNS,  TRNS_5X__________,  NAV__R0__________,  KC_TRNS,
    KC_TRNS,  TRNS_5X__________,  NAV__R1__________,  KC_TRNS,
    KC_TRNS,  NAV__L2__________,  NAV__R2__________,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_light] = LAYOUT_2u_wrap(
    KC_TRNS,  RGB__L0__________,  ETC__R0__________,  KC_TRNS,
    KC_TRNS,  ETC__L1__________,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  RGB__LX__________,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
)

};
// clang-format on
