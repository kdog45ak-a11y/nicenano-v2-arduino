#ifndef _NICE_NANO_V2_H_
#define _NICE_NANO_V2_H_

#define TARGET_NICE_NANO_V2

/** Master clock frequency */
#define VARIANT_MCK       (64000000ul)

#define USE_LFXO      // Board uses 32khz crystal for LF
//#define USE_LFRC    // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#define PINS_COUNT           (23)
#define NUM_DIGITAL_PINS     (23)
#define NUM_ANALOG_INPUTS    (3)
#define NUM_ANALOG_OUTPUTS   (0)

// NOTE:
//
// BATTERY VOLTAGE IS READ VIA VDDH/5 BY CALLING
//
// analogReadVDDHDIV5() // returns uint32_t

// 3V3 Regulator Disable
#define PIN_EXT_VCC          (22) // EXT_VCC is P0.13 (set low to disable 3v3)
#define EXT_VCC              (PIN_EXT_VCC)

// LEDs
#define PIN_LED              (PINS_COUNT) // no LED on this board
#define LED_BLUE             (PINS_COUNT) // required by Bluefruit52Lib; no physical LED
#define LED_RED              (PINS_COUNT) // required by some Adafruit libs; no physical LED
#define LED_PWR              (PINS_COUNT) // no LED_PWR
#define PIN_NEOPIXEL         (PINS_COUNT) // no neopixel
#define NEOPIXEL_NUM         0
#define LED_BUILTIN          (PINS_COUNT) // no built-in LED

#define LED_STATE_ON         1         // State when LED is on

/*
 * Buttons
 */
#define PIN_BUTTON1          (PINS_COUNT) // no button

// Digital PINs
// Pin numbers follow the physical nice!nano V2 board layout.
//
// Left side (top to bottom, USB end first):
//   D0  = P0.08  (RX)
//   D1  = P0.06  (TX)
//   D2  = P0.17  (SCK)
//   D3  = P0.20  (MISO)
//   D4  = P0.22  (MOSI)
//   D5  = P0.24  (CS)
//   D6  = P1.00  (SDA)
//   D7  = P0.11  (SCL)
//   D8  = P1.04
//   D9  = P1.06
//
// Right side (bottom to top, opposite end first):
//   D10 = P0.09  (NFC1)
//   D11 = not brought out
//   D12 = not brought out
//   D13 = not brought out
//   D14 = P1.11
//   D15 = P1.13  (SDA1)
//   D16 = P0.10  (NFC2)
//   D17 = not brought out
//   D18 = P1.15  (SCL1)
//   D19 = P0.02  (A2)
//   D20 = P0.29  (A1)
//   D21 = P0.31  (A0)
//   D22 = P0.13  (EXT_VCC)

#define D0  (0ul)  // P0.08 (RX)
#define D1  (1ul)  // P0.06 (TX)
#define D2  (2ul)  // P0.17 (SCK)
#define D3  (3ul)  // P0.20 (MISO)
#define D4  (4ul)  // P0.22 (MOSI)
#define D5  (5ul)  // P0.24 (CS)
#define D6  (6ul)  // P1.00 (SDA)
#define D7  (7ul)  // P0.11 (SCL)
#define D8  (8ul)  // P1.04
#define D9  (9ul)  // P1.06

#define D10 (10ul) // P0.09 (NFC1)
#define D11 (11ul) // not brought out
#define D12 (12ul) // not brought out
#define D13 (13ul) // not brought out
#define D14 (14ul) // P1.11
#define D15 (15ul) // P1.13 (SDA1)
#define D16 (16ul) // P0.10 (NFC2)
#define D17 (17ul) // not brought out
#define D18 (18ul) // P1.15 (SCL1)
#define D19 (19ul) // P0.02 (A2)
#define D20 (20ul) // P0.29 (A1)
#define D21 (21ul) // P0.31 (A0)

/*
 * Macros for nRF pin numbers for compatibility
 */
#define P0_08 (D0)
#define P0_06 (D1)
#define P0_17 (D2)
#define P0_20 (D3)
#define P0_22 (D4)
#define P0_24 (D5)
#define P1_00 (D6)
#define P0_11 (D7)
#define P1_04 (D8)
#define P1_06 (D9)
#define P0_09 (D10)
#define P1_11 (D14)
#define P1_13 (D15)
#define P0_10 (D16)
#define P1_15 (D18)
#define P0_02 (D19)
#define P0_29 (D20)
#define P0_31 (D21)
#define P0_13 (PIN_EXT_VCC)

/*
 * Analog pins
 */
#define PIN_A0               (21) // P0.31 (D21)
#define PIN_A1               (20) // P0.29 (D20)
#define PIN_A2               (19) // P0.02 (D19)

static const uint8_t A0  = PIN_A0 ;
static const uint8_t A1  = PIN_A1 ;
static const uint8_t A2  = PIN_A2 ;
#define ADC_RESOLUTION    12

/*
 * Other pins
 */
#define PIN_NFC1             (10) // P0.09 - also D10
#define PIN_NFC2             (16) // P0.10 - also D16

/*
 * Serial interfaces
 */
#define PIN_SERIAL1_TX       (1) // P0.06 - also D1
#define PIN_SERIAL1_RX       (0) // P0.08 - also D0

/*
 * SPI Interfaces
 */
#define SPI_INTERFACES_COUNT 2

#define PIN_SPI_SCK          (2)  // P0.17 - D2
#define PIN_SPI_MISO         (3)  // P0.20 - D3
#define PIN_SPI_MOSI         (4)  // P0.22 - D4

static const uint8_t SS   = (5);  // P0.24 - D5
static const uint8_t MOSI = PIN_SPI_MOSI ;
static const uint8_t MISO = PIN_SPI_MISO ;
static const uint8_t SCK  = PIN_SPI_SCK ;

#define PIN_SPI1_SCK          (18) // P1.15 - D18
#define PIN_SPI1_MISO         (16) // P0.10 - D16
#define PIN_SPI1_MOSI         (20) // P0.29 - D20

/*
 * Wire Interfaces
 */
#define WIRE_INTERFACES_COUNT 2

#define PIN_WIRE_SDA         (6) // P1.00 - D6
#define PIN_WIRE_SCL         (7) // P0.11 - D7

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#define PIN_WIRE1_SDA        (15) // P1.13 - D15
#define PIN_WIRE1_SCL        (18) // P1.15 - D18

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
