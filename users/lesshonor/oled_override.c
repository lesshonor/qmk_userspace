// Copyright 2023 The QMK Community (@qmk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycode.h"
#include "oled_driver.h"
#include "progmem.h"
#if defined(RGB_MATRIX_ENABLE)
#include "rgb_matrix_types.h"
#endif
#include "quantum.h" // led_t

#include <string.h>
#include <lib/lib8tion/lib8tion.h>

#define LESS_LAYER_OLED_MACRO(A, B, C, D, E, F, G, H) \
const char PROGMEM layer_ ## A[] = #A; \
const char PROGMEM layer_ ## B[] = #B; \
const char PROGMEM layer_ ## C[] = #C; \
const char PROGMEM layer_ ## D[] = #D; \
const char PROGMEM layer_ ## E[] = #E; \
const char PROGMEM layer_ ## F[] = #F; \
const char PROGMEM layer_ ## G[] = #G; \
const char PROGMEM layer_ ## H[] = #H; \
const char* const PROGMEM layer_names[] = { \
      layer_ ## A, \
      layer_ ## B, \
      layer_ ## C, \
      layer_ ## D, \
      layer_ ## E, \
      layer_ ## F, \
      layer_ ## G, \
      layer_ ## H, \
}

LESS_LAYER_OLED_MACRO(base, noHRM, symb, numL, numR, fkeyL, nav, etc);

static layer_state_t top_layer_cache;
static char oled_layer_buf[6] = {0x00};

__attribute__((weak)) bool oled_task_keymap(void) {
    return true;
}

bool oled_task_user(void) {
    if (!oled_task_keymap()) {
        // Skip my user code in favor of the keymap's or keyboard's code.
        #ifdef DEBUG_MATRIX_SCAN_RATE
        //oled_write_P(get_u16_str((uint16_t)get_matrix_scan_rate(), ' '), false);
        #endif
        return true;
    }
    return false;
}

#if defined(UNICODE_COMMON_ENABLE)
void render_current_input_mode_user(bool singleline) {
    switch (unicode_config.input_mode) {
       case UNICODE_MODE_WINDOWS:
           oled_write_P(PSTR("MS"), false);
           if (singleline) {
               oled_advance_page(true);
           }
           break;
       case UNICODE_MODE_URXVT: // ...thanks urxvt
           oled_write_P(PSTR("urxvt"), false);
           break;
       case UNICODE_MODE_VIM: // ...thanks vim
           oled_write_P(PSTR("vim"), false);
           if (singleline) {
               oled_advance_page(true);
           }
           break;
       default: // fall back to linux (iBus)
           oled_write_P(PSTR("linux"), false);
           break;
       }
}
#endif

void render_short_mod_status_user(uint8_t modifiers) {
    oled_write_P(PSTR("A"), (modifiers & MOD_BIT(KC_LALT)));
    oled_write_P(PSTR("C"), (modifiers & MOD_BIT(KC_LCTL)));
    oled_write_P(PSTR("S"), (modifiers & MOD_BIT(KC_LSFT)));
    oled_write_P(PSTR("G"), (modifiers & MOD_BIT(KC_LGUI)));

    oled_advance_char();
    oled_advance_char();

    oled_write_P(PSTR("G"), (modifiers & MOD_BIT(KC_RGUI)));
    oled_write_P(PSTR("S"), (modifiers & MOD_BIT(KC_RSFT)));
    oled_write_P(PSTR("C"), (modifiers & MOD_BIT(KC_RCTL)));
    oled_write_P(PSTR("A"), (modifiers & MOD_BIT(KC_RALT)));
}

void render_layer_status_user(bool singleline) {
    oled_write(oled_layer_buf, false);
    if (singleline && strlen(oled_layer_buf) < oled_max_chars()) {
        oled_advance_page(true);
    }
}

void render_keylock_status_user(led_t led_state) {
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), led_state.scroll_lock);
}

#if defined(RGB_MATRIX_ENABLE)
void render_lighting_mode_user(uint8_t user_lighting_mode) {
    oled_write_P(PSTR("m"), user_lighting_mode & LED_FLAG_MODIFIER);
    oled_write_P(PSTR("u"), user_lighting_mode & LED_FLAG_UNDERGLOW);
    oled_write_P(PSTR("k"), user_lighting_mode & LED_FLAG_KEYLIGHT);
    oled_write_P(PSTR("i"), user_lighting_mode & LED_FLAG_INDICATOR);
}
#endif

// Avoid excessive copying by only updating the layer name buffer when the layer changes
static void update_layer_namebuf(layer_state_t layer, bool force_update) {
    if (force_update || layer != top_layer_cache) {
        top_layer_cache = layer;
        if (layer < ARRAY_SIZE(layer_names)) {
            memcpy_P(oled_layer_buf, pgm_read_ptr(&layer_names[layer]), ARRAY_SIZE(oled_layer_buf) - 1);
        } else {
            memcpy8(oled_layer_buf, get_u8_str(layer, ' '), ARRAY_SIZE(oled_layer_buf) - 1);
        }
    }
}

// If we don't force an update during initialization, the layer name buffer will start out blank.
layer_state_t default_layer_state_set_user(layer_state_t state) {
    update_layer_namebuf(get_highest_layer(state), true);
    return state;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    update_layer_namebuf(get_highest_layer(state | default_layer_state), false);
    return state;
}
