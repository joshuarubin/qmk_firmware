#include "joshuarubin.h"

#ifdef SSD1306OLED
void set_keylog(uint16_t keycode, keyrecord_t *record);
// void set_timelog(void);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
#ifdef UNICODE_ENABLE
    case SHRUG:
      if (!record->event.pressed) {
        send_unicode_hex_string("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF"); // ¯\_(ツ)_/¯
      }
      break;
#endif

  }

  return true;
};

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
#ifdef KEYBOARD_kyria_rev1
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
        return;
    }
#endif
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}
#endif
