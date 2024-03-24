//
//  Matrix3x3.cpp
//  Lab03
//
//  Created by khoa le on 13/3/2024.
//

#define _USE_MATH_DEFINES     // must be defined before any #include

#include "Matrix3x3.h"

#include <cmath>
#include <cassert>

Matrix3x3::Matrix3x3() noexcept :
fRows {
    Vector3D(1.0f, 0.0f, 0.0f),
    Vector3D(0.0f, 1.0f, 0.0f),
    Vector3D(.0f, 0.0f, 1.0f) }
{}

Matrix3x3::Matrix3x3( const Vector3D& aRow1, const Vector3D& aRow2, const Vector3D& aRow3 ) noexcept :
fRows { aRow1, aRow2, aRow3 }
{}

Matrix3x3 Matrix3x3::operator*( const float aScalar ) const noexcept
{
    return Matrix3x3(
                     row(0) * aScalar,
                     row(1) * aScalar,
                     row(2) * aScalar
                     );
}
Matrix3x3 Matrix3x3::operator+( const Matrix3x3& aOther ) const noexcept
{
    return Matrix3x3(
                     row(0) + aOther.row(0),
                     row(1) + aOther.row(1),
                     row(2) + aOther.row(2)
                     );
}

Vector3D Matrix3x3::operator*( const Vector3D& aVector ) const noexcept
{
    return Vector3D(
                     row(0).dot(aVector),
                     row(1).dot(aVector),
                     row(2).dot(aVector)
                     );
}

Matrix3x3 Matrix3x3::scale( const float aX, const float aY )
{
    return Matrix3x3(
                     Vector3D(aX, 0.0f, 0.0f),
                     Vector3D(0.0f, aY, 0.0f),
                     Vector3D(0.0f, 0.0f, 1.0f)
                     );
}

Matrix3x3 Matrix3x3::translate( const float aX, const float aY )
{
    return Matrix3x3(
                     Vector3D(1.0f, 0.0f, aX),
                     Vector3D(0.0f, 1.0f, aY),
                     Vector3D(0.0f, 0.0f, 1.0f)
                     );
}

Matrix3x3 Matrix3x3::rotate( const float aAngleInDegree )
{
    float lRadians = aAngleInDegree * static_cast<float>(M_PI) / 180.0f;
    float sin = std::sin(lRadians);
    float cos = std::cos(lRadians);
    
    return Matrix3x3(
                     Vector3D(cos, -sin, 0.0f),
                     Vector3D(sin, cos, 0.0f),
                     Vector3D(0.0f, 0.0f, 1.0f)
                     );
}

const Vector3D Matrix3x3::row( size_t aRowIndex ) const
{
    assert(aRowIndex <3);
    return fRows[aRowIndex];
}
const Vector3D Matrix3x3::column( size_t aColumnIndex ) const
{
    assert(aColumnIndex <3);

    return Vector3D(
                    row(0)[aColumnIndex],
                    row(1)[aColumnIndex],
                    row(2)[aColumnIndex]);
}
