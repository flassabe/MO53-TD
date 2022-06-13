#include <iostream>
#include "data_table.h"
#include "data_list.h"
#include "table_sum.h"
#include "moving_average.h"
#include "average.h"
#include "sort_table.h"
#include "table_count.h"
#include "table_sum.h"
using namespace std;

int main() {
    cout << "heho:" << endl;
    data_list t;
    t.from_binary("binary.bin");
    cout << "t:" << endl;
    t.print_data();

    //auto t2 = t.sort_table(false);
    average<data_list> avg ;

    auto averave_of_t = avg.do_average(&t);//t2 ou &t2 ou *t2
    cout << "Average of t:" << endl;
    averave_of_t.print_data();

    cout << "t sorted:" << endl;
    sort_table<data_list> sort_my_table;
    data_list t_sorted;
    t_sorted = sort_my_table.do_sort_table(true,&t);
    t_sorted.print_data();

    table_count<data_list> my_table_count;
    data_list t_table_count;
    t_table_count = my_table_count.do_table_count(&t);
    cout << "t counted:" << endl;
    t_table_count.print_data();
    return 0;
}
