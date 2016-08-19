#include "planck.h"
#include "../../quantum/keymap_extras/keymap_colemak.h"

#define _______ KC_TRNS

// SPEEDS
#define QUICK 125
#define NORMAL 150
#define SLOW 300

// LAYERS
#define COLEMAK_SOFT 0
#define COLEMAK_HARD 1
#define NUMBERS 2
#define RABBIT_HOLE 3
#define MISC1 4
#define MISC2 5

// COLEMAK_SOFT
#define LOGIN 20

// MISC1
#define CTL__LBRC 30
#define SFT__RBRC 31
#define ALT__BSLS 32

// NUMBERS
#define _0__F1 0
#define DOT__F2 1
#define ENT__F3 2
#define _1__F4 3
#define _2__F5 4
#define _3__F6 5
#define _4__F7 6
#define _5__F8 7
#define _6__F9 8
#define _7__F10 9
#define _8__F11 10
#define _9__F12 11

static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [COLEMAK_SOFT] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT, KC_SLSH, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, CM_L, CM_U, CM_Y, CM_SCLN},
    {TG(COLEMAK_HARD), _______, _______, _______, _______, _______, _______, _______, CM_N, CM_E, CM_I, CM_O},
    {M(LOGIN), _______, _______, _______, _______, _______, MO(RABBIT_HOLE), KC_LSFT, CM_H, CM_K, CM_M, CM_J}
  },

  [COLEMAK_HARD] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_L, KC_U, KC_Y, KC_SCLN},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_N, KC_E, KC_I, KC_O},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_H, KC_K, KC_M, KC_J}
  },

  [RABBIT_HOLE] = {
    {RESET, _______, _______, _______, _______, _______, _______, _______, S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT, KC_MINS, KC_EQL, MO(MISC1)},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, S(KC_1), MO(MISC2)},
    {_______, _______, _______, _______, _______, _______, _______, _______, TG(NUMBERS), _______, KC_ENT, _______}
  },

  [MISC1] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, M(CTL__LBRC), M(SFT__RBRC), M(ALT__BSLS), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_GRV, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, KC_RALT, KC_LGUI, _______, _______, _______, _______}
  },

  [MISC2] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, S(KC_QUOT), S(KC_MINS), S(KC_EQL), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [NUMBERS] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, M(_7__F10), M(_8__F11), M(_9__F12), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, M(_4__F7), M(_5__F8), M(_6__F9), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, M(_1__F4), M(_2__F5), M(_3__F6), KC_BSPC},
    {_______, _______, _______, _______, _______, _______, _______, TG(NUMBERS), M(_0__F1), M(DOT__F2), M(ENT__F3), _______}
  }

  // [] = {
  //   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  //   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  //   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  //   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  // },

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
// COLEMAK_SOFT//////////////////////////////////////////////////////
    case LOGIN: {
      if (record->event.pressed) {
        register_code(CM_A);
        unregister_code(CM_A);
        register_code(CM_R);
        unregister_code(CM_R);
        register_code(CM_S);
        unregister_code(CM_S);
        register_code(CM_T);
        unregister_code(CM_T);
        register_code(KC_ENT);
        unregister_code(KC_ENT);
      }
      break;
    }
// MISC1 //////////////////////////////////////////////////////
    case CTL__LBRC: {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LBRC);
          unregister_code(KC_LBRC);
        }
      }
      break;
    }
    case SFT__RBRC: {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_RBRC);
          unregister_code(KC_RBRC);
        }
      }
      break;
    }
    case ALT__BSLS: {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_BSLS);
          unregister_code(KC_BSLS);
        }
      }
      break;
    }
// NUMBERS //////////////////////////////////////////////////////
    case _0__F1: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_0);
          unregister_code(KC_0);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_off(NUMBERS);
          register_code(KC_0);
          unregister_code(KC_0);
        } else {
          layer_off(NUMBERS);
          register_code(KC_F1);
          unregister_code(KC_F1);
        }
      }
      break;
    }
    case DOT__F2: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_DOT);
          unregister_code(KC_DOT);
        } else {
          layer_off(NUMBERS);
          register_code(KC_F2);
          unregister_code(KC_F2);
        }
      }
      break;
    }
    case ENT__F3: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_ENT);
          unregister_code(KC_ENT);
        } else {
          layer_off(NUMBERS);
          register_code(KC_F3);
          unregister_code(KC_F3);
        }
      }
      break;
    }
    case _1__F4: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_1);
          unregister_code(KC_1);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_off(NUMBERS);
          register_code(KC_1);
          unregister_code(KC_1);
        } else {
          register_code(KC_F4);
          unregister_code(KC_F4);
        }
      }
      break;
    }
    case _2__F5: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_2);
          unregister_code(KC_2);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_off(NUMBERS);
          register_code(KC_2);
          unregister_code(KC_2);
        } else {
          register_code(KC_F5);
          unregister_code(KC_F5);
        }
      }
      break;
    }
    case _3__F6: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_3);
          unregister_code(KC_3);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_off(NUMBERS);
          register_code(KC_3);
          unregister_code(KC_3);
        } else {
          register_code(KC_F6);
          unregister_code(KC_F6);
        }
      }
      break;
    }
    case _4__F7: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_4);
          unregister_code(KC_4);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_off(NUMBERS);
          register_code(KC_4);
          unregister_code(KC_4);
        } else {
          register_code(KC_F7);
          unregister_code(KC_F7);
        }
      }
      break;
    }
    case _5__F8: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_5);
          unregister_code(KC_5);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_off(NUMBERS);
          register_code(KC_5);
          unregister_code(KC_5);
        } else {
          register_code(KC_F8);
          unregister_code(KC_F8);
        }
      }
      break;
    }
    case _6__F9: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_6);
          unregister_code(KC_6);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_off(NUMBERS);
          register_code(KC_6);
          unregister_code(KC_6);
        } else {
          register_code(KC_F9);
          unregister_code(KC_F9);
        }
      }
      break;
    }
    case _7__F10: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_7);
          unregister_code(KC_7);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_off(NUMBERS);
          register_code(KC_7);
          unregister_code(KC_7);
        } else {
          register_code(KC_F10);
          unregister_code(KC_F10);
        }
      }
      break;
    }
    case _8__F11: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_8);
          unregister_code(KC_8);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_off(NUMBERS);
          register_code(KC_8);
          unregister_code(KC_8);
        } else {
          register_code(KC_F11);
          unregister_code(KC_F11);
        }
      }
      break;
    }
    case _9__F12: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_9);
          unregister_code(KC_9);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_off(NUMBERS);
          register_code(KC_9);
          unregister_code(KC_9);
        } else {
          layer_off(NUMBERS);
          register_code(KC_F12);
          unregister_code(KC_F12);
        }
      }
      break;
    }
  }
  return MACRO_NONE;
};
