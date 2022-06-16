/*Created by Catherine*/
#include <data_list.h>
#include <data_table.h>
#include "table_sum.h"
        data_list table_sum::do_sum2(data_list* dlist){
            data_list result;
            double current_sum = 0.0;
            values_list *temp = dlist->get_values_all();
            for (size_t i=0; i<temp->size(); i++) {
                current_sum += temp->get_value(i);
            }
            result.get_values_all()->push_back(current_sum);
            return result;

        };
        double table_sum::do_sum2(data_table *d){
            data_table result;
            double current_sum = 0.0;
            for (const double &value: d->get_values_table()) {
                current_sum += value;
            }
            //Je renvoie juste un entier car on n'a pas besoin d'un tableau pour Ã§a
           return current_sum;
    };

