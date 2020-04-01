# MCU name
MCU = atmega32a

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = qmk-dfu

# Custom local font file
OPT_DEFS += -DOLED_FONT_H=\"common/glcdfont.c\"

ENCODER_ENABLE = yes

DEFAULT_FOLDER = rgbkb/pan/rev1
