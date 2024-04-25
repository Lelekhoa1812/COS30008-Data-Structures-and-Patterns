#include "FibonacciSequenceIterator.h"
#include <iostream>



FibonacciSequenceIterator::FibonacciSequenceIterator(const FibonacciSequence& aSequenceObject, uint64_t aStart) 
{
	fSequenceObject = aSequenceObject;
	fIndex = aStart;
}

FibonacciSequenceIterator::FibonacciSequenceIterator(uint64_t aLimit, uint64_t aStart) : fSequenceObject(aLimit)
{
	
	fIndex = aStart;
}

const uint64_t& FibonacciSequenceIterator::operator*() const
{
	
	return fSequenceObject.current();
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++()
{
	fSequenceObject.advance();


	/*std::cout << "This is fIndex from Iterator" << fIndex << "\t";*/
	fIndex++;
	return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int)
{
	FibonacciSequenceIterator temp = *this;
	++(*this);
	return temp;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const
{
	return (fIndex == aOther.fIndex);
}

bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const
{
	return !(*this == aOther);
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const
{
	FibonacciSequenceIterator Result = *this;
	Result.fSequenceObject.reset();
	Result.fIndex = 1;
	return Result;
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
	FibonacciSequenceIterator Result = *this; 
	/*std::cout << "My Limit is: \t" << fSequenceObject.getLimit() << std::endl;*/
;	Result.fIndex = Result.fSequenceObject.getLimit();
	
	/*std::cout << "\n\t end(): Result.fIndex: " << Result.fIndex << std::endl;*/
	if (Result.fIndex != 0) {
		Result.fIndex += 1;
	}
	else {
		Result.fIndex = 0;
	}
	return Result;
}










