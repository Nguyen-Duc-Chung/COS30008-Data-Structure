#include "Polygon.h"
// Constructor
Polygon::Polygon() : fNumberOfVertices(0) {}

// Getter for the number of vertices
size_t Polygon::getNumberOfVertices() const {
    return fNumberOfVertices;
}

// Getter for a vertex at a given index
const Vector2D& Polygon::getVertex(size_t aIndex) const {
    return fVertices[aIndex];
}

// Read data from input stream
void Polygon::readData(std::istream& aIStream) {
    fNumberOfVertices = 0;
    Vector2D lVertex;
    while (aIStream >> lVertex) {
        if (fNumberOfVertices < MAX_VERTICES) {
            fVertices[fNumberOfVertices++] = lVertex;
        }
    }
}

// Calculate the perimeter of the polygon
float Polygon::getPerimeter() const {
    float lPerimeter = 0.0f;
    for (size_t i = 0; i < fNumberOfVertices; i++) {
        size_t nextIndex = (i + 1) % fNumberOfVertices;
        Vector2D lSegment = fVertices[nextIndex] - fVertices[i];
        lPerimeter += lSegment.length();
    }
    return lPerimeter;
}

// Scale the polygon by a scalar value
Polygon Polygon::scale(float aScalar) const {
    Polygon lResult = *this;
    for (size_t i = 0; i < fNumberOfVertices; i++) {
        lResult.fVertices[i] = fVertices[i] * aScalar;
    }
    return lResult;
}
