/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16F18325
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED aliases
#define LED_TRIS               TRISAbits.TRISA0
#define LED_LAT                LATAbits.LATA0
#define LED_PORT               PORTAbits.RA0
#define LED_WPU                WPUAbits.WPUA0
#define LED_OD                ODCONAbits.ODCA0
#define LED_ANS                ANSELAbits.ANSA0
#define LED_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED_GetValue()           PORTAbits.RA0
#define LED_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED_SetPullup()      do { WPUAbits.WPUA0 = 1; } while(0)
#define LED_ResetPullup()    do { WPUAbits.WPUA0 = 0; } while(0)
#define LED_SetPushPull()    do { ODCONAbits.ODCA0 = 1; } while(0)
#define LED_SetOpenDrain()   do { ODCONAbits.ODCA0 = 0; } while(0)
#define LED_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define LED_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()    do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()   do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()   do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()         PORTCbits.RC0
#define RC0_SetDigitalInput()   do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()  do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()     do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()   do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode() do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()    do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()   do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()   do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()         PORTCbits.RC1
#define RC1_SetDigitalInput()   do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()  do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()     do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()   do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode() do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set SS aliases
#define SS_TRIS               TRISCbits.TRISC2
#define SS_LAT                LATCbits.LATC2
#define SS_PORT               PORTCbits.RC2
#define SS_WPU                WPUCbits.WPUC2
#define SS_OD                ODCONCbits.ODCC2
#define SS_ANS                ANSELCbits.ANSC2
#define SS_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define SS_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define SS_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define SS_GetValue()           PORTCbits.RC2
#define SS_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define SS_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define SS_SetPullup()      do { WPUCbits.WPUC2 = 1; } while(0)
#define SS_ResetPullup()    do { WPUCbits.WPUC2 = 0; } while(0)
#define SS_SetPushPull()    do { ODCONCbits.ODCC2 = 1; } while(0)
#define SS_SetOpenDrain()   do { ODCONCbits.ODCC2 = 0; } while(0)
#define SS_SetAnalogMode()  do { ANSELCbits.ANSC2 = 1; } while(0)
#define SS_SetDigitalMode() do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set CDIR aliases
#define CDIR_TRIS               TRISCbits.TRISC3
#define CDIR_LAT                LATCbits.LATC3
#define CDIR_PORT               PORTCbits.RC3
#define CDIR_WPU                WPUCbits.WPUC3
#define CDIR_OD                ODCONCbits.ODCC3
#define CDIR_ANS                ANSELCbits.ANSC3
#define CDIR_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define CDIR_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define CDIR_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define CDIR_GetValue()           PORTCbits.RC3
#define CDIR_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define CDIR_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define CDIR_SetPullup()      do { WPUCbits.WPUC3 = 1; } while(0)
#define CDIR_ResetPullup()    do { WPUCbits.WPUC3 = 0; } while(0)
#define CDIR_SetPushPull()    do { ODCONCbits.ODCC3 = 1; } while(0)
#define CDIR_SetOpenDrain()   do { ODCONCbits.ODCC3 = 0; } while(0)
#define CDIR_SetAnalogMode()  do { ANSELCbits.ANSC3 = 1; } while(0)
#define CDIR_SetDigitalMode() do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()    do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()   do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()   do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()         PORTCbits.RC4
#define RC4_SetDigitalInput()   do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()  do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()     do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()   do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode() do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()    do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()   do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()   do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()         PORTCbits.RC5
#define RC5_SetDigitalInput()   do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()  do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()     do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()   do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode() do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()do { ANSELCbits.ANSC5 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/