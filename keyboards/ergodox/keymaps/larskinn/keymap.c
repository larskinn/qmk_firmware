#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define _______ KC_TRNS
#define xxxxxxx KC_NO

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)

enum {
  BASE = 0,
  COLEMAK,
  GAME,
  SYMB,
  ARRW,
  MDIA,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Base (Qwerty) layer
 *
 * ,---------------------------------------------------.          ,---------------------------------------------------.
 * |         |   1  |   2  |   3  |   4  |   5  |  =   |          |   -  |  6   |  7   |  8   |  9   |  0   | Colemak |
 * |---------+------+------+------+------+-------------|          |------+------+------+------+------+------+---------|
 * |    `~   |   Q  |   W  |   E  |   R  |   T  |  [   |          |   ]  |  Y   |  U   |  I   |  O   |  P   |    \    |
 * |---------+------+------+------+------+------|      |          |      |------+------+------+------+------+---------|
 * | Tab/Arw |   A  |   S  |   D  |   F  |   G  |------|          |------|  H   |  J   |  K   |  L   |  ;   |    '    |
 * |---------+------+------+------+------+------| Hyper|          |  Del |------+------+------+------+------+---------|
 * |         |   Z  |   X  |   C  |   V  |   B  |      |          |      |  N   |  M   |  ,   |  .   |  /   |         |
 * `---------+------+------+------+------+-------------'          `-------------+------+------+------+------+---------'
 *   |       |      |      |      | Alt  |                                      | Ctrl |      |      |      |      |
 *   `-----------------------------------'                                      `----------------------------------'
 *                                       ,-------------.          ,-------------.
 *                                       |  Gui | Ctrl |          | Ctrl | Gui  |
 *                                ,------|------|------|          |------+------+------.
 *                                |      |      | Games|          | Symb |      |      |
 *                                | BkSp | Shift|------|          |------| Enter| Space|
 *                                |      |      | Esc  |          |AltGr |      |      |
 *                                `--------------------'          `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(
        // left hand
        xxxxxxx,         KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_EQL,
        KC_GRV,          KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_LBRC,
        LT(ARRW,KC_TAB), KC_A,    KC_S,     KC_D,    KC_F,    KC_G,
        xxxxxxx,         KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_HYPR,
        xxxxxxx,         xxxxxxx, xxxxxxx,  xxxxxxx, OS_LALT,
                                                              KC_LGUI, KC_LCTRL,
                                                                       TG(GAME),
                                                     KC_BSPC, OS_LSFT, KC_ESC,
        // right hand
        KC_MINS,         KC_6,    KC_7,     KC_8,    KC_9,    KC_0,      TG(COLEMAK),
        KC_RBRC,         KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,      KC_BSLS,
                         KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN,   KC_QUOT,
        KC_DEL,          KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH,   xxxxxxx,
                                  OS_LCTL,  xxxxxxx, xxxxxxx, xxxxxxx,   xxxxxxx,
        KC_RCTRL, OS_LGUI,
        TG(SYMB),
        OS_RALT,  KC_ENT, KC_SPC
    ),
/* Keymap 1: Colemak layer
 *
 * ,---------------------------------------------------.          ,---------------------------------------------------.
 * |         |      |      |      |      |      |      |          |      |      |      |      |      |      |         |
 * |---------+------+------+------+------+-------------|          |------+------+------+------+------+------+---------|
 * |         |   Q  |   W  |   F  |   P  |   B  |      |          |      |  J   |  L   |  U   |  Y   |  ;   |         |
 * |---------+------+------+------+------+------|      |          |      |------+------+------+------+------+---------|
 * |         |   A  |   R  |   S  |   T  |   G  |------|          |------|  M   |  N   |  E   |  I   |  O   |         |
 * |---------+------+------+------+------+------|      |          |      |------+------+------+------+------+---------|
 * |         |   Z  |   X  |   C  |   D  |   V  |      |          |      |  K   |  H   |      |      |      |         |
 * `---------+------+------+------+------+-------------'          `-------------+------+------+------+------+---------'
 *   |       |      |      |      |      |                                      |      |      |      |      |      |
 *   `-----------------------------------'                                      `----------------------------------'
 *                                       ,-------------.          ,-------------.
 *                                       |      |      |          |      |      |
 *                                ,------|------|------|          |------+------+------.
 *                                |      |      |      |          |      |      |      |
 *                                |      |      |------|          |------|      |      |
 *                                |      |      |      |          |      |      |      |
 *                                `--------------------'          `--------------------'
 */
[COLEMAK] = KEYMAP(
        // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    _______,
        _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,
        _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,
        _______, _______, _______, _______, _______,
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,
        // right hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
                 KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
        _______, KC_K,    KC_H,    _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
        _______, _______,
        _______,
        _______, _______, _______
    ),
/* Keymap 2: Gaming (qwerty) layer
 *
 * ,---------------------------------------------------.          ,---------------------------------------------------.
 * |    `~   |   1  |   2  |   3  |   4  |   5  |  =   |          |   -  |  6   |  7   |  8   |  9   |  0   |GAME off |
 * |---------+------+------+------+------+-------------|          |------+------+------+------+------+------+---------|
 * |  Symbol |   Q  |   W  |   E  |   R  |   T  | Esc  |          |  Esc |  Y   |  U   |  I   |  O   |  P   |    \    |
 * |---------+------+------+------+------+------|      |          |      |------+------+------+------+------+---------|
 * |   Tab   |   A  |   S  |   D  |   F  |   G  |------|          |------|  H   |  J   |  K   |  L   |  :   |    '    |
 * |---------+------+------+------+------+------| Hyper|          |  Del |------+------+------+------+------+---------|
 * | LShift  |   Z  |   X  |   C  |   V  |   B  |      |          |      |  N   |  M   |  ,   |  .   |  /   |  RShift |
 * `---------+------+------+------+------+-------------'          `-------------+------+------+------+------+---------'
 *   |  Ctrl | SYMB | MDIA | Gui  | Alt  |                                      |AltGr | LEFT | DOWN |  UP  | RGHT |
 *   `-----------------------------------'                                      `----------------------------------'
 *                                       ,-------------.          ,-------------.
 *                                       |  Gui | Ctrl |          | Ctrl | Gui  |
 *                                ,------|------|------|          |------+------+------.
 *                                |      |      | Games|          | Symb |      |      |
 *                                | Space| Enter|------|          |------| Tab  | BkSp |
 *                                |      |      | End  |          | PgDn |      |      |
 *                                `--------------------'          `--------------------'
 */
[GAME] = KEYMAP(  // layer 2 : Games
        // left hand
        KC_GRV,          KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    KC_EQL,
        OSL(SYMB),       KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,    KC_ESC,
        KC_TAB,          KC_A,    KC_S,     KC_D,    KC_F,    KC_G,
        KC_LSFT,         KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_HYPR,
        KC_LCTRL,        MO(SYMB),MO(MDIA), KC_LGUI, KC_LALT,
                                                              KC_LGUI, KC_LCTRL,
                                                                       KC_HOME,
                                                     KC_SPC,  KC_ENT,  KC_END,
        // right hand
        KC_MINS,         KC_6,    KC_7,     KC_8,    KC_9,    KC_0,      TG(GAME),
        KC_ESC,          KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,      KC_BSLS,
                         KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN,   KC_QUOT,
        KC_DEL,          KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH,   KC_RSFT,
                                  KC_RALT,  KC_LEFT, KC_DOWN, KC_UP,     KC_RGHT,
        KC_RCTRL, KC_RGUI,
        KC_PGUP,
        KC_PGDN,  KC_TAB, KC_BSPC
    ),
/* Keymap 3: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
       _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
       _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
       _______, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
                         _______, KC_DOT,  KC_0,    KC_EQL,  _______,
       _______, _______,
       _______,
       _______, _______, _______
),

/* Keymap 3: Arrow layer
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      | Home |  Up  |  End |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |------|           |------|      | Left | Down | Rght |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  |      |      |------|           |------| PgUp | PgDn |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */

[ARRW] = KEYMAP(
 // left hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,

                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,

                                                                // right hand
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,

        _______, _______,
        _______,
        _______, KC_PGUP, KC_PGDN
),
/* Keymap 4: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_BTN1, KC_BTN2,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 _______, _______, _______, _______, _______, KC_MPLY,
       _______,  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),

};

const uint16_t PROGMEM fn_actions[] = {
  //    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
    case 1:
      ergodox_right_led_3_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      ergodox_right_led_2_on();
      break;
    case 4:
      ergodox_right_led_3_on();
      ergodox_right_led_2_on();
      ergodox_right_led_1_on();
      break;
    default:
      // none
      break;
    }

};
