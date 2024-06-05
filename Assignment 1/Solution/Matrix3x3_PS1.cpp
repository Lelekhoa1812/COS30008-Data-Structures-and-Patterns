
// Matrix3x3, problem set 1, 2024

#include "Matrix3x3.h"

#include <cassert>

Matrix3x3 Matrix3x3::operator*( const Matrix3x3& aOther ) const noexcept
{
    Vector3D lRow1 = row( 0 );
    Vector3D lRow2 = row( 1 );
    Vector3D lRow3 = row( 2 );
    Vector3D lColumn1 = aOther.column( 0 );
    Vector3D lColumn2 = aOther.column( 1 );
    Vector3D lColumn3 = aOther.column( 2 );                         // 12

    return Matrix3x3( Vector3D( lRow1.dot( lColumn1 ),
                                lRow1.dot( lColumn2 ),
                                lRow1.dot( lColumn3 ) ),
                      Vector3D( lRow2.dot( lColumn1 ),
                                lRow2.dot( lColumn2 ),
                                lRow2.dot( lColumn3 ) ),
                      Vector3D( lRow3.dot( lColumn1 ),
                                lRow3.dot( lColumn2 ),
                                lRow3.dot( lColumn3 ) ) );          // 14
}                                                                   // (26)

float Matrix3x3::det() const noexcept
{
    Vector3D lRow1 = row( 0 );                                      // 2
    Vector3D lRow2 = row( 1 );                                      // 2
    Vector3D lRow3 = row( 2 );                                      // 2

    float Result = 0.0f;                                            // 2(8)
    
    Result += lRow1[0] * (lRow2[1] * lRow3[2] - lRow2[2] * lRow3[1]);
    Result -= lRow1[1] * (lRow2[0] * lRow3[2] - lRow2[2] * lRow3[0]);
    Result += lRow1[2] * (lRow2[0] * lRow3[1] - lRow2[1] * lRow3[0]);
                                                                    // 12
    return Result;                                                  // 2/(22)
}

Matrix3x3 Matrix3x3::transpose() const noexcept
{
    return Matrix3x3( column( 0 ),                                  // 4
                      column( 1 ),                                  // 2
                      column( 2 ) );                                // 2/(8)
}

bool Matrix3x3::hasInverse() const noexcept
{
    return det() != 0.0f;                                           // (4)
}

Matrix3x3 Matrix3x3::inverse() const noexcept
{
    float lDet = det();
    
    assert ( lDet != 0.0f );                                        // 4
    
    Vector3D lRow1 = row( 0 );
    Vector3D lRow2 = row( 1 );
    Vector3D lRow3 = row( 2 );                                      // 6
    
    return Matrix3x3( Vector3D( lRow2[1] * lRow3[2] - lRow2[2] * lRow3[1],
                                lRow1[2] * lRow3[1] - lRow1[1] * lRow3[2],
                                lRow1[1] * lRow2[2] - lRow1[2] * lRow2[1] ),
                      Vector3D( lRow2[2] * lRow3[0] - lRow2[0] * lRow3[2],
                                lRow1[0] * lRow3[2] - lRow1[2] * lRow3[0],
                                lRow1[2] * lRow2[0] - lRow1[0] * lRow2[2] ) ,
                      Vector3D( lRow2[0] * lRow3[1] - lRow2[1] * lRow3[0],
                                lRow1[1] * lRow3[0] - lRow1[0] * lRow3[1],
                                lRow1[0] * lRow2[1] - lRow1[1] * lRow2[0] )
                     ) * (1.0f / lDet);                             // 14
}                                                                   // (24)

std::ostream& operator<<( std::ostream& aOStream, const Matrix3x3& aMatrix )
{
    return aOStream << "[" << aMatrix.row( 0 ).toString() << ","        // 6
                           << aMatrix.row( 1 ).toString() << ","        // 4
                           << aMatrix.row( 2 ).toString() << "]";       // 4/(14)
}
