#ifndef CAMCODE_H
#define CAMCODE_H

#include "ApiCode.h"

/********************************************************************\
*                      Dynamx Design Lab C Code                      *
*--------------------------------------------------------------------*
*                                                                    *
*  File:      CAMCode.h                                              *
*  Circuit:   Untitled                                               *
*  Generated: April 26, 2022:  05:50 PM                              *
*  Version:   2.8.0.10 -  (Standard) - Release                       *
*  Copyright: Copyright © 2015 Okika. All rights reserved.           *
*                                                                    *
\********************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

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
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     double an_setFilterLowPass(an_CAM cam, double Fo, double G);   
  /*                                                              *\
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
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     double an_fixed_setGainInv(an_CAM cam, double G);              
  /*                                                              *\
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

  /*--------------------------------------------------------------*\
  |                           setGainInv                           |
  +----------------------------------------------------------------+
  |                                                                |
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     double an_setGainInv(an_CAM cam, double G);                    
  /*                                                              *\
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
  |  Function Declaration                                          |
  \*  ------------------------------                              */
     double an_setGainLimiter(an_CAM cam, double G, double VL);     
  /*                                                              *\
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


#ifdef __cplusplus
}
#endif

#endif /* CAMCODE_H */
