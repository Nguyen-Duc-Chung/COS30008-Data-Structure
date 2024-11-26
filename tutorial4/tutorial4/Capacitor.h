#pragma once

#include "ResistorBase.h"
#include <cmath> // for M_PI
#define M_PI 3.14159265358979323846



class Capacitor : public ResistorBase
{
protected:
    bool mustScale(double aValue) const override {
        return aValue < 1.0;
    }

    const double getMultiplier() const override {
        return 1000.0;
    }

    const std::string getMajorUnit() const override {
        return "F"; // Farads
    }

    const std::string getMinorUnits() const override {
        return "Fmunp"; // p = pico, n = nano, u = micro, m = milli
    }

public:
    Capacitor(double aBaseValue = 0.0) : ResistorBase(aBaseValue) {}

    // Reactance of a capacitor: Xc = 1 / (2 * pi * f * C)
    double getReactance(double aFrequency = 0.0) const override {
        return 1.0 / (2 * M_PI * aFrequency * getBaseValue());
    }
};
