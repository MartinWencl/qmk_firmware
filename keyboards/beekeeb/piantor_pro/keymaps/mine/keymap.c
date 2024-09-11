// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum macro_keycodes {
    M_TASK_MANAGER = SAFE_RANGE,
    M_VSCODE,
    M_DELPHI,
    M_CHROME,
    M_EXPLORER_VYVOJ,   
    M_WT,

    M_EMAIL,

    M_SELECT_WORD,
    M_SELECT_LINE,
    M_CUT,
    M_COPY,
    M_PASTE,

    M_CLOSE_WINDOW,
    
    // Virtual Desktop
    M_VD_NEW,
    M_VD_CLOSE,
    M_VD_NEXT,
    M_VD_PREV,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case M_EMAIL: 
      if (record->event.pressed) {
        SEND_STRING("marta.wencl@gmail.com");
      }
      return false;

    case M_TASK_MANAGER: 
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_ESCAPE))));
      }
      return false;

    case M_VSCODE: 
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "Visual Studio Code" SS_DELAY(100) SS_TAP(X_ENTER));
      }
      return false;

    case M_DELPHI: 
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "Delphi 11" SS_DELAY(100) SS_TAP(X_ENTER));
      }
      return false;

    case M_CHROME: 
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_LGUI) SS_DELAY(100) "Google Chrome" SS_DELAY(100) SS_TAP(X_ENTER));
      }
      return false;

    case M_EXPLORER_VYVOJ: 
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("e") SS_DELAY(100) SS_LALT("d") SS_DELAY(100)
                   "C:\\Vyvoj\\Projekty-developer"  SS_TAP(X_ENTER));
      }
      return false;

    case M_WT: 
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("r") SS_DELAY(100) "wt" SS_DELAY(100)  SS_TAP(X_ENTER));
      }
      return false;

    case M_CLOSE_WINDOW: 
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(SS_TAP(X_F4)));
      }
      return false;

    case M_VD_NEW: 
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LCTL("d")));
      }
      return false;

    case M_VD_CLOSE: 
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_F4))));
      }
      return false;

    case M_VD_NEXT: 
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_RIGHT))));
      }
      return false;

    case M_VD_PREV: 
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_LCTL(SS_TAP(X_LEFT))));
      }
      return false;

    case M_SELECT_WORD: 
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
      }
      return false;

    case M_SELECT_LINE: 
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
      }
      return false;

    case M_CUT: 
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT("x")));
      }
      return false;

    case M_COPY: 
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("c"));
      }
      return false;

    case M_PASTE: 
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_LSFT("v")));
      }
      return false;
  }
  return true;
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_S, KC_W)) {
        // [s]elect [w]ord
        SEND_STRING(SS_LCTL(SS_TAP(X_RGHT) SS_LSFT(SS_TAP(X_LEFT))));
    } else if (leader_sequence_two_keys(KC_S, KC_L)) {
        // [s]elect [l]ine
        SEND_STRING(SS_TAP(X_HOME) SS_LSFT(SS_TAP(X_END)));
    } else if (leader_sequence_two_keys(KC_F, KC_Y)) {
        // [f]orce [y]ank - cut
        SEND_STRING(SS_LCTL(SS_LSFT("x")));
    } else if (leader_sequence_one_key(KC_Y)) {
        // [y]ank
        SEND_STRING(SS_LCTL("c"));
    } else if (leader_sequence_one_key(KC_P)) {
        // [p]aste
        SEND_STRING(SS_LCTL(SS_LSFT("v")));
    } else if (leader_sequence_two_keys(KC_W, KC_E)) {
        // [w]ork [e]mail
        SEND_STRING("martin.wencl@dek-cz.com");
    } else if (leader_sequence_two_keys(KC_P, KC_E)) {
        // [p]ersonal [e]mail
        SEND_STRING("marta.wencl@gmail.com");
    } else {
        // When no matches, default to tab
        SEND_STRING(SS_TAP(X_TAB));
    }
}

// Combos   
// macro layer - midle thumb keys
const uint16_t PROGMEM macro_combo[] = {LT(2, KC_SPC), LT(5, KC_BSPC), COMBO_END};
// text manipulation macos left midle, right inner thumb key
const uint16_t PROGMEM text_macro_combo[] = {LT(2, KC_SPC), LT(4, KC_ENTER), COMBO_END};

combo_t key_combos[] = {
    COMBO(macro_combo, OSL(7)),
    COMBO(text_macro_combo, OSL(8)),
};  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ' │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ESC├───┐           ┌───┤DEL│
      *               └───┤SPC├───┐   ┌───┤BSP├───┘
      *                   └───┤TAB│   │ENT├───┘
      *                       └───┘   └───┘
      */
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,        KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                                            KC_J,           KC_L,              KC_U,              KC_Y,              KC_QUOT,           KC_NO,
        QK_LEAD, MT(MOD_LGUI,KC_A), MT(MOD_LALT,KC_R), MT(MOD_LCTL,KC_S), MT(MOD_LSFT,KC_T), KC_G,                                                  KC_M,           MT(MOD_LSFT,KC_N), MT(MOD_LCTL,KC_E), MT(MOD_LALT,KC_I), MT(MOD_LGUI,KC_O), KC_NO,
        KC_LCTL,       KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,                                            KC_K,           KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           KC_NO,
                                                                          LT(1, KC_ESC),    LT(2, KC_SPC), LT(3, KC_TAB),                        LT(4, KC_ENTER), LT(5, KC_BSPC), LT(6, KC_DEL)
    ),

     /*  MEDIA LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │PRE│V- │V+ │NEX│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                     ┌────┐
      *               │   ├───┐            ┌────┤MUTE│
      *               └───┤   ├───┐   ┌────┤PLAY├────┘
      *                   └───┤   │   │STOP├────┘
      *                       └───┘   └────┘
      */
    [1] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_NO,   KC_NO,        KC_NO,      KC_NO,   KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                   KC_NO,   KC_MPRV, KC_VOLD,      KC_VOLU,    KC_MNXT, KC_CAPS,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END,  KC_INS,
                                          _______, KC_NO, KC_NO,   KC_MSTP, KC_MPLY, KC_MUTE
    ),

     /*  NAV LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌────┬────┬────┬────┬────┬────┐
      * │   │   │   │   │   │   │       │REDO│PAST│CUT │COPY│UNDO│    │
      * ├───┼───┼───┼───┼───┼───┤       ├────┼────┼────┼────┼────┼────┤
      * │   │GUI│ALT│CRL│SFT│   │       │CAPS│ ←  │ ↑  │ ↓  │ →  │CAPS│
      * ├───┼───┼───┼───┼───┼───┤       ├────┼────┼────┼────┼────┼────┤
      * │   │   │   │   │   │   │       │INS │HOME│PGD │PGUP│END │INS │
      * └───┴───┴───┴───┴───┴───┘       └────┴────┴────┴────┴────┴────┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤DEL│
      *               └───┤   ├───┐   ┌───┤BSP├───┘
      *                   └───┤   │   │ENT├───┘
      *                       └───┘   └───┘
      */
    [2] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_AGAIN, M_PASTE,  M_COPY,       M_CUT,      KC_UNDO,  KC_NO,
        KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                      KC_CAPS,  KC_LEFT,  KC_DOWN,      KC_UP,      KC_RIGHT, KC_CAPS,
        KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_INS,   KC_HOME,  KC_PAGE_DOWN, KC_PAGE_UP, KC_END,   KC_INS,
                                          KC_NO,   _______, KC_NO,   KC_ENTER, KC_BSPC, KC_DEL
    ),

     /*  MOUSE LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌────┬────┬────┬────┬────┬────┐
      * │   │   │   │   │   │   │       │REDO│PAST│CUT │COPY│UNDO│    │
      * ├───┼───┼───┼───┼───┼───┤       ├────┼────┼────┼────┼────┼────┤
      * │   │GUI│ALT│CRL│SFT│   │       │    │ M← │ M↑ │ M↓ │ M→ │    │
      * ├───┼───┼───┼───┼───┼───┤       ├────┼────┼────┼────┼────┼────┤
      * │   │   │   │   │   │   │       │    │    │    │    │    │    │
      * └───┴───┴───┴───┴───┴───┘       └────┴────┴────┴────┴────┴────┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤MWD│ - Mouse wheel down
      *               └───┤   ├───┐   ┌───┤ M1├───┘
      *                   └───┤   │   │ M2├───┘
      *                       └───┘   └───┘
      */
    [3] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_AGAIN, KC_PASTE,   KC_COPY,      KC_CUT,     KC_UNDO,     KC_NO,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                        KC_CAPS,    KC_MS_LEFT, KC_MS_DOWN,   KC_MS_UP,   KC_MS_RIGHT, KC_CAPS,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_INS,     KC_HOME,    KC_PAGE_DOWN, KC_PAGE_UP, KC_END,      KC_INS,
                                            KC_NO,   KC_NO, _______,   KC_MS_BTN2, KC_MS_BTN1, KC_MS_WH_DOWN
    ),

     /*  SPECIAL CHARACTERS LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ { │ & │ * │ ( │ } │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ : │ $ │ % │ ^ │ + │       │   │SFT│CRL│ALT│GUI│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ~ │ ! │ @ │ # │ | │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ ( ├───┐           ┌───┤   │
      *               └───┤ ) ├───┐   ┌───┤   ├───┘
      *                   └───┤ _ │   │   ├───┘
      *                       └───┘   └───┘
      */
    [4] = LAYOUT_split_3x6_3(
        KC_NO, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                     KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                     KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
        KC_NO, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                     KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                          KC_LPRN, KC_RPRN, KC_UNDS,   _______, KC_NO, KC_NO
    ),

     /*  NUMBERS LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ [ │ 7 │ 8 │ 9 │ ] │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ; │ 4 │ 5 │ 6 │ = │       │   │SFT│CRL│ALT│GUI│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ ` │ 1 │ 2 │ 3 │ \ │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ . ├───┐           ┌───┤   │
      *               └───┤ 0 ├───┐   ┌───┤   ├───┘
      *                   └───┤ _ │   │   ├───┘
      *                       └───┘   └───┘
      */
    [5] = LAYOUT_split_3x6_3(
        KC_NO, KC_LBRC,  KC_7, KC_8, KC_9,   KC_RBRC,                 KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_SCLN,  KC_4, KC_5, KC_6,   KC_EQL,                  KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
        KC_NO, KC_GRAVE, KC_1, KC_2, KC_3,   KC_BSLS,                 KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                     KC_DOT, KC_0, KC_MINS,    KC_NO, _______, KC_NO
    ),

     /*  FUNCTION KEYS LAYER
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │F12│F7 │F8 │F9 │   │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │F11│F4 │F5 │F6 │   │       │   │SFT│CRL│ALT│GUI│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │F10│F1 │F2 │F3 │   │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │ESC├───┐           ┌───┤   │
      *               └───┤SPC├───┐   ┌───┤   ├───┘
      *                   └───┤TAB│   │   ├───┘
      *                       └───┘   └───┘
      */
    [6] = LAYOUT_split_3x6_3(
        KC_NO, KC_F12, KC_F7, KC_F8, KC_F9,  KC_NO,                    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO, KC_F11, KC_F4, KC_F5, KC_F6,  KC_NO,                    KC_NO, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
        KC_NO, KC_F10, KC_F1, KC_F2, KC_F3,  KC_NO,                    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                     KC_ESC, KC_SPC, KC_TAB,    KC_NO, KC_NO, _______
    ),

     /*  MACROS LAYER */
    [7] = LAYOUT_split_3x6_3(
        QK_BOOT, KC_NO, KC_NO,            KC_NO,    KC_NO,    KC_NO,                       KC_NO, KC_NO, KC_NO,    KC_NO,      KC_NO, KC_NO,
        KC_NO,   KC_NO, M_EXPLORER_VYVOJ, M_WT,     KC_NO,    KC_NO,                       KC_NO, KC_NO, M_VD_NEW, M_VD_CLOSE, KC_NO, KC_NO,
        M_EMAIL, KC_NO, M_VSCODE,         M_DELPHI, M_CHROME, KC_NO,                       KC_NO, KC_NO, KC_NO,    KC_NO,      KC_NO, KC_NO,
                                          DM_PLY1,  M_TASK_MANAGER, DM_REC1,    M_VD_PREV, KC_NO, M_VD_NEXT
    ),

     /*  TEXT MACROS LAYER */
    [8] = LAYOUT_split_3x6_3(
        KC_NO, KC_NO, KC_NO, M_SELECT_LINE, KC_NO, KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, M_SELECT_WORD, KC_NO, KC_NO,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,                              KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                          M_CUT, M_COPY, M_PASTE,    KC_NO, KC_NO, KC_NO
    )
};