// Copyright 2023 The QMK Community (@qmk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "lesshonor.h"

#include "action_util.h"
#include "host.h"
#include "quantum.h"
#include "unicodemap.h"

/* UNICODE FUNCTION OVERRIDE */

led_t unicode_saved_led_state;
uint8_t unicode_saved_mods;

void unicode_input_start(void) {
    unicode_saved_led_state = host_keyboard_led_state();

    // Note the order matters here!
   // Need to do this before we mess around with the mods, or else
    // UNICODE_KEY_LNX (which is usually Ctrl-Shift-U) might not work
    // correctly in the shifted case.
    if (unicode_saved_led_state.caps_lock) {
        switch (unicode_config.input_mode) {
            case UNICODE_MODE_LINUX:
            case UNICODE_MODE_URXVT:
                tap_code(KC_CAPS_LOCK);
                break;
        }
    }

    unicode_saved_mods = get_mods(); // Save current mods
    clear_mods();                    // Unregister mods to start from a clean state
    clear_weak_mods();

    switch (unicode_config.input_mode) {
        case UNICODE_MODE_LINUX:
            tap_code16(LCTL(LSFT(KC_U)));
            break;
        case UNICODE_MODE_WINDOWS:
            // For increased reliability, use numpad keys for inputting digits
            if (!unicode_saved_led_state.num_lock) {
                tap_code(KC_NUM_LOCK);
            }
            register_code(KC_LEFT_ALT);
            break;
        case UNICODE_MODE_URXVT:
            register_code16(LCTL(KC_LSFT)); // no u!
            break;
        case UNICODE_MODE_VIM:
            tap_code16(LCTL(KC_V));
            tap_code(KC_U);
            break;
    }

    wait_ms(TAP_CODE_DELAY);
}

void unicode_input_finish(void) {
    switch (unicode_config.input_mode) {
        case UNICODE_MODE_URXVT:
            unregister_code16(LCTL(KC_LSFT));
            break;
        case UNICODE_MODE_LINUX:
            tap_code(KC_SPACE);
            break;
        case UNICODE_MODE_WINDOWS:
            unregister_code(KC_LEFT_ALT);
            if (!unicode_saved_led_state.num_lock) {
                tap_code(KC_NUM_LOCK);
            }
            break;
    }

    if (unicode_saved_led_state.caps_lock) {
        switch (unicode_config.input_mode) {
            case UNICODE_MODE_LINUX:
            case UNICODE_MODE_URXVT:
                tap_code(KC_CAPS_LOCK);
                break;
        }
    }

    set_mods(unicode_saved_mods); // Reregister previously set mods
}

void unicode_input_cancel(void) {
    switch (unicode_config.input_mode) {
        case UNICODE_MODE_URXVT:
            unregister_code16(LCTL(KC_LSFT));
        case UNICODE_MODE_LINUX:
        case UNICODE_MODE_VIM:
            tap_code(KC_ESCAPE);
            break;
        case UNICODE_MODE_WINDOWS:
            unregister_code(KC_LEFT_ALT);
            if (!unicode_saved_led_state.num_lock) {
                tap_code(KC_NUM_LOCK);
            }
            break;
    }

    if (unicode_saved_led_state.caps_lock) {
        switch (unicode_config.input_mode) {
            case UNICODE_MODE_LINUX:
            case UNICODE_MODE_URXVT:
                tap_code(KC_CAPS_LOCK);
                break;
        }
    }

    set_mods(unicode_saved_mods); // Reregister previously set mods
}

/* END UNICODE FUNCTION OVERRIDES */
