#include "Combination.h"

unsigned long long Combination::operator()() const
{
    if (fK > fN) // If k is greater than n, return 0 since it's not possible
        return 0;

    unsigned long long result = 1;

    // Loop to calculate n! / (k!(n - k)!)
    for (size_t i = 0; i < fK; ++i)
    {
        result *= (fN - i);    // Multiply by (n - i)
        result /= (i + 1);     // Divide by (i + 1)
    }

    return result;
}
