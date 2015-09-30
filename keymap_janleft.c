#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // default layers

  [0] = {
    {FUNC(31), CM_Q, CM_W, CM_F, CM_P, CM_G, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ESC},
    {FUNC(30), CM_A, CM_R, CM_S, CM_T, CM_D, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_POWER},
    {KC_LGUI, CM_Z, CM_X, CM_C, CM_V, CM_B, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCREEN},
    {KC_LALT, KC_LCTL, KC_LSFT, KC_ESC, FUNC(10), KC_SPC, FUNC(20), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(0)}
  },

  // momentary layers

  [10] = {
    {KC_GRV, RALT(CM_Q), RALT(CM_W), KC__VOLDOWN, KC__VOLUP, KC__MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {LCTL(KC_BSPC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(10), KC_TAB, S(KC_TAB), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [20] = {
    {KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_DELETE, FUNC(22), KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, FUNC(21), KC_TRNS, KC_PGUP, KC_PGDOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(20), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [21] = {
    {KC_TRNS, KC_TRNS, LCTL(CM_A), LCTL(CM_Q), LALT(CM_D), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, LCTL(KC_PGUP), LCTL(CM_W), LCTL(KC_PGDOWN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, FUNC(21), KC_TRNS, KC_TRNS, M(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [22] = {
    {KC_TRNS, KC_TRNS, LCTL(CM_Z), LCTL(KC_UP), LCTL(S(CM_Z)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, FUNC(22), LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(CM_D), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [30] = {
    {KC_TRNS, KC_BTN3, KC_BTN2, KC_BTN3, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {FUNC(30), S(KC_SPC), KC_SPC, S(KC_TAB), KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, LCTL(KC_MINS), LCTL(KC_EQL), KC_TRNS, KC__MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [31] = {
    {FUNC(31), KC_BTN1, LCTL(CM_W), KC_LEFT, M(1), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  }

  // [] = {
  //   {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  //   {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  //   {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
  //   {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  // }

};

const uint16_t PROGMEM fn_actions[] = {

  [10] = ACTION_LAYER_MOMENTARY(10),

  [20] = ACTION_LAYER_MOMENTARY(20),
  [21] = ACTION_LAYER_MOMENTARY(21),
  [22] = ACTION_LAYER_MOMENTARY(22),

  [30] = ACTION_LAYER_TAP_KEY(30, KC_BSPC),
  [31] = ACTION_LAYER_TAP_KEY(31, KC_ENT)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) 
{
  switch(id) {
    case 0:
      return MACRODOWN(TYPE(CM_A), TYPE(CM_R), TYPE(CM_S), TYPE(CM_T), TYPE(KC_ENT), END);
    break;
    case 1:
      return MACRODOWN(DOWN(KC_LALT), DOWN(KC_TAB), UP(KC_TAB), END);
    break;
    case 2:
      return MACRODOWN(DOWN(KC_LCTL), TYPE(CM_K), TYPE(CM_B), UP(KC_LCTL), END);
    break;
  } 
  return MACRO_NONE;
};
