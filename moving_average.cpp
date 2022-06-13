/*#include "moving_average.h"
#include <iostream>
#include <data_list.h>
using namespace std;
template <typename T>
moving_average<T>::moving_average(){
}


template <typename T>
T moving_average<T>:: do_moving_average(size_t window_width){
    cout << "A:" << endl;
    T result;
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
}
*/
