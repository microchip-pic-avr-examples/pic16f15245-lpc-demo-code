/**
  TMR1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.c

  @Summary
    This is the generated driver implementation file for the TMR1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for TMR1.
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

#include <xc.h>
#include "tmr1.h"

volatile uint16_t timer1ReloadVal;

void TMR1_Initialize(void)
{ 
    T1GCON = 0x00;                                                              // T1GE disabled; T1GTM disabled; T1GPOL low; T1GGO done; T1GSPM disabled; 
    T1GATE = 0x00;                                                              // GSS T1G_pin; 
    T1CLK = 0x01;                                                               // CS FOSC/4;     
    TMR1H = 0x0B;                                                               // TMR1H 11; 
    TMR1L = 0xDC;                                                               // TMR1L 220;
    PIR1bits.TMR1IF = 0;                                                        // Clearing IF flag.
    timer1ReloadVal=(uint16_t)((TMR1H << 8) | TMR1L);                           // Load the TMR value to reload variable 
    T1CON = 0x11;                                                               // CKPS 1:2; NOT_SYNC synchronize; TMR1ON enabled; T1RD16 disabled;
}

void TMR1_StartTimer(void)
{
    T1CONbits.TMR1ON = 1;                                                       // Start the Timer by writing to TMRxON bit
}

void TMR1_StopTimer(void)
{
    T1CONbits.TMR1ON = 0;                                                       // Stop the Timer by writing to TMRxON bit
}

void TMR1_WriteTimer(uint16_t timerVal)
{
    if (T1CONbits.NOT_SYNC == 1)
    {
        T1CONbits.TMR1ON = 0;                                                   // Stop the Timer by writing to TMRxON bit        
        TMR1H = (timerVal >> 8);                                                // Write to the Timer1 register
        TMR1L = timerVal;        
        T1CONbits.TMR1ON = 1;                                                   // Start the Timer after writing to the register
    }
    else
    {
        TMR1H = (timerVal >> 8);                                                // Write to the Timer1 register
        TMR1L = timerVal;
    }
}

void TMR1_Reload(void)
{
    TMR1_WriteTimer(timer1ReloadVal);
}

bool TMR1_HasOverflowOccured(void)
{
    return(PIR1bits.TMR1IF);                                                    // Check if overflow occurred by checking the TMRIF bit
}
/**
  End of File
*/
