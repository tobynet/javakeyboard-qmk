#include "nyquist.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

// #define MACRO_ENGLISH_DICTIONARY

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _EUCALYN 1
#define _GAMING 2
#define _GAMING_FN 3
#define _LOWER 4
#define _RAISE 5
#define _FN3 6
#define _FN 7

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  EUCALYN,
  GAMING,
  GAMING_FN,
  LOWER,
  RAISE,
  FN3,
  FN,

  // Custom macros
  JAVA_JA,
  JAVA_PLUS_JA,
  JAVA_PLUS_YOU_JA,
  DOWNLOAD_TODAY_JA,
  NOT_JA,
  DOWNLOAD_JAVA_BUTTON,

  // Useful macros
  ENGLISH_DICTIONARY,

  // Songs
  SONG1, SONG2, SONG3, SONG4, SONG5, SONG6, SONG7, SONG8, SONG9, SONG0,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


// Lower or Raise modifier
#define _L(x) LT(_LOWER, x)
#define _R(x) LT(_RAISE, x)

// Modifiers for One hand
#define _G(x) LT(_GAMING_FN, x)

// Mod Tap ref. https://docs.qmk.fm/#/feature_advanced_keycodes?id=mod-tap
#define CTL_SPC CTL_T(KC_SPACE)

// Macros
#define KC_JAVA JAVA_JA           // Show java as ja_JP with Japanese IME
#define KC_JAPL JAVA_PLUS_JA      // Show "java+" as ja_JP with Japanese IME
#define KC_JAPU JAVA_PLUS_YOU_JA  // Show "java+you" as ja_JP with Japanese IME
#define KC_JADT DOWNLOAD_TODAY_JA // Show "downoad today" as ja_JP with Japanese IME
#define KC_JANT NOT_JA            // Show "not" as ja_JP with Japanese IME
#define KC_DLJA DOWNLOAD_JAVA_BUTTON  // The secret

#define ENG_DIC ENGLISH_DICTIONARY


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | -or= |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | @or` |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |  S   |   D  |F Low |   G  |   H  |J Rais|   K  |   L  | ;or+ | 'or" |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  | ,or< | .or> |  UP  | /or? |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn3  |  FN  | GUI  | Alt  |Muhen |Space | Bksp |Enter |Henkan| Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_AT, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    _L(KC_F),KC_G,    KC_H,    _R(KC_J), KC_K,   KC_L,    KC_SCLN, JP_COLN, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, \
  FN3,     FN,     KC_LGUI, KC_LALT, KC_MHEN, KC_SPC,  KC_BSPC, KC_ENT,  KC_HENK, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Eucalyn 2018-03
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | -or= |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  | ,or< | .or> | ;or+ |   M  |   R  |   D  |   Y  |   P  | @or` |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   O  |   E  |I Low |   U  |   G  |T Rais|   K  |   S  |   N  | :or* |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   F  |   B  |   H  |   J  |   L  |  UP  | /or? |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn3  |  FN  | GUI  | Alt  |Muhen |Space | Bksp |Enter |Henkan| Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 * ref. http://eucalyn.hatenadiary.jp/entry/about-eucalyn-layout
 */
[_EUCALYN] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q,    KC_W,    KC_COMM, KC_DOT,  KC_SCLN, KC_M,    KC_R,    KC_D,    KC_Y,    KC_P,    JP_AT, \
  KC_LCTL, KC_A,    KC_O,    KC_E,    _L(KC_I),KC_U,    KC_G,    _R(KC_T),KC_K,    KC_S,    KC_N,    JP_COLN, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_F,    KC_B,    KC_H,    KC_J,    KC_L,    KC_UP,   KC_SLSH, \
  FN3,     FN,      KC_LGUI, KC_LALT, KC_MHEN, KC_SPC,  KC_BSPC, KC_ENT,  KC_HENK, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Qwerty based for gaming
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | -or= |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | @or` |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ;or+ | 'or" |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  | ,or< | .or> |  UP  | /or? |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn3  |  FN  | GUI  | Alt  |G(Enter)|Space| Bksp |Enter |Kanzi| Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    JP_AT, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, JP_COLN, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, \
  FN3,     FN,      KC_LGUI, KC_LALT,_G(KC_ENT),KC_SPC, KC_BSPC, KC_ENT,  JP_ZHTG, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* Qwerty based layer for gaming(The layout of right hand in left hand)
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   6  |   7  |   8  |   9  |   0  |      |      \      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Y  |   U  |   I  |   O  |   P  |      |      \      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl |   H  |   J  |   K  |   L  | ENTER|      |      \      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   N  |   M  | ,or< | .or> | DEL  |      |      \      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn3  |  FN  | GUI  | Alt  |Muhen | BSPC |      |      \      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING_FN] = LAYOUT( \
  _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, _______,  _______, _______, _______, _______, \
  _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______,  _______, _______, _______, _______, \
  _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,  _______, _______,  _______, _______, _______, _______, \
  _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_DEL,  _______, _______,  _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, KC_BSPC,  _______, _______,  _______, _______, _______, _______ \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |  !   |   "  |   #  |   $  |   %  |   &  |   '  |   (  |   )  | ^or~ | \or| |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ESC  |  !   |   "  |   #  |   $  |   %  |   &  |   '  |   (  |   )  | ^or~ | \or| |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | LEFT | DOWN |  UP  |RIGHT |      |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | LEFT | DOWN |RIGHT |PG UP |   _  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | HOME |PG DOWN| END |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  _______, JP_EXLM, JP_DQT,  JP_HASH, JP_DLR , JP_PERC, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_CIRC, JP_YEN, \
  KC_ESC,  JP_EXLM, JP_DQT,  JP_HASH, JP_DLR , JP_PERC, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_CIRC, JP_YEN, \
  _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, JP_QUOT, \
  _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, JP_UNDS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |  !   |   "  |   #  |   $  |   %  |   &  |   '  |   (  |   )  | ^or~ | \or| |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | ESC  |  !   |   "  |   #  |   $  |   %  |   &  |   '  |   (  |   )  | ^or~ | \or| |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   [  |   ]  |   :  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |   {  |   }  |      |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, JP_EXLM, JP_DQT,  JP_HASH, JP_DLR , JP_PERC, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_CIRC, JP_YEN, \
  KC_ESC,  JP_EXLM, JP_DQT,  JP_HASH, JP_DLR , JP_PERC, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_CIRC, JP_YEN, \
  _______, _______, _______, _______, _______, _______, _______, _______, JP_LBRC, JP_RBRC, JP_COLN, JP_QUOT, \
  _______, _______, _______, _______, _______, _______, _______, _______, JP_LCBR, JP_RCBR, _______, JP_UNDS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Sandbox layer
 * ,-----------------------------------------------------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | F11  |SONG 1|SONG 2|SONG 3|SONG 4|SONG 5|SONG 6|SONG 7|SONG 8|SONG 9|SONG 0|LED HSV|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |LED TST|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | LED  | LED  | LED  |      |      |      |      |      | LED  | LED  | LED  |
 * |      |Slide |Swing |blink |      |      |      |      |      | Sat- |Brght+| Sat+ |
 * |------+------+------+------+------+------+------+------+------+------+      +------|
 * |      |      |      |      |      |      |  LED |      |      | LED  | LED  |  LED |
 * |      |      |      |      |      |      |ON/OFF|      |      | HUE- |Brght-| HUE+ |
 * `-----------------------------------------------------------------------------------'
 */
[_FN3] = LAYOUT( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
  KC_F11 , SONG1,   SONG2,   SONG3,   SONG4,   SONG5,   SONG6,   SONG7,   SONG8,   SONG9,   SONG0,   RGB_M_G, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_M_T, \
  _______,RGB_M_SN, RGB_M_K, RGB_M_B, _______, _______, _______, _______, _______, RGB_SAD, RGB_VAI, RGB_SAI, \
  _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, RGB_HUD, RGB_VAD, RGB_HUI \
),

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  DEL |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F11 |      |      |ENG_DIC|      |      |      |      |      |      |     |RESET |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |QWERTY|EUCALYN|GAMING|     |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |PG UP |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | HOME |PG DOWN| END |
 * `-----------------------------------------------------------------------------------'
 */
[_FN] = LAYOUT( \
  KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
  KC_F11,  _______, _______, ENG_DIC, _______, _______, _______, _______, _______, _______, _______, RESET , \
  _______, _______, _______, _______, _______, _______, _______, QWERTY,  EUCALYN, GAMING,  _______, KC_DLJA, \
  _______, KC_JANT, KC_JAPL, KC_JAVA, KC_JADT, KC_JAPU, _______, _______, _______, _______, KC_PGUP, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_END \
)

};


#ifdef AUDIO_ENABLE
#define FAST_ONE_UP_SOUND \
    E__NOTE(_E6), \
    E__NOTE(_G6), \
    E__NOTE(_E7), \
    E__NOTE(_C7), \
    E__NOTE(_D7), \
    E__NOTE(_G7),

#define TREASURE_SOUND \
    H__NOTE(_A4), \
    H__NOTE(_AS4), \
    H__NOTE(_B4), \
    WD_NOTE(_C5),

#define DOORCHIME_SOUND \
    H__NOTE(_FS5), \
    H__NOTE(_D5), \
    H__NOTE(_A4), \
    H__NOTE(_D5), \
    \
    H__NOTE(_E5), \
    W__NOTE(_A5), \
    H__NOTE(_REST), \
    \
    H__NOTE(_E5), \
    H__NOTE(_FS5), \
    H__NOTE(_E5), \
    H__NOTE(_A4), \
    M__NOTE(_D5, 128),


// How to make array initialization??
float tone_song1[][2] = SONG(COIN_SOUND);
float tone_song2[][2] = SONG(FAST_ONE_UP_SOUND);
float tone_song3[][2] = SONG(ZELDA_PUZZLE);
float tone_song4[][2] = SONG(TREASURE_SOUND);
float tone_song5[][2] = SONG(DOORCHIME_SOUND);
float tone_qwerty[][2] = SONG(QWERTY_SOUND);
float tone_eucalyn[][2]  = SONG(COLEMAK_SOUND);
float tone_gaming[][2] = SONG(DVORAK_SOUND);
#endif


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;

    case EUCALYN:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_eucalyn);
        #endif
        persistent_default_layer_set(1UL<<_EUCALYN);
      }
      return false;
      break;

    case GAMING:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_gaming);
        #endif
        persistent_default_layer_set(1UL<<_GAMING);
      }
      return false;
      break;

    case FN:
      if (record->event.pressed) {
        layer_on(_FN);
      } else {
        layer_off(_FN);
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

#ifdef AUDIO_ENABLE
    // Play songs
    case SONG1:
      if (record->event.pressed) PLAY_SONG(tone_song1);
      return false;
    case SONG2:
      if (record->event.pressed) PLAY_SONG(tone_song2);
      return false;
    case SONG3:
      if (record->event.pressed) PLAY_SONG(tone_song3);
      return false;
    case SONG4:
      if (record->event.pressed) PLAY_SONG(tone_song4);
      return false;
    case SONG5:
      if (record->event.pressed) PLAY_SONG(tone_song5);
      return false;
#endif

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

#ifdef MACRO_ENGLISH_DICTIONARY
    // Use English Dictionary on browser
    //
    // Prerequisites:
    //
    // * Browser
    //   * Chrome web browser must be pinned 1st app on taskbar in Windows 8, 10 or lator.
    //   * The dictionary must be defined as alternative search engine on Chrome.
    //   * Search engine keyword must be `e`.
    // * Your words must be copied into clipboard.
    // * Shortcut for pasting from clipboard must be assigned `Ctrl + V`.
    // * Configuration:
    //   * Press Muhenkan(無変換) key to off Japanese IME.
    case ENGLISH_DICTIONARY:
      if (record->event.pressed) {
        // IME off
        SEND_STRING(SS_TAP(X_INT5));
        wait_ms(50);

        // Open new window of 1st app on taskbar(Chrome)
        // Memo: hack for press "Shift + Win + 1".
        SEND_STRING(SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_DOWN(X_LGUI));
        SEND_STRING(SS_DOWN(X_1));
        wait_ms(50);
        SEND_STRING(SS_UP(X_1));
        SEND_STRING(SS_UP(X_LGUI));
        SEND_STRING(SS_UP(X_LSHIFT));
        wait_ms(500);

        // Select addressbar
        SEND_STRING(SS_LCTRL("l"));

        // Input search engine keyword
        SEND_STRING("e");
        wait_ms(50);
        SEND_STRING(SS_TAP(X_TAB));
        wait_ms(50);

        // Paste words from clipboard
        SEND_STRING(SS_LCTRL("v"));

        // Search as current tab
        SEND_STRING(SS_TAP(X_ENTER));
      }
      return false;
      break;
#endif
  }

  return true;
}
