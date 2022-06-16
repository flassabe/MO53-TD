#ifndef TABLE_SUM_H
#define TABLE_SUM_H

#include <data_list.h>
#include <data_table.h>
class table_sum {
public:
    table_sum(){};
    ~table_sum(){};
    data_list do_sum2(data_list* dlist);
    double do_sum2(data_table *d);
};

#endif // TABLE_SUM_H
