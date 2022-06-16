#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H
#include <iostream>
#include <calculation.h>
#include <data_list.h>
#include "data_table.h"

using namespace std;

class moving_average : public calculation{
public:
    moving_average(){

    }
    data_list do_moving_average(size_t window_width) {
        cout << "A:" << endl;
        data_list result;
        cout << "A:" << endl;
        if(window_width <result.get_values().size()){
            cout << "A:" << endl;
            double current_sum = 0.0;
            cout << "A:" << endl;
            for(size_t i=0; i<window_width; i++){
                cout << "A:" << endl;
                current_sum+= result.get_values().get_value(i);
            }
            cout << "A:" << endl;
            result.get_values().push_back(current_sum/window_width);
            cout << "A:" << endl;
            for (size_t i=0; i+window_width<result.get_values().size(); ++i) {
                cout << "A:" << endl;
                current_sum -= result.get_values().get_value(i);
                cout << "A:" << endl;
                current_sum += result.get_values().get_value(i+window_width);
                cout << "A:" << endl;
                result.get_values().push_back(current_sum/window_width);
                cout << "A:" << endl;
            }
        }
        return result;

    };
    data_table do_moving_average2(size_t window_width);
    ~moving_average();

};


#endif // MOVING_AVERAGE_H
