/********************************************************************
 Software License Agreement:

 The software supplied herewith by Microchip Technology Incorporated
 (the "Company") for its PIC(R) Microcontroller is intended and
 supplied to you, the Company's customer, for use solely and
 exclusively on Microchip PIC Microcontroller products. The
 software is owned by the Company and/or its supplier, and is
 protected under applicable copyright laws. All rights are reserved.
 Any use in violation of the foregoing restrictions may subject the
 user to criminal sanctions under applicable laws, as well as to
 civil liability for the breach of the terms and conditions of this
 license.

 THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *******************************************************************/
#include <system.h>

/* Demo I/O options. */
#define LED_USB_DEVICE_STATE                            LED_D1
#define LED_USB_DEVICE_HID_KEYBOARD_CAPS_LOCK           LED_D2

#define BUTTON_USB_DEVICE_HID_KEYBOARD_KEY              BUTTON_S1
#define BUTTON_USB_DEVICE_REMOTE_WAKEUP                 BUTTON_S1

//#define BUTTON_MAP
//#define BUTTON_VOICE_SEARCH
//#define BUTTON_USER0
//#define BUTTON_USER1
#define BUTTON_VOL_UP                                   BUTTON_S6
#define BUTTON_VOL_DN                                   BUTTON_S5

/* keyboard key code values */
#define KEY_VAL_VOL_UP                                  (128)
#define KEY_VAL_VOL_DN                                  (129)
#define KEY_VAL_ESC                                     (0x29)

#define CDC_TYPE_LAUNCH                                 (0x01)
#define CDC_VAL_KEY1                                    (1)
#define CDC_VAL_KEY2                                    (2)
#define CDC_VAL_KEY3                                    (3)
#define CDC_VAL_KEY4                                    (4)
#define CDC_VAL_KEY5                                    (5)

/* USB Stack I/O options. */
#define self_power                                      1
