// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY = 0,
    _SYM_NUM,
    _NAV,
};

/*#define xxxxxxx KC_NO*/

#define LY_NAV MO(_NAV)
#define LY_SYM MO(_SYM_NUM)

/*#define LY_ADJ MO(_ADJUST)*/
/*#define ALT_GR OSM(MOD_RALT)*/
/*#define OSM_SFT OSM(MOD_LSFT)*/
#define PLY_PAU  KC_MEDIA_PLAY_PAUSE

#define NW_CTL MT(MOD_RCTL, KC_BSPC)
#define KC_LCURL S(KC_LBRC)
#define KC_RCURL S(KC_RBRC)
#define KC_LPAREN S(KC_9)
#define KC_RPAREN S(KC_0)

#define KC_HASH S(KC_3)
#define KC_CARET S(KC_6)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                           KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_EQUAL,
     NW_CTL,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                           KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ESC,                                      CW_TOGG,  KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                          KC_LOPT, KC_SPC,  KC_LGUI, LY_SYM,                     LY_NAV, KC_ENTER, KC_SPC, KC_MINUS
    ),
    /*[_NAV] = LAYOUT(*/
    /* COPY   , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,*/
    /* CUT    , KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, PASTE  ,                                        KC_PGUP, KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_PGDN,*/
    /* _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , xxxxxxx,                      xxxxxxx, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_RCTL,*/
    /*                                     _______, _______, _______, _______,    LY_ADJ , _______, _______, _______*/
    /*),*/
    [_SYM_NUM] = LAYOUT(
     _______, KC_EXLM,    KC_AT,     KC_LCURL,  KC_RCURL,  KC_PIPE,                                                KC_CIRC, KC_7, KC_8, KC_9, KC_RPRN, KC_DEL,
     _______, KC_HASH,    KC_DOLLAR, KC_LPAREN, KC_RPAREN, KC_GRAVE,                                               KC_HOME, KC_4, KC_5, KC_6, KC_PPLS, KC_END,
     _______, KC_PERCENT, KC_CARET,  KC_LBRC,   KC_RBRC,   _______,  _______,                             _______, KC_AMPR, KC_1, KC_2, KC_3, _______, KC_RCTL,
                                                _______,   _______,  _______, _______,      KC_BACKSLASH, _______, _______, KC_0 
    ),
    [_NAV] = LAYOUT(
     KC_ESC,  KC_EXLM,    KC_AT,     KC_LCURL,  KC_RCURL,  KC_PIPE,                                                     KC_PGUP, _______, _______, _______,  KC_BRIU, KC_VOLU, 
     _______, KC_HASH,    KC_DOLLAR, KC_LPAREN, KC_RPAREN, KC_GRAVE,                                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_BRID, KC_VOLD, 
     _______, KC_PERCENT, KC_CARET,  KC_LBRC,   KC_RBRC,   _______,  _______,                                   _______, KC_PGUP, KC_MPRV, PLY_PAU, KC_MNXT,  _______, _______,
                                                _______,   _______,  _______, KC_BACKSLASH,            _______, _______, _______, _______
    ),
    /*[_ADJUST] = LAYOUT(*/
    /* xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, AG_SWAP, CG_SWAP,                                        xxxxxxx, KC_F11 , KC_F12 , KC_PSCR, xxxxxxx, EE_CLR,*/
    /* xxxxxxx, xxxxxxx, KC_BRID, KC_BRIU, AG_NORM, CG_NORM,                                        RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, xxxxxxx, xxxxxxx, */
    /* xxxxxxx, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, xxxxxxx, xxxxxxx,                     RGB_TOG, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, xxxxxxx, QK_BOOT,*/
    /*                                     xxxxxxx, xxxxxxx, xxxxxxx, _______,    _______, xxxxxxx, xxxxxxx, xxxxxxx*/
    /*),*/
};

//  Template:
//    [_INDEX] = LAYOUT(
//     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______, 
//     _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______, 
//     _______, _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______,
//                                         _______, _______, _______, _______,    _______, _______, _______, _______
//    ),
