//
// Created by axels on 13/06/2022.
//

#ifndef MO53_REFRACTO_VALUESLIST_H
#define MO53_REFRACTO_VALUESLIST_H


#include "Iterator.h"
#include "ListElement.h"

class ValuesList {
    ListElement *_head;
    ListElement *_tail;

public:
    ValuesList(): _head(nullptr), _tail(nullptr) {}
    ValuesList(const ValuesList &other);
    ~ValuesList() {clear();}
    ValuesList &operator=(const ValuesList &other);

    void clear();
    void pushBack(double v); // Always add at the end
    void popElement(); // Remove last element
    size_t size()const;
    double getValue(size_t position)const;

    void sortList(bool ascending);

    // Iterator definition here ...
    Iterator begin() { return Iterator(_head); };
    Iterator end() { return Iterator(_tail); };

    ListElement &operator[](int i) {
        Iterator it = begin();
        int count = 0;
        while(count < i && it != end()) {
            it++;
            count ++;
        }
        return *it;
    }
};

#endif //MO53_REFRACTO_VALUESLIST_H
