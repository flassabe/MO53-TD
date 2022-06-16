#include "data_list.h"
#include"sort_table.h"

    /*
    This function is used to sort the table
    We used for it in the parameters a data_list element and a boolean to choose in which order the table should be sorted: ascending or descending
    We return the table sorted.
    */
    data_list sort_table::do_sort_table(bool ascending, data_list *dlist){
        data_list result{*dlist};
        result.get_values_all()->sort_list(ascending);
        return result;

    };
