#pragma once

#include "FPAA1_FilterBilinear2.h"
#include "FPAA1_GainInv1.h"
#include "FPAA1_GainInv2.h"
#include "FPAA1_GainLimiter1.h"

class FPAA1
{
public:
   FPAA1();

   ot_Byte GetDeviceID();

   void ExecutePrimaryConfig(bool Reset);	// Dave Lovell added bool Reset
   void ExecuteReconfig(bool x=false);
   void ExecuteReset();

   void AppendFullReconfig();

// Public CAM member variables for easy access to the chip's CAMs
public:
   FPAA1_FilterBilinear2 FilterBilinear2;
   FPAA1_GainInv1 GainInv1;
   FPAA1_GainInv2 GainInv2;
   FPAA1_GainLimiter1 GainLimiter1;

private:
   ot_Chip m_instance;
};
