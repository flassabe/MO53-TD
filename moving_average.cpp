/*#include "moving_average.h"
template <typename T>
moving_average<T>::moving_average(){
}
template <typename T>
T moving_average<T>:: do_moving_average(size_t window_width){
    T result;
    if(window_width <result.get_values().size()){
        double current_sum = 0.0;
        for(size_t i=0; i<window_width; i++){
            current_sum+= result.get_values().get_value(i);
        }
        result.get_values().push_back(current_sum/window_width);
        for (size_t i=0; i+window_width<result.get_values().size(); ++i) {
            current_sum -= result.get_values().get_value(i);
            current_sum += result.get_values().get_value(i+window_width);
            result.get_values().push_back(current_sum/window_width);
        }
    }
    return result;
}
*/
#include <iostream>
#include <data_list.h>
#include "data_table.h"
#include "moving_average.h"

using namespace std;

    moving_average::moving_average(){}
    data_list moving_average::do_moving_average(size_t window_width) {
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
    data_table moving_average::do_moving_average2(size_t window_width){

    }
