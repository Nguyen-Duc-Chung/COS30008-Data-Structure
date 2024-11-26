// SortableIntVector.cpp

#include "SortableIntVector.h"

SortableIntVector::SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements)
    : IntVector(aArrayOfIntegers, aNumberOfElements) {}

void SortableIntVector::sort(Comparable aOrderFunction)
{
  
    for (size_t i = 0; i < size(); i++)
    {
        for (size_t j = 0; j < size() - i - 1; j++) 
        {
            int leftElement = get(j);
            int rightElement = get(j + 1);

            bool inCorrectOrder = aOrderFunction(leftElement, rightElement);

            if (!inCorrectOrder)
            {
                swap(j, j + 1);
            }
        }
    }
}
