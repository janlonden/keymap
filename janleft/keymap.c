#include "planck.h"
#include "../../quantum/keymap_extras/keymap_colemak.h"

#define _______ KC_TRNS

#define NORMAL 150
#define SLOW 300
#define SUPERSLOW 600

// layer 0
#define SPC__LAYER16 10
#define LOGIN 11

// layer 10
#define TAB__A__D 20
#define ENT__T__N 21
#define TAB__P__O 22
#define HOME__W__Q 23
#define END__S__R 24
#define BSPC__LAYER11 25
#define BSPC__LAYER12 26

// layer 11
#define _SLSH 30
#define D__K 31

// layer 12
#define LEFT__UP 41
#define ALT_TAB 42
#define X__LEFT 43
#define C__DOWN 44
#define V__RIGHT 45
#define F12__F2__F11 46
#define _DEL 47

static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = {
    {M(SPC__LAYER16), CM_G, CM_D, CM_B, RALT(CM_SCLN), KC__MUTE, _______, _______, _______, _______, _______, _______},
    {CM_Q, CM_W, CM_F, CM_P, RALT(CM_W), KC__VOLUP, _______, _______, _______, _______, _______, _______},
    {CM_A, CM_R, CM_S, CM_T, RALT(CM_Q), KC__VOLDOWN, _______, _______, _______, _______, _______, _______},
    {CM_Z, CM_X, CM_C, CM_V, KC_SPC, MO(10), MO(14), _______, _______, _______, _______, M(LOGIN)}
  },

  [10] = {
    {_______, M(TAB__A__D), M(ENT__T__N), M(TAB__P__O), _______, _______, _______, _______, _______, _______, _______, _______},
    {MO(13), M(HOME__W__Q), KC_UP, M(END__S__R), _______, _______, _______, _______, _______, _______, _______, _______},
    {M(BSPC__LAYER11), KC_LEFT, KC_DOWN, KC_RIGHT, OSL(15), _______, _______, _______, _______, _______, _______, _______},
    {M(BSPC__LAYER12), _______, KC_ESC, LCTL(CM_D), _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [11] = {
    {_______, _______, LCTL(CM_Z), LCTL(S(CM_Z)), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, LCTL(KC_PGUP), LCTL(KC_UP), LCTL(KC_PGDOWN), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, M(_SLSH), M(D__K), KC_BTN3, _______, _______, _______, _______, _______, _______}
  },

  [12] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, M(LEFT__UP), M(ALT_TAB), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, M(X__LEFT), M(C__DOWN), M(V__RIGHT), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, M(F12__F2__F11), LSFT(KC_SPC), M(_DEL), _______, _______, _______, _______, _______, _______}
  },

  [13] = {
    {_______, KC_LALT, KC_LSFT, KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, KC_RALT, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, KC_LGUI, _______, _______, _______, _______, _______, _______}
  },

  [14] = {
    {_______, _______, M(7), M(8), M(9), _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, M(4), M(5), M(6), _______, _______, _______, _______, _______, _______, _______},
    {_______, M(0), M(1), M(2), M(3), _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_BSPC, _______, _______, KC_DOT, _______, _______, _______, _______, _______, _______, _______}
  },

  [15] = {
    {_______, KC_F10, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_F7, KC_F8, KC_F9, _______, _______, _______, _______, _______, _______, _______, _______},
    {KC_PSCREEN, KC_F4, KC_F5, KC_F6, _______, _______, _______, _______, _______, _______, _______, _______},
    {KC_SLEP, KC_F1, KC_F2, KC_F3, _______, RESET, _______, _______, _______, _______, _______, _______}
  },

  [16] = {
    {_______, S(KC_SPC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, LCTL(CM_W), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {KC_LSFT, KC_LCTL, LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_ENT, _______, _______, _______, _______, _______, _______, _______}
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
    case SPC__LAYER16: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(16);
      } else {
        layer_off(16);
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_SPC);
          unregister_code(KC_SPC);
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
// layer 10 //////////////////////////////////////////////////////
    case TAB__A__D: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LSFT);
          register_code(KC_TAB);
          unregister_code(KC_TAB);
          unregister_code(KC_LSFT);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_A);
          unregister_code(CM_A);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LALT);
          register_code(CM_D);
          unregister_code(CM_D);
          unregister_code(KC_LALT);
        }
      }
      break;
    }
    case ENT__T__N: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_ENT);
          unregister_code(KC_ENT);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_T);
          unregister_code(CM_T);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_N);
          unregister_code(CM_N);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case TAB__P__O: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_P);
          unregister_code(CM_P);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_O);
          unregister_code(CM_O);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case HOME__W__Q: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_HOME);
          unregister_code(KC_HOME);
        } else if (timer_elapsed(key_timer) < SUPERSLOW) {
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
    case END__S__R: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_END);
          unregister_code(KC_END);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_S);
          unregister_code(CM_S);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_R);
          unregister_code(CM_R);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case BSPC__LAYER11: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(11);
      } else {
        layer_off(11);
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
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
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LCTL);
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
// layer 11 //////////////////////////////////////////////////////
    case _SLSH: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LCTL);
          register_code(KC_SLSH);
          unregister_code(KC_SLSH);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_SLSH);
          unregister_code(KC_SLSH);
          register_code(KC_SLSH);
          unregister_code(KC_SLSH);
        }
      }
      break;
    }
    case D__K: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          register_code(CM_D);
          unregister_code(CM_D);
          unregister_code(KC_LSFT);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          register_code(CM_K);
          unregister_code(CM_K);
          unregister_code(KC_LSFT);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
// layer 12 //////////////////////////////////////////////////////
    case LEFT__UP: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LEFT);
          unregister_code(KC_LEFT);
        } else {
          register_code(KC_LCTL);
          register_code(KC_LGUI);
          register_code(KC_UP);
          unregister_code(KC_UP);
          unregister_code(KC_LGUI);
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
    case X__LEFT: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_X);
          unregister_code(CM_X);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(KC_LGUI);
          register_code(KC_LEFT);
          unregister_code(KC_LEFT);
          unregister_code(KC_LGUI);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case C__DOWN: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_C);
          unregister_code(CM_C);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(KC_LGUI);
          register_code(KC_DOWN);
          unregister_code(KC_DOWN);
          unregister_code(KC_LGUI);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case V__RIGHT: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_V);
          unregister_code(CM_V);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(KC_LGUI);
          register_code(KC_RIGHT);
          unregister_code(KC_RIGHT);
          unregister_code(KC_LGUI);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case F12__F2__F11: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_F12);
          unregister_code(KC_F12);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_F2);
          unregister_code(KC_F2);
        } else {
          register_code(KC_F11);
          unregister_code(KC_F11);
        }
      }
      break;
    }
    case _DEL: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
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
// layer 14 //////////////////////////////////////////////////////
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
        if (timer_elapsed(key_timer) < NORMAL) {
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
        if (timer_elapsed(key_timer) < NORMAL) {
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
        if (timer_elapsed(key_timer) < NORMAL) {
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
        if (timer_elapsed(key_timer) < NORMAL) {
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
        if (timer_elapsed(key_timer) < NORMAL) {
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
        if (timer_elapsed(key_timer) < NORMAL) {
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
        if (timer_elapsed(key_timer) < NORMAL) {
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
        if (timer_elapsed(key_timer) < NORMAL) {
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
        if (timer_elapsed(key_timer) < NORMAL) {
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
