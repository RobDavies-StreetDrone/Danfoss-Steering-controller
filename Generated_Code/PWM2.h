/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : PWM2.h
**     Project     : S12Z_CAN_DBW
**     Processor   : MC9S12ZVCA192MLF
**     Component   : PWM
**     Version     : Component 02.243, Driver 01.17, CPU db: 3.00.000
**     Compiler    : CodeWarrior HCS12Z C Compiler
**     Date/Time   : 2022-01-04, 11:40, # CodeGen: 4
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       31            |  PP4_KWP4_PWM1_1_ETRIG0
**             ----------------------------------------------------
**
**         Timer name                  : PWM101 [16-bit]
**         Counter                     : PWM1CNT01 [0x050C]
**         Mode register               : PWM1CTL   [0x0505]
**         Run register                : PWM1E     [0x0500]
**         Prescaler                   : PWM1PRCLK [0x0503]
**         Compare 1 register          : PWM1PER01 [0x0514]
**         Compare 2 register          : PWM1DTY01 [0x051C]
**         Flip-flop 1 register        : PWM1POL   [0x0501]
**
**         User handling procedure     : not specified
**
**         Output pin
**
**         Port name                   : P
**         Bit number (in port)        : 4
**         Bit mask of the port        : 0x0010
**         Port data register          : PTP       [0x02F0]
**         Port control register       : DDRP      [0x02F2]
**
**         Runtime setting period      : none
**         Runtime setting ratio       : calculated
**         Initialization:
**              Aligned                : Left
**              Output level           : high
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 64000000 Hz
**           Initial value of            period        pulse width (ratio 0%)
**             Xtal ticks              : 1000          0
**             microseconds            : 1000          0
**             milliseconds            : 1             0
**             seconds (real)          : 0.001         0.0
**
**     Contents    :
**         SetRatio16 - byte PWM2_SetRatio16(word Ratio);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file PWM2.h
** @version 01.17
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup PWM2_module PWM2 module documentation
**  @{
*/         

#ifndef __PWM2
#define __PWM2

/* MODULE PWM2. */

#include "Cpu.h"

#pragma CODE_SEG PWM2_CODE

#define PWM2_PERIOD_VALUE    0xFA00UL  /* Initial period value in ticks of the timer */
#define PWM2_PERIOD_VALUE_HIGH 0xFA00UL /* Initial period value in ticks of the timer in high speed mode */

byte PWM2_SetRatio16(word Ratio);
/*
** ===================================================================
**     Method      :  PWM2_SetRatio16 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. Value 0 - 65535 value
**         is proportional to ratio 0 - 100%. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**         The method is available only if method <SetPeriodMode> is
**         not selected.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

void PWM2_Init(void);
/*
** ===================================================================
**     Method      :  PWM2_Init (component PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the component's 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG DEFAULT

/* END PWM2. */

#endif /* ifndef __PWM2 */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS12Z series of microcontrollers.
**
** ###################################################################
*/
