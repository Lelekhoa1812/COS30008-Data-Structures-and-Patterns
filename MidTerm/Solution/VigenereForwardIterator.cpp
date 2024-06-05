
// COS30008, Midterm 2024

#include "VigenereForwardIterator.h"

#include <cctype>                                                   // (2)

void VigenereForwardIterator::encodeCurrentChar() noexcept
{
    fCurrentChar = fSource[fIndex];                                 // 4
    
    if ( std::isalpha( fCurrentChar ) )                             // 4
    {
        bool isLower = std::islower( fCurrentChar );                // 4
        char aCharacter = std::toupper( fCurrentChar );             // 4

        // get indices
        size_t lRow = *fKeys - 'A';                                 // 4
        size_t lColumn = aCharacter - 'A';                          // 4

        // advance keyword provider
        ++fKeys;                                                    // 4

        // object encoded character
        fCurrentChar = fMappingTable[lRow][lColumn];                // 4

        if (isLower)                                                // 2
        {
            fCurrentChar = std::tolower( fCurrentChar );            // 4(38)
        }
     }
}

void VigenereForwardIterator::decodeCurrentChar() noexcept
{
    fCurrentChar = fSource[fIndex];                                 // 4

    if ( std::isalpha( fCurrentChar ) )                             // 4
    {
        bool isLower = std::islower( fCurrentChar );                // 4
        char aCharacter = std::toupper( fCurrentChar );             // 4
        
        // get indices and clear character
        char lRow = *fKeys - 'A';                                   // 4
        
        for ( char lColumn = 0; lColumn < CHARACTERS; lColumn++ )   // 6
        {
            if ( aCharacter == fMappingTable[lRow][lColumn] )       // 6
            {
                fCurrentChar = 'A' + lColumn;                       // 4
                break;                                              // 2
            }
        }

        // advance keyword provider
        ++fKeys;                                                    // 4

        // recover spelling
        if ( isLower )                                              // 2
        {
            fCurrentChar = std::tolower( fCurrentChar );            // 4/(48)
        }
    }
}

VigenereForwardIterator::VigenereForwardIterator(
                const std::string& aKeyword,
                const std::string& aSource,
                EVigenereMode aMode) noexcept :
    fMode(aMode),                                                   // 2
    fKeys(aKeyword, aSource),                                       // 2
    fSource(aSource),                                               // 2
    fIndex(0),                                                      // 2
    fCurrentChar('\0')                                              // 2[10]
{
    initializeTable();                                              // 4
    
    if (fKeys != fKeys.end())                                       // 4
    {
        if (fMode == EVigenereMode::Encode)                         // 4
        {
            encodeCurrentChar();                                    // 2
        }
        else
        {
            decodeCurrentChar();                                    // 2(26)
        }
    }
}

char VigenereForwardIterator::operator*() const noexcept
{
    return fCurrentChar;                                            // (2)
}

VigenereForwardIterator& VigenereForwardIterator::operator++() noexcept
{
    fIndex++;                                                       // 2

    if (fMode == EVigenereMode::Encode)                             // 4
    {
        encodeCurrentChar();                                        // 2
    }
    else
    {
        decodeCurrentChar();                                        // 2
    }

    return *this;                                                   // 4(14)
}

VigenereForwardIterator VigenereForwardIterator::operator++(int) noexcept
{
    VigenereForwardIterator old = *this;                            // 4
    
    ++(*this);                                                      // 4
    
    return old;                                                     // 2(10)
}

bool VigenereForwardIterator::operator==(const VigenereForwardIterator& aOther) const noexcept
{
    return                                                          // 2
        fSource == aOther.fSource &&                                // 4
        fIndex == aOther.fIndex;                                    // 4(10)
}

bool VigenereForwardIterator::operator!=(const VigenereForwardIterator& aOther) const noexcept
{
    return !(*this == aOther);                                      // (4)
}

VigenereForwardIterator VigenereForwardIterator::begin() const noexcept
{
    VigenereForwardIterator copy = *this;                           // 4
    
    copy.fKeys = fKeys.begin();                                     // 4
    copy.fIndex = 0;                                                // 4
    copy.fCurrentChar = '\0';                                       // 4
    
    if (copy.fKeys != fKeys.end())                                  // 4
    {
        if (fMode == EVigenereMode::Encode)                         // 4
        {
            copy.encodeCurrentChar();                               // 2
        }
        else
        {
            copy.decodeCurrentChar();                               // 2
        }
    }

    return copy;                                                    // 2(30)
}

VigenereForwardIterator VigenereForwardIterator::end() const noexcept
{
    VigenereForwardIterator copy = *this;                           // 4

    copy.fIndex = fSource.size();                                   // 4
    
    return copy;                                                    // 2(10)
}
                        // total: 2+38+48+26++2+14+10+10+4+30+10=194
