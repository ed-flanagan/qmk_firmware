# Haute42 C16-S

![Haute42 C16-S](https://google.com)

The Haute42 Cosmox C16-S

* Keyboard Maintainer: [Ed Flanagan](https://github.com/ed-flanagan)
* Hardware Supported: RP2040
* Hardware Availability: Amazon

Make example for this keyboard (after setting up your build environment):

    make haute42_c16s:default

Flashing example for this keyboard:

    make haute42_c16s:default:flash

See the
[build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide)
for more information. Brand new to QMK? Start with our
[Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: Briefly press the button on the back of the PCB -
  some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT`
