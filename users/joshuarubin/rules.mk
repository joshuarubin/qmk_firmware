SRC += joshuarubin.c
UNICODE_ENABLE = yes
EXTRAKEY_ENABLE = yes
SLEEP_LED_ENABLE = no

# lily58 slave side stops working if this is set
ifneq ($(strip $(KEYBOARD)), lily58/rev1)
	# enable link time optimization to reduce firmware size
	EXTRAFLAGS += -flto
endif

ifeq ($(strip $(KEYBOARD)), lets_split/rev2)
	BOOTLOADER = atmel-dfu
	AUDIO_ENABLE = yes
	RGBLIGHT_ENABLE = yes
endif

ifeq ($(strip $(KEYBOARD)), wilba_tech/zeal60)
	RGBLIGHT_ENABLE = yes
endif

ifeq ($(strip $(KEYBOARD)), lily58/rev1)
	BOOTLOADER = atmel-dfu
	RGBLIGHT_ENABLE = yes
endif

ifeq ($(strip $(KEYBOARD)), keyhive/maypad)
	BOOTLOADER = caterina
endif

ifeq ($(strip $(KEYBOARD)), kyria/rev1)
	OLED_DRIVER_ENABLE = yes
	ENCODER_ENABLE = yes
	RGBLIGHT_ENABLE = yes
endif
