#pragma once

#ifndef USB_MAX_POWER_CONSUMPTION
#    define USB_MAX_POWER_CONSUMPTION 100
#endif

#define PERMISSIVE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define UNICODE_SELECTED_MODES UC_LNX, UC_OSX
#define UNICODE_KEY_LNX LCTL(LSFT(KC_U))
#define BACKLIGHT_BREATHING

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS

#    undef RGBLIGHT_HUE_STEP
#    define RGBLIGHT_HUE_STEP 5  // How much each press of rgb_hue changes hue

#    undef RGBLIGHT_SAT_STEP
#    define RGBLIGHT_SAT_STEP 10  // How much each press of rgb_sat changes sat

#    undef RGBLIGHT_VAL_STEP
#    define RGBLIGHT_VAL_STEP 10  // How much each press of rgb_val changes val
#endif

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#ifdef KEYBOARD_planck_rev6
#    define ENCODER_RESOLUTION 4
#    define TAP_CODE_DELAY 10
#endif

#ifdef KEYBOARD_lets_split
#    define EE_HANDS
#    undef RGBLED_NUM
#    define RGBLED_NUM 10
#    undef RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_EFFECT_BREATHING
#    define C6_AUDIO
#endif

#ifdef KEYBOARD_lily58_rev1
#    undef USB_MAX_POWER_CONSUMPTION
#    define USB_MAX_POWER_CONSUMPTION 500
#    define EE_HANDS
#    define SSD1306OLED
#    undef RGBLED_NUM
#    define RGBLED_NUM 70
#    define RGBLIGHT_LIMIT_VAL 120
#    define B7_AUDIO
#endif

#ifdef KEYBOARD_wilba_tech_zeal60
#    include "config_zeal60.h"
#endif

#ifdef KEYBOARD_kyria_rev1
#    ifdef OLED_DRIVER_ENABLE
#        define OLED_DISPLAY_128X64
#    endif
#    define EE_HANDS
#    define ENCODER_RESOLUTION 2
#endif

#ifdef KEYBOARD_pancake_feather
#    define OUTPUT_AUTO_ENABLE
#endif

#ifdef KEYBOARD_hhkb
#    undef DEBOUNCE
#    define DEBOUNCE 0
#endif
