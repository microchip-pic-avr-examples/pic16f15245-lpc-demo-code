/**
  Blink Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    Blink.c

  Summary:
    This is the source file for the Blink lab

  Description:
    This source file contains the code on how the Blink lab works.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.0
        Device            :  PIC16F15245
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20
        MPLAB             :  MPLAB X v5.40
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

#include "../../mcc_generated_files/pin_manager.h"
#include "../../mcc_generated_files/tmr1.h"
#include "../../labs.h"

#define FLAG_COUNTER_MAX 3  // Maximum flag count to create 1.5 seconds delay

static uint8_t flagCounter = 0;

void Blink(void) 
{
    if (labState == NOT_RUNNING) 
    {
        LEDs_SetLow();
        TMR1_StartTimer();
        labState = RUNNING;
    }

    if (labState == RUNNING) 
    {  
        while(!TMR1_HasOverflowOccured());   
        TMR1IF = 0;  
        TMR1_Reload();    
        flagCounter++;

        if (flagCounter == FLAG_COUNTER_MAX) 
        {
            LED_D4_Toggle();
            flagCounter = 0;
        }
    }

    if (switchEvent) 
    {
        TMR1_StopTimer();
        labState = NOT_RUNNING;
    }
}
/**
 End of File
 */
