#ifndef AVERAGE2_H
#define AVERAGE2_H
#include <calculation.h>
#include <data_list.h>
#include <table_sum2.h>
#include <data_table.h>

using namespace std;

class average2{
public:
    average2(){};
    ~average2(){};
    //virtual data_table do_average(data_table);
    virtual data_list do_average(data_list* dlist){
        data_list result;
        table_sum2 table = table_sum2();
        data_list sum_table = table.do_sum2(dlist);
        values_list temp = dlist->get_values();
        result.get_values_all()->push_back(sum_table.get_values_all()->get_value(0)/temp.size());
        return result;
    }
    virtual double do_average(data_table * dtable){
//        data_table result;

//        table_sum2 sum_table = table_sum2();
//        data_table sum = sum_table.do_sum2(dtable);
//        cout << "oh no oh no oh nonononono:" << endl;
//        result.get_values_table().push_back(sum.get_values_table()[0] / dtable->get_values_table().size());
//        return result;

        data_table result;
        table_sum2 sum_table = table_sum2();
        double sum = sum_table.do_sum2(dtable);
        cout << "oh no oh no oh nonononono:" << endl;
        sum = sum / dtable->get_values_table().size();
        return sum;

    }
};

/*
This function is used to have the average value of a data_list element.
For it, we do the sum of the sum of the value and then we devide it by its length
We return the average value
*/

#endif // AVERAGE2_H
