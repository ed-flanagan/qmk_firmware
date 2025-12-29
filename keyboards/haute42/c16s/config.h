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

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U

#define I2C_DRIVER I2CD0
#define I2C1_SDA_PIN GP0
#define I2C1_SCL_PIN GP1

#define OLED_DISPLAY_128X64

// #define DEBOUNCE 5

// #define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB
#define WS2812_PIO_USE_PIO1
// #define WS2812_RGBW
#define WS2812_SPI_USE_CIRCULAR_BUFFER

#define RGB_MATRIX_DISABLE_SHARED_KEYCODES

#define RGBLIGHT_DISABLE_DYNAMIC_STEPS
#define RGBLIGHT_SPD_MAX 100
