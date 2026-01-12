# ![Haute42 Cosmox C16-S](https://cosmoxgaming.com/c16/)

* Keyboard Maintainer: [Ed Flanagan](https://github.com/ed-flanagan)
* Hardware Supported: RP2040
* Hardware Availability: Amazon, Alibaba

## About

The C16-S buttons are sequenced in this order:
```
                           0 1 2 3 4

    ┌───┬───┬───┐    ┌───┬───┬───┐
┌───┤ 5 │ 6 │ 7 ├────┤ 9 │ 10│ 11├───┐
│ 18├───┴───┴───┤ 20 ├───┼───┼───┤ 19│
└───┘           └────┤ 13│ 14│ 15├───┘
                     └───┴───┴───┘
        ┌───┐             ┌───┐
        │ 12├───┐    ┌────┤ 16│
        └───┤ 8 │    │ 17 ├───┘
            └───┘    └────┘
```

Here's how I think about grouping them logically, given their pin order:

```
[0,   1,  2,  3, 4] <- The smaller, upper row buttons (start, select, etc.)
[5,   6,  7,  8]    <- Directional buttons (Thumb being one)
[9,  10, 11, 12]    <- Top row action buttons. `12` would normally be fourth
                       button in this row, moved for this model
[13, 14, 15, 16]    <- Second row action buttons. `16` would normally be fourth
                       button in this row, moved for this model
[17, 18, 19, 20]    <- 17/20 are the "additional" buttons. 18/19 are the
                       thumbstick buttons
```

For a small optimization, since matrix rows are a minimum 1 byte, I "pack"
some groups together:

```
[ 0,  1,  2,  3 |  4]  _   _   _
[ 5,  6,  7,  8 |  9, 10, 11, 12]
[13, 14, 15, 16 | 17, 18, 19, 20]
```

I'm sure you could further "optimize", but may make the layouts needlessly
obtuse to manage.

---

The default Joystick layout:

```
          _ <FN> <HOME> <BACK> <START>

     ┌───┬───┬───┐    ┌────┬────┬────┐
┌────┤ < │ V │ > ├────┤ B3 │ B4 │ R1 ├────┐
│ L3 ├───┴───┴───┤ M2 ├────┼────┼────┤ R3 │
└────┘           └────┤ B1 │ B2 │ R2 ├────┘
                      └────┴────┴────┘
        ┌────┐             ┌────┐
        │ L1 ├───┐    ┌────┤ L2 │
        └────┤ ^ │    │ M1 ├────┘
             └───┘    └────┘
```

The default Keyboard layout:

```
                           o o o o o

    ┌───┬───┬───┐    ┌───┬───┬───┐
┌───┤ A │ S │ D ├────┤ J │ K │ L ├───┐
│ E ├───┴───┴───┤ M2 ├───┼───┼───┤ R │
└───┘           └────┤ M │ , │ . ├───┘
                     └───┴───┴───┘
        ┌───┐             ┌───┐
        │Spc├───┐    ┌────┤ U │
        └───┤ W │    │ M1 ├───┘
            └───┘    └────┘
```

---

The default Function layer:

```
                           <GK_BOOT> o o o o

    ┌─────────┬───┬─────────┐        ┌─────────┬─────────┬─────────┐
┌───┤ RM_PREV │ _ │ RM_NEXT ├────────┤ RM_HUEU │ RM_SPDU │ RM_HUEU ├─────────┐
│ _ ├─────────┴───┴─────────┤ EE_CLR ├─────────┼─────────┼─────────┤ RM_TOGG │
└───┘                       └────────┤ RM_HUED │ RM_SPDD │ RM_HUED ├─────────┘
                                     └─────────┴─────────┴─────────┘
                    ┌───┐                ┌───┐
                    │ _ ├───┐        ┌───┤ _ │
                    └───┤ _ │        │ _ ├───┘
                        └───┘        └───┘
```

---

Just for reference, how Joystick buttons map:

| Input   | Generic | XInput | PS3/4/5  | Switch | HID |
| ------- | ------- | ------ | -------- | ------ | --- |
| `JS_0`  | B1      | A      | X        | B      | 0   |
| `JS_1`  | B2      | B      | O        | A      | 1   |
| `JS_2`  | B3      | X      | □        | Y      | 2   |
| `JS_3`  | B4      | Y      | ∆        | X      | 3   |
| `JS_4`  | L1      | L1     | L1       | L1     | 4   |
| `JS_5`  | R1      | R1     | R1       | R1     | 5   |
| `JS_6`  | L2      | L2     | L2       | L2     | 6   |
| `JS_7`  | R2      | R2     | R2       | R2     | 7   |
| `JS_8`  | S1      | Back   | Select   | Minus  | 8   |
| `JS_9`  | S2      | Start  | Options  | Plus   | 9   |
| `JS_10` | L3      | LS     | LS       | L3     | 10  |
| `JS_11` | R3      | RS     | RS       | R3     | 11  |
| `JS_12` | UP      | UP     | UP       | UP     | 12  |
| `JS_13` | DOWN    | DOWN   | DOWN     | DOWN   | 13  |
| `JS_14` | LEFT    | LEFT   | LEFT     | LEFT   | 14  |
| `JS_15` | RIGHT   | RIGHT  | RIGHT    | RIGHT  | 15  |
| `JS_16` | S3      | Guide  | PS       | Home   | 16  |
| `JS_17` | ??      | ??     | Touch?   | ??     | 17  |

## Build

Make example for this keyboard (after setting up your build environment):

```
qmk compile -kb haute42/c16s -km default -j (nproc)
```

Flashing example for this keyboard:

```
qmk flash -kb haute42/c16s -km default -j (nproc)
```

See the
[build environment setup](https://docs.qmk.fm/#/getting_started_build_tools)
and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide)
for more information. Brand new to QMK? Start with our
[Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button** -- briefly press the button on the back of the
  PCB - some may have pads you must short instead
* **Keycode in layout** -- press the key mapped to `QK_BOOT`
