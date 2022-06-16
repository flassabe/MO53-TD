#ifndef SORT_TABLE_H
#define SORT_TABLE_H

#include "calculation.h"
#include "data_list.h"
template <typename T>
class sort_table : public calculation {
public:
    sort_table(){

    };
    /*
    This function is used to sort the table
    We used for it in the parameters a data_list element and a boolean to choose in which order the table should be sorted: ascending or descending
    We return the table sorted.
    */
    data_list do_sort_table(bool ascending, data_list *dlist){
        data_list result{*dlist};
        result.get_values_all()->sort_list(ascending);
        return result;

    };
    ~sort_table(){

    };

};



#endif // SORT_TABLE_H
