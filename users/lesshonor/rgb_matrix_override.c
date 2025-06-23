// Copyright 2023 QMK Contributors <@qmk>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action_util.h" //ARRAY_SIZE
#include "action_layer.h" //layer_state_t
#if defined(DYNAMIC_KEYMAP_ENABLE)
#include "dynamic_keymap.h"
#endif
#include "keymap_introspection.h"
#include "quantum.h"
#include "rgb_matrix.h"
#include "rgb_matrix_types.h"
#include "util.h"

// TODO: make it possible to re-use keymap_layer_count
uint8_t count_layers(void) {
#if defined(DYNAMIC_KEYMAP_ENABLE)
    return dynamic_keymap_get_layer_count();
#else
    return keymap_layer_count_raw();
#endif
}

#if defined(CAPS_LOCK_INDICATORS) || defined(MODIFIER_INDICATORS) || defined(LAYER_INDICATORS)
__attribute__((weak)) bool rgb_matrix_indicators_keymap(void) {
    return true;
}

bool rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_indicators_keymap()) {
        // Skip my user code in favor of the keymap's or keyboard's code.
        return true;
    }
    HSV base_hsv = rgb_matrix_config.hsv;
    // under certain parameters, the indicators won't be obvious enough
    if (base_hsv.s < INDICATOR_MIN_SAT) {
        base_hsv.s = INDICATOR_MIN_SAT;
    }
    if (base_hsv.v < RGB_MATRIX_VAL_STEP) {
        base_hsv.v = RGB_MATRIX_VAL_STEP;
    }
    uint8_t scaled_val = base_hsv.v / 3;
    uint8_t layer_color_break = UINT8_MAX / count_layers();

#if defined(CAPS_LOCK_INDICATORS) // CAPS LOCK INDICATORS
    uint8_t caps_leds[] = {CAPS_LOCK_INDICATORS};
    if (host_keyboard_led_state().caps_lock) {
        RGB caps_clr;
        // TODO: Scale this
        if (rgb_matrix_get_sat() >= INDICATOR_MIN_SAT) {
            caps_clr = (RGB){ .r = scaled_val, .g = scaled_val, .b = scaled_val };
        } else {
            caps_clr = hsv_to_rgb((HSV){ .h = (base_hsv.h + (layer_color_break / 2)) & 255, .s = base_hsv.s, .v = base_hsv.v});
        }
        // TODO: yank this out into separate function?
        for (uint8_t i = 0; i < ARRAY_SIZE(caps_leds); i++) {
            rgb_matrix_set_color(caps_leds[i], caps_clr.r, caps_clr.g, caps_clr.b);
        }
    } else {
        for (uint8_t i = 0; i < ARRAY_SIZE(caps_leds); i++) {
            if (g_led_config.flags[caps_leds[i]] == LED_FLAG_NONE) {
                rgb_matrix_set_color(caps_leds[i], 0, 0, 0);
            }
        }
    }
#endif // CAPS LOCK INDICATORS

#if defined(MODIFIER_INDICATORS) // MODIFIER INDICATORS
    uint8_t curr_mods = get_mods() | get_oneshot_mods();
    uint8_t mod_leds[] = {MODIFIER_INDICATORS};
    if (curr_mods & MOD_MASK_CAG) {
        // If the modifer is not pressed, scaling relative to the current color's saturation level will look better than just setting 0.
        uint8_t scaled_sat = (scaled_val - ((uint16_t)scaled_val * base_hsv.s >> 8)) >> 1;
        RGB mod_clr = {
            // inexact but the bitshift results in higher matrix scan frequency than dividing by 255, and AVR needs all the help it can get here
            .r = (curr_mods & MOD_MASK_GUI) ? scaled_val : scaled_sat,
            .g = (curr_mods & MOD_MASK_ALT) ? scaled_val : scaled_sat,
            .b = (curr_mods & MOD_MASK_CTRL) ? scaled_val : scaled_sat
        };
        // TODO: yank this out into separate function?
        for (uint8_t i = 0; i < ARRAY_SIZE(mod_leds); i++) {
            rgb_matrix_set_color(mod_leds[i], mod_clr.r, mod_clr.g, mod_clr.b);
        }
    } else {
        for (uint8_t i = 0; i < ARRAY_SIZE(mod_leds); i++) {
            if (g_led_config.flags[mod_leds[i]] == LED_FLAG_NONE) {
                rgb_matrix_set_color(mod_leds[i], 0, 0, 0);
            }
        }
    }
#endif // MODIFIER INDICATORS

#if defined(LAYER_INDICATORS) // LAYER INDICATORS
    layer_state_t top_layer = get_highest_layer(layer_state | default_layer_state);
    uint8_t layer_leds[] = {LAYER_INDICATORS};
    // don't modify color on base layer
    if (top_layer > 0) {
        // Calculate hue shift
        uint8_t hue_change = layer_color_break * top_layer;
        base_hsv.h         = (hue_change + base_hsv.h) & 255;

        RGB layer_clr = hsv_to_rgb(base_hsv);
        for (uint8_t i = 0; i < ARRAY_SIZE(layer_leds); i++) {
            rgb_matrix_set_color(layer_leds[i], layer_clr.r, layer_clr.g, layer_clr.b);
        }
    } else {
        for (uint8_t i = 0; i < ARRAY_SIZE(layer_leds); i++) {
            if (g_led_config.flags[layer_leds[i]] == LED_FLAG_NONE) {
                rgb_matrix_set_color(layer_leds[i], 0, 0, 0);
            }
        }
    }
#endif // LAYER INDICATORS

    return false;
}
#endif
