// PolynomialPS1.cpp
#include "Polynomial.h"
#include <cmath> // For pow
#include <iostream>
using namespace std;

// Default constructor
Polynomial::Polynomial() : fDegree(0) {
    for (size_t i = 0; i <= MAX_DEGREE; ++i) {
        fCoeffs[i] = 0.0;
    }
}

// Operator to multiply two polynomials
Polynomial Polynomial::operator*(const Polynomial& aRHS) const {
    Polynomial result;
    result.fDegree = fDegree + aRHS.fDegree; // Degree of product

    for (size_t i = 0; i <= fDegree; ++i) {
        for (size_t j = 0; j <= aRHS.fDegree; ++j) {
            result.fCoeffs[i + j] += fCoeffs[i] * aRHS.fCoeffs[j]; // Multiply terms
        }
    }

    return result;
}

// Operator to compare two polynomials
bool Polynomial::operator==(const Polynomial& aRHS) const {
    if (fDegree != aRHS.fDegree) {
        return false;
    }

    for (size_t i = 0; i <= fDegree; ++i) {
        if (fCoeffs[i] != aRHS.fCoeffs[i]) {
            return false;
        }
    }

    return true;
}

// Input operator for polynomials (highest to lowest)
istream& operator>>(istream& aIStream, Polynomial& aObject) {
    cout << "Enter the degree of the polynomial: ";
    aIStream >> aObject.fDegree;

    if (aObject.fDegree > MAX_POLYNOMIAL) {
        cout << "Degree exceeds maximum allowed, setting degree to " << MAX_POLYNOMIAL << endl;
        aObject.fDegree = MAX_POLYNOMIAL;
    }

    for (int i = aObject.fDegree; i >= 0; --i) {
        cout << "Enter coefficient for x^" << i << ": ";
        aIStream >> aObject.fCoeffs[i];
    }

    return aIStream;
}

// Output operator for polynomials
ostream& operator<<(ostream& aOStream, const Polynomial& aObject) {
    for (int i = aObject.fDegree; i > 0; --i) {
        aOStream << aObject.fCoeffs[i] << "x^" << i << " + ";
    }
    aOStream << aObject.fCoeffs[0];
    return aOStream;
}

// Call operator to calculate the polynomial for a given x
double Polynomial::operator()(double aX) const {
    double result = 0.0;
    for (size_t i = 0; i <= fDegree; ++i) {
        result += fCoeffs[i] * pow(aX, i);  // Apply aX raised to the power of i
    }
    return result;
}

// Compute derivative: the derivative is a fresh polynomial with degree fDegree-1
Polynomial Polynomial::getDerivative() const {
    Polynomial derivative;
    if (fDegree == 0) {
        return derivative;  // Derivative of a constant is zero
    }
    derivative.fDegree = fDegree - 1;
    for (size_t i = 1; i <= fDegree; ++i) {
        derivative.fCoeffs[i - 1] = fCoeffs[i] * i;  // Coeff * degree
    }
    return derivative;
}

// Compute indefinite integral: the indefinite integral is a fresh polynomial with degree fDegree+1
Polynomial Polynomial::getIndefiniteIntegral() const {
    Polynomial integral;
    integral.fDegree = fDegree + 1;
    integral.fCoeffs[0] = 0;  // The constant term (C) is usually set to 0
    for (size_t i = 0; i <= fDegree; ++i) {
        integral.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);
    }
    return integral;
}

// Calculate definite integral: computes indefinite integral, evaluates it at xlow and xhigh
double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const {
    Polynomial integral = getIndefiniteIntegral();
    return integral(aXHigh) - integral(aXLow);
}
