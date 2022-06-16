//
// Created by axels on 13/06/2022.
//

#ifndef MO53_REFRACTO_LISTELEMENT_H
#define MO53_REFRACTO_LISTELEMENT_H

class ListElement {
    /*la liste aura un pointeur sur un précédent et un suivant*/
    double _value;
    ListElement *_prev;
    ListElement *_next;

public:
    /*Constructor of ListElement*/
    ListElement(double v=0.0, ListElement *p=nullptr, ListElement *n=nullptr):
            _value(v), _prev(p), _next(n) {}
    /*Destructor of ListElement*/
    ~ListElement() {}
    /*return next element of ListElement*/
    ListElement *getNext() {return _next;}
    void setNext(ListElement *n) { _next = n;}
    ListElement *getPrev() {return _prev;}
    void setPrev(ListElement *n) { _prev = n;}
    double getValue()const {return _value;}
    void setValue(double v) { _value = v;}
};


#endif //MO53_REFRACTO_LISTELEMENT_H
