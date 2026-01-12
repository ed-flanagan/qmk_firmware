// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


/*
 * Convenience game pad labels
 */
#define GP_DU JS_12 // D-pad Up
#define GP_DD JS_13 // D-pad Down
#define GP_DL JS_14 // D-pad Left
#define GP_DR JS_15 // D-pad Right

#define GP_B1 JS_0 // South
#define GP_B2 JS_1 // East
#define GP_B3 JS_2 // West
#define GP_B4 JS_3 // North

#define GP_L1 JS_4
#define GP_R1 JS_5
#define GP_L2 JS_6
#define GP_R2 JS_7
#define GP_L3 JS_10
#define GP_R3 JS_11

#define GP_S1 JS_8  // Select
#define GP_S2 JS_9  // Start
#define GP_S3 JS_16 // Guide

// TODO: implement Turbo
#define TURBO KC_NO

enum layer_names {
    _PAD,
    _KEY,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_PAD] = LAYOUT(
        TURBO,   LT(_FN, KC_NO), GP_S3, GP_S1, GP_S2,

        GP_DL,   GP_DD, GP_DR, GP_DU,
        GP_B3,   GP_B4, GP_R1, GP_L1,
        GP_B1,   GP_B2, GP_R2, GP_L2,
        MS_BTN1, GP_L3, GP_R3, MS_BTN2
    ),

    [_KEY] = LAYOUT(
        _______, _______, KC_LCTL, KC_TAB, KC_ESC,

        KC_A,    KC_S,     KC_D,    KC_W,
        KC_J,    KC_K,     KC_L,    KC_SPC,
        KC_M,    KC_COMM,  KC_DOT,  KC_U,
        _______, KC_E,     KC_R,    _______
    ),

    [_FN] = LAYOUT(
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        RM_PREV, XXXXXXX, RM_NEXT, XXXXXXX,
        RM_HUEU, RM_SATU, RM_VALU, PDF(_PAD),
        RM_HUED, RM_SATD, RM_VALD, PDF(_KEY),
        XXXXXXX, XXXXXXX, RM_FLGN, EE_CLR
    ),
};

// TODO: SOCD

void keyboard_post_init_user(void) {
    debug_enable=true;
    debug_matrix=true;
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_mode(RGB_MATRIX_CUSTOM_TXKO_SOLID);
#endif
}

/*
 * Essentially emulates RM_FLGN -- so no real need, but kind of want this for
 * reference

#define LED_GROUP_0 (LED_FLAG_INDICATOR | LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER)
#define LED_GROUP_1 LED_FLAG_UNDERGLOW

// Cycle through LED "groups" instead of simply turning on/off
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (keycode == QK_RGB_MATRIX_TOGGLE && !record->event.pressed) {
        switch (rgb_matrix_get_flags()) {
            case LED_FLAG_ALL:
                rgb_matrix_set_flags(LED_GROUP_0);
                break;
            case LED_GROUP_0:
                rgb_matrix_set_flags(LED_GROUP_1);
                break;
            case LED_GROUP_1:
                rgb_matrix_set_flags(LED_FLAG_NONE);
                break;
            default:
                rgb_matrix_set_flags(LED_FLAG_ALL);
                break;
        }

        return false;
    }

    return true;
}
*/
