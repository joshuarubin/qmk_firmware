#pragma once

#undef DYNAMIC_KEYMAP_ENABLE // reduce firmware size

#undef USB_MAX_POWER_CONSUMPTION
#define USB_MAX_POWER_CONSUMPTION 500

#undef RGB_BACKLIGHT_EFFECT
#define RGB_BACKLIGHT_EFFECT 1

#define WT_RGB_RED    { .h = 0,   .s = 255 }
#define WT_RGB_PURPLE { .h = 204, .s = 255 }
#define WT_RGB_BLUE   { .h = 127, .s = 255 }
#define WT_RGB_ORANGE { .h = 22,  .s = 255 }

#undef RGB_BACKLIGHT_COLOR_1
#define RGB_BACKLIGHT_COLOR_1 WT_RGB_PURPLE

#undef RGB_BACKLIGHT_COLOR_2
#define RGB_BACKLIGHT_COLOR_2 WT_RGB_BLUE

// index
// 255: disabled
// 254: all keys
// else: specific backlight number from 0 to BACKLIGHT_LED_COUNT
#undef RGB_BACKLIGHT_LAYER_1_INDICATOR
#define RGB_BACKLIGHT_LAYER_1_INDICATOR { .color = RGB_BACKLIGHT_COLOR_2, .index = 254 }

// don't change config layer because you can't see the changes

#undef RGB_BACKLIGHT_EFFECT_SPEED
#define RGB_BACKLIGHT_EFFECT_SPEED 2

// underglow
#define RGB_DI_PIN B0          // The pin your RGB strip is wired to
#define RGBLED_NUM 36          // Number of LEDs
#define RGBSTRIP_CURRENT_LIMIT 1000       // current limit in mA. (USB amperage - 500mA for keyboard)
#define RGBSTRIP_MAX_CURRENT_PER_LIGHT 60 // mA per light when at max brightness.
