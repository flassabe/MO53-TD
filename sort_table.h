#ifndef SORT_TABLE_H
#define SORT_TABLE_H

#include "calculation.h"
#include "data_list.h"
class sort_table : public calculation {
public:
    sort_table(){

    };
    data_list do_sort_table(bool ascending, data_list *dlist);
    ~sort_table(){

    };

};



#endif // SORT_TABLE_H
