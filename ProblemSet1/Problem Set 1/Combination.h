
// COS30008, Problem Set 1/3, 2022
#pragma once
#include <cstddef>
class Combination
{
private:
	size_t fN;
	size_t fK;
public:
	// constructor for combination n over k with defaults
	Combination(size_t aN = 0, size_t aK = 0) : fN(aN), fK(aK) {};

	//Update here
	size_t getN() const { return fN; } ;
	size_t getK() const { return fK; } ;
	// call operator to calculate n over k
	// We do not want to evaluate factorials.
	// Rather, we use this method
	//
	// n (n-0) (n-1) (n - (k - 1))
	// ( ) = ----- * ----- * ... * -------------
	// k 1 2 k
	//
	// which maps to a simple for-loop over 64-bit values.
	unsigned long long operator()() const;
};
