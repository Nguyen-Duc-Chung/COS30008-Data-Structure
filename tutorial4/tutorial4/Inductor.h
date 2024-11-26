#pragma once
#define _USE_MATH_DEFINES
#include "ResistorBase.h"
#include <cmath>
#define PI 3.14159265358979323846


class Inductor : public ResistorBase
{
protected:
    bool mustScale(double aValue) const override {
        return aValue < 1.0;
    }

    const double getMultiplier() const override {
        return 1000.0;
    }

    const std::string getMajorUnit() const override {
        return "H"; // Henry
    }

    const std::string getMinorUnits() const override {
        return "Hmunp"; // p = pico, n = nano, u = micro, m = milli
    }

public:
    Inductor(double aBaseValue = 0.0) : ResistorBase(aBaseValue) {}

    // Reactance of an inductor: Xl = 2 * pi * f * L
    double getReactance(double aFrequency = 0.0) const override {
        return 2 * PI * aFrequency * getBaseValue();
    }
};



