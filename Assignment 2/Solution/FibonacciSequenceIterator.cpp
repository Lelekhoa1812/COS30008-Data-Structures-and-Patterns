
// COS30008, Problem Set 2, 2024

#include "FibonacciSequenceIterator.h"

FibonacciSequenceIterator::FibonacciSequenceIterator( const FibonacciSequenceGenerator& aSequenceObject,
                                                      long long aStart) noexcept :
    fSequenceObject(aSequenceObject),                                               // 1
    fIndex(aStart)                                                                  // 1
{
    fSequenceObject.reset();                                                        // 2(4)
}

const long long& FibonacciSequenceIterator::operator*() const noexcept
{
    return *fSequenceObject;                                                        // (4)
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept
{
    // guard to allow for iterator to move safely into end position
    if (fSequenceObject.hasNext())                                                  // 4
    {
        fSequenceObject.next();                                                     // 4
    }
    
    fIndex++;                                                                       // 2
    
    return *this;                                                                   // 2/(12)
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept
{
    FibonacciSequenceIterator result = *this;                                       // 4
    
    ++(*this);                                                                      // 4
    
    return result;                                                                  // 2/(10)
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const noexcept
{
    return
        (fSequenceObject.id() == aOther.fSequenceObject.id() ) &&                   // 6
        (fIndex == aOther.fIndex);                                                  // 4/(10)
}

bool FibonacciSequenceIterator::operator!=( const FibonacciSequenceIterator& aOther) const noexcept
{
    return !(*this == aOther);                                                      // (4)
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept
{
    FibonacciSequenceIterator iter = *this;                                         // 4
    
    iter.fSequenceObject.reset();                                                   // 6
    iter.fIndex = 1;                                                                // 4
    
    return iter;                                                                    // 2(16)
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept
{
    FibonacciSequenceIterator iter = *this;                                         // 4
    
    // Value determined in problem 1. Limit is 92. 93 is end marker.
    iter.fIndex = 93;                                                               // 4
    
    return iter;                                                                    // 2(10)
}

                                                                                    // 4+4+12+10+10+4+16+10=(70)
