//
//  Capacitor.cpp
//  Lab04
//
//  Created by khoa le on 20/3/2024.
//

#define _USE_MATH_DEFINES

#include "Capacitor.h"

#include <cmath>
#include <cassert>

Capacitor::Capacitor(double aBaseValue) noexcept :
    ComponentBase(aBaseValue, "F", "Fmunp")
{}

bool Capacitor::mustAdjust(double aValue) const noexcept
{
    return aValue < 1.0;
}

const double Capacitor::getScalar() const noexcept
{
    return 1000.0;
}

double Capacitor::getReactance (double aFrequency) const noexcept
{
    // Xc = 1/2 pifC
    
    assert(aFrequency != 0.0 && getBaseValue() != 0.0);
    
    //double pi = std::atan(1.0) * 4.0;
    
    return 1.0 / (2.0 * M_PI * aFrequency * getBaseValue());
}
