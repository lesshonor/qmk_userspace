/* Copyright 2021 Kyle McCreery
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 #include QMK_KEYBOARD_H

#include "lesshonor.h"
#include "wrappers.h"

#define LAYOUT_7u_wrap(...) LAYOUT_7u(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_base] = LAYOUT_7u_wrap(
   CK_TOGG,         TRNS_5X__________,                TRNS_5X__________,  QK_BOOT,
   KC_ESC,          BASE_L0__________,                BASE_R0__________,  KC_BSPC,
   LCTL_T(KC_TAB),  BASE_L1__________,                BASE_R1__________,  KC_QUOT,
   KC_LSFT,         BASE_L2__________,  TG(L_noHRM),  BASE_R2__________,  KC_RSFT,
   KC_LCTL,         KC_LGUI,  BASE_BOTTOM_3KEYS,  KC_RGUI, KC_RCTL
),

[L_noHRM] = LAYOUT_7u_wrap(
   KC_TRNS,  TRNS_5X__________,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  TRNS_5X__________,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  NHRM_L1__________,            NHRM_R1__________,  KC_TRNS,
   KC_TRNS,  TRNS_5X__________,  KC_TRNS,  TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_symb] = LAYOUT_7u_wrap(
   KC_TRNS,  TRNS_5X__________,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  SYMB_L0__________,            SYMB_R0__________,  KC_DEL,
   KC_TRNS,  SYMB_L1__________,            SYMB_R1__________,  KC_TRNS,
   KC_TRNS,  SYMB_L2__________,  KC_TRNS,  SYMB_R2__________,  KC_TRNS,
   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_numL] = LAYOUT_7u_wrap(
   KC_TRNS,  TRNS_5X__________,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  NUMPL_L0_________,            TRNS_5X__________,  KC_DEL,
   KC_TRNS,  NUMPL_L1_________,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  NUMPL_L2_________,  KC_TRNS,  TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_numR] = LAYOUT_7u_wrap(
   KC_TRNS,  TRNS_5X__________,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  NUMPR_L0_________,            NUMPR_R0_________,  KC_DEL,
   KC_TRNS,  TRNS_5X__________,            NUMPR_R1_________,  KC_TRNS,
   KC_TRNS,  NUMPR_L2_________,  KC_TRNS,  NUMPR_R2_________,  KC_TRNS,
   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_fkeyL] = LAYOUT_7u_wrap(
   KC_TRNS,  TRNS_5X__________,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  FKEYS_0,  KC_TRNS,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  FKEYS_1,  KC_TRNS,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  FKEYS_2,  KC_TRNS,  KC_TRNS,  FKEYS_R2_________,  KC_TRNS,
   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_nav] = LAYOUT_7u_wrap(
   KC_TRNS,  TRNS_5X__________,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  TRNS_5X__________,            NAV__R0__________,  KC_TRNS,
   KC_TRNS,  TRNS_5X__________,            NAV__R1__________,  KC_TRNS,
   KC_TRNS,  NAV__L2__________,  KC_TRNS,  NAV__R2__________,  KC_TRNS,
   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_light] = LAYOUT_7u_wrap(
   KC_TRNS,  TRNS_5X__________,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  RGB_CUSTOM_L0____,            ETC__R0__________,  KC_TRNS,
   KC_TRNS,  RGB_CUSTOM_L1____,            TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  RGB__LX__________,  RGB_TOG,  TRNS_5X__________,  KC_TRNS,
   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
)
};


// clang-format on

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(C_WNDWB, C_WNDWF) },
    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    { ENCODER_CCW_CW(UC_PREV, UC_NEXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    { ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    { ENCODER_CCW_CW(C_LIGHB, C_LIGHF) }
};
#endif
/* CUSTOM KEYMAP FUNCTIONALITY */

/*
#if defined(RGB_MATRIX_ENABLE)
bool rgb_matrix_indicators_keymap(void) {
    // Prevent my own custom indicator code from running, because it's effectively identical to the keyboard's
    return false;
}
#endif
*/

