#include "data_list.h"
#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>
#include "moving_average.h"

using namespace std;
/*Constructor of data_list*/
data_list::data_list() {
}
/*Constructor of data_list with parameter*/
data_list::data_list(const data_list &other) {
    _values = other._values;
}
/**/
values_list::values_list(const values_list &other) {
    list_element *ptr = other._head;
    while (ptr) {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
}
/*We copy a list L1 of value in another list L1 after it was empty L2*/
values_list &values_list::operator=(const values_list &other) {
    clear();
    list_element *ptr = other._head;
    while (ptr) {
        push_back(ptr->get_value());
        ptr = ptr->get_next();
    }
    return *this;
}

/*Function to erase the content of the values list*/
void values_list::clear() {
    list_element *tmp = _head;
    while (tmp) {
        _head = tmp->get_next();
        delete tmp;
        tmp = _head;
    }
    _head = _tail = nullptr;
}

/*Function to add a value to the values list*/
void values_list::push_back(double v) {
    if (!_head) {
        _head = new list_element(v);
        _tail = _head;
    } else {
        _tail->set_next(new list_element(v, _tail));
        _tail = _tail->get_next();
    }
}
/*Function to remove a value to the values list*/
void values_list::pop_element() {
    if (_head) {
        list_element *tmp = _head->get_next();
        delete _head;
        _head = tmp;
        if (tmp) {
            tmp->set_prev(nullptr);
        } else {
            _tail = _head; // both =nullptr
        }
    }
}
/*Function to get the size of the values list*/
size_t values_list::size() const {
    size_t s = 0;
    list_element *ptr = _head;
    while (ptr) {
        ptr = ptr->get_next();
        ++s;
    }
    return s;
}

/*Function to get a value from the values list at a position*/
double values_list::get_value(size_t position) const {
    size_t pos = 0;
    list_element *ptr = _head;
    while (ptr) {
        if (pos == position)
            return ptr->get_value();
        ptr = ptr->get_next();
        ++pos;
    }
    throw ("ERROR : Out of bounds of the list"); // Error case: position out of bounds
}
/*Function to sort a list of value*/
void values_list::sort_list(bool ascending) { // Naive sort
    list_element *ptr = _head;
    while (ptr && ptr->get_next()) {
        list_element *min_element = ptr;
        list_element *cursor = ptr;
        while (cursor) {
            if (ascending && cursor->get_value() < min_element->get_value())
                min_element = cursor;
            else if (!ascending && cursor->get_value() > min_element->get_value())
                min_element = cursor;
            cursor = cursor->get_next();
        }
        double tmp = ptr->get_value();
        ptr->set_value(min_element->get_value());
        min_element->set_value(tmp);
        ptr = ptr->get_next();
    }
}


void data_list::from_text(const std::string &source) {
    _values.clear();
    ifstream f{source};
    if (f.is_open()) {
        array<char, 100> buffer;
        while (f.getline(&buffer[0], 100)) {
            _values.push_back(stold(string{buffer.data()}));
        }
    } else {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}
/*Read data from binary file*/
void data_list::from_binary(const std::string &source) {
    _values.clear();
    ifstream f{source, std::ios::binary};
    if (f.is_open()) {
        double buffer;
        while (f.read(reinterpret_cast<char *>(&buffer), sizeof(double))) {
            _values.push_back(buffer);
        }
    } else  {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}

void data_list::to_text(const std::string &destination) {
    ofstream f{destination};
    if (f.is_open()) {
        for (size_t i=0; i<_values.size(); ++i) {
            f << _values.get_value(i) << endl;
        }
    }
}

void data_list::to_binary(const std::string &destination) {
    ofstream f{destination, std::ios::binary};
    if (f.is_open()) {
        for (size_t i=0; i<_values.size(); ++i) {
            double val = _values.get_value(i);
            f.write(reinterpret_cast<const char *>(&val), sizeof(double));
        }
    } else  {
        throw ios_base::failure("File cannot be opened for writing.");
    }
}

/*Function to print the data of a values list*/
void data_list::print_data() const {
    for (size_t i=0; i<_values.size(); ++i) {
        cout << _values.get_value(i) << endl;
    }
}
/*
data_list data_list::moving_average(size_t window_width) {

    data_list result;
    if (window_width < _values.size()) {
        double current_sum = 0.0;
        for (size_t i=0; i<window_width; ++i) {
            current_sum += _values.get_value(i);
        }
        result._values.push_back(current_sum/window_width);
        for (size_t i=0; i+window_width<_values.size(); ++i) {
            current_sum -= _values.get_value(i);
            current_sum += _values.get_value(i+window_width);
            result._values.push_back(current_sum/window_width);
        }
    }
    return result;
}

//This function is used to sort the table according to a boolean to choose the order
data_list data_list::sort_table(bool ascending) {
    data_list result{*this};
    result._values.sort_list(ascending);
    return result;
}

//This function is used to get a liste of average value.
data_list data_list::average() {
    data_list result;
    data_list sum_table = table_sum();
    result._values.push_back(sum_table._values.get_value(0) / _values.size());
    return result;
}

data_list data_list::table_sum() {
    data_list result;
    double current_sum = 0.0;
    for (size_t i=0; i<_values.size(); ++i) {
        current_sum += _values.get_value(i);
    }
    result._values.push_back(current_sum);
    return result;
}
*/
data_list data_list::table_count() {
    data_list result;
    result._values.push_back(static_cast<double>(_values.size()));
    return result;
}