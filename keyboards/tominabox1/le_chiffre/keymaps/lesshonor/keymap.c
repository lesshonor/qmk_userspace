// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "lesshonor.h"
#include "wrappers.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_base] = LAYOUT_wrap(
    BASE_L0__________,  TG(L_noHRM),  BASE_R0__________,
    BASE_L1__________,                BASE_R1__________,
    BASE_L2__________,                BASE_R2__________,
    BASE_L3__________,                BASE_R3__________
),

[L_noHRM] = LAYOUT_wrap(
    TRNS_5X__________,  KC_TRNS,  TRNS_5X__________,
    NHRM_L1__________,            NHRM_R1__________,
    TRNS_5X__________,            TRNS_5X__________,
    TRNS_2X__________,            TRNS_2X__________
),

[L_symb] = LAYOUT_wrap(
    SYMB_L0__________,  KC_TRNS,  SYMB_R0__________,
    SYMB_L1__________,            SYMB_R1__________,
    SYMB_L2__________,            SYMB_R2__________,
    TRNS_2X__________,            TRNS_2X__________
),

[L_numL] = LAYOUT_wrap(
    NUMPL_L0_________,  KC_TRNS,  TRNS_5X__________,
    NUMPL_L1_________,            TRNS_5X__________,
    NUMPL_L2_________,            TRNS_5X__________,
    TRNS_2X__________,            TRNS_2X__________
),

[L_numR] = LAYOUT_wrap(
    NUMPR_L0_________,  KC_TRNS,  NUMPR_R0_________,
    TRNS_5X__________,            NUMPR_R1_________,
    NUMPR_L2_________,            NUMPR_R2_________,
    TRNS_2X__________,            TRNS_2X__________
),

[L_fkeyL] = LAYOUT_wrap(
    FKEYS_0,  KC_TRNS,  KC_TRNS,  TRNS_5X__________,
    FKEYS_1,  KC_TRNS,            TRNS_5X__________,
    FKEYS_2,  KC_TRNS,            FKEYS_R2_________,
    TRNS_2X__________,            TRNS_2X__________
),

[L_nav] = LAYOUT_wrap(
    TRNS_5X__________,  KC_TRNS,  NAV__R0__________,
    TRNS_5X__________,            NAV__R1__________,
    NAV__L2__________,            NAV__R2__________,
    TRNS_2X__________,            TRNS_2X__________
),

[L_light] = LAYOUT_wrap(
    RGB_CUSTOM_L0____,  RGB_TOG,  ETC__R0__________,
    RGB_CUSTOM_L1____,            TRNS_5X__________,
    RGB__LX__________,            TRNS_5X__________,
    TRNS_2X__________,            TRNS_2X__________
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
    { ENCODER_CCW_CW(C_LIGHB, C_LIGHF) },
};
#endif

/* CUSTOM KEYMAP FUNCTIONALITY */

#if defined(OLED_ENABLE)
void render_lighting_mode_keymap(uint8_t user_lighting_mode) {
#if defined(RGB_MATRIX_ENABLE)
    oled_advance_char();
    oled_write_P(PSTR("u"), user_lighting_mode & LED_FLAG_UNDERGLOW);
    oled_write_ln_P(PSTR("i"), user_lighting_mode & LED_FLAG_INDICATOR);
#endif
}

/* BEGIN STANDARD QMK FUNCTIONS */
bool oled_task_keymap(void) {
    render_layer_status_user(true);
    oled_write_P(oled_section_break, false);
    //render_mod_status(get_mods() | get_oneshot_mods());
    render_short_mod_status_user(get_mods() | get_oneshot_mods());
    render_keylock_status(host_keyboard_led_state());
    oled_write_P(oled_section_break, false);
    render_lighting_mode_keymap(rgb_matrix_get_flags());
    oled_write_P(oled_section_break, false);
    render_current_input_mode_user(true);
#if defined(DEBUG_MATRIX_SCAN_RATE)
    oled_write(get_u16_str((uint16_t)get_matrix_scan_rate(), ' '), false);
#endif
    return false;
}
#endif
