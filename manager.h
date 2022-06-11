#ifndef MANAGER_H
#define MANAGER_H



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

class loader { // pure virtual
}; // as for storage_type, text and bin loaders are children of loader

class text_loader : public loader{

};

class bin_loader : public loader{

};

class calculation { // pure virtual
}; // average, rolling_average, etc. inherit from calculation

class average : public calculation{

};

class rolling_average{

};

class writer { // pure virtual
}; // any output (file - text or bin, screen) inherit from this one

class text_writer : public writer {

};

class bin_writer : public writer{

};

class process { // raw pointers may be improved
    storage_type *_storage;
    loader *_loader;
    calculation *_calc;
    writer *_writer;

public:
    process(storage_type *stor, loader *load, calculation *calc, writer *write);
    void execute();
};

class manager
{





public:
    manager();

    //create the right storage type object
    storage_type make_storage();

    //create the right loader type object
    loader make_reader();

    //create the right calculation type object
    calculation make_calculation();

    //create the right writer type object
    writer make_writer();

};



#endif // MANAGER_H
