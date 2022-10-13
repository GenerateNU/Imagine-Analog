#pragma once

class FPAA1_GainLimiter1
{
public:
   FPAA1_GainLimiter1();

   //-----------------------------------------------------------
   //  A full floating point method for setting the gain and output  
   //  voltage limit of this module.                                 
   //-----------------------------------------------------------
   double setGainLimiter(double G, double VL);

private:
   an_CAM m_instance;
};
