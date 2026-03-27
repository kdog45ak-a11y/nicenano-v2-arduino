# nice!nano v2 Arduino Board Package (pin fixed)

Arduino Board Manager package for the nice!nano v2 with the correct physical pin mapping.

## What is "pin fixed"?

The nice!nano v2 has two common pin numbering variants:

| Variant | D0 | D1 | D16 |
|---------|----|----|-----|
| **pin fixed (this package)** | P0.08 (RX) | P0.06 (TX) | P0.10 |
| USB fixed | P0.06 (TX) | P0.08 (RX) | P0.29 |

The **pin fixed** mapping follows the physical board silkscreen. Using the wrong variant silently breaks I2C (D0/D1 swapped) and drives the wrong GPIO for any peripherals on D16.

## Installation

### Step 1 — Install Adafruit nRF52

This package uses the Adafruit nRF52 core and toolchain. Install it first:

1. Open Arduino IDE → **File → Preferences**
2. Add to "Additional Boards Manager URLs":
   ```
   https://adafruit.github.io/arduino-board-index/package_adafruit_index.json
   ```
3. Open **Tools → Board → Boards Manager**, search **Adafruit nRF52**, install

### Step 2 — Install this package

1. Open **File → Preferences**
2. Add to "Additional Boards Manager URLs" (comma-separate from the Adafruit URL):
   ```
   https://raw.githubusercontent.com/kdog45ak-a11y/nicenano-v2-arduino/main/package_nicenano_index.json
   ```
3. Open **Boards Manager**, search **nice!nano**, install **nice!nano v2 Boards**
4. Select **Tools → Board → nice!nano v2 Boards → nice!nano v2 (pin fixed)**

### arduino-cli

```bash
arduino-cli core install adafruit:nrf52
arduino-cli core install nicenano:nrf52 --additional-urls https://raw.githubusercontent.com/kdog45ak-a11y/nicenano-v2-arduino/main/package_nicenano_index.json
arduino-cli compile --fqbn nicenano:nrf52:nicenanov2pf your_sketch/
arduino-cli upload  --fqbn nicenano:nrf52:nicenanov2pf --port COM22 your_sketch/
```

## Pin reference

| Function | Arduino Pin | nRF52 GPIO |
|----------|-------------|------------|
| D0 (RX)  | D0 | P0.08 |
| D1 (TX)  | D1 | P0.06 |
| D2 (SCK) | D2 | P0.17 |
| D3 (MISO)| D3 | P0.20 |
| D4 (MOSI)| D4 | P0.22 |
| D5 (CS)  | D5 | P0.24 |
| D6 (SDA) | D6 | P1.00 |
| D7 (SCL) | D7 | P0.11 |
| D8       | D8 | P1.04 |
| D9       | D9 | P1.06 |
| D10 (NFC1)| D10 | P0.09 |
| D14      | D14 | P1.11 |
| D15 (SDA1)| D15 | P1.13 |
| D16 (NFC2)| D16 | P0.10 |
| D18 (SCL1)| D18 | P1.15 |
| D19 (A2) | D19 | P0.02 |
| D20 (A1) | D20 | P0.29 |
| D21 (A0) | D21 | P0.31 |
| EXT_VCC  | D22 | P0.13 |

D11, D12, D13, D17 are not brought out on this board.

Battery voltage: `analogReadVDDHDIV5()` — no pin needed.

## Upload

Upload uses nRF52 DFU over USB. Double-tap the reset button to enter the bootloader if the upload fails to connect.

## License

`variant.h` / `variant.cpp` — MIT
`platform.txt` build system — LGPL 2.1 (derived from Adafruit nRF52 Arduino)
