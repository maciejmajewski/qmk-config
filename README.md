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

Build with `qmk`:

```sh
qmk compile -kb preonic/rev3_drop -km mmaj
```

#### K3 Pro

```
cd /Users/maj/Development/qmk/qmk_firmware_keychron/keyboards/keychron/k3_pro/ansi/rgb/keymaps
ln -s ../../../../../../../keyboards-config-qmk/k3_pro maj

qmk config user.qmk_home=/Users/maj/Development/qmk/qmk_firmware_keychron
qmk compile -kb keychron/k3_pro/ansi/rgb -km maj
```

Reset Key: Connect the USB cable, toggle mode switch to "Off", hold down the Esc key or reset button underneath space bar, then toggle then switch to "Cable".