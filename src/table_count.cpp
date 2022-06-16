/*Created by Catherine*/
#include "table_count.h"
#include "data_list.h"
data_list table_count::do_table_count(data_list* dlist){
    data_list result;
    result.get_values_all()->push_back(static_cast<double>(dlist->get_values_all()->size()));
    return result;
};
