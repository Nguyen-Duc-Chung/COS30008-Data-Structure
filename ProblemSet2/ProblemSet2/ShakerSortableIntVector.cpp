// ShakerSortableIntVector.cpp
#include "ShakerSortableIntVector.h"
ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
    : SortableIntVector(aArrayOfIntegers, aNumberOfElements) {}
void ShakerSortableIntVector::sort(Comparable aOrderFunction)
{
    bool swapped = true;
    size_t start = 0;
    size_t end = size() - 1;

    while (swapped)
    {
        swapped = false;
        for (size_t i = start; i < end; ++i)
        {
            if (!aOrderFunction(get(i), get(i + 1))) 
            {
                swap(i, i + 1); 
                swapped = true;
            }
        }
        
        if (!swapped) break;
        
        swapped = false;
        
        --end;
       
        for (size_t i = end; i > start; --i)
        {
            if (!aOrderFunction(get(i - 1), get(i))) 
            {
                swap(i - 1, i); 
                swapped = true;
            }
        }
        
        ++start;
    }
}
