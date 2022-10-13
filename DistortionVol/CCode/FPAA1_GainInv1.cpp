#include "stdafx.h"
#include "FPAA1_GainInv1.h"

FPAA1_GainInv1::FPAA1_GainInv1()
{
   m_instance = an_FPAA1_GainInv1;
}

//-----------------------------------------------------------
//  A full fixed-point method for setting the gain of the module.  
//  It accepts floating-point inputs and returns a floating-point  
//  result.                                                       
//-----------------------------------------------------------
double FPAA1_GainInv1::fixed_setGainInv(double G)
{
   return an_fixed_setGainInv(m_instance, G);
}

//-----------------------------------------------------------
//  A full floating point method for setting the gain of this     
//  module.                                                       
//-----------------------------------------------------------
double FPAA1_GainInv1::setGainInv(double G)
{
   return an_setGainInv(m_instance, G);
}

