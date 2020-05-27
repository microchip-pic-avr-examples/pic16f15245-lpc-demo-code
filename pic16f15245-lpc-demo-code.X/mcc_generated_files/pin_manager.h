/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC16F15245
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.20
        MPLAB 	          :  MPLAB X 5.40	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_ANA0 aliases
#define channel_ANA0_TRIS                 TRISAbits.TRISA0
#define channel_ANA0_LAT                  LATAbits.LATA0
#define channel_ANA0_PORT                 PORTAbits.RA0
#define channel_ANA0_WPU                  WPUAbits.WPUA0
#define channel_ANA0_OD                   ODCONAbits.ODCA0
#define channel_ANA0_ANS                  ANSELAbits.ANSA0
#define channel_ANA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_ANA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_ANA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_ANA0_GetValue()           PORTAbits.RA0
#define channel_ANA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_ANA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_ANA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_ANA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_ANA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define channel_ANA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define channel_ANA0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define channel_ANA0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED_D5 aliases
#define LED_D5_TRIS                 TRISAbits.TRISA1
#define LED_D5_LAT                  LATAbits.LATA1
#define LED_D5_PORT                 PORTAbits.RA1
#define LED_D5_WPU                  WPUAbits.WPUA1
#define LED_D5_OD                   ODCONAbits.ODCA1
#define LED_D5_ANS                  ANSELAbits.ANSA1
#define LED_D5_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_D5_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_D5_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_D5_GetValue()           PORTAbits.RA1
#define LED_D5_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_D5_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_D5_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define LED_D5_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define LED_D5_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define LED_D5_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define LED_D5_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED_D5_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED_D6 aliases
#define LED_D6_TRIS                 TRISAbits.TRISA2
#define LED_D6_LAT                  LATAbits.LATA2
#define LED_D6_PORT                 PORTAbits.RA2
#define LED_D6_WPU                  WPUAbits.WPUA2
#define LED_D6_OD                   ODCONAbits.ODCA2
#define LED_D6_ANS                  ANSELAbits.ANSA2
#define LED_D6_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_D6_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_D6_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_D6_GetValue()           PORTAbits.RA2
#define LED_D6_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_D6_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_D6_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define LED_D6_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define LED_D6_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define LED_D6_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define LED_D6_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_D6_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set LED_D4 aliases
#define LED_D4_TRIS                 TRISAbits.TRISA5
#define LED_D4_LAT                  LATAbits.LATA5
#define LED_D4_PORT                 PORTAbits.RA5
#define LED_D4_WPU                  WPUAbits.WPUA5
#define LED_D4_OD                   ODCONAbits.ODCA5
#define LED_D4_ANS                  ANSELAbits.ANSA5
#define LED_D4_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define LED_D4_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define LED_D4_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define LED_D4_GetValue()           PORTAbits.RA5
#define LED_D4_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define LED_D4_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define LED_D4_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define LED_D4_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define LED_D4_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define LED_D4_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define LED_D4_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define LED_D4_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set POT_CHANNEL aliases
#define POT_CHANNEL_TRIS                 TRISCbits.TRISC2
#define POT_CHANNEL_LAT                  LATCbits.LATC2
#define POT_CHANNEL_PORT                 PORTCbits.RC2
#define POT_CHANNEL_WPU                  WPUCbits.WPUC2
#define POT_CHANNEL_OD                   ODCONCbits.ODCC2
#define POT_CHANNEL_ANS                  ANSELCbits.ANSC2
#define POT_CHANNEL_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define POT_CHANNEL_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define POT_CHANNEL_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define POT_CHANNEL_GetValue()           PORTCbits.RC2
#define POT_CHANNEL_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define POT_CHANNEL_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define POT_CHANNEL_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define POT_CHANNEL_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define POT_CHANNEL_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define POT_CHANNEL_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define POT_CHANNEL_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define POT_CHANNEL_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set SWITCH_S1 aliases
#define SWITCH_S1_TRIS                 TRISCbits.TRISC4
#define SWITCH_S1_LAT                  LATCbits.LATC4
#define SWITCH_S1_PORT                 PORTCbits.RC4
#define SWITCH_S1_WPU                  WPUCbits.WPUC4
#define SWITCH_S1_OD                   ODCONCbits.ODCC4
#define SWITCH_S1_ANS                  ANSELCbits.ANSC4
#define SWITCH_S1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SWITCH_S1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SWITCH_S1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SWITCH_S1_GetValue()           PORTCbits.RC4
#define SWITCH_S1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SWITCH_S1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SWITCH_S1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SWITCH_S1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SWITCH_S1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SWITCH_S1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define SWITCH_S1_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define SWITCH_S1_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set LED_D7 aliases
#define LED_D7_TRIS                 TRISCbits.TRISC5
#define LED_D7_LAT                  LATCbits.LATC5
#define LED_D7_PORT                 PORTCbits.RC5
#define LED_D7_WPU                  WPUCbits.WPUC5
#define LED_D7_OD                   ODCONCbits.ODCC5
#define LED_D7_ANS                  ANSELCbits.ANSC5
#define LED_D7_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define LED_D7_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define LED_D7_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define LED_D7_GetValue()           PORTCbits.RC5
#define LED_D7_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define LED_D7_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define LED_D7_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define LED_D7_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define LED_D7_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define LED_D7_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define LED_D7_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define LED_D7_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)
#define RB7_SetAnalogMode()         do { ANSELBbits.ANSB7 = 1; } while(0)
#define RB7_SetDigitalMode()        do { ANSELBbits.ANSB7 = 0; } while(0)


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

#endif // PIN_MANAGER_H
/**
 End of File
*/