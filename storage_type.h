#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H

template <typename T>
class storage_type
{
public:

    //Useful getters to have a clear view of the storage
    virtual storage_type* get_next();
    virtual storage_type* get_previous();
    virtual int get_size();
    virtual T get_elem();

    //Watcher on the element
    virtual bool is_next();
    virtual bool is_previous();

    virtual void add_value(double value, int position); //Function that add a value at the spécified position
    virtual void remove_value(double value); //Remove the value specified from the storage
    virtual void remove_value_at(int position); //Remove the value at the specified position
};

#endif // STORAGE_TYPE_H
