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
  JAVA_JA,
  JAVA_PLUS_JA,
  JAVA_PLUS_YOU_JA,
  DOWNLOAD_TODAY_JA,
  NOT_JA,
  DOWNLOAD_JAVA_BUTTON,
};

#define KC_ KC_TRNS
#define KC_XXXX KC_TRNS   // Need Trans
#define _______ KC_TRNS

#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

// WARNING: Use `_LOWER` in `LT` macro, not `LOWER`. if you make mistake, hungup your keyboards.
#define KC_F_MU LT(_FN3, KC_MHEN)
#define KC_F_HE LT(_FN3, KC_HENK)

#define KC_LFT KC_LEFT
#define KC_RGT KC_RIGHT
#define KC_DWN KC_DOWN

#define KC_L(x) LT(_LOWER, KC_ ## x)
#define KC_R(x) LT(_RAISE, KC_ ## x)

#define KC_X3 LT(_FN3, KC_ZKHK)
#define KC_FN3 FN3
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
#define KC_JAVA JAVA_JA           // Show java as ja_JP with Japanese IME
#define KC_JAPL JAVA_PLUS_JA      // Show "java+" as ja_JP with Japanese IME
#define KC_JAPU JAVA_PLUS_YOU_JA  // Show "java+you" as ja_JP with Japanese IME
#define KC_JADT DOWNLOAD_TODAY_JA // Show "downoad today" as ja_JP with Japanese IME
#define KC_JANT NOT_JA            // Show "not" as ja_JP with Japanese IME
#define KC_DLJA DOWNLOAD_JAVA_BUTTON  // The secret

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
     LCTL, A  ,L(S),L(D),L(F), G  ,      H  ,R(J),  K , L  ,SCLN,J_CLN,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,R(RO),
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      Fn ,FN3 ,LGUI,LALT,F_MU,SPC ,     BSPC,ENT, F_HE ,LFT ,DWN ,RGT
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
         ,    ,    ,    ,    ,    ,     ENT ,    ,    ,XXXX,    ,XXXX
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     ESC ,EXLM,J_DQ,HASH,DLR ,PERC,     CIRC,AMPR,ASTR,LPRN,J_CRT,J_YEN,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         , 1  , 2  , 3  , 4  , 5  ,         ,XXXX,J_LBR,J_RBR,J_AT,   ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         , 6  , 7  , 8  , 9  , 0  ,         ,    ,J_LBC,J_RBC,UP,XXXX,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,     ENT ,    ,    ,XXXX,    ,XXXX
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  // Sandbox layer
  [_FN3] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
         , W1 , W2 , W3 , W4 , W5 ,      W6 , W7 , W8,  W9 , W0 ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,         ,    ,    ,MS_BTN1,MS_UP,MS_BTN2,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,XXXX,    ,    ,    ,MS_BTN1,      ,    ,XXXX,MS_LEFT,MS_DOWN,MS_RIGHT
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_Fn] = KC_KEYMAP(
  //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,      F6 , F7 , F8 , F9 ,F10 ,DEL ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     F11 , W1 , W2 , W3 , W4 , W5 ,      W6 , W7 , W8,  W9 , W0 ,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
         ,JANT,JAPL,JAVA,JADT,JAPU,         ,    ,    ,    ,PGUP,    ,
  //|----+----+----+----+----+----|    |----+----+----+----+----+----|
     XXXX,DLJA,VRSN,    ,    ,    ,     RST ,    ,XXXX,HOME,PGDN,END
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

    case FN3:
      if (record->event.pressed) {
        layer_on(_FN3);
      } else {
        layer_off(_FN3);
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

    // java key(lang:ja)
    case JAVA_JA:
      if (record->event.pressed) {
        // Input "ジャバ"
        // X_GRAVE is an alternative code of X_ZKHK(Zenkaku/Hankaku)
        SEND_STRING (SS_TAP(X_GRAVE) "jyaba" SS_TAP(X_F7) SS_TAP(X_ENTER) SS_TAP(X_GRAVE));
      }
      return false;
      break;

    // java+ key(lang:ja)
    case JAVA_PLUS_JA:
      if (record->event.pressed) {
        // Input "あなたと"
        // X_GRAVE is an alternative code of X_ZKHK(Zenkaku/Hankaku)
        SEND_STRING (SS_TAP(X_GRAVE)
          "anatato" SS_TAP(X_F6)
          SS_TAP(X_ENTER) SS_TAP(X_GRAVE));
      }
      return false;
      break;

    // java+you key(lang:ja)
    case JAVA_PLUS_YOU_JA:
      if (record->event.pressed) {
        // Input "あなたとジャバ、"
        // X_GRAVE is an alternative code of X_ZKHK(Zenkaku/Hankaku)
        SEND_STRING (SS_TAP(X_GRAVE)
          "anatato" SS_TAP(X_F6)
          "jyaba," SS_TAP(X_F7)
          SS_TAP(X_ENTER) SS_TAP(X_GRAVE));
      }
      return false;
      break;

    // download today key(lang:ja)
    case DOWNLOAD_TODAY_JA:
      if (record->event.pressed) {
        // Input "今すぐダウンロー\nド"
        // X_GRAVE is an alternative code of X_ZKHK(Zenkaku/Hankaku)
        SEND_STRING (SS_TAP(X_GRAVE)
          "imasugu "
          "daunro-" SS_TAP(X_F7)
          SS_TAP(X_ENTER) SS_TAP(X_ENTER)
          "do" SS_TAP(X_F7)
          SS_TAP(X_ENTER) SS_TAP(X_GRAVE));
      }
      return false;
      break;

    // NOT key(lang:ja)
    case NOT_JA:
      if (record->event.pressed) {
        // Input "ノット"
        // X_GRAVE is an alternative code of X_ZKHK(Zenkaku/Hankaku)
        SEND_STRING (SS_TAP(X_GRAVE)
          "notto" SS_TAP(X_F7)
          SS_TAP(X_ENTER) SS_TAP(X_GRAVE));
      }
      return false;
      break;

    // DOWNLOAD Java Button
    // **CAUTION** : This function causes downloading real JAVA RUNTIME in 2017 Dec.
    // JIS keyboard layout only.
    case DOWNLOAD_JAVA_BUTTON:
      if (record->event.pressed) {

        // Win+R -> "{java url}"
        SEND_STRING (SS_LGUI("r"));
        wait_ms(200);

        // "'" means ":" in JIS Keyboard...
        SEND_STRING (SS_TAP(X_BSPACE) "https'//java.com/"
          SS_TAP(X_ENTER));

        wait_ms(3000);

        // In top page
        // Tab * n -> Enter (goto Download page)
        SEND_STRING (
          SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
          SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
          SS_TAP(X_ENTER));

        wait_ms(3000);

        // In download page
        // Tab * n -> Enter (goto Download page)
        SEND_STRING (
          SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
          SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB) SS_TAP(X_TAB)
          SS_TAP(X_ENTER));

        // DONE!
      }
      return false;
      break;

  }
  return true;
}
