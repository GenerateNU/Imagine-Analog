#pragma once

class FPAA1_FilterBilinear2
{
public:
   FPAA1_FilterBilinear2();

   //-----------------------------------------------------------
   //  A full floating-point method for setting the corner frequency  
   //  [kHz] and gain of a low-pass filter.                          
   //-----------------------------------------------------------
   double setFilterLowPass(double Fo, double G);

private:
   an_CAM m_instance;
};
