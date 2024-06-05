
// COS30008, problem set 1, 2024

#include "Vector3D.h"

#include <sstream>

std::string Vector3D::toString() const noexcept
{
    std::stringstream ss;                               // 2
    
    ss << "[";                                          // 2
    ss << round( x() * 10000.0f ) / 10000.0f << ",";    // 6
    ss << round( y() * 10000.0f ) / 10000.0f << ",";    // 6
    ss << round( w() * 10000.0f ) / 10000.0f;           // 4
    ss << "]";                                          // 2
    
    return ss.str();                                    // 4/(26)
}
