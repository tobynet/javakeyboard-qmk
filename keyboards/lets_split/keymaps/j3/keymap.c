#include "lets_split.h"
#include "action_layer.h"
#include "version.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _FN3 3
#define _Fn 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  FN3,
  FN,
  ADJUST,

  // Custom macros
  SEMICOLON_ENTER,
  VERSION,
};

#define KC_ KC_TRNS
#define KC_XXXX KC_TRNS   // Need Trans
#define _______ KC_TRNS

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

// WARNING: Use `_LOWER` in `LT` macro, not `LOWER`. if you make mistake, hungup your keyboards.
#define KC_F_MU LT(_LOWER, KC_MHEN)
#define KC_F_HE LT(_RAISE, KC_HENK)
#define KC__S LT(_LOWER, KC_S)
#define KC__D LT(_LOWER, KC_D)
#define KC__F LT(_LOWER, KC_F)
#define KC__J LT(_RAISE, KC_J)
#define KC__K LT(_RAISE, KC_K)
#define KC__L LT(_RAISE, KC_L)

#define KC_X3 LT(_FN3, KC_ZKHK)
#define KC_Fn LT(_Fn, KC_ZKHK)

#define KC_W1 LGUI(KC_1)  // Change window to 1st
#define KC_W2 LGUI(KC_2)  // Change window to 2nd
#define KC_W3 LGUI(KC_3)  // Change window to 3rd
#define KC_W4 LGUI(KC_4)  // Change window to 4th
#define KC_W5 LGUI(KC_5)  // Change window to 5th
#define KC_W6 LGUI(KC_6)  // Change window to 6th
#define KC_W7 LGUI(KC_7)  // Change window to 7th
#define KC_W8 LGUI(KC_8)  // Change window to 8th
#define KC_W9 LGUI(KC_9)  // Change window to 9th
#define KC_W0 LGUI(KC_0)  // Change window to 10th

#define KC_SENT SEMICOLON_ENTER   // ; -> Enter
#define KC_VRSN VERSION           // Show firmware version

#define KC_RST RESET

// JP for KC_KEYMAP
#define KC_J_CRT KC_EQL         // ^, ~
#define KC_J_YEN KC_INT3       // yen, |

#define KC_J_AT KC_LBRC        // @, `
#define KC_J_LBR KC_RBRC       // [, {
#define KC_J_CLN KC_QUOT       // :, *
#define KC_J_RBR KC_NUHS       // ], }
#define KC_J_LBC LSFT(JP_LBRC) // {
#define KC_J_RBC LSFT(JP_RBRC) // }
#define KC_J_DQ LSFT(KC_2)     // "


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// "Q" means "KC_Q"
  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     TAB , Q  , W  , E  , R  , T  ,      Y  ,  U , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LCTL, A  , _S , _D , _F , G  ,      H  , _J ,  K , L  ,SCLN,J_CLN,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH, RO ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      Fn , X3 ,LGUI,LALT,ZKHK,SPC ,     BSPC,ENT ,LEFT,DOWN, UP ,RGHT
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,      6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,XXXX,XXXX,XXXX,    ,     LEFT,DOWN, UP ,RGHT,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    , UP ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,     DEL ,SENT,    ,LEFT,DOWN,RGHT
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     ESC ,EXLM,J_DQ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,J_CRT,J_YEN,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,EXLM,J_DQ,HASH,DLR ,PERC,         ,XXXX,J_LBR,J_RBR,J_AT,J_LBR,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,J_LBC,J_RBC,UP,J_RBR,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,     DEL ,SENT,    ,LEFT,DOWN,RGHT
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  // Sandbox layer
  [_FN3] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_Fn] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,      F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         , W1 , W2 , W3 , W4 , W5 ,      W6 , W7 , W8,  W9 , W0,     ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,PGUP,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,     RST ,VRSN,    ,HOME,PGDN,END
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),


/* Adjust (Lower + Raise) */
  [_ADJUST] = KEYMAP( \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
  )


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

#ifdef TAP_DANCE_ENABLE
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_U] = ACTION_TAP_DANCE_DOUBLE(KC_U, JP_QUOT),
  [TD_UP] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_SLASH),
};
#endif // TAP_DANCE_ENABLE


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
//        update_tri_layer(_LOWER, _RAISE, _ADJUST);
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

    // ; + Enter
    case SEMICOLON_ENTER:
      if (record->event.pressed) {
        SEND_STRING (SS_TAP(X_SCOLON) SS_TAP(X_ENTER));
      }
      return false;
      break;

    // Show version
    case VERSION:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}
