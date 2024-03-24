#define _USE_MATH_DEFINES     // must be defined before any #include
#include "Vector3D.h"
#include <sstream>
#include <iomanip>
#include <cmath>

std::string Vector3D::toString() const noexcept {
    std::stringstream ss;

    // Check if it is an integer
    bool isInteger = (std::floor(x()) == x()) && (std::floor(y()) == y()) && (std::floor(w()) == w());

       // Vector a as and integer has 0 decimal places
       if (isInteger) {
           ss << std::setprecision(0);
       // Non-integer values return as 4 decimal places.
       } else {
           ss << std::fixed << std::setprecision(4);
       }

       // Format output for x and y (as default):
       ss << "[" << x() << "," << y() << ",";

       // Format output for w (by which's whole number has more than 4 digits)
       if (std::abs(w()) > 9999) {
           ss << std::setprecision(1) << w(); // If w()'s whole number has 5 digits, set precision to 1
       } else {
           ss << w(); // Otherwise, set at default
       }
       ss << "]";
    
    // Return the resulting string
    return ss.str();
}
