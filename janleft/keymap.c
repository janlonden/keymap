#include "planck.h"
#include "../../quantum/keymap_extras/keymap_colemak.h"

#define _______ KC_TRNS

#define QUICK_PRESS 100
#define NORMAL_PRESS 150
#define SLOW_PRESS 300

#define ENT__LAYER 0
#define LOGIN 1

#define CTL_SFT_K__RALT_Q 10
#define ENT__RALT_W 11
#define CTL_SFT_D__RALT_SCLN 12
#define CTL_Q__LAYER 13
#define SFT_TAB__CTL_W 14
#define CTL_PGUP__CTL_F 15
#define CTL_BSPC__CTL_P 16
#define CTL_A__LAYER 17
#define TAB__CTL_R 18
#define CTL_PGDOWN__CTL_S 19
#define BSPC__CTL_T 20
#define CTL_Z__LAYER 21
#define CTL_X__CTL 22
#define CTL_C__SFT 23
#define CTL_V__ALT 24
#define _TILD 25

#define _DEL 30
#define ALT_TAB 31

static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = {
    {KC_ESC, CM_G, CM_D, CM_B, KC__MUTE, _______, _______, _______, KC_F10, KC_F11, KC_F12, KC_SLEP},
    {CM_Q, CM_W, CM_F, CM_P, KC__VOLUP, _______, _______, _______, KC_F7, KC_F8, KC_F9, KC_PSCREEN},
    {CM_A, CM_R, CM_S, CM_T, KC__VOLDOWN, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______},
    {CM_Z, CM_X, CM_C, CM_V, KC_SPC, MO(10), RESET, _______, KC_F1, KC_F2, KC_F3, M(LOGIN)}
  },

  [10] = {
    {M(_TILD), M(CTL_SFT_K__RALT_Q), M(ENT__RALT_W), M(CTL_SFT_D__RALT_SCLN), _______, _______, _______, _______, _______, _______, _______, _______},
    {M(CTL_Q__LAYER), M(SFT_TAB__CTL_W), M(CTL_PGUP__CTL_F), M(CTL_BSPC__CTL_P), _______, _______, _______, _______, _______, _______, _______, _______},
    {M(CTL_A__LAYER), M(TAB__CTL_R), M(CTL_PGDOWN__CTL_S), M(BSPC__CTL_T), _______, _______, _______, _______, _______, _______, _______, _______},
    {M(CTL_Z__LAYER), M(CTL_X__CTL), M(CTL_C__SFT), M(CTL_V__ALT), _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [11] = {
    {_______, _______, LCTL(CM_D), M(_DEL), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_HOME, KC_UP, KC_END, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, KC_PGUP, KC_PGDOWN, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [12] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_LEFT, LCTL(KC_UP), M(ALT_TAB), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [13] = {
    {_______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, LCTL(CM_O), LCTL(CM_N), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  }

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch(id) {
    case ENT__LAYER: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(10);
      } else {
        layer_off(10);
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_ENT);
          unregister_code(KC_ENT);
        }
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
//////////////////////////////////////////////////////////////////
    case CTL_SFT_K__RALT_Q: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          register_code(CM_K);
          unregister_code(CM_K);
          unregister_code(KC_LSFT);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_RALT);
          register_code(CM_Q);
          unregister_code(CM_Q);
          unregister_code(KC_RALT);
        }
      }
      break;
    }
    case ENT__RALT_W: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_ENT);
          unregister_code(KC_ENT);
        } else {
          register_code(KC_RALT);
          register_code(CM_W);
          unregister_code(CM_W);
          unregister_code(KC_RALT);
        }
      }
      break;
    }
    case CTL_SFT_D__RALT_SCLN: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          register_code(CM_D);
          unregister_code(CM_D);
          unregister_code(KC_LSFT);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_RALT);
          register_code(CM_SCLN);
          unregister_code(CM_SCLN);
          unregister_code(KC_RALT);
        }
      }
      break;
    }
    case CTL_Q__LAYER: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(13);
      } else {
        layer_off(13);
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_LCTL);
          register_code(CM_Q);
          unregister_code(CM_Q);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case SFT_TAB__CTL_W: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW_PRESS) {
          register_code(KC_LSFT);
          register_code(KC_TAB);
          unregister_code(KC_TAB);
          unregister_code(KC_LSFT);
        } else {
          register_code(KC_LCTL);
          register_code(CM_W);
          unregister_code(CM_W);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case CTL_PGUP__CTL_F: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW_PRESS) {
          register_code(KC_LCTL);
          register_code(KC_PGUP);
          unregister_code(KC_PGUP);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_F);
          unregister_code(CM_F);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case CTL_BSPC__CTL_P: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW_PRESS) {
          register_code(KC_LCTL);
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_P);
          unregister_code(CM_P);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case CTL_A__LAYER: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(11);
      } else {
        layer_off(11);
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_LCTL);
          register_code(CM_A);
          unregister_code(CM_A);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case TAB__CTL_R: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW_PRESS) {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        } else {
          register_code(KC_LCTL);
          register_code(CM_R);
          unregister_code(CM_R);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case CTL_PGDOWN__CTL_S: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW_PRESS) {
          register_code(KC_LCTL);
          register_code(KC_PGDOWN);
          unregister_code(KC_PGDOWN);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_S);
          unregister_code(CM_S);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case BSPC__CTL_T: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW_PRESS) {
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
        } else {
          register_code(KC_LCTL);
          register_code(CM_T);
          unregister_code(CM_T);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case CTL_Z__LAYER: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(12);
      } else {
        layer_off(12);
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_LCTL);
          register_code(CM_Z);
          unregister_code(CM_Z);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case CTL_X__CTL: {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LCTL);
      } else {
        unregister_code(KC_LCTL);
        if (timer_elapsed(key_timer) < SLOW_PRESS) {
          register_code(KC_LCTL);
          register_code(CM_X);
          unregister_code(CM_X);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case CTL_C__SFT: {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LSFT);
      } else {
        unregister_code(KC_LSFT);
        if (timer_elapsed(key_timer) < SLOW_PRESS) {
          register_code(KC_LCTL);
          register_code(CM_C);
          unregister_code(CM_C);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case CTL_V__ALT: {
      if (record->event.pressed) {
        key_timer = timer_read();
        register_code(KC_LALT);
      } else {
        unregister_code(KC_LALT);
        if (timer_elapsed(key_timer) < SLOW_PRESS) {
          register_code(KC_LCTL);
          register_code(CM_V);
          unregister_code(CM_V);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case _TILD: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
          register_code(KC_TILD);
          unregister_code(KC_TILD);
        } else {
          register_code(KC_LSFT);
          register_code(KC_TILD);
          unregister_code(KC_TILD);
          unregister_code(KC_LSFT);
        }
      }
      break;
    }
//////////////////////////////////////////////////////////////////
    case _DEL: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
          register_code(KC_DEL);
          unregister_code(KC_DEL);
        } else {
          register_code(KC_LCTL);
          register_code(KC_DEL);
          unregister_code(KC_DEL);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case ALT_TAB: {
      if (record->event.pressed) {
        return MACRO(D(LALT), D(TAB), U(TAB), END);
      }
      break;
    }
  }
  return MACRO_NONE;
};
