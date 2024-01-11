// Copyright 2023 Johan Aulin
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   Ö  |   Ä  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  <   | Alt  |Lower |    Space    |Raise |AltGr | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,           KC_E,    KC_R,       KC_T,   KC_Y,   KC_U,       KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,           KC_D,    KC_F,       KC_G,   KC_H,   KC_J,       KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,           KC_C,    KC_V,       KC_B,   KC_N,   KC_M,       KC_COMM, KC_DOT,  KC_UP,   SC_SENT,
    KC_LCTL, KC_LGUI, MEH_T(KC_NUBS), KC_LALT, MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  '   |   !  |   "  |   #  |   $  |   %  |   &  |   /  |   (  |   )  |   =  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   \  |   {  |   }  |   ¨  |   +  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  F7  |  F8  |  F9  | F10  | F11  | F12  |   -  |   [  |   ]  |  ´   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  <   | Alt  |Lower |    Numpad   |Adjust|AltGr | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    KC_BSLS, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), RALT(KC_4), LSFT(KC_5),  LSFT(KC_6),  LSFT(KC_7),    LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), KC_TRNS,
    KC_DEL,  KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,       KC_F6,       RALT(KC_MINS), RALT(KC_7), RALT(KC_0), KC_SCLN,    KC_MINS,
    KC_TRNS, KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,      KC_F12,      KC_SLSH,       RALT(KC_8), RALT(KC_9), KC_EQL,     KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    TO(_NUMPAD), TO(_NUMPAD), MO(_ADJUST),   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  ~   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |Print |ScrLk |      |      |      |      |      | Home | PgUp |   Ö  |   Å  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|Pause |AuShTg|CapsLk|      |      |      |   -  |  End | PgDn |VolUp |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  <   | Alt  |Adjust|    Space    |Raise |AltGr | Next |VolDn | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    RALT(KC_RBRC), KC_1,    KC_2,    KC_3,    KC_4,        KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_DEL,        KC_PSCR, KC_SCRL, KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_HOME, KC_PGUP, KC_TRNS, KC_LBRC,
    KC_TRNS,       KC_PAUS, AS_TOGG, KC_CAPS, KC_NO,       KC_NO,   KC_NO,   KC_SLSH, KC_END,  KC_PGDN, KC_VOLU, KC_TRNS,
    KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, MO(_ADJUST), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_MPLY
),

/* Adjust
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |RGBMDn|RGBMUp|      |RGBTog|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Reset|      |      |      |      |      |      |      |BriDn |BriUp |      |Reset |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |EEPROM|      |      |      |      |      |      |      |HueDn |HueUp |      |EEPROM|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |      |EffDn |EffUp |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, RGB_RMOD, RGB_MOD, KC_NO, RGB_TOG,
    QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, RGB_VAD,  RGB_VAI, KC_NO, QK_BOOT,
    EE_CLR,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, RGB_HUD,  RGB_HUI, KC_NO, EE_CLR,
    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, RGB_SPD,  RGB_SPI, KC_NO, KC_NO
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |Qwerty|      |      |      |      |      |      |   7  |   8  |   9  |   -  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   +  |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |    Space    |   0  |   .  | Left |   *  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_4x12(
    TO(_QWERTY), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_P7, KC_P8,  KC_P9,   KC_PMNS, KC_BSPC,
    KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_P4, KC_P5,  KC_P6,   KC_PPLS, LSFT(KC_0),
    KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NUM,  KC_P1, KC_P2,  KC_P3,   KC_PSLS, KC_ENT,
    KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_P0, KC_DOT, KC_LEFT, KC_PAST, KC_RGHT
)

};





