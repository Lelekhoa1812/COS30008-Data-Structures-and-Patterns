
// COS30008, Problem Set 4, 2024

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

template<typename T>
class List
{
private:
  using Node = typename DoublyLinkedList<T>::Node;
    
  Node fHead;		// first element
  Node fTail;		// last element
  size_t fSize;	// number of elements
    
public:

  using Iterator = DoublyLinkedListIterator<T>;
    
  List() noexcept;								// default constructor	(2)

  // copy semantics
  List( const List& aOther );					// copy constructor		(10)
  List& operator=( const List& aOther );		// copy assignment		(14)

  // move semantics
  List( List&& aOther ) noexcept;				// move constructor		(4)
  List& operator=( List&& aOther ) noexcept;	// move assignment		(8)
  void swap( List& aOther ) noexcept;			// swap elements		(9)

  // basic operations
  size_t size() const noexcept;					// list size			(2)
    
  template<typename U>
  void push_front( U&& aData );					// add element at front	(24)
    
  template<typename U>
  void push_back( U&& aData );					// add element at back	(24)
    
  void remove( const T& aElement ) noexcept;	// remove element		(36)
    
  const T& operator[]( size_t aIndex ) const;	// list indexer			(14)
    
  // iterator interface
  Iterator begin() const noexcept;				//						(4)
  Iterator end() const noexcept;				//						(4)
  Iterator rbegin() const noexcept;				//						(4)
  Iterator rend() const noexcept;				//						(4)
};
