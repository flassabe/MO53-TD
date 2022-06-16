#ifndef SORT_TABLE_H
#define SORT_TABLE_H

#include "calculation.h"
#include "data_list.h"
#include "data_table.h"
class sort_table : public calculation {
public:
    sort_table(){

    };
    data_list do_sort_table(bool ascending, data_list *dlist);
    data_table do_sort_table(bool ascending, data_table *dtable);
    ~sort_table(){

    };

};



#endif // SORT_TABLE_H
