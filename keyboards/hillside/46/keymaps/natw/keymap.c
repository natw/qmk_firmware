// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _SYM_NUM,
    _NAV,
    _F_COMBO,
};

#define LY_NAV MO(_NAV)
#define LY_SYM MO(_SYM_NUM)

#define PLY_PAU KC_MEDIA_PLAY_PAUSE

#define NW_CTL MT(MOD_RCTL, KC_BSPC)
#define NW_LSFT MT(MOD_LSFT, S(KC_GRAVE))
#define NW_SPC LT(_NAV, KC_SPC)

#define KC_LCURL S(KC_LBRC)
#define KC_RCURL S(KC_RBRC)
#define KC_LPAREN S(KC_9)
#define KC_RPAREN S(KC_0)

#define KC_HASH S(KC_3)
#define KC_CARET S(KC_6)

#define NW_F LT(_F_COMBO, KC_F)
#define NW_J LT(_F_COMBO, KC_J)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                         KC_Y,   KC_U,     KC_I,    KC_O,    KC_P,    KC_EQUAL,
     NW_CTL,   KC_A,    KC_S,    KC_D,    NW_F,    KC_G,                                                         KC_H,   NW_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     NW_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LY_NAV,                                    CW_TOGG,  KC_N,   KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                          KC_LOPT, KC_SPC,  KC_LGUI, LY_SYM,                   LY_SYM, KC_ENTER, NW_SPC, KC_MINUS
    ),

    [_SYM_NUM] = LAYOUT(
     KC_ESC,   KC_EXLM,    KC_AT,     KC_LCURL,  KC_RCURL,  KC_PIPE,                                                   KC_CIRC, KC_7, KC_8, KC_9, KC_PAST, KC_DEL,
     _______,  KC_HASH,    KC_DOLLAR, KC_LPAREN, KC_RPAREN, KC_GRAVE,                                                  KC_HOME, KC_4, KC_5, KC_6, KC_PPLS, KC_END,
     KC_TILDE, KC_PERCENT, KC_CARET,  KC_LBRC,   KC_RBRC,   _______,  _______,                                _______, KC_AMPR, KC_1, KC_2, KC_3, KC_DOT,  KC_RCTL,
                                                 _______,   _______,  _______, KC_BACKSLASH,    KC_BACKSLASH, _______, _______, KC_0 
    ),

    [_NAV] = LAYOUT(
     KC_ESC,  _______, _______,       _______, _______, _______,                                                         KC_PGUP, _______, _______, _______,  KC_BRIU, KC_VOLU, 
     _______, _______, LOPT(KC_LEFT), _______, _______, LOPT(KC_RIGHT),                                                  KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_BRID, KC_VOLD, 
     UG_TOGG, _______, _______,       _______, _______, _______,        DT_UP  ,                                _______, KC_PGDN, KC_MPRV, PLY_PAU, KC_MNXT,  _______, KC_MUTE,
                                               _______, DT_PRNT,        DT_DOWN, KC_BACKSLASH,    KC_BACKSLASH, _______, _______, _______
    ),

    [_F_COMBO] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, KC_0, _______, _______, 
     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______, 
     _______, LCTL(KC_Z), _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
                                         _______, _______, _______, _______,    _______, _______, _______, _______
    ),
};

//  Template:
//    [_INDEX] = LAYOUT(
//     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______, 
//     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______, 
//     _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
//                                         _______, _______, _______, _______,    _______, _______, _______, _______
//    ),

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NW_F:
    case NW_J:
      return false;
    default:
      return true;
  }
}

// I like HOLD_ON_OTHER_KEY_PRESS except for home row mods
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NW_F:
    case NW_J:
      return false;
    default:
      return true;
    }
}
