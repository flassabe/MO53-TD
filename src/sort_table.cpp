/*Created by Catherine*/
#include "data_list.h"
#include"sort_table.h"
#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

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
    data_table sort_table::do_sort_table(bool ascending, data_table *dtable){
        cout << "ello"<<endl;
        data_table result;
        result.get_values_table() = dtable->get_values_table();
        if (ascending)
            sort(result.get_values_table().begin(), result.get_values_table().end());
        else
            sort(result.get_values_table().begin(), result.get_values_table().end(), [](const double &a, const double &b) {
                return a > b;
            });
        return result;

    }
