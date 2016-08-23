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
#define MISC3 6
#define MISC4 7
#define BROWSER 8

// COLEMAK_SOFT
#define BROWSER__SPC 20
#define LOGIN 21

// RABBIT_HOLE
#define V__C__X 30
#define ENT__T__N 31
#define TAB__SFT_TAB__ALT_D 32
#define MISC1__ALT_LEFT 33
#define HOME__F__W 34
#define END__S__R 35
#define MISC2__BSPC 36
#define MISC3__CTL_BSPC 37
#define D__ESC 38
#define P__SFT_CTL_P__O 39
#define NUMBERS__MISC4__CTL_SFT_2 40

// MISC2
#define SLSH 50
#define CTL_F2__F2 51

// MISC3
#define LEFT__UP 60
#define ALT_TAB 61
#define VOLDOWN__LEFT 62
#define MUTE__DOWN 63
#define VOLUP__RIGHT 64
#define DEL 65

// MISC4
#define MISC4_CLOSE 70

// NUMBERS
#define ENT__F1 0
#define DOT__F2 1
#define _0__F3 2
#define _1__F4 3
#define _2__F5 4
#define _3__F6 5
#define _4__F7 6
#define _5__F8 7
#define _6__F9 8
#define _7__F10 9
#define _8__F11 10
#define _9__F12 11
#define NUMBERS_CLOSE 12

static uint16_t key_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [COLEMAK_SOFT] = {
    {M(BROWSER__SPC), CM_G, CM_D, CM_B, RALT(CM_SCLN), _______, _______, _______, _______, KC__VOLDOWN, KC__VOLUP, KC__MUTE},
    {CM_Q, CM_W, CM_F, CM_P, RALT(CM_W), _______, _______, _______, _______, _______, _______, KC_PSCREEN},
    {CM_A, CM_R, CM_S, CM_T, RALT(CM_Q), _______, _______, _______, _______, _______, _______, TG(COLEMAK_HARD)},
    {CM_Z, CM_X, CM_C, CM_V, KC_SPC, MO(RABBIT_HOLE), _______, _______, _______, _______, _______, M(LOGIN)}
  },

  [COLEMAK_HARD] = {
    {_______, KC_G, KC_D, KC_B, _______, _______, _______, _______, _______, _______, _______, _______},
    {KC_Q, KC_W, KC_F, KC_P, _______, _______, _______, _______, _______, _______, _______, _______},
    {KC_A, KC_R, KC_S, KC_T, _______, _______, _______, _______, _______, _______, _______, _______},
    {KC_Z, KC_X, KC_C, KC_V, _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [RABBIT_HOLE] = {
    {_______, M(V__C__X), M(ENT__T__N), M(TAB__SFT_TAB__ALT_D), _______, _______, _______, _______, _______, _______, _______, RESET},
    {M(MISC1__ALT_LEFT), M(HOME__F__W), KC_UP, M(END__S__R), _______, _______, _______, _______, _______, _______, _______, _______},
    {M(MISC2__BSPC), KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______, _______, _______},
    {M(MISC3__CTL_BSPC), M(D__ESC), M(P__SFT_CTL_P__O), M(NUMBERS__MISC4__CTL_SFT_2), _______, _______, _______, _______, _______, _______, _______, _______}
  },

  [MISC1] = {
    {_______, KC_LALT, KC_LSFT, KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, KC_LGUI, KC_RALT, _______, _______, _______, _______, _______, _______}
  },

  [MISC2] = {
    {_______, _______, LCTL(CM_Z), LCTL(S(CM_Z)), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, LCTL(KC_PGUP), LCTL(KC_UP), LCTL(KC_PGDOWN), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, M(SLSH), LCTL(LALT(S(KC_DOWN))), M(CTL_F2__F2), _______, _______, _______, _______, _______, _______}
  },

  [MISC3] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, M(LEFT__UP), M(ALT_TAB), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, M(VOLDOWN__LEFT), M(MUTE__DOWN), M(VOLUP__RIGHT), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, LCTL(S(CM_K)), M(DEL), LSFT(KC_SPC), _______, _______, _______, _______, _______, _______}
  },

  [MISC4] = {
    {_______, _______, LGUI(KC_SPC), LCTL(LALT(CM_T)), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, LCTL(KC_HOME), LALT(KC_UP), LCTL(KC_END), _______, _______, _______, _______, _______, _______, _______, _______},
    {LCTL(CM_A), KC_PGUP, LALT(KC_DOWN), KC_PGDOWN, _______, _______, _______, _______, _______, _______, _______, _______},
    {LCTL(CM_W), _______, _______, LCTL(S(CM_T)), _______, M(MISC4_CLOSE), _______, _______, _______, _______, _______, _______}
  },

  [BROWSER] = {
    {_______, S(KC_SPC), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, KC_BTN3, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, LCTL(CM_W), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_ENT, _______, _______, _______, _______, _______, _______, _______}
  },

  [NUMBERS] = {
    {_______, M(_7__F10), M(_8__F11), M(_9__F12), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, M(_4__F7), M(_5__F8), M(_6__F9), _______, _______, _______, _______, _______, _______, _______, _______},
    {KC_BSPC, M(_1__F4), M(_2__F5), M(_3__F6), _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, M(ENT__F1), M(DOT__F2), M(_0__F3), _______, M(NUMBERS_CLOSE), _______, _______, _______, _______, _______, _______}
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
// COLEMAK_SOFT //////////////////////////////////////////////////////
    case BROWSER__SPC: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(BROWSER);
      } else {
        layer_off(BROWSER);
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
// RABBIT_HOLE //////////////////////////////////////////////////////
    case V__C__X: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LCTL);
          register_code(KC_V);
          unregister_code(KC_V);
          unregister_code(KC_LCTL);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(KC_C);
          unregister_code(KC_C);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(KC_X);
          unregister_code(KC_X);
          unregister_code(KC_LCTL);
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
    case TAB__SFT_TAB__ALT_D: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < QUICK) {
          register_code(KC_TAB);
          unregister_code(KC_TAB);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LSFT);
          register_code(KC_TAB);
          unregister_code(KC_TAB);
          unregister_code(KC_LSFT);
        } else {
          register_code(KC_LALT);
          register_code(CM_D);
          unregister_code(CM_D);
          unregister_code(KC_LALT);
        }
      }
      break;
    }
    case MISC1__ALT_LEFT: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(MISC1);
      } else {
        layer_off(MISC1);
        if (timer_elapsed(key_timer) < QUICK) {
          register_code(KC_LALT);
          register_code(KC_LEFT);
          unregister_code(KC_LEFT);
          unregister_code(KC_LALT);
        }
      }
      break;
    }
    case HOME__F__W: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_HOME);
          unregister_code(KC_HOME);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(CM_F);
          unregister_code(CM_F);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_LCTL);
          register_code(CM_W);
          unregister_code(CM_W);
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
    case MISC2__BSPC: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(MISC2);
      } else {
        layer_off(MISC2);
        if (timer_elapsed(key_timer) < QUICK) {
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
        }
      }
      break;
    }
    case MISC3__CTL_BSPC: {
      if (record->event.pressed) {
        key_timer = timer_read();
        layer_on(MISC3);
      } else {
        layer_off(MISC3);
        if (timer_elapsed(key_timer) < QUICK) {
          register_code(KC_LCTL);
          register_code(KC_BSPC);
          unregister_code(KC_BSPC);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
    case D__ESC: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < QUICK) {
          register_code(KC_LCTL);
          register_code(CM_D);
          unregister_code(CM_D);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_ESC);
          unregister_code(KC_ESC);
        }
      }
      break;
    }
    case P__SFT_CTL_P__O: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LCTL);
          register_code(CM_P);
          unregister_code(CM_P);
          unregister_code(KC_LCTL);
        } else if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          register_code(CM_P);
          unregister_code(CM_P);
          unregister_code(KC_LSFT);
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
    case NUMBERS__MISC4__CTL_SFT_2: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          layer_on(NUMBERS);
        } else if (timer_elapsed(key_timer) < SLOW) {
          layer_on(MISC4);
        } else {
          register_code(KC_LCTL);
          register_code(KC_LSFT);
          register_code(KC_2);
          unregister_code(KC_2);
          unregister_code(KC_LSFT);
          unregister_code(KC_LCTL);
        }
      }
      break;
    }
// MISC2 //////////////////////////////////////////////////////
    case SLSH: {
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
    case CTL_F2__F2: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_LCTL);
          register_code(KC_F2);
          unregister_code(KC_F2);
          unregister_code(KC_LCTL);
        } else {
          register_code(KC_F2);
          unregister_code(KC_F2);
        }
      }
      break;
    }
// MISC3 //////////////////////////////////////////////////////
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
    case VOLDOWN__LEFT: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC__VOLDOWN);
          unregister_code(KC__VOLDOWN);
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
    case MUTE__DOWN: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC__MUTE);
          unregister_code(KC__MUTE);
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
    case VOLUP__RIGHT: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < SLOW) {
          register_code(KC__VOLUP);
          unregister_code(KC__VOLUP);
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
    case DEL: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
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
// MISC4 //////////////////////////////////////////////////////
    case MISC4_CLOSE: {
      if (record->event.pressed) {
        layer_off(MISC4);
      }
      break;
    }
// NUMBERS //////////////////////////////////////////////////////
    case ENT__F1: {
      if (record->event.pressed) { key_timer = timer_read(); }
      else {
        if (timer_elapsed(key_timer) < NORMAL) {
          register_code(KC_ENT);
          unregister_code(KC_ENT);
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
    case _0__F3: {
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
    case NUMBERS_CLOSE: {
      if (record->event.pressed) {
        layer_off(NUMBERS);
      }
      break;
    }
  }
  return MACRO_NONE;
};
