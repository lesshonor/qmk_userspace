// Copyright 2023 The QMK Community (@qmk)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// TODO: should this be here?
#if defined(RGB_MATRIX_ENABLE)
    #if !defined(RGB_MATRIX_DEFAULT_MODE)
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
    #endif

    #if !defined(RGB_MATRIX_DEFAULT_VAL) || RGB_MATRIX_DEFAULT_VAL > 80
    #undef RGB_MATRIX_DEFAULT_VAL
    #define RGB_MATRIX_DEFAULT_VAL 80
    #endif

    #if !defined(RGB_MATRIX_MAXIMUM_BRIGHTNESS) || RGB_MATRIX_MAXIMUM_BRIGHTNESS > 120
    #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
    #endif

    #if defined(RGB_MATRIX_DISABLE_KEYCODES)
    #undef RGB_MATRIX_DISABLE_KEYCODES
    #endif
#endif

#if defined(RGBLIGHT_ENABLE)
    #if !defined(RGBLIGHT_DEFAULT_MODE)
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
    #endif

    #if !defined(RGBLIGHT_DEFAULT_VAL) || RGBLIGHT_DEFAULT_VAL > 80
    #undef RGBLIGHT_DEFAULT_VAL
    #define RGBLIGHT_DEFAULT_VAL 80
    #endif

    #if !defined(RGBLIGHT_LIMIT_VAL) || RGBLIGHT_LIMIT_VAL > 120
    #undef RGBLIGHT_LIMIT_VAL
    #define RGBLIGHT_LIMIT_VAL 120
    #endif

    #if defined(RGBLIGHT_DISABLE_KEYCODES)
    #undef RGBLIGHT_DISABLE_KEYCODES
    #endif
#endif
