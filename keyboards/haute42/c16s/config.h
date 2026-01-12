/* Copyright 2025 Ed Flanagan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// Bootloader
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

// OLED
#define OLED_DISPLAY_128X64
// #define OLED_BRIGHTNESS 128
// #define OLED_IC OLED_IC_SSD1306 // Default
#define OLED_SCROLL_TIMEOUT 60000
#define OLED_TIMEOUT 0

// I2C
#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP0
#define I2C1_SCL_PIN GP1

// SPI
// https://github.com/raspberrypi/pico-sdk/blob/2.2.0/src/boards/include/boards/pico.h#L52
#define SPI_MISO_PIN GP16 // i.e., RX
#define SPI_CSN_PIN GP17  // NOTE: unused
#define SPI_SCK_PIN GP18  // pico-sdk default
#define SPI_MOSI_PIN GP19 // i.e., TX

// #define UART_DRIVER SIOD0
#define UART_TX_PIN GP23
#define UART_RX_PIN GP24

// WS2812
// #define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB
#define WS2812_PIO_USE_PIO1
// #define WS2812_RGBW
#define WS2812_SPI_USE_CIRCULAR_BUFFER

// RGB
#define RGB_MATRIX_DISABLE_SHARED_KEYCODES
#define RGBLIGHT_DISABLE_DYNAMIC_STEPS
#define RGBLIGHT_SPD_MAX 100

// Joystick
#define JOYSTICK_BUTTON_COUNT 21
