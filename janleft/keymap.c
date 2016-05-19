#include "planck.h"
#include "../../quantum/keymap_extras/keymap_colemak.h"

#define _______ KC_TRNS

#define QUICK_PRESS 100
#define NORMAL_PRESS 150
#define SLOW_PRESS 300

// layer 0
#define LOGIN 40

// layer 10
#define SFT_TAB__RALT_Q 10
#define ENT__RALT_W 11
#define TAB__RALT_SCLN 12
#define TILD__LAYER11 13
#define KC_HOME__CTL_R 14
#define KC_END__CTL_S 15
#define BSPC__LAYER12 16
#define CTL_BSPC__LAYER13 17
#define CTL_X__CTL 18
#define CTL_C__SFT 19
#define CTL_V__ALT 20

// layer 12
#define _DEL 50
#define ALT_TAB 51

// layer 13
#define CTL_W__CTL_Q 60
#define CTL_PGUP__CTL_F 61
#define CTL_PGDOWN__CTL_P 62
#define CTL_SFT_K__CTL_A 63
#define CTL_SFT_D__CTL_T 64

static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = {
    {KC_ESC, CM_G, CM_D, CM_B, KC__MUTE, _______, _______, _______, KC_F10, KC_F11, KC_F12, KC_SLEP},
    {CM_Q, CM_W, CM_F, CM_P, KC__VOLUP, _______, _______, _______, KC_F7, KC_F8, KC_F9, KC_PSCREEN},
    {CM_A, CM_R, CM_S, CM_T, KC__VOLDOWN, _______, _______, _______, KC_F4, KC_F5, KC_F6, _______},
    {CM_Z, CM_X, CM_C, CM_V, KC_SPC, MO(10), MO(14), _______, KC_F1, KC_F2, KC_F3, M(LOGIN)}
  },

  [10] = {
    {_______, M(SFT_TAB__RALT_Q), M(ENT__RALT_W), M(TAB__RALT_SCLN), _______, _______, _______, _______, _______, _______, _______, _______},
    {M(TILD__LAYER11), M(KC_HOME__CTL_R), KC_UP, M(KC_END__CTL_S), _______, _______, _______, _______, _______, _______, _______, _______},
    {M(BSPC__LAYER12), KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______},
    {M(CTL_BSPC__LAYER13), M(CTL_X__CTL), M(CTL_C__SFT), M(CTL_V__ALT), _______, _______, RESET, _______, _______, _______, _______, _______}
  },

  [11] = {
    {_______, KC_BTN3, LCTL(CM_A), LCTL(CM_T), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, LCTL(S(CM_Z)), LCTL(CM_Z), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, LCTL(CM_N), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [12] = {
    {_______, _______, _______, M(_DEL), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_LEFT, LCTL(KC_UP), M(ALT_TAB), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [13] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, M(CTL_W__CTL_Q), M(CTL_PGUP__CTL_F), M(CTL_PGDOWN__CTL_P), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, M(CTL_SFT_K__CTL_A), M(CTL_SFT_D__CTL_T), LCTL(CM_D), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, LCTL(KC_SLSH), _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [14] = {
    {_______, _______, M(7), M(8), M(9), _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_ENT, M(4), M(5), M(6), _______, _______, _______, _______, _______, _______, _______},
    {_______, M(0), M(1), M(2), M(3), _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, KC_DOT, _______, _______, _______, _______, _______, _______, _______}
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
// layer 10 //////////////////////////////////////////////////////
    case SFT_TAB__RALT_Q: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_LSFT);
          register_code(KC_TAB);
          unregister_code(KC_TAB);
          unregister_code(KC_LSFT);
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
    case TAB__RALT_SCLN: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        } else {
          register_code(KC_RALT);
          register_code(CM_SCLN);
          unregister_code(CM_SCLN);
          unregister_code(KC_RALT);
        }
      }
      break;
    }
    case TILD__LAYER11: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(11);
      } else {
        layer_off(11);
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_LCTL);
          register_code(KC_TILD);
          unregister_code(KC_TILD);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case KC_HOME__CTL_R: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
          register_code(KC_HOME);
          unregister_code(KC_HOME);
        } else {
          register_code(KC_LCTL);
          register_code(CM_R);
          unregister_code(CM_R);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case KC_END__CTL_S: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
          register_code(KC_END);
          unregister_code(KC_END);
        } else {
          register_code(KC_LCTL);
          register_code(CM_S);
          unregister_code(CM_S);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case BSPC__LAYER12: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(12);
      } else {
        layer_off(12);
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
        }
      }
      break;
    }
    case CTL_BSPC__LAYER13: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(13);
      } else {
        layer_off(13);
        if (timer_elapsed(key_timer) < QUICK_PRESS) {
          register_code(KC_LCTL);
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
          register_code(KC_LCTL);
          register_code(CM_V);
          unregister_code(CM_V);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
// layer 12 //////////////////////////////////////////////////////
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
// layer 13 //////////////////////////////////////////////////////
    case CTL_W__CTL_Q: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW_PRESS) {
          register_code(KC_LCTL);
          register_code(CM_W);
          unregister_code(CM_W);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_Q);
          unregister_code(CM_Q);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case CTL_PGUP__CTL_F: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
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
    case CTL_PGDOWN__CTL_P: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
          register_code(KC_LCTL);
          register_code(KC_PGDOWN);
          unregister_code(KC_PGDOWN);
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
    case CTL_SFT_K__CTL_A: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          register_code(CM_K);
          unregister_code(CM_K);
          unregister_code(KC_LSFT);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_A);
          unregister_code(CM_A);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case CTL_SFT_D__CTL_T: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL_PRESS) {
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          register_code(CM_D);
          unregister_code(CM_D);
          unregister_code(KC_LSFT);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_T);
          unregister_code(CM_T);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
// layer 14 //////////////////////////////////////////////////////
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
  }
  return MACRO_NONE;
};
