#pragma once
#include "ResistorBase.h"

class PassiveResistor : public ResistorBase
{
protected:
    bool mustScale(double aValue) const override {
        return aValue >= 1000.0;
    }

    const double getMultiplier() const override {
        return 1.0 / 1000.0;
    }

    const std::string getMajorUnit() const override {
        return "Ohm";
    }

    const std::string getMinorUnits() const override {
        return "OkM"; 
    }

public:
    // Constructor with a default value
    PassiveResistor(double aBaseValue = 0.0) : ResistorBase(aBaseValue) {}

    // Frequency-independent resistance value
    double getReactance(double aFrequency = 0.0) const override {
        return getBaseValue();
    }
};
