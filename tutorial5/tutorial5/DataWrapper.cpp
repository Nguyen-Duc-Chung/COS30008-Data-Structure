#include "DataWrapper.h"

#include <fstream>
#include <stdexcept>

using namespace std;

// Constructor to initialize member variables
DataWrapper::DataWrapper() : fSize(0), fData(nullptr) {}

// Destructor to release dynamically allocated memory
DataWrapper::~DataWrapper() {
    delete[] fData;
}

// Load function to read data from the input file
bool DataWrapper::load(const std::string& aFileName) {
    ifstream inFile(aFileName);
    if (!inFile.is_open()) {
        return false;  // Failed to open file
    }

    // Read the size of the data
    inFile >> fSize;

    // Dynamically allocate the array
    fData = new DataMap[fSize];

    // Read the data into the array
    for (size_t i = 0; i < fSize; i++) {
        inFile >> fData[i].fIndex >> fData[i].fDatum;
    }

    return true;  // Successfully loaded the data
}

// Returns the size of the data array
size_t DataWrapper::size() const {
    return fSize;
}

// Overloading the index operator to access DataMap by index
const DataMap& DataWrapper::operator[](size_t aIndex) const {
    if (aIndex >= fSize) {
        throw out_of_range("Index out of bounds");
    }
    return fData[aIndex];
}

// Returns the data element selected by the Callable function
const char DataWrapper::get(size_t aIndex, Callable aSelector) {
    if (aIndex >= fSize) {
        throw out_of_range("Index out of bounds");
    }
    return aSelector(aIndex);
}

// Implementation of getAsChar for DataMap
const char DataMap::getAsChar() const {
    return static_cast<const char>(fDatum);
}
