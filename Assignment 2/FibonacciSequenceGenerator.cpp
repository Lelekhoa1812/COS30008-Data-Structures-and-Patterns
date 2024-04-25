#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"
#include <stdexcept>
#include <iostream>

class FibonacciSequenceIterator;

FibonacciSequence::FibonacciSequence(uint64_t aLimit) : fPrevious(0), fCurrent(1), fPosition(1)
{	
	
	fLimit = aLimit;
	
}

const uint64_t& FibonacciSequence::current() const
{
	return fCurrent;
}

void FibonacciSequence::advance()
{

	if (fLimit != 0) {
		if (fPosition > fLimit) {

			std::cout << "fPosition:\t" << fPosition << "\t fLimit:\t" << fLimit;
			throw std::out_of_range("Index out of range");
			return;
		}
	}
	
	++fPosition;
	
	uint64_t temp = fCurrent;
	fCurrent += fPrevious;
	fPrevious = temp;
	
}

const uint64_t& FibonacciSequence::getLimit() const
{
	return fLimit;
}

void FibonacciSequence::reset()
{
	
	fPrevious = 0;
	fCurrent = 1;
	fPosition = 1;
}

FibonacciSequenceIterator FibonacciSequence::begin() const
{
	FibonacciSequenceIterator iter(fLimit, 1);
	return iter.begin();	
}

FibonacciSequenceIterator FibonacciSequence::end() const
{
	FibonacciSequenceIterator iter(fLimit,fLimit);
	return iter.end();
}













