#ifndef TABLE_COUNT_H
#define TABLE_COUNT_H

#include <calculation.h>
#include <data_list.h>

template <typename T>
class table_count : public calculation<T>{
public:
    table_count();
    T do_table_count(T* dlist);
    ~table_count();
};



template <typename T>
table_count<T>::table_count(){
}
template <typename T>
table_count<T>::~table_count(){
}

/*
This function is used to do the table count.
*/
template <typename T>
T table_count<T>:: do_table_count(T *dlist){
    T result;
    result.get_values_all()->push_back(static_cast<double>(dlist->get_values_all()->size()));
    return result;
}

#endif // TABLE_COUNT_H
