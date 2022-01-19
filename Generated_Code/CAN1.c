/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : CAN1.c
**     Project     : S12Z_CAN_DBW
**     Processor   : MC9S12ZVCA192MLF
**     Component   : FreescaleCAN
**     Version     : Component 02.366, Driver 01.31, CPU db: 3.00.000
**     Compiler    : CodeWarrior HCS12Z C Compiler
**     Date/Time   : 2022-01-04, 11:40, # CodeGen: 4
**     Abstract    :
**         This component "FreescaleCAN" implements a CAN serial channel.
**     Settings    :
**         CAN channel                                     : MSCAN0
**
**           Interrupt service/event                       : Enabled
**             Output interrupt
**               Vector name                               : Vcan0tx
**               Priority                                  : 4
**             Input interrupt
**               Vector name                               : Vcan0rx
**               Priority                                  : 4
**             Error interrupt
**               Vector name                               : Vcan0err
**               Priority                                  : 4
**             Wakeup interrupt
**               Vector name                               : Vcan0wkup
**               Priority                                  : 4
**
**          Settings                                       : 
**                Rx pin                                   : CANPHY0_RXD_to_MSCAN0_RXD
**                Rx pin signal                            : 
**                Tx pin                                   : MSCAN0_TXD_to_CANPHY0_TXD
**                Tx pin Signal                            : 
**
**
**            Recieve accept. code                         : 0x20202040
**            Recieve accept. mask                         : 0x00
**            Loop Mode                                    : no
**            Bus-Off Recovery                             : Auto
**            Listen Only Mode                             : no
**            Wakeup                                       : Disabled
**
**         Protocol
**             Time segment 1                              : 10
**             Time segment 2                              : 3
**             RSJ                                         : 3
**             Samples per bit                             : One sample
**             Time quanta per bit                         : 16
**             Init baud rate                              : 250 kbit/s
**
**         Initialization
**             Enabled in init. code                       : yes
**             Events enabled in init.                     : yes
**
**         CPU clock/speed selection
**             High speed mode                             : This component enabled
**             Low speed mode                              : This component disabled
**             Slow speed mode                             : This component disabled
**
**     Contents    :
**         SendFrame - byte CAN1_SendFrame(byte BufferNum, dword MessageID, byte FrameType, byte...
**         ReadFrame - byte CAN1_ReadFrame(dword *MessageID, byte *FrameType, byte *FrameFormat,...
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
** @file CAN1.c
** @version 01.31
** @brief
**         This component "FreescaleCAN" implements a CAN serial channel.
*/         
/*!
**  @addtogroup CAN1_module CAN1 module documentation
**  @{
*/         

/* MODULE CAN1. */

#include "CAN1.h"
#include "TI1.h"
#include "PWM1.h"
#include "PWM2.h"
#include "EN1.h"
#include "SW1.h"
#include "SW2.h"
#include "ADC0.h"
#include "Events.h"

#define CAN_STANDARD_FRAME_MAX_ID    0x07FFU /* Max ID of the standard frame */
#define CAN_EXTENDED_FRAME_MAX_ID    0x1FFFFFFFUL /* Max ID of the extended frame */
#define CAN_EXTENDED_FRAME_MASK      0x60000000UL /* Invalid extended frame mask*/
#define CAN_MAX_DATA_LEN             0x08U /* Max number of data to be sent in one frame */
#define FULL_RX_BUF                  0x01U /* RX buffer full           */

#define MB_ID_IDE                    0x00080000UL
#define CAN_TX_MBUFFERS              0x03U /* Number of TX buffers */
#define CAN_MAX_RX_FIFO              0x04U /* Max length of the RX fifo */

#define CAN_STATUS_OVERRUN_MASK      0x02U /* Overrun error flag mask */
#define CAN_STATUS_TX_MASK           0x0CU /* Transmitter error state mask*/
#define CAN_STATUS_RX_MASK           0x30U /* Receiver error state mask*/
#define CAN_STATUS_BOFF_MASK         0x0CU /* Bus-Off state mask in register */
#define CAN_STATUS_BOFF_EXT_MASK     0x40U /* Bus-Off state mask in error flag */
#define CAN_STATUS_TX_PASS_MASK      0x08U /* Transmitter error passive state mask */
#define CAN_STATUS_RX_PASS_MASK      0x20U /* Receiver error passive state mask */
#define CAN_STATUS_TX_WARN_MASK      0x04U /* Transmitter warning mask */
#define CAN_STATUS_RX_WARN_MASK      0x10U /* Receiver warning mask */
#define CAN_STATUS_WAKEUP_MASK       0x80U /* Wakeup interrupt flag mask */

typedef struct {                       /* Message buffer structure */
          byte IDR0;
          byte IDR1;
          byte IDR2;
          byte IDR3;
          byte Data[CAN_MAX_DATA_LEN];
          byte DLR;
          byte TBPR;
          byte Reserved;
          byte Reserved2;
        }TMsgBuff;                     /* Message buffer structure */

/*lint -save  -esym(960,18.4) Disable MISRA rule (18.4) checking. */
typedef union {
          dword dw;
          struct {
            byte b0;
            byte b1;
            byte b2;
            byte b3;
          }b;
        }DwordSwap;
/*lint -restore  +esym(960,18.4) Enable MISRA rule (18.4) checking. */

#pragma DATA_SEG CAN1_DATA             /* Select data segment "CAN1_DATA" */
#pragma CODE_SEG CAN1_CODE

static volatile byte SerFlag;          /* Internal driver flags */

/*
** ===================================================================
**     Method      :  CAN1_SendFrame (component FreescaleCAN)
**     Description :
**         Sends the frame via the CAN device. Using this method the
**         user can send own message to the CAN bus. This method allows
**         to specify CAN buffer number, message ID, data to be sent
**         and frame type (DATA_FRAME/REMOTE_FRAME).
**     Parameters  :
**         NAME            - DESCRIPTION
**         BufferNum       - Number of the buffer.
**         MessageID       - Identification of the message
**                           - ID. Message ID can be specified in the
**                           STANDARD format (default) or the EXTENDED
**                           format. The most significant bit in the ID
**                           is set to specify EXTENDED format.
**                           Predefined macro CAN_EXTENDED_FRAME_ID can
**                           be used (ID "bitwise or"
**                           CAN_EXTENDED_FRAME_ID) to mark ID as
**                           extended. If the most significant bit of ID
**                           is clear, STANDARD format is used.
**         FrameType       - Type of frame
**                           DATA_FRAME - data frame
**                           REMOTE_FRAME - remote frame
**         Length          - The length of the frame in bytes (0..
**                           8)
**       * Data            - Pointer to data
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - This component is disabled
**                           by user
**                           ERR_VALUE - Some parameter is out of
**                           possible range
**                           ERR_TXFULL - Transmition buffer is full.
** ===================================================================
*/
byte CAN1_SendFrame(byte BufferNum,dword MessageID,byte FrameType,byte Length,const byte *Data)
{
  byte i;                              /* Temorary variables */
  byte bufmask = (byte)(1U << BufferNum); /* Buffer mask */
  TMsgBuff *MsgBuff;
  dword tmpId;

  if (((MessageID & CAN_EXTENDED_FRAME_ID) == 0U) && (MessageID > CAN_STANDARD_FRAME_MAX_ID)) { /* Is the standard ID greater that 2047? */
    return ERR_VALUE;                  /* If yes then error */
  }
  if (((MessageID & CAN_EXTENDED_FRAME_ID) == CAN_EXTENDED_FRAME_ID) && ((MessageID & CAN_EXTENDED_FRAME_MASK) != 0U)) { /* Is the extended ID greater that 536870911? */
    return ERR_VALUE;                  /* If yes then error */
  }
  if ((BufferNum > (CAN_TX_MBUFFERS - 1U)) || (Length > CAN_MAX_DATA_LEN)) { /* Is BufferNum greater than CAN_MAXBUFF or Length greater than CAN_MAX_DATA_LEN? */
    return ERR_VALUE;                  /* If yes then error */
  }
  if (FrameType > REMOTE_FRAME) {      /* Is FrameType other than REMOTE_FRAME or DATA_FRAME */
    return ERR_VALUE;                  /* If yes then error */
  }
  EnterCritical();                     /* Disable global interrupts */
  if ((CAN0TFLG & bufmask) == 0U) {    /* Is the transmit buffer full? */
    ExitCritical();                    /* Enable global interrupts */
    return ERR_TXFULL;                 /* If yes then error */
  }
  CAN0TBSEL = bufmask;                 /* Select requested transmit buffer */
  /*lint -save  -e926 -e927 -e928 -e929 Disable MISRA rule (11.4) checking. */
  MsgBuff = (TMsgBuff *)&CAN0TXIDR0;
  /*lint -restore Enable MISRA rule (11.4) checking. */
  if (MessageID & CAN_EXTENDED_FRAME_ID) {
    tmpId = (((MessageID & 0x1FFC0000UL) << 3) | 0x00180000UL | ((MessageID & 0x0003FFFFUL) << 1)); /* Extended frame */
  }
  else {
    tmpId = MessageID << 21;           /* Standard frame */
  }
  /*lint -save  -e926 -e927 -e928 -e929 Disable MISRA rule (11.4) checking. */
  MsgBuff->IDR3 = ((DwordSwap *)&tmpId)->b.b3; /* Store the message ID */
  MsgBuff->IDR2 = ((DwordSwap *)&tmpId)->b.b2;
  MsgBuff->IDR1 = ((DwordSwap *)&tmpId)->b.b1;
  MsgBuff->IDR0 = ((DwordSwap *)&tmpId)->b.b0;
  /*lint -restore Enable MISRA rule (11.4) checking. */
  if (FrameType == DATA_FRAME) {       /* Is it a data frame? */
    for (i=0U; i<Length; i++) {
      MsgBuff->Data[i] = Data[i];      /* Store data to the transmit register */
    }
    if (MessageID & CAN_EXTENDED_FRAME_ID) { /* Is it the extended frame? */
      MsgBuff->IDR3 &= 0xFEU;          /* If no then set message type as "data frame" */
    }
    else {
      MsgBuff->IDR1 &= 0xEFU;          /* If yes then set message type as "data frame" */
    }
  }
  else {                               /* Remote frame */
    if (MessageID & CAN_EXTENDED_FRAME_ID) { /* Is it the extended frame? */
      MsgBuff->IDR3 |= 0x01U;          /* If yes then set message type as "remote frame" */
    }
    else {
      MsgBuff->IDR1 |= 0x10U;          /* If yes then set message type as "remote frame" */
    }
  }
  MsgBuff->DLR = Length;               /* Set the length of the message */
  CAN0TFLG = bufmask;                  /* Start transmission */
  ExitCritical();                      /* Enable global interrupts */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  CAN1_ReadFrame (component FreescaleCAN)
**     Description :
**         Reads a frame from the CAN device. The user is informed
**         about CAN reception through OnFullRxBuffer event or
**         GetStateRX method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * MessageID       - Pointer to a message
**                           indentification
**       * FrameType       - Pointer to a frame type
**                           DATA_FRAME - data frame
**                           REMOTE_FRAME - remote frame
**       * FrameFormat     - Pointer to a frame format
**                           STANDARD_FORMAT - standard frame 11-bits
**                           EXTENDED_FORMAT - extended frame 29-bits.
**                           Note: This parameter is obsolete and will
**                           be removed in future releases.
**       * Length          - Pointer to a length of the frame
**       * Data            - The buffer for received data
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_DISABLED - This component is disabled
**                           by user
**                           ERR_RXEMPTY - The receive buffer is empty
**                           ERR_OVERRUN - The previous (unread) message
**                           in the receive buffer was overwriten by a
**                           new message. Returns only if Interrupt
**                           service is enabled.
** ===================================================================
*/
byte CAN1_ReadFrame(dword *MessageID,byte *FrameType,byte *FrameFormat,byte *Length,byte *Data)
{
  byte i;
  dword tmpId = 0U;

  if ((SerFlag & FULL_RX_BUF) == 0U) { /* Is the receive buffer empty? */
    return ERR_RXEMPTY;                /* If yes then error */
  }
  /*lint -save  -e926 -e927 -e928 -e929 Disable MISRA rule (11.4) checking. */
  ((DwordSwap*)&tmpId)->b.b0 = CAN0RXIDR0;
  ((DwordSwap*)&tmpId)->b.b1 = CAN0RXIDR1;
  ((DwordSwap*)&tmpId)->b.b2 = CAN0RXIDR2;
  ((DwordSwap*)&tmpId)->b.b3 = CAN0RXIDR3;
  /*lint -restore Enable MISRA rule (11.4) checking. */
  if (tmpId & MB_ID_IDE) {
    *MessageID = ((tmpId >> 1) & 0x3FFFFUL) | ((tmpId >> 3) & 0x1FFC0000UL) | CAN_EXTENDED_FRAME_ID; /* Extended frame */
  }
  else {
    *MessageID = tmpId >> 21;          /* Standard frame */
  }
  if (*MessageID & CAN_EXTENDED_FRAME_ID) {
    *FrameFormat = EXTENDED_FORMAT;
    *FrameType = (CAN0RXIDR3 & 0x01U)? (byte)REMOTE_FRAME : (byte)DATA_FRAME; /* Result the frame type */
    *MessageID &= ~CAN_EXTENDED_FRAME_ID; /* Remove EXTENDED_FRAME indicator, frame type will be returned in FrameType parameter */
  }
  else {
    *FrameFormat = STANDARD_FORMAT;
    *FrameType = (CAN0RXIDR1 & 0x10U)? (byte)REMOTE_FRAME : (byte)DATA_FRAME; /* Result the frame type */
  }
  *Length = CAN0RXDLR & 0x0FU;         /* Result length of the message */
  if (*FrameType == DATA_FRAME) {      /* Is it "data frame"? */
    for (i=0U; i<*Length; i++) {
      /*lint -save  -e926 -e927 -e928 -e929 Disable MISRA rule (11.4) checking. */
      Data[i] = *((byte *)&CAN0RXDSR0 + i); /* Return received data */
      /*lint -restore Enable MISRA rule (11.4) checking. */
    }
  }
  SerFlag &= (byte)(~(byte)FULL_RX_BUF); /* Clear flag "full RX buffer" */
  if (SerFlag & CAN0RFLG_OVRIF_MASK) { /* Is the overrun detected? */
    SerFlag &= (byte)(~(byte)CAN0RFLG_OVRIF_MASK); /* Clear the internal overrun flag */
    return ERR_OVERRUN;                /* If yes then error */
  }
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  CAN1_Init (component FreescaleCAN)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void CAN1_Init(void)
{
  /* CAN0CTL1: CANE=1,CLKSRC=0,LOOPB=0,LISTEN=0,BORM=0,WUPM=0,SLPAK=0,INITAK=0 */
  setReg8(CAN0CTL1, 0x80U);            /* Set the control register */ 
  /* CAN0CTL0: RXFRM=0,RXACT=0,CSWAI=0,SYNCH=0,TIME=0,WUPE=0,SLPRQ=0,INITRQ=1 */
  setReg8(CAN0CTL0, 0x01U);            /* Set the control register */ 
  /* CAN0IDAC: IDAM=1 */
  clrSetReg8Bits(CAN0IDAC, 0x20U, 0x10U); /* Set the acceptance mode */ 
  /* CAN0IDAR0: AC7=0,AC6=0,AC5=1,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN0IDAR0, 0x20U);           /* Set the acceptance code - register CAN0IDAR0 */ 
  /* CAN0IDAR1: AC7=0,AC6=0,AC5=1,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN0IDAR1, 0x20U);           /* Set the acceptance code - register CAN0IDAR1 */ 
  /* CAN0IDAR2: AC7=0,AC6=0,AC5=1,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN0IDAR2, 0x20U);           /* Set the acceptance code - register CAN0IDAR2 */ 
  /* CAN0IDAR3: AC7=0,AC6=1,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN0IDAR3, 0x40U);           /* Set the acceptance code - register CAN0IDAR3 */ 
  /* CAN0IDAR4: AC7=0,AC6=0,AC5=1,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN0IDAR4, 0x20U);           /* Set the acceptance code - register CAN0IDAR4 */ 
  /* CAN0IDAR5: AC7=0,AC6=1,AC5=1,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN0IDAR5, 0x60U);           /* Set the acceptance code - register CAN0IDAR5 */ 
  /* CAN0IDAR6: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN0IDAR6, 0x00U);           /* Set the acceptance code - register CAN0IDAR6 */ 
  /* CAN0IDAR7: AC7=0,AC6=0,AC5=0,AC4=0,AC3=0,AC2=0,AC1=0,AC0=0 */
  setReg8(CAN0IDAR7, 0x00U);           /* Set the acceptance code - register CAN0IDAR7 */ 
  /* CAN0IDMR0: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  setReg8(CAN0IDMR0, 0x00U);           /* Set the acceptance mask - register CAN0IDMR0 */ 
  /* CAN0IDMR1: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  setReg8(CAN0IDMR1, 0x00U);           /* Set the acceptance mask - register CAN0IDMR1 */ 
  /* CAN0IDMR2: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  setReg8(CAN0IDMR2, 0x00U);           /* Set the acceptance mask - register CAN0IDMR2 */ 
  /* CAN0IDMR3: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  setReg8(CAN0IDMR3, 0x00U);           /* Set the acceptance mask - register CAN0IDMR3 */ 
  /* CAN0IDMR4: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  setReg8(CAN0IDMR4, 0x00U);           /* Set the acceptance mask - register CAN0IDMR4 */ 
  /* CAN0IDMR5: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  setReg8(CAN0IDMR5, 0x00U);           /* Set the acceptance mask - register CAN0IDMR5 */ 
  /* CAN0IDMR6: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  setReg8(CAN0IDMR6, 0x00U);           /* Set the acceptance mask - register CAN0IDMR6 */ 
  /* CAN0IDMR7: AM7=0,AM6=0,AM5=0,AM4=0,AM3=0,AM2=0,AM1=0,AM0=0 */
  setReg8(CAN0IDMR7, 0x00U);           /* Set the acceptance mask - register CAN0IDMR7 */ 
  /* CAN0BTR0: SJW1=1,SJW0=1,BRP5=0,BRP4=0,BRP3=0,BRP2=1,BRP1=1,BRP0=1 */
  CAN0BTR0 = 0xC7U;                    /* Set the device timing register */
  /* CAN0BTR1: SAMP=0,TSEG22=0,TSEG21=1,TSEG20=1,TSEG13=1,TSEG12=0,TSEG11=1,TSEG10=0 */
  CAN0BTR1 = 0x3AU;                    /* Set the device timing register */
  CAN0CTL1_CLKSRC = 0x01U;             /* Select the clock source from bus clock */
  CAN0CTL0_INITRQ = 0x00U;             /* Start device */
  while(CAN0CTL1_INITAK) {}            /* Wait for enable */
  /* CAN0RFLG: WUPIF=1,CSCIF=1,RSTAT1=1,RSTAT0=1,TSTAT1=1,TSTAT0=1,OVRIF=1 */
  CAN0RFLG |= 0xFEU;                   /* Reset error flags */
  /* CAN0RIER: WUPIE=0,CSCIE=0,RSTATE1=0,RSTATE0=0,TSTATE1=0,TSTATE0=0,OVRIE=0,RXFIE=1 */
  CAN0RIER = 0x01U;                    /* Enable interrupts */
  CAN0CTL0_TIME = 0x01U;               /* Activates an internal free running timer. */
}


/*
** ===================================================================
**     Method      :  CAN1_InterruptRx (component FreescaleCAN)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the components event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma CODE_SEG __NEAR_SEG NON_BANKED
#define ON_OVERRUN  1U
ISR(CAN1_InterruptRx)
{
  if (SerFlag & FULL_RX_BUF) {         /* Is any char already present in the receive buffer? */
    SerFlag |= CAN_STATUS_OVERRUN_MASK; /* If yes then set internal flag OVERRUN */
  }
  SerFlag |= FULL_RX_BUF;              /* Set flag "full RX buffer" */
   __DI();
  CAN1_OnFullRxBuffer();               /* If yes then invoke user event. Parameter is always 1 because the CAN module has only one RX message buffer */
  CAN0RFLG = CAN0RFLG_RXF_MASK;        /* Reset the reception complete flag and release the RX buffer */
}

#pragma CODE_SEG CAN1_CODE
/*
** ===================================================================
**     Method      :  CAN1_InterruptError (component FreescaleCAN)
**
**     Description :
**         The method services the error interrupt of the selected 
**         peripheral(s) and eventually invokes the components event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma CODE_SEG __NEAR_SEG NON_BANKED
ISR(CAN1_InterruptError)
{

  CAN0RFLG = 0xFEU;                    /* Reset error flags */
}

#pragma CODE_SEG CAN1_CODE

/* END CAN1. */
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
