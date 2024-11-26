//PolygonPS1.cpp
#include "Polygon.h"  
#include <cmath>      


float Polygon::getSignedArea() const
{
    float area = 0.0f;  // Initialize area to zero

    // Ensure the polygon has at least 3 vertices
    if (fNumberOfVertices > 2)
    {
    
        for (size_t i = 0; i < fNumberOfVertices - 1; ++i)
        {
            // This part prepare values for terms like x1.y2 and y1.x2
            float nowX = fVertices[i].getX();
            float nowY = fVertices[i].getY();
            float nextX = fVertices[i + 1].getX();
            float nextY = fVertices[i + 1].getY();

            // Return the positive part: x1.y2 + x2.y3 + x3.y1
            area = area + (nowX * nextY);
            // Return the negative part: -( y1.x2 + y2.x3 + y3.x1 )
            area = area - (nextX * nowY);
        }
            //  This handles the terms for xn.y1 and yn.x1 , closing the loop
            float lastX = fVertices[fNumberOfVertices - 1].getX();
            float lastY = fVertices[fNumberOfVertices - 1].getY();
            float firstX = fVertices[0].getX();
            float firstY = fVertices[0].getX();

            area = area + (lastX * firstY);
            area = area - (firstX * lastY);
    
    }

   // the calculated area is divided by 2 to get correct value.
    return area * 0.5f;
}
