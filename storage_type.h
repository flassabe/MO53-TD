#ifndef STORAGE_TYPE_H
#define STORAGE_TYPE_H


class storage_type
{
public:
    storage_type();
    ~storage_type(){};

    //Useful getters to have a clear view of the storage
    double get_next();
    double get_previous();
    int get_size();

    //Watcher on the element
    bool is_next();
    bool is_previous();

    void add_value(double value, int position); //Function that add a value at the spécified position
    void remove_value(double value); //Remove the value specified from the storage
    void remove_value_at(int position); //Remove the value at the specified position
};

#endif // STORAGE_TYPE_H
