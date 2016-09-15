#include "planck.h"
#include "keymap_colemak.h"

#define _______ KC_TRNS

#define QUICK 125
#define NORMAL 150
#define SLOW 300

enum layers {
  COLEMAK_SOFT,
  COLEMAK_HARD,
  RABBIT_HOLE,
  MISC,
  MISC2,
  NUMBERS
};

enum macros {
  LOGIN,
  SFT__RABBIT_HOLE,
  SLSH,
  QUOT,
  MINS,
  EQL,
  _0__F1,
  DOT__F2,
  ENT__F3,
  _1__F4,
  _2__F5,
  _3__F6,
  _4__F7,
  _5__F8,
  _6__F9,
  _7__F10,
  _8__F11,
  _9__F12
};

static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [COLEMAK_SOFT] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_COMM, M(SFT__RABBIT_HOLE), KC_DOT, KC_ENT},
    {_______, _______, _______, _______, _______, _______, _______, _______, CM_L, CM_U, CM_Y, MO(MISC)},
    {TG(COLEMAK_HARD), _______, _______, _______, _______, _______, _______, _______, CM_N, CM_E, CM_I, CM_O},
    {M(LOGIN), _______, _______, _______, _______, _______, TG(NUMBERS), KC_SPC, CM_H, CM_K, CM_M, CM_J}
  },

  [COLEMAK_HARD] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_L, KC_U, KC_Y, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_N, KC_E, KC_I, KC_O},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_H, KC_K, KC_M, KC_J}
  },

  [RABBIT_HOLE] = {
    {RESET, _______, _______, _______, _______, _______, _______, _______, M(SLSH), _______, M(EQL), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, M(QUOT), _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, M(MINS), _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, MO(MISC2), _______, _______, _______, _______}
  },

  [MISC] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_LCTL, KC_RSFT, KC_LALT, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, CM_SCLN, KC_SCLN, KC_GRV, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, S(KC_1), _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, KC_RALT, KC_LGUI, _______, _______, _______}
  },

  [MISC2] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [NUMBERS] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, M(_7__F10), M(_8__F11), M(_9__F12), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, M(_4__F7), M(_5__F8), M(_6__F9), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, M(_1__F4), M(_2__F5), M(_3__F6), KC_BSPC},
    {_______, _______, _______, _______, _______, _______, TG(NUMBERS), _______, M(_0__F1), M(DOT__F2), M(ENT__F3), _______}
  }

  // [] = {
  //   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  //   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  //   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  //   {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  // },

};

const uint16_t PROGMEM fn_actions[] = {};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
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
    case SFT__RABBIT_HOLE: {
      if (record->event.pressed) {
        register_code(KC_RSFT);
        layer_on(RABBIT_HOLE);
      } else {
        unregister_code(KC_RSFT);
        layer_off(RABBIT_HOLE);
      }
      break;
    }
    case SLSH: {
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_SLSH);
        unregister_code(KC_SLSH);
      }
      break;
    }
    case QUOT: {
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_QUOT);
        unregister_code(KC_QUOT);
      }
      break;
    }
    case MINS: {
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_MINS);
        unregister_code(KC_MINS);
      }
      break;
    }
    case EQL: {
      if (record->event.pressed) {
        unregister_code(KC_RSFT);
        register_code(KC_EQL);
        unregister_code(KC_EQL);
      }
      break;
    }
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
          layer_off(NUMBERS);
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
          layer_off(NUMBERS);
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
          layer_off(NUMBERS);
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
          layer_off(NUMBERS);
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
          layer_off(NUMBERS);
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
          layer_off(NUMBERS);
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
          layer_off(NUMBERS);
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
          layer_off(NUMBERS);
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
