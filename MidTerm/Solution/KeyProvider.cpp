
// COS30008, Midterm 2024

#include "KeyProvider.h"

#include <cctype>                                                       // 2
#include <cassert>                                                      // 2(4)

std::string KeyProvider::preprocessString(const std::string& aString) noexcept
{
    std::string result;                                                 // 2
    
    for (size_t i = 0; i < aString.size(); i++)                         // 6
    {
        if (std::isalpha(aString[i]))                                   // 4
        {
            result += std::toupper(aString[i]);                         // 4
        }
    }
        
    return result;                                                      // 2(18)
}

KeyProvider::KeyProvider(const std::string& aKeyword, const std::string& aSource) noexcept :
    fIndex(0)
{
    // preprocess keyword and source first (result: sequence of upper case characters)
    std::string lKeyword = preprocessString(aKeyword);                  // 4
    std::string lSource = preprocessString(aSource);                    // 4

    // create keyword string
    
    size_t lIndex = 0;                                                  // 4

    for (size_t i = 0; i < lSource.size(); i++)                         // 6
    {
        fKeys += lKeyword[lIndex];                                      // 4
        
        lIndex = (lIndex + 1) % aKeyword.size();                        // 6
    }
    
    assert(fKeys.size() == lSource.size());                             // 4(32)
}

char KeyProvider::operator*() const noexcept
{
    return fKeys[fIndex];                                               // (4)
}

KeyProvider& KeyProvider::operator++() noexcept
{
    fIndex++;                                                           // 2
    
    return *this;                                                       // 2(4)
}

KeyProvider KeyProvider::operator++(int) noexcept
{
    KeyProvider old = *this;                                            // 4
    
    ++(*this);                                                          // 4
    
    return old;                                                         // 2(10)
}

bool KeyProvider::operator==(const KeyProvider& aOther) const noexcept
{
    return                                                              // 2
        fKeys == aOther.fKeys &&                                        // 4
        fIndex == aOther.fIndex;                                        // 4(10)
}

bool KeyProvider::operator!=(const KeyProvider& aOther) const noexcept
{
    return !(*this == aOther);                                          // (4)
}

KeyProvider KeyProvider::begin() const noexcept
{
    KeyProvider copy = *this;                                           // 4

    copy.fIndex = 0;                                                    // 4
    
    return copy;                                                        // 2(10)
}

KeyProvider KeyProvider::end() const noexcept
{
    KeyProvider copy = *this;                                           // 4

    copy.fIndex = fKeys.size();                                         // 4
    
    return copy;                                                        // 2(10)
}
                        // total 4+18+32+4+4+10+10+4+10+10=106
