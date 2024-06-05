
#include "Polygon.h"

float Polygon::getSignedArea() const noexcept
{
    float Result = 0.0f;

    for ( size_t i = 1; i < fNumberOfVertices; i++  )
    {
        Result += (fVertices[i-1].y() + fVertices[i].y())
                   * (fVertices[i-1].x() - fVertices[i].x());
    }                                                           // 12

    Result += (fVertices[fNumberOfVertices-1].y() + fVertices[0].y())
               * (fVertices[fNumberOfVertices-1].x() - fVertices[0].x());
                                                                // 6
    return Result / 2.0f;                                       // 4
}                                                               // (22)

Polygon Polygon::transform( const Matrix3x3& aMatrix ) const noexcept
{
    Polygon Result = *this;
    
    for ( size_t i = 0; i < fNumberOfVertices; i++ )
    {
        Result.fVertices[i] = static_cast<Vector2D>(aMatrix * fVertices[i]);
    }                                                           // (10)
    
    return Result;
}

// 22+10=(32)
