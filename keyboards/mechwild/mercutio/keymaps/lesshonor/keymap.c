// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "lesshonor.h"
#include "wrappers.h"

// clang-format off
#define LAYOUT_mercutio_wrap(...) LAYOUT_full_lshift_625u_space(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_base] = LAYOUT_mercutio_wrap(
                                                              TG(L_noHRM),
    KC_ESC,          BASE_L0__________,  BASE_R0__________,   KC_BSPC,
    LCTL_T(KC_TAB),  BASE_L1__________,  BASE_R1__________,   RALT_T(KC_SCLN),
    KC_LSFT,         BASE_L2__________,  BASE_R2__________,
    KC_TRNS,  TG(L_nav),  BASE_BOTTOM_3KEYS,  RCTL_T(KC_CAPS),  TG(L_fkeyL)
),

[L_noHRM] = LAYOUT_mercutio_wrap(
                                                      KC_TRNS,
    KC_TRNS,  TRNS_5X__________,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  NHRM_L1__________,  NHRM_R1__________,  KC_SCLN,
    KC_TRNS,  TRNS_5X__________,  TRNS_5X__________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_symb] = LAYOUT_mercutio_wrap(
                                                      KC_TRNS,
    KC_TRNS,  SYMB_L0__________,  SYMB_R0__________,  KC_DEL,
    KC_TRNS,  SYMB_L1__________,  SYMB_R1__________,  KC_QUOT,
    KC_TRNS,  SYMB_L2__________,  SYMB_R2__________,
    KC_TRNS,  KC_TRNS,  KC_DEL,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_numL] = LAYOUT_mercutio_wrap(
                                                      KC_TRNS,
    KC_TRNS,  NUMPL_L0_________,  TRNS_5X__________,  KC_DEL,
    KC_TRNS,  NUMPL_L1_________,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  NUMPL_L2_________,  TRNS_5X__________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_numR] = LAYOUT_mercutio_wrap(
                                                      KC_TRNS,
    KC_TRNS,  NUMPR_L0_________,  NUMPR_R0_________,  KC_DEL,
    KC_TRNS,  TRNS_5X__________,  NUMPR_R1_________,  KC_KP_0,
    KC_TRNS,  NUMPR_L2_________,  NUMPR_R2_________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_fkeyL] = LAYOUT_mercutio_wrap(
                                                      KC_TRNS,
    KC_TRNS,  FKEYS_0,  KC_TRNS,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  FKEYS_1,  KC_TRNS,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  FKEYS_2,  KC_TRNS,  FKEYS_R2_________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_nav] = LAYOUT_mercutio_wrap(
                                                      KC_TRNS,
    KC_TRNS,  TRNS_5X__________,  NAV__R0__________,  KC_TRNS,
    KC_TRNS,  TRNS_5X__________,  NAV__R1__________,  KC_TRNS,
    KC_TRNS,  NAV__L2__________,  NAV__R2__________,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),

[L_light] = LAYOUT_mercutio_wrap(
                                                      KC_TRNS,
    KC_TRNS,  ETC__L0__________,  ETC__R0__________,  KC_TRNS,
    KC_TRNS,  ETC__L1__________,  TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  TRNS_5X__________,  TRNS_5X__________,
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
    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

bool oled_task_keymap(void) {
    render_layer_status_user(false);
    oled_set_cursor(oled_max_chars() - 5, 0);
    render_current_input_mode_user(true);
    render_short_mod_status_user(get_mods() | get_oneshot_mods());
    oled_set_cursor(oled_max_chars() - 5, 1);
    render_keylock_status_user(host_keyboard_led_state());
return true;
}
