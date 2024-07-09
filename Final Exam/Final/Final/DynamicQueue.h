// COS30008, Final Exam, 2024

#pragma once

#include <optional>
#include <cassert>

#include <iostream>

template<typename T>
class DynamicQueue
{
private:
    T* fElements;
    size_t fFirstIndex;
    size_t fLastIndex;
    size_t fCurrentSize;
    
    void resize(size_t aNewSize)
    {
        T* newElements = new T[aNewSize];
        size_t newLastIndex = 0;
        
        for (size_t i = fFirstIndex; i < fLastIndex; ++i)
        {
            newElements[newLastIndex++] = std::move(fElements[i]);
        }

        delete[] fElements;

        fElements = newElements;
        fFirstIndex = 0;
        fLastIndex = newLastIndex;
        fCurrentSize = aNewSize;
    }
    
    void ensure_capacity()
    {
        if (fLastIndex == fCurrentSize)
        {
            resize(fCurrentSize == 0 ? 1 : fCurrentSize * 2);
        }
    }

    void adjust_capacity()
    {
        if (fLastIndex - fFirstIndex <= fCurrentSize / 4 && fCurrentSize > 1)
        {
            resize(fCurrentSize / 2);
        }
    }
    
public:
    DynamicQueue() : fElements(nullptr), fFirstIndex(0), fLastIndex(0), fCurrentSize(0) {}

        ~DynamicQueue()
        {
            delete[] fElements;
        }

        DynamicQueue(const DynamicQueue&) = delete;
        DynamicQueue& operator=(const DynamicQueue&) = delete;

        std::optional<T> top() const noexcept
        {
            if (fFirstIndex == fLastIndex)
            {
                return std::nullopt;
            }
            return fElements[fFirstIndex];
        }

        void enqueue(const T& aValue)
        {
            ensure_capacity();
            fElements[fLastIndex++] = aValue;
        }

        void dequeue()
        {
            assert(fFirstIndex < fLastIndex);
            fFirstIndex++;
            adjust_capacity();
        }
    };
