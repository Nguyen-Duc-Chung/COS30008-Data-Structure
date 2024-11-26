
// COS30008, Tutorial 6, 2022

#include <iostream>

#define P1
#define P2

#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"

using namespace std;

int main()
{
    /*
    if ( argc != 2 )
    {
        cerr << "Missing argument!" << endl;
        cerr << "Usage: Fibonacci number" << endl;
        return 1;
    }*/

#ifdef P1

    int numFibo;
    cin >> numFibo;
    cout << "Fibonacci sequence up to " << numFibo << ":" << endl;
    FibonacciSequence lSequence(numFibo);

    // test problem 1
try{
    for (uint64_t i = 1; i <= lSequence.getLimit(); i++)
    {
        cout << i << ":\t" << lSequence.current() << endl;
        lSequence.advance();
    }

}
catch (const out_of_range& e) {
    cerr << "Error: " << e.what() << endl;
}

    cout << "Start again:" << endl;

    lSequence.reset();

    for (uint64_t i = 1; i <= lSequence.getLimit(); i++)
    {
        cout << i << ":\t" << lSequence.current() << endl;
        lSequence.advance();
    }

#endif

#ifdef P2

    // C++11 range loop

    cout << "Fibonacci sequence 1..20:" << endl;

    uint64_t i = 1;
    for (const uint64_t& n : FibonacciSequence(20))
    {
        cout << i++ << ":\t" << n << endl;
    }

    // test for infinite sequence

    unsigned long lUserSpecifiedLength;

    cout << "Please specify the desired length of the Fibonacci sequence: ";
    cin >> lUserSpecifiedLength;

    cout << "Running the Fibonacci sequence up to " << lUserSpecifiedLength << endl;

    uint64_t l = 1;
    for (const uint64_t& n : FibonacciSequence(0))
    {
        cout << l << ":\t" << n << endl;

        if (l++ >= lUserSpecifiedLength)
        {
            break;
        }
    }

#endif

    return 0;
}
