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

/**
 * @class values_list 
 * @brief Provide all services to manage a chained list of list_element
 * 
 */
class values_list {
    /**
     * @brief the first current element of the list
     * 
     */
    list_element *_head;

    /**
     * @brief the last current element of the list
     * 
     */
    list_element *_tail;

public:
    /**
     * @brief Construct a new values list object
     * 
     */
    values_list(): _head(nullptr), _tail(nullptr) {}

    /**
     * @brief Copy construct of values list
     * 
     * @param other the list that will be copied
     */
    values_list(const values_list &other);

    /**
     * @brief Destroy the values list object
     * 
     */
    ~values_list() {clear();}

    /**
     * @brief Overload assignment operator : the current list will
     * replace its elements by new elements with same values as the list passed in parameter.
     * 
     * @param other the reference list
     * @return values_list& the current list
     */
    values_list &operator=(const values_list &other);

    /**
     * @brief Remove all elements from the list
     * 
     */
    void clear();

    /**
     * @brief Add new element at the end of the list with the value passed in parameter
     * 
     * @param v the value of the new element
     */
    void push_back(double v);

    /**
     * @brief Remove the head of the list
     * 
     */
    void pop_element();

    /**
     * @brief Get current list size
     * 
     * @return size_t 
     */
    size_t size()const;

    /**
     * @brief Get the double value at position
     * 
     * @param position 
     * @return double 
     */
    double get_value(size_t position)const;

    /**
     * @brief Sort the list depending on the parameter value.
     * If parameter is <code>true</code> : ascending
     * If parameter is <code>false</code> : descending
     * 
     * @param ascending the sort direction
     */
    void sort_list(bool ascending);

    struct data_list_iterator {
        private:
            list_element *element;

        public:
            data_list_iterator(list_element *element);
            list_element* getElement(){return this->element;};
            data_list_iterator& operator++();
            data_list_iterator& operator++(int);
            friend bool operator!=(const data_list_iterator& itr1,const data_list_iterator& itr2){return (itr1.element != itr2.element);};
    };

    data_list_iterator begin();
    data_list_iterator end();
};

/**
 * @brief Provide operations and calculations for entries data based on values_list
 * 
 */
class data_list {
    /**
     * @brief values list in which the data will be stored
     * 
     */
    values_list _values;
public:
    /**
     * @brief Construct a new data list object
     * 
     */
    data_list();
    
    /**
     * @brief Copy construct of data list
     * 
     * @param other the data list that will be copied
     */
    data_list(const data_list &other);
    
    /**
     * @brief Destroy the data list object
     * 
     */
    ~data_list() {_values.clear();}

    // Input methods
    /**
     * @brief Replace current data by text file values
     * 
     * @param source text file name
     */
    void from_text(const std::string &source);
    
    /**
     * @brief Replace current data by binary file values
     * 
     * @param source binary file name
     */
    void from_binary(const std::string &source);

    // Output methods
    /**
     * @brief Write all the data into given text file
     * 
     * @param destination text file name
     */
    void to_text(const std::string &destination);
    
    /**
     * @brief Write all the data into given binary file
     * 
     * @param destination text file name
     */
    void to_binary(const std::string &destination);
    
    /**
     * @brief Display data of the list into the standard output
     * 
     */
    void print_data()const;

    // Computation (return new instances of data_table)
    /**
     * @brief Calculate a series of averages of different subsets of the full data set. The size of these subsets
     * are defined by the parameter. Each time a calculation is done, the oldest data of the current substet will 
     * be remplace by the next value in the set.
     * 
     * @param window_width the size of data substets
     * @return data_list new data list with all calculated averages
     */
    data_list moving_average(size_t window_width);
    
    /**
     * @brief Sort the data depending on the parameter value.
     * If parameter is <code>true</code> : ascending
     * If parameter is <code>false</code> : descending
     * 
     * @param ascending the sort direction, default ascending
     * @return data_list new sorted data list
     */
    data_list sort_table(bool ascending=true);
    
    /**
     * @brief Calculate the average of all data
     * 
     * @return data_list with only one value : the calculation result
     */
    data_list average();
    
    /**
     * @brief Calculate the sum of all data
     * 
     * @return data_list with only one value : the calculation result
     */
    data_list table_sum();
    
    /**
     * @brief Count the number of data
     * 
     * @return data_list with only one value : the count result
     */
    data_list table_count();
};

#endif // DATA_LIST_H
