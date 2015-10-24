#include "keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // default layers

  [0] = {
    {KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS, KC_TRNS, CM_J, CM_L, CM_U, CM_Y, CM_SCLN, M(0)},
    {KC_4, KC_5, KC_6, KC_TRNS, KC_TRNS, KC_TRNS, CM_H, CM_N, CM_E, CM_I, CM_O, KC_QUOT},
    {KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS, KC_TRNS, CM_K, CM_M, CM_COMM, CM_DOT, CM_SLSH, KC_RALT},
    {FUNC(30), CM_DOT, KC_ENT, KC_TRNS, KC_TRNS, FUNC(20), KC_RSFT, FUNC(10), KC_ENT, KC_RSFT, KC_RCTL, FUNC(31)}
  },

  // momentary layers

  [10] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL, FUNC(11), KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(10), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [11] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_MINS), S(KC_EQL), FUNC(11), KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [20] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS, S(KC_LBRC), S(KC_RBRC), S(KC_BSLS), KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RALT(CM_Q), RALT(CM_W), RALT(KC_P), FUNC(21), KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F2, KC_F11, KC_F12, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(20), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [21] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(21), KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [30] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {CM_SLSH, S(KC_8), KC_MINS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, S(KC_EQL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {FUNC(30), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [31] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_SPC), FUNC(31)}
  }

};

const uint16_t PROGMEM fn_actions[] = {

  [10] = ACTION_LAYER_MOMENTARY(10),
  [11] = ACTION_LAYER_MOMENTARY(11),

  [20] = ACTION_LAYER_MOMENTARY(20),
  [21] = ACTION_LAYER_MOMENTARY(21),

  [30] = ACTION_LAYER_TAP_KEY(30, KC_0),
  [31] = ACTION_LAYER_TAP_KEY(31, KC_SPC)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0:
      return MACRODOWN(TYPE(CM_A), TYPE(CM_R), TYPE(CM_S), TYPE(CM_T), TYPE(KC_ENT), END);
    break;
  }
  return MACRO_NONE;
};
