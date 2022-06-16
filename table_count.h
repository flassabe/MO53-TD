#ifndef TABLE_COUNT_H
#define TABLE_COUNT_H

#include <calculation.h>
#include <data_list.h>

class table_count : public calculation{
public:
    table_count(){};
//This function is used to do the table count.

    data_list do_table_count(data_list* dlist){
        data_list result;
        result.get_values_all()->push_back(static_cast<double>(dlist->get_values_all()->size()));
        return result;
    };
    ~table_count(){};
};






#endif // TABLE_COUNT_H
