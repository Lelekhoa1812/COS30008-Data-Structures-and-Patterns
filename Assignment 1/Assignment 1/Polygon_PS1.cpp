#define _USE_MATH_DEFINES     // must be defined before any #include
#include "Polygon.h"
#include "Matrix3x3.h"
#include <cmath>

float Polygon::getSignedArea() const noexcept {
    float area = 0.0f;
    for (size_t i = 0; i < fNumberOfVertices; ++i) {
        const Vector2D& current = fVertices[i];
        const Vector2D& next = fVertices[(i + 1) % fNumberOfVertices];
        area += (current.y() + next.y()) * (current.x() - next.x());
    }
    return area / 2.0f;
}

Polygon Polygon::transform(const Matrix3x3& aMatrix) const noexcept {
    Polygon transformedPolygon;
    for (size_t i = 0; i < fNumberOfVertices; ++i) {
        const Vector3D vertex3D(fVertices[i].x(), fVertices[i].y(), 1.0f);
        const Vector3D transformedVertex = aMatrix * vertex3D;
        transformedPolygon.fVertices[i] = Vector2D(transformedVertex.x(), transformedVertex.y());
    }
    transformedPolygon.fNumberOfVertices = fNumberOfVertices;
    return transformedPolygon;
}
