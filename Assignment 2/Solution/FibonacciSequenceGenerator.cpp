
// COS30008, Problem Set 2, 2024

#include "FibonacciSequenceGenerator.h"

#include <cassert>                                                      // (2)

using namespace std;

FibonacciSequenceGenerator::FibonacciSequenceGenerator(const std::string& aID) noexcept :
    fID(aID),                                                           // 2
    fPrevious(0),                                                       // 2
    fCurrent(1)                                                         // 2(6)
{}

const std::string& FibonacciSequenceGenerator::id() const noexcept
{
    return fID;                                                         // (2)
}

const long long& FibonacciSequenceGenerator::operator*() const noexcept
{
    return fCurrent;                                                    // (2)
}

FibonacciSequenceGenerator::operator bool() const noexcept
{
    return hasNext();                                                   // (4)
}

void FibonacciSequenceGenerator::reset() noexcept
{
    fPrevious = 0;                                                      // 2
    fCurrent = 1;                                                       // 2(4)
}

bool FibonacciSequenceGenerator::hasNext() const noexcept
{
    long long lNext = fCurrent + fPrevious;                             // 4
    
    // An overflow occurs if lNext turns negative.
    return lNext > 0;                                                   // 4(8)
}

void FibonacciSequenceGenerator::next() noexcept
{
    assert(hasNext());                                                  // 4
    
    long long lNext = fCurrent + fPrevious;                             // 4
    
    fPrevious = fCurrent;                                               // 2
    fCurrent = lNext;                                                   // 2(12)
}

                                                                        // 2+6+2+2+4+4+8+12=(40)
