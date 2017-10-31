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

#include <xc.h>
#include <stdbool.h>
#include <buttons.h>

/*** Button Definitions *********************************************/
// 16F145x RA0, RA1, and RA3 are input only
#define S1_PORT  PORTAbits.RA5
#define S2_PORT  PORTAbits.RA4
#define S3_PORT  PORTAbits.RA3
#define S4_PORT  PORTCbits.RC5
#define S5_PORT  PORTCbits.RC4
#define S6_PORT  PORTCbits.RC3

#define S1_PORT_TRIS TRISAbits.TRISA5
#define S2_PORT_TRIS TRISAbits.TRISA4
// RA3 is always input for pic16f145x
#define S4_PORT_TRIS TRISCbits.TRISC5
#define S5_PORT_TRIS TRISCbits.TRISC4
#define S6_PORT_TRIS TRISCbits.TRISC3

#define S2_PORT_ANSEL  ANSELAbits.ANSA4
#define S6_PORT_ANSEL  ANSELCbits.ANSC3


#define BUTTON_PRESSED      0
#define BUTTON_NOT_PRESSED  1

#define PIN_INPUT           1
#define PIN_OUTPUT          0

#define PIN_ANALOG          1
#define PIN_DIGITAL         0


/*********************************************************************
* Function: bool BUTTON_IsPressed(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
* PreCondition: button configured via BUTTON_SetConfiguration()
*
* Input: BUTTON button - enumeration of the buttons available in
*        this demo.  They should be meaningful names and not the names 
*        of the buttons on the silkscreen on the board (as the demo 
*        code may be ported to other boards).
*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
*
* Output: TRUE if pressed; FALSE if not pressed.
*
********************************************************************/
bool BUTTON_IsPressed(BUTTON button)
{
    switch(button)
    {
        case BUTTON_S1:
            return ( (S1_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_S2:
            return ( (S2_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_S3:
            return ( (S3_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_S4:
            return ( (S4_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_S5:
            return ( (S5_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_S6:
            return ( (S6_PORT == BUTTON_PRESSED) ? true : false);
        case BUTTON_NONE:
            return false;
    }
    return false;
}

/*********************************************************************
* Function: void BUTTON_Enable(BUTTON button);
*
* Overview: Returns the current state of the requested button
*
* PreCondition: button configured via BUTTON_SetConfiguration()
*
* Input: BUTTON button - enumeration of the buttons available in
*        this demo.  They should be meaningful names and not the names
*        of the buttons on the silkscreen on the board (as the demo
*        code may be ported to other boards).
*         i.e. - ButtonIsPressed(BUTTON_SEND_MESSAGE);
*
* Output: None
*
********************************************************************/
void BUTTON_Enable(BUTTON button)
{
    
    switch(button)
    {
        case BUTTON_S1:
            S1_PORT_TRIS = PIN_INPUT;
            break;
        case 2:
            S2_PORT_TRIS = PIN_INPUT;
            //S2_PORT_ANSEL = PIN_DIGITAL;
            ANSELA = 0; // withou this it's not working
            //OPTION_REGbits.nWPUEN = 0; // Enable weak pull-ups
            //WPUAbits.WPUA4 = 1; // Enable pull-up on RA4
            break;
        case BUTTON_S3:
            break;
        case BUTTON_S4:
            S4_PORT_TRIS = PIN_INPUT;
            break;
        case BUTTON_S5:
            S5_PORT_TRIS = PIN_INPUT;
            break;
        case BUTTON_S6:
            S6_PORT_TRIS = PIN_INPUT;
            S6_PORT_ANSEL = PIN_DIGITAL;
            break;
        case BUTTON_NONE:
            break;
        default:
            break;
    }
}
