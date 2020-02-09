#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _FN,
    _ADJ
};

// Keycode defines for layers
#define QWERTY   DF(_QWERTY)
#define COLEMAK  DF(_COLEMAK)
#define FN       MO(_FN)
#define ADJ      MO(_ADJ)

enum custom_keycodes {
  RGBRST = SAFE_RANGE
};

#define FN_ESC   LT(_FN, KC_ESC)
#define FN_CAPS  LT(_FN, KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,------------------------------------------------.  ,------------------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |   -  |  |   =  |   6  |   7  |   8  |   9  |   0  | BkSp |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |  |   ]  |   Y  |   U  |   I  |   O  |   P  |   \  |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |FN(CAPS)| A  |   S  |   D  |   F  |   G  |   (  |  |   )  |   H  |   J  |   K  |   L  |   ;  |   '  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   V  |   B  |   {  |  |   }  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Ctrl |  Win |  Alt |  RGB | ADJ  | Space| DEL  |  | Enter| Space|  FN  | Left | Down | Up   |Right |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    | Space| DEL  |  | Enter| Space|
   *                                    `-------------'  `-------------'
   */
  [_QWERTY] = LAYOUT( \
    KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_MINS,  KC_EQL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, \
     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC, KC_RBRC,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS, \
    FN_CAPS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_LPRN, KC_RPRN,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LCBR, KC_RCBR,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT, \
    KC_LCTL, KC_LGUI, KC_LALT, RGB_TOG,     ADJ,  KC_SPC,  KC_DEL,  KC_ENT,  KC_SPC,      FN, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, \
                                                  KC_SPC,  KC_DEL,  KC_ENT,  KC_SPC \
  ),

  /* Colemak
   * ,------------------------------------------------.  ,------------------------------------------------.
   * | GESC |   1  |   2  |   3  |   4  |   5  |   -  |  |   =  |   6  |   7  |   8  |   9  |   0  | BkSp |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   F  |   P  |   B  |   [  |  |   ]  |   J  |   L  |   U  |   Y  |   ;  |   \  |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |FN(CAPS)| A  |   R  |   S  |   T  |   G  |   (  |  |   )  |   K  |   N  |   E  |   I  |   O  |   '  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |Shift |   Z  |   X  |   C  |   D  |   V  |   {  |  |   }  |   M  |   H  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * | Ctrl |  Win |  Alt |  RGB | ADJ  | Space| DEL  |  | Enter| Space|  FN  | Left | Down | Up   |Right |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    | Space| DEL  |  | Enter| Space|
   *                                    `-------------'  `-------------'
   */
  [_COLEMAK] = LAYOUT( \
    KC_GESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_MINS,  KC_EQL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, \
     KC_TAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G, KC_LBRC, KC_RBRC,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSLS, \
    FN_CAPS,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D, KC_LPRN, KC_RPRN,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, \
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LCBR, KC_RCBR,    KC_K,    KC_M, KC_COMM, KC_DOT,  KC_SLSH,  KC_ENT, \
    KC_LCTL, KC_LGUI, KC_LALT, RGB_TOG,     ADJ,  KC_SPC,  KC_DEL,  KC_ENT,  KC_SPC,      FN, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, \
                                                  KC_SPC,  KC_DEL,  KC_ENT,  KC_SPC \
  ),

  /* FN
   * ,------------------------------------------------.  ,------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | PGDN |  UP  | PGUP |      |      |      |  |      |      | PGDN |  UP  | PGUP | PRINT| HOME |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | LEFT | DOWN | RIGHT|      |      |      |  |      |      | LEFT | DOWN | RIGHT|INSERT| END  |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |      |      |RGBMOD|      |      |      |  |      |      | PLAY | NEXT | MUTE | VOL- | VOL+ |
   * `------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    |      |      |  |      |      |
   *                                    `-------------'  `-------------'
   */
  [_FN] = LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______, KC_PSCR,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, \
    _______, KC_PGDN,   KC_UP, KC_PGUP, _______, _______, _______, KC_SLCK, _______, KC_PGDN,   KC_UP, KC_PGUP, KC_PSCR, KC_HOME, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_NLCK, _______, KC_LEFT, KC_DOWN, KC_RGHT,  KC_INS,  KC_END, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, RGB_MOD, _______, _______, _______, _______, _______, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, \
                                                 _______, _______, _______, _______ \
  ),

  /* ADJ
   * ,------------------------------------------------.  ,------------------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | SAD  | VAI  | SAI  | RESET|      |      |  |      |      |  P7  |  P8  |  P9  |      |      |
   * |------+------+------+------+------+------|------|  |------|------+------+------+------+------+------|
   * |      | HUD  | VAD  | HUI  |RGBRST|      |      |  |      |      |  P4  |  P5  |  P6  |      |      |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      | SPD  |      | SPI  |      |      |      |  |      |      |  P1  |  P2  |  P3  |      |      |
   * |------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
   * |      |      |      |RGBMOD|      |      |      |  |      |      |  P0  | PDOT | NLCK |QWERTY|COLEMK|
   * `------+------+------+------+------+------+------|  |------+------+------+------+------+------+------'
   *                                    |      |      |  |      |      |
   *                                    `-------------'  `-------------'
   */

  [_ADJ] =  LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, _______, _______,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, \
    _______, RGB_SAD, RGB_VAI, RGB_SAI,   RESET, _______, _______, _______, _______,   KC_P7,   KC_P8,  KC_P9,  _______, _______, \
    _______, RGB_HUD, RGB_VAD, RGB_HUI,  RGBRST, _______, _______, _______, _______,   KC_P4,   KC_P5,  KC_P6, _______, _______, \
    _______, RGB_SPD, _______, RGB_SPI, _______, _______, _______, _______, _______,   KC_P1,   KC_P2,  KC_P3, _______, _______, \
    _______, _______, _______, RGB_MOD, _______, _______, _______, _______, _______,   KC_P0, KC_PDOT, KC_NLCK,  QWERTY, COLEMAK, \
                                                 _______, _______, _______, _______ \
  )
};

// For RGBRST Keycode
#if defined(RGB_MATRIX_ENABLE)
void rgb_matrix_increase_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}

void rgb_matrix_decrease_flags(void)
{
    switch (rgb_matrix_get_flags()) {
        case LED_FLAG_ALL: {
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_disable_noeeprom();
            }
            break;
        case LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER: {
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        case LED_FLAG_UNDERGLOW: {
            rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER);
            rgb_matrix_set_color_all(0, 0, 0);
            }
            break;
        default: {
            rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
            rgb_matrix_enable_noeeprom();
            }
            break;
    }
}
#endif

#ifdef ENCODER_ENABLE

static pin_t encoders_pad_a[] = ENCODERS_PAD_A;
#define NUMBER_OF_ENCODERS (sizeof(encoders_pad_a)/sizeof(pin_t))

const uint16_t PROGMEM encoders[][NUMBER_OF_ENCODERS * 2][2]  = {
    [_QWERTY] = ENCODER_LAYOUT( \
        KC_VOLU, KC_VOLD,
        KC_VOLU, KC_VOLD
    ),
    [_COLEMAK] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_FN] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    ),
    [_ADJ] = ENCODER_LAYOUT( \
        _______, _______,
        _______, _______
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (!is_keyboard_master())
    return;

  {
    uint8_t layer = biton32(layer_state);
    uint16_t keycode = pgm_read_word(&encoders[layer][index][clockwise]);
    while (keycode == KC_TRANSPARENT && layer > 0)
    {
      layer--;
      if ((layer_state & (1 << layer)) != 0)
          keycode = pgm_read_word(&encoders[layer][index][clockwise]);
    }
    if (keycode != KC_TRANSPARENT)
      tap_code16(keycode);
  }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t reset_timer;
  switch (keycode) {
    case RGBRST:
#if defined(RGB_MATRIX_ENABLE)
        if (record->event.pressed) {
          eeconfig_update_rgb_matrix_default();
        }
#endif
      return false;
    case RESET:
      if (record->event.pressed) {
          reset_timer = timer_read();
      } else {
          if (timer_elapsed(reset_timer) >= 500) {
              reset_keyboard();
          }
      }
      return false;
#if defined(RGB_MATRIX_ENABLE) && defined(KEYBOARD_rgbkb_sol_rev2)
    case RGB_TOG:
      if (record->event.pressed) {
        rgb_matrix_increase_flags();
      }
      return false;
#endif
  }
  return true;
}
