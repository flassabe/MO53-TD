/**
 * 
 * @file data_list.h
 * @author antoine richard
 * @date 2022-06-03
 * @brief Contains all classes used to represent a chained list of doubles :
 * - list_element
 * - value_list
 * - data_list
 * 
 */

//
// Define guards
#ifndef DATA_LIST_H
#define DATA_LIST_H


#include <vector>
#include <string>

/**
 * @class list_element
 * @brief Element of a chained list that contains a double value and is linked with previous and next values of the list :
 * - if previous element is null : the element is the list head
 * - if next element is null : the element is the list tail
 * 
 */
class list_element {
    /**
     * @brief element value 
     * 
     */
    double _value;

    /**
     * @brief pointer to the previous list element
     * 
     */
    list_element *_prev;

    /**
     * @brief pointer to the next list element
     * 
     */
    list_element *_next;
    
public:
    /**
     * @brief Construct a new list element
     * 
     * @param v the double value
     * @param p pointer to the previous element
     * @param n pointer to the next element
     */
    list_element(double v=0.0, list_element *p=nullptr, list_element *n=nullptr):
        _value(v), _prev(p), _next(n) {}
    
    /**
     * @brief Destroy the list element
     * 
     */
    ~list_element() {}

    /**
     * @brief Get the next list element
     * 
     * @return list_element* 
     */
    list_element *get_next() {return _next;}

    /**
     * @brief Set the next list element
     * 
     * @param n the new element of the list that will be insert after the current
     * element
     */
    void set_next(list_element *n) {_next = n;}

    /**
     * @brief Get the previous list element
     * 
     * @return list_element* 
     */
    list_element *get_prev() {return _prev;}

    /**
     * @brief Set the previous list element
     * 
     * @param n the new element of the list that will be insert before the current
     * element
     */
    void set_prev(list_element *n) {_prev = n;}

    /**
     * @brief Get the element value
     * 
     * @return double 
     */
    double get_value()const {return _value;}

    /**
     * @brief Set the element value
     * 
     * @param v the new double value
     */
    void set_value(double v) {_value = v;}
};

class values_list {
    list_element *_head;
    list_element *_tail;

public:
    values_list(): _head(nullptr), _tail(nullptr) {}
    values_list(const values_list &other);
    ~values_list() {clear();}
    values_list &operator=(const values_list &other);

    void clear();
    void push_back(double v); // Always add at the end
    void pop_element(); // Remove last element
    size_t size()const;
    double get_value(size_t position)const;

    void sort_list(bool ascending);
};

class data_list {
    values_list _values;
public:
    data_list();
    data_list(const data_list &other);
    ~data_list() {_values.clear();}

    // Input methods
    void from_text(const std::string &source);
    void from_binary(const std::string &source);

    // Output methods
    void to_text(const std::string &destination);
    void to_binary(const std::string &destination);
    void print_data()const;

    // Computation (return new instances of data_table)
    data_list moving_average(size_t window_width);
    data_list sort_table(bool ascending=true);
    data_list average(); // returns a data_table with only one value
    data_list table_sum(); // returns a data_table with only one value
    data_list table_count(); // returns a data_table with only one value
};

#endif // DATA_LIST_H
