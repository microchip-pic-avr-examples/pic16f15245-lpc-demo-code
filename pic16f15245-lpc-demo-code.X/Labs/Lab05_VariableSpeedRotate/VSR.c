/**
  Variable Speed Rotate Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    VSR.c

  Summary:
    This is the source file for the VSR lab

  Description:
    This source file contains the code on how the VSR lab works.
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
#include "../../mcc_generated_files/eusart1.h"
#include "../../labs.h"

static uint8_t delay;
static uint8_t rotateReg;
    
void VSR(void)
{
    if(labState == NOT_RUNNING)
    {               
        LEDs_SetLow();        
        rotateReg = 1;                                                          //Initialize temporary register to begin at 1        
        labState = RUNNING;                                                     
    }

    if (labState == RUNNING) 
    {    
        delay = ADC_GetConversion(POT_CHANNEL) >> 8;                            // Use the top 8 MSbs of the ADC result as delay
        
        printf("ADC Result: %d\n\r", ADRES >> 6);                               // Printing ADC result on Serial port
        
        __delay_ms(2);            
                
        while (delay-- != 0)                                                    // Decrement the 8 MSbs of the ADC and delay each for 2ms
        {
           __delay_ms(2);    
        }
        
        //Determine which LED will light up
        LED_D4_LAT = rotateReg & 1;                                                
        LED_D5_LAT = (rotateReg & 2) >> 1;                                         
        LED_D6_LAT = (rotateReg & 4) >> 2;
        LED_D7_LAT = (rotateReg & 8) >> 3;
        
        rotateReg = rotateReg << 1 ;    
        
        //Return to initial position of LED
        if (rotateReg == LAST)
        {
            rotateReg = 1;  
        }
    }

    if(switchEvent)
    {     
        labState = NOT_RUNNING;  
    }
}
/**
 End of File
 */
