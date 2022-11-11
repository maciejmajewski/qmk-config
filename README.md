# QMK keymaps

Custom QMK keymaps for Moonlander and Preonic keyboards.

## Preonic

### Building

Symlink this repo:

```sh
# git clone ....
cd qmk_firmware
cd keyboards/preonic/keymaps
ln -s ../../../../qmk-keymaps/preonic mmaj
```

To build with `qmk`:

```sh
qmk compile -kb preonic/rev3_drop -km mmaj
```
