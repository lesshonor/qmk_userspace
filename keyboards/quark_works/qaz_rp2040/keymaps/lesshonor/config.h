// Copyright 2024 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RGBW
#define RGBLIGHT_LED_COUNT 4

//#define RGB_MATRIX_DEFAULT_HUE 162
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL 72

// until I get around to providing rgb matrix definitions for this board...
#define RGBLIGHT_DEFAULT_SAT RGB_MATRIX_DEFAULT_SAT
#define RGBLIGHT_DEFAULT_VAL RGB_MATRIX_DEFAULT_VAL

#define LAYER_INDICATORS 3
#define MODIFIER_INDICATORS 1, 4
#define CAPS_LOCK_INDICATORS 2
