# nice!nano v2 — Arduino Board Package

Self-contained Arduino Board Manager package for the **nice!nano v2** (Nordic nRF52840).
Install once, compile and upload — no additional board packages required.

## Board Specs

| | |
|---|---|
| **MCU** | Nordic nRF52840 — ARM Cortex-M4 @ 64 MHz |
| **Flash / RAM** | 1 MB flash (815 KB usable) / 256 KB RAM |
| **Wireless** | Bluetooth 5.0 Low Energy (SoftDevice S140 6.1.1) |
| **USB** | Native USB via TinyUSB (CDC serial, HID, MSC) |
| **GPIO** | 21 digital pins (D0–D21), 3 analog inputs (A0–A2) |
| **Interfaces** | 2x I2C, 2x SPI, 1x UART |
| **Battery** | LiPo charging over USB; read voltage with `analogReadVDDHDIV5()` |
| **Bootloader** | Adafruit nRF52 DFU (double-tap reset to enter) |

## Installation

1. In the Arduino IDE, go to **File > Preferences**.
2. In **Additional Board Manager URLs**, add:
   ```
   https://raw.githubusercontent.com/kdog45ak-a11y/nicenano-v2-arduino/master/package_nicenano_index.json
   ```
3. Open **Tools > Board > Boards Manager**, search for **nice!nano**, and install **nice!nano v2 Boards**.
4. Select **Tools > Board > nice!nano v2 Boards > nice!nano v2**.

That's it. The ARM compiler, CMSIS headers, and nRF52 core are all pulled in automatically.

## Pin Map

Pins are numbered to match the physical board layout (silkscreen labels).

### Left Side (top to bottom, USB end)

| Pin | nRF52840 | Function |
|-----|----------|----------|
| D0 | P0.08 | UART RX |
| D1 | P0.06 | UART TX |
| D2 | P0.17 | SPI SCK |
| D3 | P0.20 | SPI MISO |
| D4 | P0.22 | SPI MOSI |
| D5 | P0.24 | SPI CS |
| D6 | P1.00 | I2C SDA |
| D7 | P0.11 | I2C SCL |
| D8 | P1.04 | GPIO |
| D9 | P1.06 | GPIO |

### Right Side (bottom to top)

| Pin | nRF52840 | Function |
|-----|----------|----------|
| D10 | P0.09 | GPIO (NFC1) |
| D14 | P1.11 | GPIO |
| D15 | P1.13 | I2C1 SDA |
| D16 | P0.10 | GPIO (NFC2) |
| D18 | P1.15 | I2C1 SCL |
| D19 | P0.02 | A2 |
| D20 | P0.29 | A1 |
| D21 | P0.31 | A0 |

D11, D12, D13, and D17 exist in the pin table but are not physically routed on the board.

### Special Pins

| Name | Pin | Notes |
|------|-----|-------|
| `EXT_VCC` | D22 / P0.13 | Controls the 3.3 V regulator. Defaults to HIGH (enabled). Set LOW to cut power for deep sleep. |

## GPIO Drive Strength

The nRF52840's GPIO pins default to **standard drive mode**, which sources/sinks roughly **2–4 mA**. That is not enough to drive most LEDs, buzzers, or other loads directly.

**High drive mode** increases the output to approximately **15 mA** source and sink. You should enable it on any pin that drives a load beyond basic logic levels.

### How to Enable High Drive

```cpp
#include "nrf_gpio.h"

// Helper — call once in setup() for each pin that needs it
void cfgHighDrive(uint32_t pin) {
    uint32_t nrfPin = g_ADigitalPinMap[pin];   // convert Arduino pin to nRF pin
    nrf_gpio_cfg(nrfPin,
                 NRF_GPIO_PIN_DIR_OUTPUT,
                 NRF_GPIO_PIN_INPUT_DISCONNECT,
                 NRF_GPIO_PIN_NOPULL,
                 NRF_GPIO_PIN_H0H1,             // high drive both directions
                 NRF_GPIO_PIN_NOSENSE);
}

void setup() {
    pinMode(D2, OUTPUT);
    cfgHighDrive(D2);       // now D2 can push ~15 mA
    digitalWrite(D2, HIGH);
}
```

> **Rule of thumb:** If a pin drives an LED, motor driver enable, buzzer, or anything with a load resistor under ~220 ohm, use high drive.

## Battery Voltage

The nice!nano v2 reads battery voltage through an internal divider — no analog pin is consumed.

```cpp
uint32_t mv = analogReadVDDHDIV5();   // raw ADC count
float voltage = mv * 5.0 * 3.6 / 4096.0;
```

## EXT_VCC and Deep Sleep

The 3.3 V regulator can be shut off to save power:

```cpp
digitalWrite(EXT_VCC, LOW);   // cut 3.3 V rail — peripherals lose power
// enter system-off or system-on sleep here
```

Set it HIGH again (or reset the board) to restore power. `EXT_VCC` is enabled by default at startup.

## Upload

The board uses the **Adafruit nRF52 DFU bootloader** over USB serial. Select the correct COM port under **Tools > Port** and click Upload. The IDE will automatically trigger the bootloader via a 1200-baud touch.

If the board is unresponsive, **double-tap the reset button** to force the bootloader. A new drive may appear (UF2 mode) — you can drag-and-drop a `.uf2` firmware file onto it, or just click Upload in the IDE.

## License

Board package structure and build recipes are based on the [Adafruit nRF52 Arduino platform](https://github.com/adafruit/Adafruit_nRF52_Arduino) (LGPL 2.1).
The Nordic SDK and ARM CMSIS components retain their original licenses.
