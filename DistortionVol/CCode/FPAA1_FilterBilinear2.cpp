#include "stdafx.h"
#include "FPAA1_FilterBilinear2.h"

FPAA1_FilterBilinear2::FPAA1_FilterBilinear2()
{
   m_instance = an_FPAA1_FilterBilinear2;
}

//-----------------------------------------------------------
//  A full floating-point method for setting the corner frequency  
//  [kHz] and gain of a low-pass filter.                          
//-----------------------------------------------------------
double FPAA1_FilterBilinear2::setFilterLowPass(double Fo, double G)
{
   return an_setFilterLowPass(m_instance, Fo, G);
}

