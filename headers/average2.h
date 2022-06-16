/*Created by Catherine*/
#ifndef AVERAGE2_H
#define AVERAGE2_H
#include <calculation.h>
#include <data_list.h>
#include <table_sum.h>
#include <data_table.h>

using namespace std;

class average2{
public:
    average2(){};
    ~average2(){};
    //virtual data_table do_average(data_table);
    virtual data_list do_average(data_list* dlist){
        data_list result;
        table_sum table = table_sum();
        data_list sum_table = table.do_sum2(dlist);
        values_list temp = dlist->get_values();
        result.get_values_all()->push_back(sum_table.get_values_all()->get_value(0)/temp.size());
        return result;
    }
    virtual double do_average(data_table * dtable){

        data_table result;
        table_sum sum_table = table_sum();
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
