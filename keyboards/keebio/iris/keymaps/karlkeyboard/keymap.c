#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _SWE 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

enum combos {
  JK_ESC,
  /*UI_BKSCP,*/
  /*LEFT_PARAN,*/
  /*RIGHT_PARAN,*/
  /*LEFT_CURLY,*/
  /*RIGHT_CURLY,*/
  /*LEFT_BRACK,*/
  /*RIGHT_BRACK,*/
};


enum unicode_names {
    aa,
    AA,
    ae,
    AE,
    oo,
    OO
};

const uint32_t PROGMEM unicode_map[] = {
    [aa]  = 0x00E5,  // å
    [AA]  = 0x00C5,  // Å
    [ae]  = 0x00E4,  // ä
    [AE]  = 0x00C4,  // Ä
    [oo]  = 0x00F6,  // ö
    [OO]  = 0x00D6,  // Ö
};


const uint16_t PROGMEM esc_combo[] = {KC_J, KC_K, COMBO_END};
/*const uint16_t PROGMEM bkspc_combo[] = {KC_U, KC_I, COMBO_END};*/

/*const uint16_t PROGMEM left_paran_combo[] = {KC_I, KC_O, COMBO_END};*/
/*const uint16_t PROGMEM right_paran_combo[] = {KC_O, KC_P, COMBO_END};*/

/*const uint16_t PROGMEM left_curly_combo[] = {KC_K, KC_L, COMBO_END};*/
/*const uint16_t PROGMEM right_curly_combo[] = {KC_L, KC_SCLN, COMBO_END};*/

/*const uint16_t PROGMEM left_brack_combo[] = {KC_COMM, KC_DOT, COMBO_END};*/
/*const uint16_t PROGMEM right_brack_combo[] = {KC_DOT, KC_SLSH, COMBO_END};*/

combo_t key_combos[COMBO_COUNT] = {
  [JK_ESC] = COMBO(esc_combo, KC_ESC),
  /*[UI_BKSCP] = COMBO(bkspc_combo, KC_BSPC),*/
  /*[LEFT_PARAN] = COMBO(left_paran_combo, KC_LPRN),*/
  /*[RIGHT_PARAN] = COMBO(right_paran_combo, KC_RPRN),*/
  /*[LEFT_CURLY] = COMBO(left_curly_combo, KC_LCBR),*/
  /*[RIGHT_CURLY] = COMBO(right_curly_combo, KC_RCBR),*/
  /*[LEFT_BRACK] = COMBO(left_brack_combo, KC_LBRC),*/
  /*[RIGHT_BRACK] = COMBO(right_brack_combo, KC_RBRC),*/
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                        ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                        ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                        ├────────┼────────┼────────┼────────┼────────┼────────┤
     LOWER,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                      ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    RAISE,                          TG(3),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TG(4),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘                      └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LCTL,  KC_SPC,                           KC_SPC,   KC_ENT,  KC_LALT
                                // └────────┴────────┴────────┘                         └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_TRNS,  KC_UP,  KC_TRNS, KC_BSPC, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_TRNS,                           KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_TRNS, KC_HOME, KC_END,  KC_TRNS, RGB_RMOD, RGB_VAD,         RGB_VAI, RGB_MOD, KC_TRNS, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,  KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_F7,   KC_F8,   KC_F9,    KC_TRNS, KC_MPRV, KC_MNXT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_F4,   KC_F5,   KC_F6,   KC_TRNS, KC_VOLD, KC_VOLU,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         TG(3),   KC_F1,   KC_F2,   KC_F3,   KC_TRNS, KC_TRNS, KC_MPLY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐
     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_TRNS,            KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SWE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XP(aa, AA),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                           KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,XP(oo, OO),XP(ae, AE),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(4),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX);
}
