#include "Polygon.h"
#include <cassert>

Vector2D fVertices [MAX_VERTICES];
 size_t fNumberOfVertices;

Polygon:: Polygon() noexcept :
fVertices(),
fNumberOfVertices( 0 )
{}

void Polygon::readData(std::istream& aIStream)
{
    while (aIStream >> fVertices[fNumberOfVertices])
    {
        fNumberOfVertices++;
        
    }
}

size_t Polygon::getNumberOfVertices() const noexcept
{
    return fNumberOfVertices;
}

const Vector2D& Polygon::getVertex(size_t aIndex) const
{
    assert(aIndex < fNumberOfVertices);
    return fVertices[aIndex];
}

float Polygon::getPerimeter() const noexcept
{
    float result = 0.0f;
    
    for (size_t i = 0; i < fNumberOfVertices - 1; i++)
    {
        result += (fVertices[i + 1] - fVertices[i]).length();
    }
    result += (fVertices[0] - fVertices[fNumberOfVertices - 1]).length();
    return  result;
}

Polygon Polygon:: scale(float aScalar) const noexcept
{
    Polygon result = *this;
    
    for (size_t i = 0; i < fNumberOfVertices - 1; i++)
    {
        result.fVertices[i] = fVertices[i] * aScalar;
    }
    
    return result;
}
