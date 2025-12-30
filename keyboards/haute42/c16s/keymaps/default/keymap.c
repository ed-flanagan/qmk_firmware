// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     *                            o o o o o
     *
     *     ┌───┬───┬───┐    ┌───┬───┬───┐
     * ┌───┤ A │ S │ D ├────┤ J │ K │ L ├───┐
     * │ E ├───┴───┴───┤ M2 ├───┼───┼───┤ R │
     * └───┘           └────┤ M │ , │ . ├───┘
     *                      └───┴───┴───┘
     *         ┌───┐             ┌───┐
     *         │Spc├───┐    ┌────┤ U │
     *         └───┤ W │    │ M1 ├───┘
     *             └───┘    └────┘
     */

    /*
     *                            0 1 2 3 4
     *
     *     ┌───┬───┬───┐    ┌───┬───┬───┐
     * ┌───┤ 5 │ 6 │ 7 ├────┤ 9 │ 10│ 11├───┐
     * │ 18├───┴───┴───┤ 20 ├───┼───┼───┤ 19│
     * └───┘           └────┤ 13│ 14│ 15├───┘
     *                      └───┴───┴───┘
     *         ┌───┐             ┌───┐
     *         │ 12├───┐    ┌────┤ 16│
     *         └───┤ 8 │    │ 17 ├───┘
     *             └───┘    └────┘
     */
    [0] = LAYOUT(
        KC_NO,   LT(1, KC_NO),    KC_NO, KC_NO,  KC_NO,

        KC_A,    KC_S,    KC_D,   KC_W,
        KC_J,    KC_K,    KC_L,   KC_SPC,
        KC_M,    KC_COMM, KC_DOT, KC_U,
        MS_BTN1, KC_E,    KC_R,   MS_BTN2
    ),
    [1] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______,

        _______, _______, _______, _______,
        RM_NEXT, RM_SPDU, RM_HUEU, _______,
        RM_PREV, RM_SPDD, RM_HUED, _______,
        _______, _______, RM_TOGG, EE_CLR
    ),
};

