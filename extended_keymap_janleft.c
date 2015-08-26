#include "extended_keymap_common.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // default layers

  [0] = {
    {KC_ESC, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_ENT, CM_Q, CM_W, CM_F, CM_P, CM_G, KC_TRNS},
    {KC_POWER, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_BSPC, CM_A, CM_R, CM_S, CM_T, CM_D, KC_TRNS},
    {KC_PSCREEN, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_LSFT, CM_Z, CM_X, CM_C, CM_V, CM_B, KC_TRNS},
    {M(0), KC_TRNS, KC_F10, KC_F11, KC_F12, KC_LGUI, KC_LCTL, KC_LALT, KC_ESC, FUNC(10), KC_SPC, FUNC(20)}
  },

  // momentary layers

  [10] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_GRV, RALT(CM_Q), RALT(CM_W), KC__VOLDOWN, KC__VOLUP, KC__MUTE, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_BSPC), KC_1, KC_2, KC_3, KC_4, KC_5, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(10), KC_TAB, KC_TRNS}
  },

  [20] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_TRNS, RESET},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DELETE, FUNC(21), KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(22), KC_TRNS, KC_PGUP, KC_PGDOWN, KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(20)}
  },

  [21] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(CM_Q), LCTL(CM_W), LALT(CM_D), KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(21), LCTL(CM_A), LCTL(KC_PGUP), LCTL(KC_PGDOWN), KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, M(2), KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS}
  },

  [22] = {
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, LCTL(KC_UP), M(1), KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LCTL(KC_LEFT), LCTL(KC_DOWN), LCTL(KC_RIGHT), KC_TRNS, KC_TRNS},
    {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, FUNC(22), LCTL(CM_Z), LCTL(S(CM_Z)), LCTL(CM_D), KC_TRNS, KC_TRNS},
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

  // default layers

  [0] = ACTION_DEFAULT_LAYER_SET(0),

  // momentary layers

  [10] = ACTION_LAYER_MOMENTARY(10),

  [20] = ACTION_LAYER_MOMENTARY(20),
  [21] = ACTION_LAYER_TAP_KEY(21, KC_TAB),
  [22] = ACTION_LAYER_TAP_KEY(22, KC_NO)

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
