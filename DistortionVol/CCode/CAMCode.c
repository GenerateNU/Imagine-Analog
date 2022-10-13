#include "CAMCode.h"

/********************************************************************\
*                      Dynamx Design Lab C Code                      *
*--------------------------------------------------------------------*
*                                                                    *
*  File:      CAMCode.c                                              *
*  Circuit:   Untitled                                               *
*  Generated: April 26, 2022:  05:50 PM                              *
*  Version:   2.8.0.10 -  (Standard) - Release                       *
*  Copyright: Copyright © 2015 Okika. All rights reserved.           *
*                                                                    *
\********************************************************************/

/*##################################################################*\
#                                                                    #
#                         FilterBilinear.cam                         #
#                                                                    #
\*##################################################################*/

 /*================================================================*\
 )                    Gain and Corner Frequency                     (
 \*================================================================*/

  /*--------------------------------------------------------------*\
  |                        setFilterLowPass                        |
  +----------------------------------------------------------------+
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  A full floating-point method for setting the corner frequency |
  |  [kHz] and gain of a low-pass filter.                          |
  |                                                                |
  |                                                                |
  |  Instance Name       cam                 chip                  |
  |  ------------------------------------------------------------  |
  |  FilterBilinear2     an_FPAA1_FilterBilinear2 an_FPAA1           |
  |                                                                |
  \*--------------------------------------------------------------*/

     double an_setFilterLowPass(an_CAM cam, double Fo, double G)
     {
        static const double an_Pi = 3.1415926535897931;
        short dCin, dCout;
        short dCint = 255;
        short Cin, Cint, Cout;
        double aG, aomega, aFo;
        long clocka = an_GetApexClockFrequency(cam, an_CAMClock_ClockA);
        // Prewarp omega (Fo) into omega_a with Bilinear Transform
        double omega = 2.0 * clocka * tan(an_Pi*Fo*1000.0/clocka);
        double alpha = (clocka/omega - 0.5);
        double err = 99999;
        double bestErr = 999;
        
        while (dCint>0)
        {
           dCout = an_AdjustCap(dCint/alpha);
           dCin = an_AdjustCap(1.0*G*dCout);
           aG = 1.0*dCin/dCout;
           aomega = 2.0 * dCout *clocka/(2.0 * dCint + dCout);
           err = aG/G + G/aG + aomega/omega + omega/aomega;
           if (err < bestErr)
           {
              bestErr = err;
              Cout = dCout;
              Cint = dCint;
              Cin = dCin;
           }
           dCint--;
        }
        aomega = 2.0 * Cout * clocka/(2.0 * Cint + Cout);
        aFo = 0.001*clocka * atan(0.5 * aomega / clocka) / an_Pi;
        an_SetCapValue(cam, an_okikaApex_FilterBilinear_Cin,Cin);
        an_SetCapValue(cam, an_okikaApex_FilterBilinear_Cout,Cout);
        an_SetCapValue(cam, an_okikaApex_FilterBilinear_Cint,Cint);
        return aFo;
     }


/*##################################################################*\
#                                                                    #
#                            GainInv.cam                             #
#                                                                    #
\*##################################################################*/

 /*================================================================*\
 )                               Gain                               (
 \*================================================================*/

  /*--------------------------------------------------------------*\
  |                        fixed_setGainInv                        |
  +----------------------------------------------------------------+
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  A full fixed-point method for setting the gain of the module. |
  |  It accepts floating-point inputs and returns a floating-point |
  |  result.                                                       |
  |                                                                |
  |                                                                |
  |  Instance Name       cam                 chip                  |
  |  ------------------------------------------------------------  |
  |  GainInv1            an_FPAA1_GainInv1   an_FPAA1              |
  |  GainInv2            an_FPAA1_GainInv2   an_FPAA1              |
  |                                                                |
  \*--------------------------------------------------------------*/

     double an_fixed_setGainInv(an_CAM cam, double G)
     {
        an_Byte cap1;
        an_Byte cap2;
        
        an_FixedChooseCapRatio(G, &cap1, &cap2);
        
        an_SetCapValue(cam, an_okikaApex_GainInv_Cin,cap1);
        an_SetCapValue(cam, an_okikaApex_GainInv_aCin,cap1);
        an_SetCapValue(cam, an_okikaApex_GainInv_Cout,cap2);
        an_SetCapValue(cam, an_okikaApex_GainInv_aCout,cap2);
        return an_FixedToFloat(an_FixedDivide(an_IntToFixed(cap1),an_IntToFixed(cap2)));
     }

  /*--------------------------------------------------------------*\
  |                           setGainInv                           |
  +----------------------------------------------------------------+
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  A full floating point method for setting the gain of this     |
  |  module.                                                       |
  |                                                                |
  |                                                                |
  |  Instance Name       cam                 chip                  |
  |  ------------------------------------------------------------  |
  |  GainInv1            an_FPAA1_GainInv1   an_FPAA1              |
  |  GainInv2            an_FPAA1_GainInv2   an_FPAA1              |
  |                                                                |
  \*--------------------------------------------------------------*/

     double an_setGainInv(an_CAM cam, double G)
     {
        an_Byte cap1;
        an_Byte cap2;
        
        an_ChooseCapRatio(G, &cap1, &cap2);
        
        an_SetCapValue(cam, an_okikaApex_GainInv_Cin,cap1);
        an_SetCapValue(cam, an_okikaApex_GainInv_aCin,cap1);
        an_SetCapValue(cam, an_okikaApex_GainInv_Cout,cap2);
        an_SetCapValue(cam, an_okikaApex_GainInv_aCout,cap2);
        
        return (double) cap1 / (double) cap2;
     }


/*##################################################################*\
#                                                                    #
#                          GainLimiter.cam                           #
#                                                                    #
\*##################################################################*/

 /*================================================================*\
 )                  Gain and Output Voltage Limit                   (
 \*================================================================*/

  /*--------------------------------------------------------------*\
  |                         setGainLimiter                         |
  +----------------------------------------------------------------+
  |                                                                |
  |  Description                                                   |
  |  ------------------------------                                |
  |  A full floating point method for setting the gain and output  |
  |  voltage limit of this module.                                 |
  |                                                                |
  |                                                                |
  |  Instance Name       cam                 chip                  |
  |  ------------------------------------------------------------  |
  |  GainLimiter1        an_FPAA1_GainLimiter1 an_FPAA1            |
  |                                                                |
  \*--------------------------------------------------------------*/

     double an_setGainLimiter(an_CAM cam, double G, double VL)
     {
        an_Byte cap1;
        an_Byte cap2;
        an_Byte cap3;
        an_Byte cap4;
        
        double G2 = VL/3.0;
        double G1 = G/G2;
        
        an_ChooseCapRatio(G1, &cap1, &cap2);
        an_ChooseCapRatio(G2, &cap3, &cap4);
        
        an_SetCapValue(cam, an_okikaApex_GainLimiter_Cin,cap1);
        an_SetCapValue(cam, an_okikaApex_GainLimiter_aCin,cap1);
        an_SetCapValue(cam, an_okikaApex_GainLimiter_C2,cap2);
        an_SetCapValue(cam, an_okikaApex_GainLimiter_aC2,cap2);
        an_SetCapValue(cam, an_okikaApex_GainLimiter_C3,cap3);
        an_SetCapValue(cam, an_okikaApex_GainLimiter_aC3,cap3);
        an_SetCapValue(cam, an_okikaApex_GainLimiter_Cout,cap4);
        an_SetCapValue(cam, an_okikaApex_GainLimiter_aCout,cap4);
        
        return (double) cap1 * (double) cap3 /( (double) cap2 * (double) cap4);
        
     }


