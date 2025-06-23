// Copyright 2023 The QMK Community (@qmk)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "lesshonor.h"

#include "action.h"
#include "debug.h"
#include "deferred_exec.h"
#include "host.h"
#include "quantum.h"
#include "process_unicodemap.h"

bool         window_nav_in_progress = false;
bool         window_nav_cancel      = false;
uint16_t     window_timer           = 0;
os_variant_t current_os             = OS_LINUX;
int8_t offset;

#if defined(RGB_MATRIX_ENABLE) && defined(RGB_INDICATORS_ENABLE)
#include "rgb_matrix_types.h"
led_flags_t curr_lighting_mode;
#endif

const uint32_t unicode_map[] PROGMEM = {[WIN_EMDASH] = 151, // technically an alt code
                                        [ENE_CAPS]   = 0xD1,
                                        [ENE]        = 0xF1,
                                        //  [EMDASH]       = 0x2013,
                                        [EMDASH] = 0x2014};

__attribute__((weak)) bool led_update_keymap(led_t led_state) {
    return true;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/* STANDARD QMK FUNCTIONS */
void keyboard_post_init_user() {
    //debug_enable=true;
#if defined(OS_DETECTION_ENABLE)
    // TODO: maybe cancel this if it just fails in X seconds
    defer_exec(100, config_os, NULL);
#endif
#if defined(RGB_MATRIX_ENABLE) && defined(RGB_INDICATORS_ENABLE)
    for(uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        orig_led_flags[i] = g_led_config.flags[i];
    }
    // Remove flags that are irrelevant.
    led_flags_t curr_lighting_mode = rgb_matrix_get_flags();
    if (HAS_ANY_FLAGS(curr_lighting_mode, (LIGHTING_FLAGS ^ LED_FLAG_ALL))) {
        rgb_matrix_set_flags_noeeprom(LIGHTING_FLAGS);
    }
    // g_led_config flags have been reset, so indicators won't darken
    process_lighting_mode(curr_lighting_mode);
#endif
}

bool led_update_user(led_t led_state) {
    // Doesn't seem to work from post_init_user :(
    force_numlock();
    return led_update_keymap(led_state);
}

void housekeeping_task_user(void) {
    if (window_nav_in_progress && (window_nav_cancel || timer_expired(timer_read(), (window_timer + 1000)))) {
    //dprintf("expired at %u, window_timer was %u\n", timer_read(), window_timer);
    //dprintf("window_nav_in_progress is %u\n", window_nav_in_progress);
    //dprintln("Canceling");
        switch (current_os) {
            case OS_WINDOWS:
                unregister_code(KC_LALT);
                break;
            case OS_LINUX:
                unregister_code(KC_LGUI);
                break;
            default:
                break;
        }
        window_nav_in_progress = false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case C_WNDWF:
        case C_WNDWB:
            if (record->event.pressed) {
                if (!window_nav_in_progress) {
                    window_nav_in_progress = true;
                    switch (current_os) {
                        case OS_WINDOWS:
                            register_code(KC_LALT);
                            break;
                        case OS_LINUX:
                            register_code(KC_LGUI);
                            break;
                        default:
                            break;
                    }
                }
                window_timer = timer_read();
                //dprintf("timer armed: %u\n", window_timer);
                switch (current_os) {
                    case OS_WINDOWS:
                        register_code16(keycode == C_WNDWF ? KC_TAB : S(KC_TAB));
                        break;
                    case OS_LINUX:
                        register_code(keycode == C_WNDWF ? KC_L : KC_H);
                        break;
                    default:
                        break;
                }
            } else {
                switch (current_os) {
                    case OS_WINDOWS:
                        unregister_code16(keycode == C_WNDWF ? KC_TAB : S(KC_TAB));
                        break;
                    case OS_LINUX:
                        unregister_code(keycode == C_WNDWF ? KC_L : KC_H);
                        break;
                    default:
                        break;
                }
            }
            break;
#if defined(RGB_MATRIX_ENABLE) && defined(RGB_INDICATORS_ENABLE)
        case C_LIGHF: // cycle lighting mode forward
        case C_LIGHB: // cycle lighting mode back
            curr_lighting_mode = rgb_matrix_get_flags();
            if (record->event.pressed) {
                if (keycode == C_LIGHF && curr_lighting_mode < LIGHTING_FLAGS) {
                    offset = 1;
                } else if (keycode == C_LIGHB && curr_lighting_mode > LED_FLAG_NONE) {
                    offset = -1;
                } else {
                    break; // invalid, bail out
                }
                curr_lighting_mode += offset;
                while (HAS_ANY_FLAGS(curr_lighting_mode, (LIGHTING_FLAGS ^ LED_FLAG_ALL))) {
                    curr_lighting_mode += offset;
                }
                rgb_matrix_set_flags(curr_lighting_mode);
                process_lighting_mode(curr_lighting_mode);
            }
            break;
        case C_INDTG: // enable/disable indicator lighting
            if (record->event.pressed) {
                indicators_enabled ^= 1;
                process_lighting_mode(curr_lighting_mode);
            }
            break;
#endif
        case C_PAREN:
            if (record->event.pressed) {
                tap_code16(KC_LPRN);
                tap_code16(KC_RPRN);
                tap_code(KC_LEFT);
            }
            break;
        case C_CBRKT:
            if (record->event.pressed) {
                tap_code16(KC_LCBR);
                tap_code16(KC_RCBR);
                tap_code(KC_LEFT);
            }
            break;
        case C_SBRAC:
            if (record->event.pressed) {
                tap_code(KC_LBRC);
                tap_code(KC_RBRC);
                tap_code(KC_LEFT);
            break;
            }
        case C_ABRKT:
            if (record->event.pressed) {
                tap_code16(S(KC_COMM));
                tap_code16(S(KC_DOT));
                tap_code(KC_LEFT);
            }
            break;
#if defined(UNICODE_COMMON_ENABLE)
        case C_ENE:
            if (record->event.pressed) {
                switch (unicode_config.input_mode) {
                    case UNICODE_MODE_WINDOWS: // TODO: leverage unicodemap built-in where possible to handle shifted version?
                        // unicode_input_start();
                        // register_hex(UM(ENE)); // I don't think this is going to work right. May need to create my own non-hex version for alt codes
                        unicode_input_start();
                        if (((get_mods() | get_weak_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) ^ host_keyboard_led_state().caps_lock) {
                            tap_code(KC_KP_0);
                            tap_code(KC_KP_2);
                            tap_code(KC_KP_0);
                            tap_code(KC_KP_9);
                        } else {
                            tap_code(KC_KP_0);
                            tap_code(KC_KP_2);
                            tap_code(KC_KP_4);
                            tap_code(KC_KP_1);
                        }
                        unicode_input_finish();
                        break;
                    default:
                        process_unicodemap(UP(ENE, ENE_CAPS), record);
                        break;
                }
            }
            break;
        case C_NDASH:
            if (record->event.pressed) {
                switch (unicode_config.input_mode) {
                    case UNICODE_MODE_WINDOWS:
                        unicode_input_start();
                        // tap_code(UM(WIN_EMDASH)); // see above, I don't think this is going to work right.
                        tap_code(KC_KP_0);
                        tap_code(KC_KP_1);
                        tap_code(KC_KP_5);
                        tap_code(KC_KP_1);
                        unicode_input_finish();
                        break;
                    default:
                        process_unicodemap(UM(EMDASH), record);
                        break;
                }
            }
            break;
#endif // UNICODE KEYCODES
        default:
            break;
    }

    // do we need to cancel window navigation before timeout?
    if (window_nav_in_progress && record->event.pressed) {
        if (QK_MODS_GET_MODS(keycode) && MOD_MASK_SHIFT) {
            window_nav_cancel = false;
        }
        switch (keycode) {
            case KC_LSFT:
            case KC_RSFT:
            case C_WNDWF:
            case C_WNDWB:
                window_nav_cancel = false;
                break;
            case KC_TAB:
                if (current_os == OS_WINDOWS) {
                    window_nav_cancel = false;
                    window_timer += 250;
                    //dprintf("extending timer: %u\n", window_timer);
                }
                break;
            case KC_L:
            case KC_H:
                if (current_os == OS_LINUX) {
                    window_nav_cancel = false;
                    window_timer += 250;
                    //dprintf("extending timer: %u\n", window_timer);
                }
                break;
            default:
                //dprintf("Canceling with %x\n", keycode);
                window_nav_cancel = true;
                break;
        }
    }
    return process_record_keymap(keycode, record);
}

/* END STANDARD QMK FUNCTIONS */

#if defined(OS_DETECTION_ENABLE)
uint32_t config_os(uint32_t trigger_time, void *cb_arg) {
    current_os = detected_host_os();
    switch (current_os) {
        case OS_UNSURE:
            return 100; // try again in 100ms
            break;
        case OS_WINDOWS:
            // avoid eeprom write, hopefully?
            // unicode_config.input_mode = UNICODE_MODE_WINDOWS;
            while (unicode_config.input_mode != UNICODE_MODE_WINDOWS) {
                unicode_input_mode_step();
            }
            break;
        default:
            // unicode_config.input_mode = UNICODE_MODE_LINUX;
            while (unicode_config.input_mode != UNICODE_MODE_LINUX) {
                unicode_input_mode_step();
            }
            break;
    }
    force_numlock();
    return 0;
}
#endif

// perpetual numlock
void force_numlock(void) {
    // REMINDER, GENIUS: THE PARENTHESES ENCLOSING THIS ENTIRE EXPRESSION ARE NECESSARY SO THE NEGATION APPLIES TO THE WHOLE THING
    if (!(host_keyboard_led_state().num_lock)) {
        tap_code(KC_NUM);
    }
}
