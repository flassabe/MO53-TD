#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H
#include <iostream>
#include <calculation.h>
#include <data_list.h>
#include "data_table.h"

using namespace std;

class moving_average : public calculation{
public:
    moving_average();
    data_list do_moving_average(size_t window_width);
    data_table do_moving_average2(size_t window_width);
    ~moving_average(){};

};


#endif // MOVING_AVERAGE_H
