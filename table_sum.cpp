/*#include "table_sum.h"
#include "data_list.h"


#include <iostream>
using namespace std;

template <typename T>
table_sum<T>::table_sum(){
}
template <typename T>
table_sum<T>::~table_sum(){
}

This function is used to do the sum of a data_list.
Since it has been called from another file, we must create a function in this file to access the private element
his function return the sum of the data_list that has been put in parameters.

template <typename T>
T table_sum<T>::do_sum(T* dlist){
    T result;
    double current_sum = 0.0;
    values_list *temp = dlist->get_values_all();
    for (size_t i=0; i<temp->size(); i++) {
        current_sum += temp->get_value(i);
    }
    result.get_values_all()->push_back(current_sum);
    cout << "End of table_sum :" << endl;
    return result;
}
*/
