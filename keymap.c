#include QMK_KEYBOARD_H
#include "phongnh.h"

enum ergotravel_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};

// Tri Layers
// #ifdef TRI_LAYER_LOWER_LAYER
// #undef TRI_LAYER_LOWER_LAYER
// #endif
// #define TRI_LAYER_LOWER_LAYER _LOWER

// #ifdef TRI_LAYER_UPPER_LAYER
// #undef TRI_LAYER_UPPER_LAYER
// #endif
// #define TRI_LAYER_UPPER_LAYER  _RAISE

// #ifdef TRI_LAYER_ADJUST_LAYER
// #undef TRI_LAYER_ADJUST_LAYER
// #endif
// #define TRI_LAYER_ADJUST_LAYER _ADJUST

#define LOWER   TL_LOWR
#define RAISE   TL_UPPR
#define LWR_EQL LT(_LOWER, KC_EQL)      // Turn on _LOWER layer when held, = when tapped
#define RSE_MIN LT(_RAISE, KC_MINS)     // Turn on _RAISE layer when held, = when tapped
#define MOU_SCL LT(_MOUSE, KC_SCLN)     // Turn on _MOUSE layer when held, ; when tapped
#define CTL_ESC LCTL_T(KC_ESC)          // Left CTRL when held, Esc when tapped
#define CTL_Z   LCTL_T(KC_Z)            // Left CTRL when held, z when tapped
#define CTL_SLS RCTL_T(KC_SLSH)         // Right CTRL when held, / when tapped
#define CTL_GRV LCTL_T(KC_GRV)          // Left CTRL when held, ` when tapped
#define CTL_DEL LCTL_T(KC_DEL)          // Left CTRL when held, Delete when tapped
#define GUI_LBR LGUI_T(KC_LBRC)         // Left GUI when held, [ when tapped
#define ALT_RBR LALT_T(KC_RBRC)         // Left ALT when held, ] when tapped
#define ALT_BSP LALT_T(KC_BSPC)         // Left ALT when held, Backspace when tapped
#define ALT_QUO LALT_T(KC_QUOT)         // Left ALT when held, ' when tapped
#define ALT_F11 LALT_T(KC_F11)          // Left ALT when held, F11 when tapped
#define ALT_MIN RALT_T(KC_MINS)         // Right ALT when held, - when tapped
#define SFT_ENT RSFT_T(KC_ENT)          // Right SHIFT when held, Enter when tapped
#define SFT_PPL RSFT_T(KC_PPLS)         // Right SHIFT when held, + when tapped
#define SFT_F12 RSFT_T(KC_F12)          // Right SHIFT when held, F12 when tapped
#define SFT_LEF RSFT_T(KC_LEFT)         // Right SHIFT when held, Left when tapped
#define RGB_RMO RGB_RMOD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
#if defined(SWAP_MINUS_AND_EQUAL)
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_EQL,      KC_MINS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
#else
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,     KC_EQL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
#endif
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,     KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    MOU_SCL, ALT_QUO,
        KC_LSFT, CTL_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,      KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_SLS, SFT_ENT,
        KC_LCTL, GUI_LBR, ALT_RBR, KC_LSFT,      LWR_EQL,     KC_SPC,      KC_ENT,      RSE_MIN,      SFT_LEF, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_LOWER] = LAYOUT(
#if defined(ATREUS44_ARROW_STYLE)
        KC_TILD, KC_EXLM, KC_AT,   KC_UP,   KC_DLR,  KC_PERC, KC_HOME,     KC_PGUP, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        CTL_DEL, KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN, KC_END,      KC_PGDN, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ALT_F11,
        _______, KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  SFT_F12,
        _______, _______, _______, _______,      _______,     _______,     ALT_BSP,     _______,      _______, _______, _______, _______
#else
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_HOME,     KC_PGUP, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
        CTL_DEL, KC_LPRN, KC_LEFT, KC_UP,   KC_RGHT, KC_RPRN, KC_END,      KC_PGDN, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   ALT_F11,
        _______, KC_LBRC, KC_RBRC, KC_DOWN, KC_LCBR, KC_RCBR, _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  SFT_F12,
        _______, _______, _______, _______,      _______,     _______,     ALT_BSP,     _______,      _______, _______, _______, _______
#endif
    ),

    [_RAISE] = LAYOUT(
#if defined(ATREUS44_ARROW_STYLE)
        KC_GRV,  KC_1,    KC_2,    KC_UP,   KC_4,    KC_5,    KC_HOME,     KC_PGUP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        CTL_DEL, KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN, KC_END,      KC_PGDN, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_PSLS, ALT_MIN,
        _______, KC_LBRC, KC_RBRC, KC_3,    KC_LCBR, KC_RCBR, _______,     _______, KC_PDOT, KC_1,    KC_2,    KC_3,    KC_PAST, SFT_PPL,
        _______, _______, _______, _______,      _______,     ALT_BSP,     _______,     _______,      KC_PDOT, KC_0,    KC_PEQL, KC_PENT
#else
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_HOME,     KC_PGUP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        CTL_DEL, KC_LPRN, KC_LEFT, KC_UP,   KC_RGHT, KC_RPRN, KC_END,      KC_PGDN, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_PSLS, ALT_MIN,
        _______, KC_LBRC, KC_RBRC, KC_DOWN, KC_LCBR, KC_RCBR, _______,     _______, KC_PDOT, KC_1,    KC_2,    KC_3,    KC_PAST, SFT_PPL,
        _______, _______, _______, _______,      _______,     ALT_BSP,     _______,     _______,      KC_PDOT, KC_0,    KC_PEQL, KC_PENT
#endif
    ),

    [_ADJUST] = LAYOUT(
        QK_BOOT, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, AG_NORM,     AG_SWAP, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,
        RGB_TOG, RGB_VAI, RGB_SAI, RGB_HUI, RGB_SPI, RGB_MOD, KC_BRID,     KC_BRIU, XXXXXXX, XXXXXXX, CPY_SCR, CPY_WIN, CPY_SEL, KC_VOLU,
        RGB_RST, RGB_VAD, RGB_SAD, RGB_HUD, RGB_SPD, RGB_RMO, EE_CLR,      VRSN,    XXXXXXX, XXXXXXX, PRT_SCR, PRT_WIN, PRT_SEL, CW_TOGG,
        _______, _______, _______, _______,      _______,     _______,     _______,     _______,      _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
        QK_BOOT, XXXXXXX, KC_BTN3, KC_MS_U, KC_BTN2, XXXXXXX, AG_NORM,     AG_SWAP, XXXXXXX, KC_BTN2, KC_WH_U, KC_BTN3, XXXXXXX, XXXXXXX,
        KC_CAPS, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BRID,     KC_BRIU, KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______, XXXXXXX,
        EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN4, XXXXXXX,     XXXXXXX, KC_BTN5, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______, _______, _______,      KC_BTN4,     KC_BTN1,     KC_BTN2,     KC_BTN5,      _______, _______, _______, _______
    ),

    // [_SAMPLE] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______,      _______,     _______,     _______,     _______,      _______, _______, _______, _______
    // ),
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
