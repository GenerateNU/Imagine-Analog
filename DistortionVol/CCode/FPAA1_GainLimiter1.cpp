#include "stdafx.h"
#include "FPAA1_GainLimiter1.h"

FPAA1_GainLimiter1::FPAA1_GainLimiter1()
{
   m_instance = an_FPAA1_GainLimiter1;
}

//-----------------------------------------------------------
//  A full floating point method for setting the gain and output  
//  voltage limit of this module.                                 
//-----------------------------------------------------------
double FPAA1_GainLimiter1::setGainLimiter(double G, double VL)
{
   return an_setGainLimiter(m_instance, G, VL);
}

