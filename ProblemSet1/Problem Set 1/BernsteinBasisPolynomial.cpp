#include "BernsteinBasisPolynomial.h"
#include <cmath> // for pow()

double BernsteinBasisPolynomial::operator()(double aX) const
{
    // Make sure x is within [0, 1]
    if (aX < 0.0 || aX > 1.0)
        return 0.0;

    unsigned int v = fFactor.getK();
    unsigned int n = fFactor.getN();

    // Calculate (n choose v) * x^v * (1 - x)^(n - v)
    double term1 = static_cast<double>(fFactor()); // Binomial coefficient (n choose v)
    double term2 = pow(aX, v);                     // x^v
    double term3 = pow(1.0 - aX, n - v);           // (1 - x)^(n - v)

    return term1 * term2 * term3;
}
