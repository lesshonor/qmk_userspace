// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "lesshonor.h"

#define LAYOUT_wrap(...) LAYOUT(__VA_ARGS__)

#define BASE_L0__________ LT(L_numR,KC_Q),    KC_W,              KC_E,          KC_R,          KC_T
#define BASE_L1__________ LALT_T(KC_A),       LCTL_T(KC_S),      LSFT_T(KC_D),  LGUI_T(KC_F),  KC_G
#define BASE_L2__________ LT(L_nav,KC_Z),     KC_X,              KC_C,          KC_V,          KC_B
#define BASE_L3__________ TT(L_nav),          LT(L_symb,KC_SPC)

#define BASE_R0__________ KC_Y,               KC_U,              KC_I,          KC_O,          LT(L_light,KC_P)
#define BASE_R1__________ KC_H,               RGUI_T(KC_J),      RSFT_T(KC_K),  RCTL_T(KC_L),  RALT_T(KC_SCLN)
#define BASE_R2__________ KC_N,               KC_M,              KC_COMM,       KC_DOT,        LT(L_fkeyL,KC_SLSH)
#define BASE_R2S_________ KC_N,               KC_M,              KC_COMM,       LT(L_fkeyL,KC_DOT)
#define BASE_R3__________ LT(L_symb,KC_SPC),  TT(L_numL)

#define BASE_BOTTOM_3KEYS TT(L_nav),  LT(L_symb,KC_SPC),  TT(L_numL)

#define NHRM_L1__________ KC_A,  KC_S,  KC_D,  KC_F,  KC_G
#define NHRM_R1__________ KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN

#define SYMB_L0__________ KC_TILD,  KC_LCBR,  KC_RCBR,  KC_UNDS,  KC_TRNS
#define SYMB_L1__________ KC_GRV,   KC_LBRC,  KC_RBRC,  KC_MINS,  C_NDASH
#define SYMB_L2__________ KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC

#define SYMB_R0__________ KC_TRNS,  KC_PLUS,  KC_ASTR,  KC_PIPE,  KC_DQUO
#define SYMB_R1__________ KC_BSLS,  KC_EQL,   KC_LPRN,  KC_RPRN,  KC_QUOT
#define SYMB_R2__________ KC_CIRC,  KC_AMPR,  KC_TRNS,  KC_TRNS,  KC_TRNS
#define SYMB_R2S_________ KC_CIRC,  KC_AMPR,  KC_TRNS,  KC_TRNS

#define NUMPL_L0_________ KC_TRNS,  KC_7,     KC_8,     KC_9,     KC_TRNS
#define NUMPL_L1_________ KC_0,     KC_4,     KC_5,     KC_6,     KC_MINS
#define NUMPL_L2_________ KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_SLSH

#define NUMPR_L0_________ KC_TRNS,  KC_LALT,  KC_TRNS,  KC_TRNS,  KC_TRNS
#define NUMPR_L2_________ KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NUM,   KC_TRNS
#define NUMPR_R0_________ KC_TRNS,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_TRNS
#define NUMPR_R1_________ KC_MINS,  KC_KP_4,  KC_KP_5,  KC_KP_6,  KC_KP_0
#define NUMPR_R2_________ KC_SLSH,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_TRNS
#define NUMPR_R2S________ KC_SLSH,  KC_KP_1,  KC_KP_2,  KC_KP_3

#define FKEYS_0           KC_F1,    KC_F2,    KC_F3,    KC_F4
#define FKEYS_1           KC_F5,    KC_F6,    KC_F7,    KC_F8
#define FKEYS_2           KC_F9,    KC_F10,   KC_F11,   KC_F12

#define FKEYS_R2_________ KC_RGUI,  KC_RALT,  KC_RSFT,  KC_RCTL,  KC_TRNS
#define FKEYS_R2S________ KC_RGUI,  KC_RALT,  KC_RSFT,  KC_RCTL
#define FKEYS_L2_________ KC_TRNS,  KC_RGUI,  KC_RALT,  KC_RSFT,  KC_RCTL

//#define NUMP_L0__________ KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS

#define NAV__L2__________ KC_TRNS,  KC_LCTL,  KC_LSFT,  KC_TRNS,   KC_TRNS

#define NAV__R0__________ KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_TRNS
#define NAV__R1__________ KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_TRNS
#define NAV__R2__________ KC_TRNS,  KC_TRNS,  C_WNDWB,  C_WNDWF,  KC_TRNS
#define NAV__R2S_________ KC_TRNS,  KC_TRNS,  C_WNDWB,  C_WNDWF

#define ETC__L0__________ KC_TRNS,  KC_VOLU,  UC_NEXT,  KC_TRNS,  KC_TRNS
#define ETC__L1__________ KC_TRNS,  KC_VOLD,  UC_PREV,  KC_TRNS,  KC_TRNS

#define RGB_CUSTOM_L0____ RGB_TOG,  KC_VOLU,  UC_NEXT,  C_LIGHF,  C_INDTG
#define RGB__L0__________ RGB_TOG,  KC_VOLU,  UC_NEXT,  KC_TRNS,  KC_TRNS
#define RGB_CUSTOM_L1____ KC_TRNS,  KC_VOLD,  UC_PREV,  C_LIGHB,  KC_TRNS

#define BACKLIGHT__L0____ BL_TOGG,  KC_VOLU,  UC_NEXT,  KC_TRNS,  KC_TRNS

#define ETC__R0__________ KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_RSFT,  KC_TRNS

#define RGB__LX__________ RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,  RGB_SPI
#define BACKLIGHT__LX____ BL_BRTG,  BL_UP,    BL_DOWN,  KC_TRNS,  KC_TRNS

#define TRNS_5X__________ KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
#define TRNS_4X__________ KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
#define TRNS_2X__________ KC_TRNS,  KC_TRNS

