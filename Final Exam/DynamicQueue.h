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
    
    void resize(size_t aNewSize);
    void ensure_capacity();
    void adjust_capacity();
    
public:
    DynamicQueue();
    ~DynamicQueue();
    
    DynamicQueue(const DynamicQueue&) = delete;
    DynamicQueue& operator=(const DynamicQueue&) = delete;
    
    std::optional<T> top() const noexcept;
    void enqueue(const T& aValue);
    void dequeue();
};
