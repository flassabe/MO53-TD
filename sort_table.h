#ifndef SORT_TABLE_H
#define SORT_TABLE_H

#include "calculation.h"
#include "data_list.h"
template <typename T>
class sort_table : public calculation<T> {
public:
    sort_table();
    T do_sort_table(bool ascending, T *dlist);
    ~sort_table();

};



template <typename T>
sort_table<T>::sort_table(){
}
template <typename T>
sort_table<T>::~sort_table(){

}
/*
This function is used to sort the table
We used for it in the parameters a data_list element and a boolean to choose in which order the table should be sorted: ascending or descending
We return the table sorted.
*/
template <typename T>
T sort_table<T>:: do_sort_table(bool ascending, T *dlist){
    T result{*dlist};
    result.get_values_all()->sort_list(ascending);
    return result;

}



#endif // SORT_TABLE_H
