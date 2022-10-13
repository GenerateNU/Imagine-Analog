#ifndef APICODE_H
#define APICODE_H

/********************************************************************\
*                      Dynamx Design Lab C Code                      *
*--------------------------------------------------------------------*
*                                                                    *
*  File:      ApiCode.h                                              *
*  Circuit:   Untitled                                               *
*  Generated: April 26, 2022:  05:50 PM                              *
*  Version:   2.8.0.10 -  (Standard) - Release                       *
*  Copyright: Copyright © 2015 Okika. All rights reserved.           *
*                                                                    *
\********************************************************************/

#include <stdlib.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

/*##################################################################*\
#                                                                    #
#                        Data and Definitions                        #
#                                                                    #
\*##################################################################*/

/* All basic data types required by the C code. */
typedef unsigned char        an_Byte;
typedef long                 an_Fixed;
typedef long                 an_Frequency;
typedef short                an_Component;
typedef an_Byte              an_Bool;
typedef an_Byte              an_Chip;
typedef an_Byte              an_CAM;

/* Enumerated type representing CAMClock */
typedef enum an_CAMClock
{
   an_CAMClock_ClockA,                      /* ClockA          */
   an_CAMClock_ClockB,                      /* ClockB          */
   an_CAMClock_ClockC,                      /* ClockC          */
   an_CAMClock_ClockD                       /* ClockD          */
} an_CAMClock;

/* Enumerated type representing ApexClockDivisor */
typedef enum an_ApexClockDivisor
{
   an_ApexClockDivisor_Clock5Delay,         /* Clock5Delay     */
   an_ApexClockDivisor_Clock5,              /* Clock5          */
   an_ApexClockDivisor_Clock4Delay,         /* Clock4Delay     */
   an_ApexClockDivisor_Clock4,              /* Clock4          */
   an_ApexClockDivisor_Clock3,              /* Clock3          */
   an_ApexClockDivisor_Clock2,              /* Clock2          */
   an_ApexClockDivisor_Clock1,              /* Clock1          */
   an_ApexClockDivisor_Clock0,              /* Clock0          */
   an_ApexClockDivisor_ClockPowerUps,         /* ClockPowerUps   */
   an_ApexClockDivisor_ClockSys1,           /* ClockSys1       */
   an_ApexClockDivisor_ClockSys2,           /* ClockSys2       */
   an_ApexClockDivisor_ClockSys1Sys2Flag          /* ClockSys1Sys2Flag */
} an_ApexClockDivisor;

/* Enumerated type representing ClockDivisor */
typedef enum an_ClockDivisor
{
   an_ClockDivisor_Chop2,                   /* Chop2           */
   an_ClockDivisor_Chop1,                   /* Chop1           */
   an_ClockDivisor_Clock3,                  /* Clock3          */
   an_ClockDivisor_Clock2,                  /* Clock2          */
   an_ClockDivisor_Clock1,                  /* Clock1          */
   an_ClockDivisor_Clock0,                  /* Clock0          */
   an_ClockDivisor_PreScale                 /* PreScale        */
} an_ClockDivisor;

/* Enumerated type representing VortexControlByte */
typedef enum an_VortexControlByte
{
   an_VortexControlByte_SAFD        = 0x80, /* SAFD            */
   an_VortexControlByte_ResetAll    = 0x40, /* ResetAll        */
   an_VortexControlByte_InhibitRdbck = 0x20, /* InhibitRdbck    */
   an_VortexControlByte_Read        = 0x10, /* Read            */
   an_VortexControlByte_SReset      = 0x08, /* SReset          */
   an_VortexControlByte_EndExecute  = 0x04, /* EndExecute      */
   an_VortexControlByte_TESTCTRL    = 0x02, /* TESTCTRL        */
   an_VortexControlByte_Pullups     = 0x01, /* Pullups         */
   an_VortexControlByte_PUs_Ex      = 0x05  /* PUs_Ex          */
} an_VortexControlByte;

/* Enumerated type representing ApexControlByte */
typedef enum an_ApexControlByte
{
   an_ApexControlByte_EndExecute    = 0x80, /* EndExecute      */
   an_ApexControlByte_Pullups       = 0x40, /* Pullups         */
   an_ApexControlByte_ResetAll      = 0x20, /* ResetAll        */
   an_ApexControlByte_SAFD          = 0x10, /* SAFD            */
   an_ApexControlByte_UpdateClocks  = 0x01, /* UpdateClocks    */
   an_ApexControlByte_SReset        = 0x07, /* SReset          */
   an_ApexControlByte_PUs_UpClks    = 0x41, /* PUs_UpClks      */
   an_ApexControlByte_PUs_UpClks_Ex = 0xC1  /* PUs_UpClks_Ex   */
} an_ApexControlByte;

/* Enumerated type representing ApiReconfigState */
typedef enum an_ApiReconfigState
{
   an_ApiReconfigState_Initialized  = 0x01, /* Initialized     */
   an_ApiReconfigState_CRCEnabled   = 0x02  /* CRCEnabled      */
} an_ApiReconfigState;

/* If NULL has not yet been defined, do it now. */
#ifndef NULL
#define NULL 0
#endif

/* Just a definition for ease of code reading. */
#define an_apiInvalid        0xFF

/* Each chip is given a numeric ID to be used when calling C Code   
functions */                                                        
#define an_FPAA1                       0         /* "FPAA1" */

/* How many chips with programmable Chips there are. */             
#define an_apiChipCount                1

/* This array maps the numeric ID assigned to each chip in the      
ApiCode.h file to the chip's Address1. */                           
extern const an_Byte an_apiAddress1[an_apiChipCount];

/* This structure contains all the information about the primary    
configuration of a chip */                                          
typedef struct an_apiPrimaryConfigInfo
{
   const an_Byte* data;
   short length;
} an_apiPrimaryConfigInfo;

/* These hold the initial configuration streams for the chips. */   
extern const an_Byte an_FPAA1_PrimaryConfigInfo[];

/* This array maps the numeric ID assigned to each chip in the      
ApiCode.h file to its primary configuration data. */                
extern const an_apiPrimaryConfigInfo an_apiPrimaryConfigData[an_apiChipCount];

/* This is the constant synchronizing header byte. */               
extern const an_Byte an_apiSynchByte;

/* This structure contains all the information about the current state  
of an update stream. */                                             
typedef struct an_apiReconfigInfo
{
   an_Byte* data; /* Pointer to the configuration data. */
   short length;   /* Length of the configuration data */
   short capacity; /* Amount of memory allocated */
   short lastUpdateIndex; /* Index of address1 of the last update. */
   an_ApiReconfigState flags; /* Internal state */
} an_apiReconfigInfo;

/* There is one of these structures for each programmable chip. */  
extern an_apiReconfigInfo an_FPAA1_ReconfigInfo;   /* FPAA1 */

/* This array maps the numeric ID assigned to each chip in the      
ApiCode.h fileto the apiReconfigInfo struct of that chip. */        
extern an_apiReconfigInfo* an_apiReconfigData[an_apiChipCount];

/* There is one of these buffers for each programmable chip. */     
extern an_Byte an_FPAA1_ReconfigBuffer[64];        /* FPAA1 */

/* This array maps the numeric ID assigned to each chip in the      
ApiCode.h file to the reconfiguration buffer of that chip. */       
extern an_Byte* an_apiReconfigBuffer[an_apiChipCount];

/* Each CAM that is controllable is given a numeric ID to be used when  
calling C Code functions. */                                        
#define an_FPAA1_FilterBilinear2       0         /* "FilterBilinear2" */
#define an_FPAA1_GainInv1              1         /* "GainInv1" */
#define an_FPAA1_GainInv2              2         /* "GainInv2" */
#define an_FPAA1_GainLimiter1          3         /* "GainLimiter1" */

/* How many programmable CAMs there are. */                         
#define an_apiCAMCount                 4

/* This array maps the numeric ID assigned to each CAM in the       
ApiCode.h file to the numeric ID of the chip which the CAM is in. */  
extern const an_Byte an_apiChipFromCAM[an_apiCAMCount];

/* Component ID's for okikaApex\FilterBilinear */
#define an_okikaApex_FilterBilinear_Cin  0          /* Cin */
#define an_okikaApex_FilterBilinear_Cint 1          /* Cint */
#define an_okikaApex_FilterBilinear_Cout 2          /* Cout */

/* Component ID's for okikaApex\GainInv */
#define an_okikaApex_GainInv_Cin         0          /* Cin */
#define an_okikaApex_GainInv_Cout        1          /* Cout */
#define an_okikaApex_GainInv_aCin        2          /* aCin */
#define an_okikaApex_GainInv_aCout       3          /* aCout */

/* Component ID's for okikaApex\GainLimiter */
#define an_okikaApex_GainLimiter_C2      0          /* C2 */
#define an_okikaApex_GainLimiter_C3      1          /* C3 */
#define an_okikaApex_GainLimiter_Cin     2          /* Cin */
#define an_okikaApex_GainLimiter_Cout    3          /* Cout */
#define an_okikaApex_GainLimiter_aC2     4          /* aC2 */
#define an_okikaApex_GainLimiter_aC3     5          /* aC3 */
#define an_okikaApex_GainLimiter_aCin    6          /* aCin */
#define an_okikaApex_GainLimiter_aCout   7          /* aCout */

/* This is the data structure for a capacitor. */
typedef struct an_apiCapacitor
{
   an_Byte bank;
   an_Byte byteNum;
} an_apiCapacitor;


/* Component tables for FilterBilinear2 */
extern const an_apiCapacitor an_FPAA1_FilterBilinear2_Capacitor[3];

/* Component tables for GainInv1 */
extern const an_apiCapacitor an_FPAA1_GainInv1_Capacitor[4];

/* Component tables for GainInv2 */
extern const an_apiCapacitor an_FPAA1_GainInv2_Capacitor[4];

/* Component tables for GainLimiter1 */
extern const an_apiCapacitor an_FPAA1_GainLimiter1_Capacitor[8];

/* There is one of these tables for each programmable CAM. Each table  
maps the ID of a component to its ComponentFinder. */               
extern void* an_FPAA1_FilterBilinear2_Components[3];
extern void* an_FPAA1_GainInv1_Components[4];
extern void* an_FPAA1_GainInv2_Components[4];
extern void* an_FPAA1_GainLimiter1_Components[8];

/* This array maps the numeric ID assigned to each CAM in the       
ApiCode.h file to its component map */                              
extern void** an_apiCAMComponentData[an_apiCAMCount];

/* Table to map clock divider ID's to the divider's current value for  
chip FPAA1 */                                                       
extern short an_FPAA1_Clocks[12];

/* This array maps the numeric ID assigned to each chip in the      
ApiCode.h file to the chip's clock data. */                         
extern short* an_apiClockDivisorData[an_apiChipCount];

/* This array maps the numeric ID assigned to each chip in the      
ApiCode.h file to the chip's master clock frequency. */             
extern const long an_apiMasterClockData[an_apiChipCount];

/* Table to map module virtual clocks to actual chip clock for module  
FilterBilinear2 */                                                  
extern const an_ApexClockDivisor an_FPAA1_FilterBilinear2_CAMClocks[4];

/* This array maps the numeric ID assigned to each CAM in the       
ApiCode.h file to the CAM's virtual clock mapping. */               
extern const an_ApexClockDivisor* an_apiCAMClockToApexChipClock[an_apiCAMCount];

/*##################################################################*\
#                                                                    #
#                             Functions                              #
#                                                                    #
\*##################################################################*/

/********************************************************************\
 *                      Primary Configuration                       * 
\********************************************************************/

  /*--------------------------------------------------------------*\
  |                      GetPrimaryConfigData                      |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     const an_Byte* an_GetPrimaryConfigData(an_Chip chip, int* count); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Retrieves the primary configuration data for the chip. The    |
  |  returned data begins with the synch byte and ends with the    |
  |  last error byte. There are no pad bytes included. The number  |
  |  of bytes in the configuration data is set in count.           |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                          GetResetData                          |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     const an_Byte* an_GetResetData(an_Chip chip, int* count);      
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Retrieves configuration data that will perform a soft reset   |
  |  on the chip. The returned data begins with the synch byte and |
  |  ends with the control byte. There are no pad bytes included.  |
  |  The number of bytes in the configuration data is set in       |
  |  count.                                                        |
  |                                                                |
  \*--------------------------------------------------------------*/

/********************************************************************\
 *                         Power Management                         * 
\********************************************************************/

  /*--------------------------------------------------------------*\
  |                       GetVortexSleepData                       |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     const an_Byte* an_GetVortexSleepData(an_Chip chip, int* count, an_Bool powerDown); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Retrieves configuration data that will put the chip to sleep. |
  |  If powerDown is non-zero, then all analog functions will be   |
  |  turned off except the crystal oscillator. The returned data   |
  |  begins with the synch byte and ends with the last error byte. |
  |  There are no pad bytes included. The number of bytes in the   |
  |  configuration data is set in count.                           |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                        GetApexSleepData                        |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     const an_Byte* an_GetApexSleepData(an_Chip chip, int* count, 
                                       an_Bool powerDown,
                                       an_Bool VMR,
                                       an_Bool watchDog
                                       ); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Retrieves configuration data that will put the chip to sleep. |
  |  If powerDown is non-zero, then the analog cells are powered   |
  |  DOWN. If VMR is non-zero, then VMR is powered UP. If watchDog |
  |  is non-zero, then the watchDog circuit is powered up. The     |
  |  returned data begins with the synch byte and ends with the    |
  |  last error byte. There are no pad bytes included. The number  |
  |  of bytes in the configuration data is set in count.           |
  |                                                                |
  \*--------------------------------------------------------------*/

/********************************************************************\
 *                         Reconfiguration                          * 
\********************************************************************/

  /*--------------------------------------------------------------*\
  |                  InitializeVortexReconfigData                  |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_InitializeVortexReconfigData(an_Chip chip);            
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Configures memory for the reconfiguration data and does       |
  |  initial setup of the header. Must be called prior to using    |
  |  any other reconfiguration functions for the chip.             |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                   InitializeApexReconfigData                   |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_InitializeApexReconfigData(an_Chip chip);              
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Configures memory for the reconfiguration data and does       |
  |  initial setup of the header. Must be called prior to using    |
  |  any other reconfiguration functions for the chip.             |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                    ClearVortexReconfigData                     |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_ClearVortexReconfigData(an_Chip chip);                 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Resets the reconfiguration data for the chip back to what it  |
  |  was when ApiCall:InitializeVortexReconfigData was first       |
  |  called. This does not free any memory.                        |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                     ClearApexReconfigData                      |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_ClearApexReconfigData(an_Chip chip);                   
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Resets the reconfiguration data for the chip back to what it  |
  |  was when ApiCall:InitializeApexReconfigData was first called. |
  |  This does not free any memory.                                |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                   ShutdownVortexReconfigData                   |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_ShutdownVortexReconfigData(an_Chip chip);              
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Frees memory allocated by an_InitializeVortexReconfigData.    |
  |  an_InitializeVortexReconfigData must be called again prior to |
  |  using any other reconfiguration functions for the chip.       |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                    ShutdownApexReconfigData                    |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_ShutdownApexReconfigData(an_Chip chip);                
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Frees memory allocated by an_InitializeApexReconfigData.      |
  |  an_InitializeApexReconfigData must be called again prior to   |
  |  using any other reconfiguration functions for the chip.       |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                     GetVortexReconfigData                      |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     const an_Byte* an_GetVortexReconfigData(an_Chip chip, int* count); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Retrieves the current reconfiguration data for the chip. The  |
  |  returned data begins with the synch byte and ends with the    |
  |  last error byte. There are no pad bytes included. The number  |
  |  of bytes in the reconfiguration is set in count. The data     |
  |  returned from this function is invalidated if another         |
  |  reconfiguration function is called for this chip. The data    |
  |  returned from this function should not be modified.           |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                      GetApexReconfigData                       |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     const an_Byte* an_GetApexReconfigData(an_Chip chip, int* count); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Retrieves the current reconfiguration data for the chip. The  |
  |  returned data begins with the synch byte and ends with the    |
  |  last error byte. There are no pad bytes included. The number  |
  |  of bytes in the reconfiguration is set in count. The data     |
  |  returned from this function is invalidated if another         |
  |  reconfiguration function is called for this chip. The data    |
  |  returned from this function should not be modified.           |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                 SetVortexReconfigControlFlags                  |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_SetVortexReconfigControlFlags(an_Chip chip, an_VortexControlByte flags); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Sets flags in the control byte of the reconfiguration data    |
  |  for a Vortex chip.                                            |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                  SetApexReconfigControlFlags                   |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_SetApexReconfigControlFlags(an_Chip chip, an_ApexControlByte flags); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Sets flags in the control byte of the reconfiguration data    |
  |  for an Apex chip.                                             |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                 SetApexReconfigControlFlagsNOP                 |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_SetApexReconfigControlFlagsNOP(an_Chip chip, an_ApexControlByte flags); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Sets flags in the control byte of the reconfiguration data    |
  |  for an Apex chip.                                             |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                 GetVortexReconfigControlFlags                  |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     an_VortexControlByte an_GetVortexReconfigControlFlags(an_Chip chip); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Retrieves the flags in the control byte of the                |
  |  reconfiguration data for the chip.                            |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                  GetApexReconfigControlFlags                   |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     an_ApexControlByte an_GetApexReconfigControlFlags(an_Chip chip); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Retrieves the flags in the control byte of the                |
  |  reconfiguration data for the chip.                            |
  |                                                                |
  \*--------------------------------------------------------------*/

/********************************************************************\
 *                          CAM Functions                           * 
\********************************************************************/

  /*--------------------------------------------------------------*\
  |                     GetApexClockFrequency                      |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     //NEED TO TAKE WHICH PRESCALER WAS USED INTO ACCOUNT, i.e., an_ClockDivisor_PreScale
an_Frequency an_GetApexClockFrequency(an_CAM cam, an_CAMClock camClock); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Returns the frequency in hz for the CAM clock desired. The    |
  |  clock values are taken from the chip the CAM is in. This      |
  |  should only be called from within CAM functions, and is not   |
  |  intended for use otherwise.                                   |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                          SetCapValue                           |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_SetCapValue(an_CAM cam, an_Component capID, an_Byte value); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Set a capacitor to a given value. The new 8-bit value is      |
  |  value. capID is the name given to represent the capacitor in  |
  |  the CAM net list. This should only be called from within CAM  |
  |  functions, and is not intended for use otherwise.             |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                         ChooseCapRatio                         |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_ChooseCapRatio(double dGain, an_Byte* pCap1, an_Byte* pCap2); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Given a desired gain, this function will calculate the ideal  |
  |  capacitor values. The realized capacitor values will be       |
  |  returned in the pointers that are passed in.                  |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                           AdjustCap                            |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     an_Byte an_AdjustCap(double dValue);                           
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Returns the 8-bit capacitor value most closely representing   |
  |  the passed in value.                                          |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                      FixedChooseCapRatio                       |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_FixedChooseCapRatio(double dGain, an_Byte* pCap1, an_Byte* pCap2); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Given a desired gain, this function will calculate the ideal  |
  |  capacitor values. The realized capacitor values will be       |
  |  returned in the pointers that are passed in.                  |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                         FixedAdjustCap                         |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     an_Byte an_FixedAdjustCap(an_Fixed fValue);                    
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Returns the 8-bit capacitor value most closely representing   |
  |  the passed in value.                                          |
  |                                                                |
  \*--------------------------------------------------------------*/

/********************************************************************\
 *                         Fixed-Point Math                         * 
\********************************************************************/

  /*--------------------------------------------------------------*\
  |                          FloatToFixed                          |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     an_Fixed an_FloatToFixed(float fValue);                        
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Convert from float to ApiName::fixed                          |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                           IntToFixed                           |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     an_Fixed an_IntToFixed(int value);                             
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Convert from int to ApiName::fixed                            |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                           FixedToInt                           |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     int an_FixedToInt(an_Fixed fValue);                            
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Convert from ApiName::fixed to int                            |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                          FixedToFloat                          |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     float an_FixedToFloat(an_Fixed fValue);                        
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Convert from ApiName::fixed to float                          |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                            FixedAbs                            |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     an_Fixed an_FixedAbs(an_Fixed fValue);                         
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  This function returns the absolute value of a fixed-point     |
  |  number.                                                       |
  |                                                                |
  \*--------------------------------------------------------------*/

  /*--------------------------------------------------------------*\
  |                          FixedDivide                           |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     an_Fixed an_FixedDivide(an_Fixed fLeft, an_Fixed fRight);      
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  This function returns the result of dividing two fixed-point  |
  |  numbers. Input fLeft is the left-side of the implied division |
  |  sign. It is the first value to divide. Input fRight is the    |
  |  right-side of the implied division sign. It is the value to   |
  |  divide the first value by. The fixed-point numbers are        |
  |  assumed to be in 16:16 form, although the routine might work  |
  |  for any other fixed-point setup, as long as the two values    |
  |  are identical in their fixed-point setup. But this has not    |
  |  been tested. Division of fixed-point numbers is defined as    |
  |  dividing the mantissas, and subtracting the exponents. Since  |
  |  we are implying 16:16 numbers, the subtraction of exponents   |
  |  would leave us with no fractional part. To solve this         |
  |  problem, we try to shift the numerator up by 16 bits.         |
  |  However, many compilers do not support 64-bit numbers, so we  |
  |  have to improvise a way to do the division without resorting  |
  |  to assembly language or unsupported types.                    |
  |                                                                |
  \*--------------------------------------------------------------*/

/********************************************************************\
 *                           Internal API                           * 
\********************************************************************/

  /*--------------------------------------------------------------*\
  |                     BuildReconfigDataBlock                     |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     void an_BuildReconfigDataBlock(an_Chip chip, an_Byte bank, an_Byte byteNum, an_Byte* values, short count); 
  /*                                                              *\
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  Called by other API functions and should not be directly      |
  |  called by the user. The heart of the reconfiguration API,     |
  |  this function packages an address and a list of values into   |
  |  the proper reconfiguration format, adhering to current        |
  |  auto-grow and CRC16 policies.                                 |
  |                                                                |
  \*--------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif /* APICODE_H */
