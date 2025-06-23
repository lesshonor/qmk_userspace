// Copyright 2023 QMK Contributors
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "lesshonor.h"
#include "wrappers.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_base] = LAYOUT_wrap(
    KC_ESC,   BASE_L0__________,                                       QK_BOOT,     BASE_R0__________,  KC_BSPC,
    KC_LCTL,  BASE_L1__________,                          KC_MUTE,     EE_CLR,      BASE_R1__________,  KC_ENT,
    KC_LSFT,  BASE_L2__________,                                       KC_TRNS,     BASE_R2__________,  KC_RSFT,
              KC_MS_BTN3,  BASE_L3__________, KC_TRNS, KC_MS_BTN1, TAP_TOG, KC_MS_BTN2, KC_TRNS,  BASE_R3__________,  TG(L_noHRM)
  ),

[L_noHRM] = LAYOUT_wrap(
    KC_TRNS,  TRNS_5X__________,                                       KC_TRNS,     TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  NHRM_L1__________,                          KC_TRNS,     KC_TRNS,     NHRM_R1__________,  KC_TRNS,
    KC_TRNS,  TRNS_5X__________,                                       KC_TRNS,     TRNS_5X__________,  KC_TRNS,
              KC_TRNS,  KC_TRNS, TRNS_2X__________,  KC_TRNS, KC_TRNS, KC_TRNS, TRNS_2X__________,  KC_TRNS,  KC_TRNS
  ),

[L_symb] = LAYOUT_wrap(
    KC_TRNS,  SYMB_L0__________,                                       KC_TRNS,     SYMB_R0__________,  KC_TRNS,
    KC_TRNS,  SYMB_L1__________,                          KC_TRNS,     KC_TRNS,     SYMB_R1__________,  KC_TRNS,
    KC_TRNS,  SYMB_L2__________,                                       KC_TRNS,     SYMB_R2__________,  KC_TRNS,
              KC_TRNS,  KC_TRNS, TRNS_2X__________,  KC_TRNS, KC_TRNS, KC_TRNS, TRNS_2X__________,  KC_TRNS,  KC_TRNS
  ),

[L_numL] = LAYOUT_wrap(
    KC_TRNS,  NUMPL_L0_________,                                       KC_TRNS,      TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  NUMPL_L1_________,                          KC_TRNS,     KC_TRNS,      TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  NUMPL_L2_________,                                       KC_TRNS,      TRNS_5X__________,  KC_TRNS,
              KC_TRNS,  KC_TRNS, TRNS_2X__________,  KC_TRNS, KC_TRNS, KC_TRNS, TRNS_2X__________,  KC_TRNS,  KC_TRNS
  ),

[L_numR] = LAYOUT_wrap(
    KC_TRNS,  NUMPR_L0_________,                                       KC_TRNS,     NUMPR_R0_________,  KC_TRNS,
    KC_TRNS,  TRNS_5X__________,                          KC_TRNS,     KC_TRNS,     NUMPR_R1_________,  KC_TRNS,
    KC_TRNS,  NUMPR_L2_________,                                       KC_TRNS,     NUMPR_R2_________,  KC_TRNS,
              KC_TRNS,  KC_TRNS, TRNS_2X__________,  KC_TRNS, KC_TRNS, KC_TRNS, TRNS_2X__________,  KC_TRNS,  KC_TRNS
  ),

[L_fkeyL] = LAYOUT_wrap(
    KC_TRNS,  FKEYS_0,  KC_TRNS,                                       KC_TRNS,     TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  FKEYS_1,  KC_TRNS,                          KC_TRNS,     KC_TRNS,     TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  FKEYS_2,  KC_TRNS,                                       KC_TRNS,     FKEYS_R2_________,  KC_TRNS,
              KC_TRNS,  KC_TRNS, TRNS_2X__________,  KC_TRNS, KC_TRNS, KC_TRNS, TRNS_2X__________,  KC_TRNS,  KC_TRNS
  ),

[L_nav] = LAYOUT_wrap(
    KC_TRNS,  TRNS_5X__________,                                       KC_TRNS,     NAV__R0__________,  KC_TRNS,
    KC_TRNS,  TRNS_5X__________,                          KC_TRNS,     KC_TRNS,     NAV__R1__________,  KC_TRNS,
    KC_TRNS,  NAV__L2__________,                                       KC_TRNS,     NAV__R2__________,  KC_TRNS,
              KC_TRNS,  KC_TRNS, TRNS_2X__________,  KC_TRNS, KC_TRNS, KC_TRNS, TRNS_2X__________,  KC_TRNS,  KC_TRNS
  ),

[L_light] = LAYOUT_wrap(
    KC_TRNS,  RGB__L0__________,                                       KC_TRNS,     ETC__R0__________,  KC_TRNS,
    KC_TRNS,  ETC__L1__________,                          KC_TRNS,     KC_TRNS,     TRNS_5X__________,  KC_TRNS,
    KC_TRNS,  RGB__LX__________,                                       KC_TRNS,     TRNS_5X__________,  KC_TRNS,
              KC_TRNS,  KC_TRNS, TRNS_2X__________,  KC_TRNS, KC_TRNS, KC_TRNS, TRNS_2X__________,  KC_TRNS,  RGB_TOG
  )

};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_LEFT, KC_RGHT),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(C_WNDWB, C_WNDWF),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(UC_PREV, UC_NEXT),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    { ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_WH_D, KC_WH_U),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    { ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),  ENCODER_CCW_CW(KC_TRNS, KC_TRNS) }
};
#endif

#if defined(POINTING_DEVICE_ENABLE)
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}
#endif

#if defined(OLED_ENABLE)
bool oled_task_keymap(void) {
/*
    render_layer_status_user(false);
    oled_set_cursor(oled_max_chars() - 5, 0);
    render_current_input_mode_user(true);
    render_short_mod_status_user(get_mods() | get_oneshot_mods());
    oled_set_cursor(oled_max_chars() - 5, 1);
    render_keylock_status_user(host_keyboard_led_state());
return true;
*/
return false;
}
#endif
