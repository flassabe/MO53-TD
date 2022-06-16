/*Created by Catherine*/
#include "average.h"
#include "data_list.h"
#include "table_sum.h"

//Mettre en virtuelle dans table_list et _average
#include <iostream>
using namespace std;
/*
template <typename T>
average<T>::average(){
}

template <typename T>
average<T>::~average(){

}*/

/*
This function is used to have the average value of a data_list element.
For it, we do the sum of the sum of the value and then we devide it by its length
We return the average value
*//*
template <typename T>
T average<T>::do_average(T* dlist){
    T result;
    table_sum<T> table = table_sum<T>();
    T sum_table = table.do_sum(dlist);
    values_list temp = dlist->get_values();
    cout << "OH no oh no oh nonononono !!!:" << endl;
    result.get_values_all()->push_back(sum_table.get_values_all()->get_value(0)/temp.size());
    return result;
}
*/
