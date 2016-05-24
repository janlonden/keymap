#include "planck.h"
#include "../../quantum/keymap_extras/keymap_colemak.h"

#define _______ KC_TRNS

#define NORMAL 150
#define SLOW 300

// layer 0
#define OPEN_LAYER12 10
#define LOGIN 11

// layer 10
#define _LBRC 20
#define _RBRC 21
#define _BSLS 22
#define _QUOT 23
#define _MINS 26
#define _EQL 27

// layer 11
#define LPRN_1 31
#define RPRN_E 32

// layer 12
#define CLOSE_LAYER12 40

static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_DOT, KC_SLSH, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, CM_L, CM_U, CM_Y, CM_SCLN},
    {_______, _______, _______, _______, _______, _______, _______, _______, CM_N, CM_E, CM_I, CM_O},
    {M(LOGIN), _______, _______, _______, _______, _______, MO(10), KC_LSFT, CM_M, CM_J, CM_K, CM_H}
  },

  [10] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, M(_LBRC), M(_RBRC), M(_BSLS), _______},
    {_______, _______, _______, _______, _______, _______, _______, M(OPEN_LAYER12), M(_QUOT), M(_MINS), M(_EQL), MO(11)},
    {_______, _______, _______, _______, _______, _______, _______, OSL(13), _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [11] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_LCTL, KC_LSFT, KC_LALT, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_RALT, M(LPRN_1), M(RPRN_E), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, KC_LGUI, KC_ENT, _______, _______, _______, _______}
  },

  [12] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, M(7), M(8), M(9), _______},
    {_______, _______, _______, _______, _______, _______, _______, M(CLOSE_LAYER12), M(4), M(5), M(6), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, M(1), M(2), M(3), KC_ENT},
    {_______, _______, _______, _______, _______, _______, KC_BSPC, M(0), KC_DOT, _______, _______, _______}
  },

  [13] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F11, KC_F12, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______},
    {_______, _______, _______, _______, _______, _______, RESET, _______, KC_F1, KC_F2, KC_F3, _______}
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
// layer 0 //////////////////////////////////////////////////////
    case OPEN_LAYER12: {
      if (record->event.pressed) {
        layer_on(12);
      }
      break;
    }
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
// layer 10 //////////////////////////////////////////////////////
    case _LBRC: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LSFT);
          register_code(KC_LBRC);
          unregister_code(KC_LBRC);
          unregister_code(KC_LSFT);
        } else {
          register_code(KC_LBRC);
          unregister_code(KC_LBRC);
        }
      }
      break;
    }
    case _RBRC: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LSFT);
          register_code(KC_RBRC);
          unregister_code(KC_RBRC);
          unregister_code(KC_LSFT);
        } else {
          register_code(KC_RBRC);
          unregister_code(KC_RBRC);
        }
      }
      break;
    }
    case _BSLS: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LSFT);
          register_code(KC_BSLS);
          unregister_code(KC_BSLS);
          unregister_code(KC_LSFT);
        } else {
          register_code(KC_BSLS);
          unregister_code(KC_BSLS);
        }
      }
      break;
    }
    case _QUOT: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
        } else {
          register_code(KC_LSFT);
          register_code(KC_QUOT);
          unregister_code(KC_QUOT);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case _MINS: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_MINS);
          unregister_code(KC_MINS);
        } else {
          register_code(KC_LSFT);
          register_code(KC_MINS);
          unregister_code(KC_MINS);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case _EQL: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_EQL);
          unregister_code(KC_EQL);
        } else {
          register_code(KC_LSFT);
          register_code(KC_EQL);
          unregister_code(KC_EQL);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
// layer 11 //////////////////////////////////////////////////////
    case LPRN_1: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LSFT);
          register_code(KC_9);
          unregister_code(KC_9);
          unregister_code(KC_LSFT);
        } else {
          register_code(KC_LSFT);
          register_code(KC_1);
          unregister_code(KC_1);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case RPRN_E: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LSFT);
          register_code(KC_0);
          unregister_code(KC_0);
          unregister_code(KC_LSFT);
        } else {
          register_code(KC_RALT);
          register_code(CM_E);
          unregister_code(CM_E);
          unregister_code(KC_RALT);
        }
      }
      break;
    }
// layer 12 //////////////////////////////////////////////////////
    case 0: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_0);
          unregister_code(KC_0);
        } else {
          register_code(KC_LSFT);
          register_code(KC_0);
          unregister_code(KC_0);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case 1: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_1);
          unregister_code(KC_1);
        } else {
          register_code(KC_LSFT);
          register_code(KC_1);
          unregister_code(KC_1);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case 2: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_2);
          unregister_code(KC_2);
        } else {
          register_code(KC_LSFT);
          register_code(KC_2);
          unregister_code(KC_2);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case 3: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_3);
          unregister_code(KC_3);
        } else {
          register_code(KC_LSFT);
          register_code(KC_3);
          unregister_code(KC_3);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case 4: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_4);
          unregister_code(KC_4);
        } else {
          register_code(KC_LSFT);
          register_code(KC_4);
          unregister_code(KC_4);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case 5: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_5);
          unregister_code(KC_5);
        } else {
          register_code(KC_LSFT);
          register_code(KC_5);
          unregister_code(KC_5);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case 6: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_6);
          unregister_code(KC_6);
        } else {
          register_code(KC_LSFT);
          register_code(KC_6);
          unregister_code(KC_6);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case 7: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_7);
          unregister_code(KC_7);
        } else {
          register_code(KC_LSFT);
          register_code(KC_7);
          unregister_code(KC_7);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case 8: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_8);
          unregister_code(KC_8);
        } else {
          register_code(KC_LSFT);
          register_code(KC_8);
          unregister_code(KC_8);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case 9: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_9);
          unregister_code(KC_9);
        } else {
          register_code(KC_LSFT);
          register_code(KC_9);
          unregister_code(KC_9);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
    case CLOSE_LAYER12: {
      if (record->event.pressed) {
        layer_off(12);
      }
      break;
    }
  }
  return MACRO_NONE;
};
