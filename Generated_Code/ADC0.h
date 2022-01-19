/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : ADC0.h
**     Project     : S12Z_CAN_DBW
**     Processor   : MC9S12ZVCA192MLF
**     Component   : ADC
**     Version     : Component 01.699, Driver 01.00, CPU db: 3.00.000
**     Compiler    : CodeWarrior HCS12Z C Compiler
**     Date/Time   : 2022-01-04, 11:40, # CodeGen: 4
**     Abstract    :
**         This device "ADC" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
**     Settings    :
**          Component name                                 : ADC0
**          A/D converter                                  : ADC0
**          Sharing                                        : Disabled
**          Interrupt service/event                        : Enabled
**            A/D interrupt                                : Vadc0conv_compl
**            A/D interrupt priority                       : medium priority
**            Error interrupt                              : Vadc0err
**            Error interrupt priority                     : medium priority
**            Abort interrupt                              : Vadc0conv_seq_abrt
**            Abort interrupt priority                     : medium priority
**          A/D channels                                   : 6
**            Channel0                                     : 
**              A/D channel (pin)                          : PAD0_KWAD0_AN0_ACMP0_0
**              A/D channel (pin) signal                   : 
**            Channel1                                     : 
**              A/D channel (pin)                          : PAD1_KWAD1_AN1_ACMP0_1_ETRIG0
**              A/D channel (pin) signal                   : 
**            Channel2                                     : 
**              A/D channel (pin)                          : PAD2_KWAD2_AN2_ACMPO0
**              A/D channel (pin) signal                   : 
**            Channel3                                     : 
**              A/D channel (pin)                          : PAD3_KWAD3_AN3_VRH_0_ACMP1_0
**              A/D channel (pin) signal                   : 
**            Channel4                                     : 
**              A/D channel (pin)                          : PAD4_KWAD4_AN4_ACMP1_1
**              A/D channel (pin) signal                   : 
**            Channel5                                     : 
**              A/D channel (pin)                          : PAD5_KWAD5_AN5_ACMPO1
**              A/D channel (pin) signal                   : 
**          Queue                                          : Enabled
**            Mode                                         : Sequential
**            A/D samples                                  : 6
**              Sample0                                    : Enabled
**                Channel                                  : 0
**                Sample time                              : 10 ADC clock cycles
**                High volt. ref. source                   : VRH_1
**                Low volt. ref. source                    : VRL_1
**              Sample1                                    : Enabled
**                Channel                                  : 1
**                Sample time                              : 10 ADC clock cycles
**                High volt. ref. source                   : VRH_1
**                Low volt. ref. source                    : VRL_1
**              Sample2                                    : Enabled
**                Channel                                  : 2
**                Sample time                              : 10 ADC clock cycles
**                High volt. ref. source                   : VRH_1
**                Low volt. ref. source                    : VRL_1
**              Sample3                                    : Enabled
**                Channel                                  : 3
**                Sample time                              : 10 ADC clock cycles
**                High volt. ref. source                   : VRH_1
**                Low volt. ref. source                    : VRL_1
**              Sample4                                    : Enabled
**                Channel                                  : 4
**                Sample time                              : 10 ADC clock cycles
**                High volt. ref. source                   : VRH_1
**                Low volt. ref. source                    : VRL_1
**              Sample5                                    : Enabled
**                Channel                                  : 5
**                Sample time                              : 10 ADC clock cycles
**                High volt. ref. source                   : VRH_1
**                Low volt. ref. source                    : VRL_1
**          A/D resolution                                 : 12 bits
**          Conversion time                                : 17.4375 �s
**          Result mode                                    : Left justified/unsigned
**          External trigger                               : Disabled
**          Internal trigger                               : Disabled
**          Number of conversions                          : 2
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Events enabled in init.                      : yes
**          CPU clock/speed selection                      : 
**            High speed mode                              : This component enabled
**            Low speed mode                               : This component disabled
**            Slow speed mode                              : This component disabled
**          High input limit                               : 1
**          Low input limit                                : 0
**          Get value directly                             : yes
**          Wait for result                                : yes
**     Contents    :
**         Start          - byte ADC0_Start(void);
**         Measure        - byte ADC0_Measure(bool WaitForResult);
**         GetValue16     - byte ADC0_GetValue16(word *Values);
**         GetChanValue16 - byte ADC0_GetChanValue16(byte Channel, word *Value);
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
** @file ADC0.h
** @version 01.00
** @brief
**         This device "ADC" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
*/         
/*!
**  @addtogroup ADC0_module ADC0 module documentation
**  @{
*/         

#ifndef __ADC0_H
#define __ADC0_H

/* MODULE ADC0. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */

#include "Cpu.h"

#define CEASE_ERROR_MASK          0xF8U   /* Constant for check the error flags register of the Error type if it holds the cease flags or not */
#define ERR_FLG_CEASE_ERROR_MASK  0xF800U /* Constant for check the variable of the Error type if it holds the cease flags or not */
#define ERR_FLG_MASK              0xFE40U /* Constant for check the variable of the Error type if it holds any error flags or not */


#ifndef __BWUserType_ADC0_TError
#define __BWUserType_ADC0_TError
  /*lint -save  -esym(960,18.4) Disable MISRA rule (18.4) checking. */
  typedef union {
    word err;
    struct {
      /*lint -save  -e46 Disable MISRA rule (6.4) checking. */
      word                           : 1; /* Reserved */
      word                           : 1; /* Reserved */
      word                           : 1; /* Reserved */
      word                           : 1; /* Reserved */
      word                           : 1; /* Reserved */
      word                           : 1; /* Reserved */
      word ConversionOverrun_Error   : 1; /* Overrun of the ADCxCONIF register */
      word                           : 1; /* Reserved */
      word                           : 1; /* Reserved */
      word LDOK_Error                : 1; /* Restart without Load OK */
      word Restart_Error             : 1; /* Restart in the wrong time */
      word Trigger_Error             : 1; /* Trigger in the wrong time or trigger overflow - Cease ADC operation. */
      word CompareValue_Error        : 1; /* Compare value not available - Cease ADC operation. */
      word EOL_Error                 : 1; /* End of list command missing in the current CSL - Cease ADC operation. */
      word CommandValue_Error        : 1; /* Invalid conversion command loaded - Cease ADC operation. */
      word IllegalAccess_Error       : 1; /* Wrong DMA access to illegal memory area - Cease ADC operation. */
      /*lint -restore Enable MISRA rule (6.4) checking. */
    } errName;
  } ADC0_TError;                       /* Error flags. For languages which don't support bit access is byte access only to error flags possible. */
  /*lint -restore  +esym(960,18.4) Enable MISRA rule (18.4) checking. */
#endif




byte ADC0_Start(void);
/*
** ===================================================================
**     Method      :  ADC0_Start (component ADC)
*/
/*!
**     @brief
**         This method starts continuous conversion on all channels
**         that are set in the component inspector. When each
**         measurement on all channels has finished the [OnEnd ] event
**         may be invoked. This method is not available if the
**         [interrupt service] is disabled and the device doesn't
**         support the continuous mode. Note: If time of measurement is
**         too short and the instruction clock is too slow then the
**         conversion complete interrupt and its handler may cause a
**         system overflow.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSY - A conversion is already running
*/
/* ===================================================================*/

byte ADC0_Measure(bool WaitForResult);
/*
** ===================================================================
**     Method      :  ADC0_Measure (component ADC)
*/
/*!
**     @brief
**         This method performs one measurement on all channels that
**         are set in the component inspector. (Note: If the [number of
**         conversions] is more than one the conversion of A/D channels
**         is performed specified number of times.)
**     @param
**         WaitForResult   - Wait for a result of a
**                           conversion. If [interrupt service] is
**                           disabled, A/D peripheral doesn't support
**                           measuring all channels at once or Autoscan
**                           mode property isn't enabled and at the same
**                           time the [number of channels] is greater
**                           than 1, then the WaitForResult parameter is
**                           ignored and the method waits for each
**                           result every time. If the [interrupt
**                           service] is disabled and a [number of
**                           conversions] is greater than 1, the
**                           parameter is ignored and the method also
**                           waits for each result every time.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - Device is disabled
**                           ERR_BUSY - A conversion is already running
*/
/* ===================================================================*/

byte ADC0_GetValue16(word *Values);
/*
** ===================================================================
**     Method      :  ADC0_GetValue16 (component ADC)
*/
/*!
**     @brief
**         This method returns the last measured values of all channels.
**         Compared with [GetValue] method this method returns more
**         accurate result if the [number of conversions] is greater
**         than 1 and [AD resolution] is less than 16 bits. In addition,
**         the user code dependency on [AD resolution] is eliminated.
**     @param
**         Values          - Pointer to the array that contains
**                           the measured data.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_NOTAVAIL - Requested value not
**                           available
**                           ERR_OVERRUN - External trigger overrun flag
**                           was detected after the last value(s) was
**                           obtained (for example by GetValue). This
**                           error may not be supported on some CPUs
**                           (see generated code).
*/
/* ===================================================================*/

byte ADC0_GetChanValue16(byte Channel, word *Value);
/*
** ===================================================================
**     Method      :  ADC0_GetChanValue16 (component ADC)
*/
/*!
**     @brief
**         This method returns the last measured value of the required
**         channel. Compared with [GetChanValue] method this method
**         returns more accurate result if the [number of conversions]
**         is greater than 1 and [AD resolution] is less than 16 bits.
**         In addition, the user code dependency on [AD resolution] is
**         eliminated.
**     @param
**         Channel         - Channel number. If only one
**                           channel in the component is set then this
**                           parameter is ignored.
**     @param
**         Value           - Pointer to the measured value.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_NOTAVAIL - Requested value not
**                           available
**                           ERR_RANGE - Parameter "Channel" out of
**                           range
**                           ERR_OVERRUN - External trigger overrun flag
**                           was detected after the last value(s) was
**                           obtained (for example by GetValue). This
**                           error may not be supported on some CPUs
**                           (see generated code).
*/
/* ===================================================================*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED
void ADC0_Interrupt(void);
#pragma CODE_SEG ADC0_CODE
/*
** ===================================================================
**     Method      :  ADC0_Interrupt (component ADC)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED
void ADC0_ErrorInterrupt(void);
#pragma CODE_SEG ADC0_CODE
/*
** ===================================================================
**     Method      :  ADC0_ErrorInterrupt (component ADC)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED
void ADC0_AbortInterrupt(void);
#pragma CODE_SEG ADC0_CODE
/*
** ===================================================================
**     Method      :  ADC0_AbortInterrupt (component ADC)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void ADC0_SetHigh(void);
/*
** ===================================================================
**     Method      :  ADC0_SetHigh (component ADC)
**
**     Description :
**         The method reconfigures the component and its selected 
**         peripheral(s) when the CPU is switched to the High speed mode. 
**         The method is called automatically as s part of the CPU 
**         SetHighSpeed method.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

void ADC0_Init(void);
/*
** ===================================================================
**     Method      :  ADC0_Init (component ADC)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG DEFAULT
/* END ADC0. */

#endif
/* ifndef __ADC0_H */
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
