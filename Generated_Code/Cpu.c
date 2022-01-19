/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : Cpu.c
**     Project     : S12Z_CAN_DBW
**     Processor   : MC9S12ZVCA192MLF
**     Component   : MC9S12ZVCA192_48
**     Version     : Component 01.050, Driver 02.08, CPU db: 3.00.000
**     Datasheet   : MC9S12ZVC-Family Reference Manual Preliminary Confidential Rev. 1.7 29-September-2016
**     Compiler    : CodeWarrior HCS12Z C Compiler
**     Date/Time   : 2022-01-04, 11:40, # CodeGen: 4
**     Abstract    :
**         This component "MC9S12ZVCA192_48" implements properties, methods,
**         and events of the CPU.
**     Settings    :
**
**     Contents    :
**         EnableInt   - void Cpu_EnableInt(void);
**         DisableInt  - void Cpu_DisableInt(void);
**         SetWaitMode - void Cpu_SetWaitMode(void);
**         SetStopMode - void Cpu_SetStopMode(void);
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
** @file Cpu.c
** @version 02.08
** @brief
**         This component "MC9S12ZVCA192_48" implements properties, methods,
**         and events of the CPU.
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */

#include "CAN1.h"
#include "TI1.h"
#include "PWM1.h"
#include "PWM2.h"
#include "EN1.h"
#include "SW1.h"
#include "SW2.h"
#include "ADC0.h"
#include "Events.h"
#include "Cpu.h"

#define CGM_DELAY  0x0FFFU

#pragma DATA_SEG DEFAULT               /* Select data segment "DEFAULT" */
#pragma CODE_SEG DEFAULT


/* Global variables */
volatile byte CCR_reg;                 /* Current CCR reegister */
#pragma CODE_SEG __NEAR_SEG NON_BANKED


/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MC9S12ZVCA192_48)
**
**     Description :
**         The method services unhandled interrupt vectors.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(Cpu_Interrupt)
{
  /*lint -save -e950 Disable MISRA rule (1.1) checking. */
  asm(BGND);
  /*lint -restore Enable MISRA rule (1.1) checking. */
}


#pragma CODE_SEG DEFAULT

/*
** ===================================================================
**     Method      :  Cpu_DisableInt (component MC9S12ZVCA192_48)
**     Description :
**         Disable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_DisableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_EnableInt (component MC9S12ZVCA192_48)
**     Description :
**         Enable maskable interrupts
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_EnableInt(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetStopMode (component MC9S12ZVCA192_48)
**     Description :
**         Set low power mode - Stop mode.
**         For more information about the stop mode see
**         documentation of this CPU.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetStopMode(void)

**      This method is implemented as macro in the header module. **
*/

/*
** ===================================================================
**     Method      :  Cpu_SetWaitMode (component MC9S12ZVCA192_48)
**     Description :
**         Set low power mode - Wait mode.
**         For more information about the wait mode see
**         documentation of this CPU.
**         Release from Wait mode: Reset or interrupt
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void Cpu_SetWaitMode(void)

**      This method is implemented as macro in the header module. **
*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED

/*
** ===================================================================
**     Method      :  _EntryPoint (component MC9S12ZVCA192_48)
**
**     Description :
**         Initializes the whole system like timing and so on. At the end 
**         of this function, the C startup is invoked to initialize stack,
**         memory areas and so on.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
extern void _Startup(void);            /* Forward declaration of external startup function declared in file Start12.c */

/*** !!! Here you can place your own code using property "User data declarations" on the build options tab of the CPU component. !!! ***/



#pragma NO_RETURN                      /* Suppress generation of return from a function */
void _EntryPoint(void)
{

  /*** !!! Here you can place your own code using property "User code before PE initialization" on the build options tab of the CPU compoennt. !!! ***/

  /* ### MC9S12ZVCA192_48 "Cpu" init code ... */
  /*  PE initialization code after reset */
  /* IVBR: IVB_ADDR=0x7FFF,??=0 */
  setReg16(IVBR, 0xFFFEU);              
  /* ECLKCTL: NECLK=1,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  setReg8(ECLKCTL, 0x80U);              
  /*  System clock initialization */
  /* CPMUPROT: ??=0,??=0,??=1,??=0,??=0,??=1,??=1,PROT=0 */
  setReg8(CPMUPROT, 0x26U);            /* Disable protection of clock configuration registers */ 
  /* CPMUCLKS: PSTP=0 */
  clrReg8Bits(CPMUCLKS, 0x40U);         
  /* CPMUCLKS: PLLSEL=1 */
  setReg8Bits(CPMUCLKS, 0x80U);        /* Enable the PLL to allow write to divider registers */ 
  /* CPMUPOSTDIV: ??=0,??=0,??=0,POSTDIV4=0,POSTDIV3=0,POSTDIV2=0,POSTDIV1=0,POSTDIV0=0 */
  setReg8(CPMUPOSTDIV, 0x00U);         /* Set the post divider register */ 
  /* Whenever changing PLL reference clock (REFCLK) frequency to a higher value
   it is recommended to write CPMUSYNR = 0x00 in order to stay within specified
   maximum frequency of the MCU */
  /* CPMUSYNR: VCOFRQ1=0,VCOFRQ0=0,SYNDIV5=0,SYNDIV4=0,SYNDIV3=0,SYNDIV2=0,SYNDIV1=0,SYNDIV0=0 */
  setReg8(CPMUSYNR, 0x00U);            /* Set the multiplier register */ 
  /* CPMUPLL: ??=0,??=0,FM1=0,FM0=0,??=0,??=0,??=0,??=0 */
  setReg8(CPMUPLL, 0x00U);             /* Set the PLL frequency modulation */ 
  /* CPMUSYNR: VCOFRQ1=0,VCOFRQ0=1,SYNDIV5=0,SYNDIV4=1,SYNDIV3=1,SYNDIV2=1,SYNDIV1=1,SYNDIV0=1 */
  setReg8(CPMUSYNR, 0x5FU);            /* Set the multiplier register */ 
  while(CPMUIFLG_LOCK == 0U) {         /* Wait until the PLL is within the desired tolerance of the target frequency */
  }
  /* CPMUPROT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,PROT=0 */
  setReg8(CPMUPROT, 0x00U);            /* Enable protection of clock configuration registers */ 
  /* CPMUCOP: RSBCK=0,WRTMASK=1 */
  clrSetReg8Bits(CPMUCOP, 0x40U, 0x20U); 
  /* CPMUHTCTL: ??=0,??=0,VSEL=0,??=0,HTE=0,HTDS=0,HTIE=0,HTIF=0 */
  setReg8(CPMUHTCTL, 0x00U);            
  /* CPMUVREGCTL: ??=0,??=0,??=0,??=0,??=0,EXTCON=1,EXTXON=0,INTXON=1 */
  setReg8(CPMUVREGCTL, 0x05U);          
  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code using property "User code after PE initialization" on the build options tab of the CPU component. !!! ***/

  /*lint -save  -e950 Disable MISRA rule (1.1) checking. */
  __asm(jmp _Startup);                 /* Jump to C startup code */
  /*lint -restore Enable MISRA rule (1.1) checking. */
}

#pragma CODE_SEG DEFAULT
/*
** ===================================================================
**     Method      :  PE_low_level_init (component MC9S12ZVCA192_48)
**
**     Description :
**         Initializes components and provides common register 
**         initialization. The method is called automatically as a part 
**         of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /* Int. priority initialization */
  /*                                        No. Address Pri XGATE Name                 Description */
  setReg8(INT_CFADDR, 0x40U);           
  setReg8(INT_CFDATA0, 0x07U);         /*  0x40  0x00FFFF00   7   no   ivVapi               used by PE */ 
  setReg8(INT_CFADDR, 0x50U);           
  setReg8(INT_CFDATA5, 0x04U);         /*  0x55  0x00FFFF54   4   no   ivVcan0rx            used by PE */ 
  setReg8(INT_CFDATA6, 0x04U);         /*  0x56  0x00FFFF58   4   no   ivVcan0err           used by PE */ 
  setReg8(INT_CFADDR, 0x60U);           
  setReg8(INT_CFDATA1, 0x04U);         /*  0x61  0x00FFFF84   4   no   ivVadc0conv_compl    used by PE */ 
  setReg8(INT_CFDATA2, 0x04U);         /*  0x62  0x00FFFF88   4   no   ivVadc0conv_seq_abrt used by PE */ 
  setReg8(INT_CFDATA3, 0x04U);         /*  0x63  0x00FFFF8C   4   no   ivVadc0err           used by PE */ 
  /* Common initialization of the CPU registers */
  /* MODRR0: M0C0RR&=~3 */
  clrReg8Bits(MODRR0, 0x03U);           
  /* CPMUAPICTL: APICLK=0,APIFE=0,APIE=1,APIF=1 */
  clrSetReg8Bits(CPMUAPICTL, 0x84U, 0x03U); 
  /* PWM0E: PWME7=0,PWME6=0,PWME5=0,PWME4=0,PWME3=0,PWME2=0,PWME1=0,PWME0=0 */
  setReg8(PWM0E, 0x00U);                
  /* PWM0CTL: CON01=1 */
  setReg8Bits(PWM0CTL, 0x10U);          
  /* PWM0CAE: CAE1=0 */
  clrReg8Bits(PWM0CAE, 0x02U);          
  /* PWM0POL: PPOL1=1 */
  setReg8Bits(PWM0POL, 0x02U);          
  /* PTP: PTP4=1,PTP0=1 */
  setReg8Bits(PTP, 0x11U);              
  /* PWM1E: PWME7=0,PWME6=0,PWME5=0,PWME4=0,PWME3=0,PWME2=0,PWME1=0,PWME0=0 */
  setReg8(PWM1E, 0x00U);                
  /* PWM1CTL: CON01=1 */
  setReg8Bits(PWM1CTL, 0x10U);          
  /* PWM1CAE: CAE1=0 */
  clrReg8Bits(PWM1CAE, 0x02U);          
  /* PWM1POL: PPOL1=1 */
  setReg8Bits(PWM1POL, 0x02U);          
  /* PIES: PIES7=0 */
  clrReg8Bits(PIES, 0x80U);             
  /* PTS: PTS7=1 */
  setReg8Bits(PTS, 0x80U);              
  /* WOMS: WOMS7=0 */
  clrReg8Bits(WOMS, 0x80U);             
  /* DDRS: DDRS7=1,DDRS6=1,DDRS5=1,DDRS4=1 */
  setReg8Bits(DDRS, 0xF0U);             
  /* DIENADL: DIENADL7=1,DIENADL6=1 */
  setReg8Bits(DIENADL, 0xC0U);          
  /* PIEADL: PIEADL7=0,PIEADL6=0 */
  clrReg8Bits(PIEADL, 0xC0U);           
  /* PPSADL: PPSADL7=0,PPSADL6=0 */
  clrReg8Bits(PPSADL, 0xC0U);           
  /* PERADL: PERADL7=1,PERADL6=1 */
  setReg8Bits(PERADL, 0xC0U);           
  /* DDRADL: DDRADL7=0,DDRADL6=0 */
  clrReg8Bits(DDRADL, 0xC0U);           
  /* CPMUINT: LOCKIE=0,OSCIE=0 */
  clrReg8Bits(CPMUINT, 0x12U);          
  /* CPMULVCTL: LVIE=0 */
  clrReg8Bits(CPMULVCTL, 0x02U);        
  /* ECCIE: SBEEIE=0 */
  clrReg8Bits(ECCIE, 0x01U);            
  /* ECCDCMD: ECCDRR=0 */
  clrReg8Bits(ECCDCMD, 0x80U);          
  /* DDRADH: DDRADH7=1,DDRADH6=1,DDRADH5=1,DDRADH4=1,DDRADH3=1,DDRADH2=1 */
  setReg8Bits(DDRADH, 0xFCU);           
  /* DDRJ: DDRJ1=1,DDRJ0=1 */
  setReg8Bits(DDRJ, 0x03U);             
  /* DDRP: DDRP7=1,DDRP3=1,DDRP1=1 */
  setReg8Bits(DDRP, 0x8AU);             
  /* DDRT: DDRT6=1,DDRT5=1 */
  setReg8Bits(DDRT, 0x60U);             
  /* RDRP: RDRP6=0,RDRP5=0,RDRP4=0,RDRP2=0,RDRP0=0 */
  clrReg8Bits(RDRP, 0x75U);             
  /* IRQCR: IRQEN=0 */
  clrReg8Bits(IRQCR, 0x40U);            
  /* CPMUAPIR: APIR2=1 */
  setReg16Bits(CPMUAPIR, 0x04U);        
  /* ### MC9S12ZVCA192_48 "Cpu" init code ... */
  /* ###  "CAN1" init code ... */
  CAN1_Init();
  /* ### TimerInt "TI1" init code ... */
  /* ### Programable pulse generation "PWM1" init code ... */
  PWM1_Init();
  /* ### Programable pulse generation "PWM2" init code ... */
  PWM2_Init();
  /* ### BitIO "EN1" init code ... */
  /* ### BitIO "SW1" init code ... */
  /* ### BitIO "SW2" init code ... */
  /* ### ADC "ADC0" init code ... */
  ADC0_Init();
  /* Common peripheral initialization - ENABLE */
  /* CPMUAPICTL: APIFE=1 */
  setReg8Bits(CPMUAPICTL, 0x04U);       
  __EI();                              /* Enable interrupts */
}

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
/* Initialization of the CPU registers in FLASH */
/*lint -restore Enable MISRA rule (1.1) checking. */

/* END Cpu. */

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
