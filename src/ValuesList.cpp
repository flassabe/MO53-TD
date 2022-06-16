//
// Created by axels on 13/06/2022.
//
#include "../headers/ValuesList.h"

/**/
ValuesList::ValuesList(const ValuesList &other) {
    ListElement *ptr = other._head;
    while (ptr) {
        pushBack(ptr->getValue());
        ptr = ptr->getNext();
    }
}
/*We copy a list L1 of value in another list L1 after it was empty L2*/
ValuesList &ValuesList::operator=(const ValuesList &other) {
    clear();
    ListElement *ptr = other._head;
    while (ptr) {
        pushBack(ptr->getValue());
        ptr = ptr->getNext();
    }
    return *this;
}

/*Function to erase the content of the values list*/
void ValuesList::clear() {
    ListElement *tmp = _head;
    while (tmp) {
        _head = tmp->getNext();
        delete tmp;
        tmp = _head;
    }
    _head = _tail = nullptr;
}

/*Function to add a value to the values list*/
void ValuesList::pushBack(double v) {
    if (!_head) {
        _head = new ListElement(v);
        _tail = _head;
    } else {
        _tail->setNext(new ListElement(v, _tail));
        _tail = _tail->getNext();
    }
}
/*Function to remove a value to the values list*/
void ValuesList::popElement() {
    if (_head) {
        ListElement *tmp = _head->getNext();
        delete _head;
        _head = tmp;
        if (tmp) {
            tmp->setPrev(nullptr);
        } else {
            _tail = _head; // both =nullptr
        }
    }
}
/*Function to get the size of the values list*/
size_t ValuesList::size() const {
    size_t s = 0;
    ListElement *ptr = _head;
    while (ptr) {
        ptr = ptr->getNext();
        ++s;
    }
    return s;
}

/*Function to get a value from the values list at a position*/
double ValuesList::getValue(size_t position) const {
    size_t pos = 0;
    ListElement *ptr = _head;
    while (ptr) {
        if (pos == position)
            return ptr->getValue();
        ptr = ptr->getNext();
        ++pos;
    }
    throw ("ERROR : Out of bounds of the list"); // Error case: position out of bounds
}

/*Function to sort a list of value*/
void ValuesList::sortList(bool ascending) {
    // Bubble sort
    ListElement *ptr;
    int n = this->size();
    double tmp;
    for (int i=0; i<n-1; ++i) {
        ptr = _head;
        for (int j=0; j<n-i-1; ++j) {
            if((ptr->getValue() > ptr->getNext()->getValue() && ascending) || (ptr->getValue() <
                                                                               ptr->getNext()->getValue() && !ascending)) {
                tmp = ptr->getValue();
                ptr->setValue(ptr->getNext()->getValue());
                ptr->getNext()->setValue(tmp);
            }
            ptr = ptr->getNext();
        }
    }
}
