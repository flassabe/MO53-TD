#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H


class storage_type { // pure virtual
    /* Declarations */

public :

    //add element
    virtual void push_back();

    //delete one element
    virtual void pop_element();

    //get an iterator on the storage
    virtual void iterator();

    //TODO histoire d'opérateur poto

};
// list_storage, vector_storage inherit from storage_type

class list_storage : public storage_type{

};

class vector_storage : public storage_type{

};

#endif // STORAGE_TYPE_H
