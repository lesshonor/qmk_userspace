// Copyright 2023 The QMK Community (@qmk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "lesshonor.h"
#include "process_combo.h"

const uint16_t PROGMEM cmb_bspc[]   = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_del[]    = {KC_AMPR, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_tab[]    = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_tab_hrm[]   = {LSFT_T(KC_D), LGUI_T(KC_F), COMBO_END};
//const uint16_t PROGMEM cmb_tab_hrm[]   = {LGUI_T(KC_D), LALT_T(KC_F), COMBO_END};
const uint16_t PROGMEM cmb_esc[]    = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_enter[]  = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_enter_hrm[]  = {RGUI_T(KC_J), RSFT_T(KC_K), COMBO_END};
//const uint16_t PROGMEM cmb_enter_hrm[]  = {RALT_T(KC_J), RGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM cmb_caps[]  = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_caps_hrm[]  = {LSFT_T(KC_D), RSFT_T(KC_K), COMBO_END};
//const uint16_t PROGMEM cmb_caps_hrm[]  = {LSFT_T(KC_S), RSFT_T(KC_L), COMBO_END};
//const uint16_t PROGMEM cmb_caps_mt1[]  = {LSFT_T(KC_Z), RSFT_T(KC_SLSH), COMBO_END};

const uint16_t PROGMEM cmb_grv[]  = {KC_X, KC_C, COMBO_END};
//const uint16_t PROGMEM cmb_grv_mt[]  = {LSFT_T(KC_Z), KC_X, COMBO_END};
//const uint16_t PROGMEM cmb_grv_lt[]  = {LT(L_fkeyR, KC_Z), KC_X, COMBO_END};
//const uint16_t PROGMEM cmb_grv_hrm[]  = {LSFT_T(KC_S), LGUI_T(KC_D), COMBO_END};
//const uint16_t PROGMEM cmb_tild[]  = {KC_Q, KC_W, COMBO_END};

const uint16_t PROGMEM cmb_exlm[]  = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM cmb_dash_hrm[]  = {LCTL_T(KC_S), LSFT_T(KC_D), COMBO_END};
//const uint16_t PROGMEM cmb_dash_hrm[]  = {LSFT_T(KC_S), LGUI_T(KC_D), COMBO_END};

const uint16_t PROGMEM cmb_quot[]  = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_quot_hrm[]  = {RSFT_T(KC_K), RCTL_T(KC_L), COMBO_END};
//const uint16_t PROGMEM cmb_quot_hrm[]  = {RGUI_T(KC_K), RSFT_T(KC_L), COMBO_END};
//const uint16_t PROGMEM cmb_dquo[]  = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_bsls[]  = {KC_COMM, KC_DOT, COMBO_END};
//const uint16_t PROGMEM cmb_bsls_lt[]  = {KC_COMM, LT(L_fkeyL, KC_DOT), COMBO_END};

//"Enclosing" type combos
//const uint16_t PROGMEM cmb_paren[]  = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_paren[]  = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM cmb_square[]  = {KC_C, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_curly[]  = {KC_X, KC_DOT, COMBO_END};
//const uint16_t PROGMEM cmb_curly_lt[]  = {KC_X, LT(L_fkeyR, KC_DOT), COMBO_END};

//ñ and other unicode alphas?
const uint16_t PROGMEM cmb_ene[]  = {KC_SCLN, KC_N, COMBO_END};
const uint16_t PROGMEM cmb_ene_hrm[]  = {RALT_T(KC_SCLN), KC_N, COMBO_END};
//const uint16_t PROGMEM cmb_ene_hrm[]  = {RCTL_T(KC_SCLN), KC_N, COMBO_END};

combo_t key_combos[] = {
    COMBO(cmb_bspc, KC_BSPC),
    COMBO(cmb_del, KC_DEL),
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_tab_hrm, KC_TAB),
    COMBO(cmb_esc, KC_ESC),
    COMBO(cmb_enter, KC_ENTER),
    COMBO(cmb_enter_hrm, KC_ENTER),
    COMBO(cmb_caps, KC_CAPS),
    COMBO(cmb_caps_hrm, KC_CAPS),
//    COMBO(cmb_caps_mt1, KC_CAPS),

    COMBO(cmb_grv, KC_GRV),
//    COMBO(cmb_grv_mt, KC_GRV),
//    COMBO(cmb_grv_lt, KC_GRV),
//  COMBO(cmb_tild, KC_TILD),

    COMBO(cmb_exlm, KC_EXLM),
    COMBO(cmb_dash_hrm, KC_MINS),

    COMBO(cmb_quot, KC_QUOT),
    COMBO(cmb_quot_hrm, KC_QUOT),
    //COMBO(cmb_dquo, KC_DQUO),
    COMBO(cmb_bsls, KC_BSLS),
//  COMBO(cmb_bsls_lt, KC_BSLS),

    COMBO(cmb_paren, C_PAREN),
    COMBO(cmb_square, C_SBRAC),
    COMBO(cmb_curly, C_CBRKT),
//    COMBO(cmb_curly_lt, C_CBRKT),

    COMBO(cmb_ene, C_ENE),
    COMBO(cmb_ene_hrm, C_ENE)
};
