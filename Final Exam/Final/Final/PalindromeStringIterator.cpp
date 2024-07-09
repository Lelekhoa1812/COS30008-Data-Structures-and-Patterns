
// COS30008, Final Exam, 2024

#include "PalindromeStringIterator.h"

void PalindromeStringIterator::moveToNextIndex()
{
	// 3a
    while (fIndex < static_cast<int>(fString.length()) && !std::isalpha(fString[fIndex]))
    {
        ++fIndex;
    }
}

void PalindromeStringIterator::moveToPreviousIndex()
{
	// 3b
    while (fIndex >= 0 && !std::isalpha(fString[fIndex]))
    {
        --fIndex;
    }
}

PalindromeStringIterator::PalindromeStringIterator(const std::string& aString)
    : fString(aString), fIndex(-1) // Initialize fIndex to -1 start before first element of forward iteration
{
	// 3c	
}

char PalindromeStringIterator::operator*() const noexcept
{
	// 3d
    return std::toupper(fString[fIndex]);
}

PalindromeStringIterator& PalindromeStringIterator::operator++() noexcept
{
	// 3e
    ++fIndex;
    moveToNextIndex();
    return *this;
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
    --fIndex;
    moveToPreviousIndex();
    return *this;
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
    return fIndex == aOther.fIndex;
}

bool PalindromeStringIterator::operator!=(const PalindromeStringIterator& aOther) const noexcept
{
	return !(*this == aOther);
}

PalindromeStringIterator PalindromeStringIterator::begin() const noexcept
{
	// 3h
    PalindromeStringIterator iter(fString);
    iter.fIndex = 0;
    iter.moveToNextIndex();
    return iter;
}

PalindromeStringIterator PalindromeStringIterator::end() const noexcept
{
	// 3i
    PalindromeStringIterator iter(fString);
    iter.fIndex = static_cast<int>(fString.length());
    return iter;
}

PalindromeStringIterator PalindromeStringIterator::rbegin() const noexcept
{
	// 3j
    PalindromeStringIterator iter(fString);
    iter.fIndex = static_cast<int>(fString.length()) - 1;
    iter.moveToPreviousIndex();
    return iter;
}

PalindromeStringIterator PalindromeStringIterator::rend() const noexcept
{
	// 3k
    PalindromeStringIterator iter(fString);
    iter.fIndex = -1;
    return iter;
}
