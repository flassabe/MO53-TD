#ifndef MO53_REFRACTO_ITERATOR_H
#define MO53_REFRACTO_ITERATOR_H

#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
#include "ListElement.h"
#include <iostream>

using namespace std;

struct Iterator
{
    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = int;
    using pointer           = ListElement*;  // or also value_type*
    using reference         = ListElement&;  // or also value_type&

    Iterator(pointer ptr) : m_ptr(ptr) {}

    reference operator*() const {
        return *m_ptr;
    }

    pointer operator->() { return m_ptr; }

    // Prefix increment
    Iterator& operator++() {
        m_ptr = m_ptr->getNext();
        return *this;
    }

    // Postfix increment
    Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

    friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

private:

    pointer m_ptr;
};

#endif //MO53_REFRACTO_ITERATOR_H
