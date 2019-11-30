/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6061
#define MANUFACTURER    OLKB
#define PRODUCT         Preonic
#define DESCRIPTION     A compact ortholinear keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

/* Planck PCB default pin-out */
#define MATRIX_ROW_PINS { D7, C6, D4, D0, D1 }
#define MATRIX_COL_PINS { F7, F6, F5, F4, F0, F1, B4, B5, B6, B7, D6, C7 }
#define UNUSED_PINS

#define QMK_ESC_OUTPUT E1
#define QMK_ESC_INPUT E5
#define QMK_LED     E6
#define QMK_SPEAKER E2

#define AUDIO_VOICES
#define C6_AUDIO

#define BACKLIGHT_PIN E7

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
#define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#ifdef PS2_USE_INT
#define PS2_CLOCK_PORT  PORTD
#define PS2_CLOCK_PIN   PIND
#define PS2_CLOCK_DDR   DDRD
#define PS2_CLOCK_BIT   2
#define PS2_DATA_PORT   PORTD
#define PS2_DATA_PIN    PIND
#define PS2_DATA_DDR    DDRD
#define PS2_DATA_BIT    3


#define PS2_INT_INIT()  do {	 \
     EICRA |= ((1<<ISC21) |      \
               (0<<ISC20));      \
 } while (0)
#define PS2_INT_ON()  do {	 \
     EIMSK |= (1<<INT2);         \
 } while (0)
#define PS2_INT_OFF() do {	 \
     EIMSK &= ~(1<<INT2);        \
 } while (0)
#define PS2_INT_VECT   INT2_vect
#endif


#endif
