/**
  Pulse Width Modulation Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    PWM.c

  Summary:
    This is the source file for the PWM lab

  Description:
    This source file contains the code on how the PWM lab works.
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
#include "../../mcc_generated_files/adc.h"
#include "../../mcc_generated_files/pwm1.h"
#include "../../mcc_generated_files/tmr2.h"
#include "../../mcc_generated_files/eusart1.h"
#include "../../labs.h"

void PWM_Output_D7_Enable(void);
void PWM_Output_D7_Disable(void);

static uint16_t adcResult;

void PWM(void) 
{
    if (labState == NOT_RUNNING) 
    {
        LEDs_SetLow();
        PWM_Output_D7_Enable();
        TMR2_StartTimer();
        labState = RUNNING;
    }

    if (labState == RUNNING) 
    {
        adcResult = ADC_GetConversion(POT_CHANNEL) >> 6;
        PWM1_LoadDutyValue(adcResult);
        printf("ADC Result: %d\n\r", ADRES >> 6);
    }

    if (switchEvent) 
    {
        TMR2_StopTimer();
        PWM_Output_D7_Disable();
        labState = NOT_RUNNING;
    }
}

void PWM_Output_D7_Enable(void) 
{   
    RC5PPS = 0x01;                                                              // Set D7 as the output of PWM1 
}

void PWM_Output_D7_Disable(void) 
{  
    RC5PPS = 0x00;                                                              // Restore D7 as a normal I/O pin
}

/**
 End of File
 */
