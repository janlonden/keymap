#include "planck.h"
#include "../../quantum/keymap_extras/keymap_colemak.h"

#define _______ KC_TRNS

#define QUICK_PRESS 100
#define NORMAL_PRESS 150
#define SLOW_PRESS 300

// layer 0
#define LOGIN 10
#define LAYER11__SFT 11

// layer 10
#define _LBRC 30
#define _RBRC 31
#define _BSLS 32
#define _QUOT 33
#define _LPRN 34
#define _RPRN 35
#define _MINS 36
#define _EQL 37
#define _LSFT 38
#define _LCTL 39
#define _RALT 40
#define OPEN_LAYER11 41

// layer 11
#define CLOSE_LAYER11 50

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
    {_______, _______, _______, _______, _______, _______, _______, _______, M(_LPRN), M(_RPRN), M(_QUOT), S(KC_1)},
    {_______, _______, _______, _______, _______, _______, _______, _______, M(_MINS), M(_EQL), RALT(CM_E), M(OPEN_LAYER11)},
    {_______, _______, _______, _______, _______, RESET, _______, _______, _______, KC_LSFT, KC_LCTL, KC_RALT}
  },

  [11] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, M(7), M(8), M(9), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, M(4), M(5), M(6), _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, M(1), M(2), M(3), M(CLOSE_LAYER11)},
    {_______, _______, _______, _______, _______, _______, _______, M(0), KC_DOT, KC_ENT, _______, _______}
  }

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
// layer 0 //////////////////////////////////////////////////////
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
    case LAYER11__SFT: {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          layer_on(11);
        }
      }
      break;
    }
// layer 10 //////////////////////////////////////////////////////
    case _LBRC: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
    case _LPRN: {
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_9);
        unregister_code(KC_9);
        unregister_code(KC_LSFT);
      } else {
      }
      break;
    }
    case _RPRN: {
      if (record->event.pressed) {
        register_code(KC_LSFT);
        register_code(KC_0);
        unregister_code(KC_0);
        unregister_code(KC_LSFT);
      } else {
      }
      break;
    }
    case _MINS: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
    case OPEN_LAYER11: {
      if (record->event.pressed) {
        layer_on(11);
      }
      break;
    }
// layer 11 //////////////////////////////////////////////////////
    case 0: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
    case CLOSE_LAYER11: {
      if (record->event.pressed) {
        layer_off(11);
      }
      break;
    }
  }
  return MACRO_NONE;
};
