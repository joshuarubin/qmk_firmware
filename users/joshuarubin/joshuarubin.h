#pragma once

#include "quantum.h"

enum custom_keycodes {
    SHRUG = SAFE_RANGE,
    TFLIP,
};

#ifdef UNICODE_ENABLE
#    define KC_NDSH UC(0x2013)
#    define KC_MDSH UC(0x2014)
#    define KC_ELIP UC(0x2026)
#else
#    define KC_NDSH KC_NO
#    define KC_MDSH KC_NO
#endif
