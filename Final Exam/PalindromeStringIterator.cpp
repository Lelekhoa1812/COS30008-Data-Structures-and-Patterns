
// COS30008, Final Exam, 2024

#include "PalindromeStringIterator.h"

void PalindromeStringIterator::moveToNextIndex()
{
	// 3a
}

void PalindromeStringIterator::moveToPreviousIndex()
{
	// 3b
}

PalindromeStringIterator::PalindromeStringIterator(const std::string& aString)
{
	// 3c	
}

char PalindromeStringIterator::operator*() const noexcept
{
	// 3d
}

PalindromeStringIterator& PalindromeStringIterator::operator++() noexcept
{
	// 3e
}

PalindromeStringIterator PalindromeStringIterator::operator++(int) noexcept
{
    PalindromeStringIterator old = *this;

	++(*this);

	return old;
}

PalindromeStringIterator& PalindromeStringIterator::operator--() noexcept
{
	// 3f
}

PalindromeStringIterator PalindromeStringIterator::operator--(int) noexcept
{
    PalindromeStringIterator old = *this;

	--(*this);

	return old;
}

bool PalindromeStringIterator::operator==(const PalindromeStringIterator& aOther) const noexcept
{
	// 3g
}

bool PalindromeStringIterator::operator!=(const PalindromeStringIterator& aOther) const noexcept
{
	return !(*this == aOther);
}

PalindromeStringIterator PalindromeStringIterator::begin() const noexcept
{
	// 3h
}

PalindromeStringIterator PalindromeStringIterator::end() const noexcept
{
	// 3i
}

PalindromeStringIterator PalindromeStringIterator::rbegin() const noexcept
{
	// 3j
}

PalindromeStringIterator PalindromeStringIterator::rend() const noexcept
{
	// 3k
}
