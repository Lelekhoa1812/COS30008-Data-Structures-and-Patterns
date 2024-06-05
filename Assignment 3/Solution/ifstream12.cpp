
// COS30008, Problem Set 3, 2024

#include "ifstream12.h"

#include <cassert>                                                  // (2)

void ifstream12::reset()
{
    fByteCount = 0;                                                 // 2
    fByteIndex = 0;                                                 // 2
    fBitIndex = 7;                                                  // 2(6)
}

void ifstream12::fetch_data()
{
    reset();                                                        // 2
    
    fIStream.read(reinterpret_cast<char*>(fBuffer), fBufferSize);   // 6
    
    // set the actual number of bytes read
    fByteCount = fIStream.gcount();                                 // 4(12)
}

std::optional<size_t> ifstream12::readBit()
{
    // no data available
    if ( fByteCount == 0 )                                                          // 4
    {
        fetch_data();                                                               // 2
    }
    
    // have we reached the end
    if ( !eof() )                                                                   // 4
    {
        size_t result = 0;                                                          // 4
        
        // conversion from bits to a single value
        std::byte lByte = fBuffer[fByteIndex] & (std::byte{1} << fBitIndex);        // 4
        
        if ( std::to_integer<size_t>(lByte) > 0 )                                   // 4
        {
            result = 1;                                                             // 2
        }
        
        // move bit pointer
        fBitIndex--;                                                                // 2
        if ( fBitIndex < 0 )                                                        // 4
        {
            fByteCount--;                                                           // 2
            fByteIndex++;                                                           // 2
            fBitIndex = 7;                                                          // 2
        }
        
        return { result };                                                          // 4
    }
        
    return {};                                                                      // 2(42)
}

ifstream12::ifstream12( const char* aFileName, size_t aBufferSize ) :
    fBuffer(new std::byte[aBufferSize]),                            // 6
    fBufferSize(aBufferSize),                                       // 2
    fByteCount(0),                                                  // 2
    fByteIndex(0),                                                  // 2
    fBitIndex(7)                                                    // 2
{
    // open associated input file, if specified
    open( aFileName );                                              // 4(18)
}

ifstream12::~ifstream12()
{
    close();                                                        // 2
    
    delete[] fBuffer;                                               // 2(4)
}

void ifstream12::open( const char* aFileName )
{
    assert(!isOpen());                                              // 4
    
    if (aFileName != nullptr)                                       // 4
    {
        fIStream.open(aFileName, std::ifstream::binary);            // 4(12)
    }
}

void ifstream12::close()
{
    fIStream.close();                                               // (2)
}

bool ifstream12::isOpen() const
{
    return fIStream.is_open();                                      // (4)
}

bool ifstream12::good() const
{
    return fIStream.good();                                         // (4)
}

bool ifstream12::eof() const
{
    return fByteCount == 0;                                         // (4)
}

ifstream12& ifstream12::operator>>( size_t& aValue )
{
    // clear value
    aValue = 0;                                                     // 2
    
    for ( size_t i = 0; i < 12; i++ )                               // 6
    {
        auto lBit = readBit();                                      // 4
        
        if ( lBit )                                                 // 4
        {
            if ( lBit.value() == 1 )                                // 4
            {
                aValue |= static_cast<size_t>(1) << i;              // 4
            }
        }
        else
        {
            break;                                                  // 2
        }
    }
    
    return *this;                                                   // 2(28)
}
