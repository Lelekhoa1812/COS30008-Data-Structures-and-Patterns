#define _USE_MATH_DEFINES     // must be defined before any #include
#include "Vector3D.h"
#include <sstream>
#include <cmath>

std::string Vector3D::toString() const noexcept {
    std::stringstream ss;
    ss << "[" << std::roundf(10000.0 * x()) / 10000.0 << ","
              << std::roundf(10000.0 * y()) / 10000.0 << ","
              << std::roundf(10000.0 * w()) / 10000.0 << "]";
    
    // Return the resulting string
    return ss.str();
}
