#include "variant.h"
#include "wiring_constants.h"
#include "wiring_digital.h"
#include "nrf.h"

const uint32_t g_ADigitalPinMap[] =
{
    // Left side, top to bottom
    8,   // D0 = P0.08 (RX)
    6,   // D1 = P0.06 (TX)
    17,  // D2 = P0.17 (SCK)
    20,  // D3 = P0.20 (MISO)
    22,  // D4 = P0.22 (MOSI)
    24,  // D5 = P0.24 (CS)
    32,  // D6 = P1.00 (SDA)
    11,  // D7 = P0.11 (SCL)
    36,  // D8 = P1.04
    38,  // D9 = P1.06

    // Right side, bottom to top
    9,   // D10 = P0.09 (NFC1)
    0xFF, // D11 - not brought out
    0xFF, // D12 - not brought out
    0xFF, // D13 - not brought out
    43,  // D14 = P1.11
    45,  // D15 = P1.13 (SDA1)
    10,  // D16 = P0.10 (NFC2)
    0xFF, // D17 - not brought out
    47,  // D18 = P1.15 (SCL1)
    2,   // D19 = P0.02 (A2)
    29,  // D20 = P0.29 (A1)
    31,  // D21 = P0.31 (A0)

    // External VCC cutoff control
    13,  // D22 = P0.13 (EXT_VCC)
};

void initVariant()
{
    // enable EXT_VCC by default
    pinMode(EXT_VCC, OUTPUT);
    digitalWrite(EXT_VCC, HIGH);
}
