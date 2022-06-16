#include <iostream>
#include "data_list.h"
#include "moving_average.h"
#include "average2.h"
#include "sort_table.h"
#include "table_count.h"
using namespace std;

int main() {
    data_list t;
    t.from_binary("binary.bin");
    cout << "t:" << endl;
    t.print_data();
    average2 avg ;
    auto averave_of_t = avg.do_average(&t);//t2 ou &t2 ou *t2
    cout << "Average of t:" << endl;
    averave_of_t.print_data();

    cout << "t sorted:" << endl;
    sort_table sort_my_table;
    data_list t_sorted;
    t_sorted = sort_my_table.do_sort_table(true,&t);
    t_sorted.print_data();
    cout << "--------------------" << endl;
    cout << "--------------------" << endl;
    cout << "D" << endl;
    data_table D;
    D.from_binary("binary.bin");
    D.print_data();
    auto averave_of_t2 = avg.do_average(&D);
    cout << "Average of D:" << endl;
    cout << averave_of_t2<< endl;
    sort_table sort_my_data;
    data_table d_sorted;
    d_sorted = sort_my_data.do_sort_table(true,&D);
    d_sorted.print_data();
    return 0;
}

/*#include <iostream>
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

    data_table D;
    D.from_binary("binary.bin");
    cout << "D:" << endl;
    D.print_data();
    D.average();
    //average <data_table> avg2;
    //auto average_of_D = avg2.do_average2(&D);
    return 0;
}
*/
