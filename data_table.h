/**
 *
 * @file data_table.h
 * @author antoine richard
 * @date 2022-06-10
 * @brief Contains data_table class that provides operations and calulations on entries based on vector
 * 
 */

//
// Define guards
#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <vector>
#include <string>

/**
 * @brief Provide operations and calculations for entries data based on vector
 * 
 */
class data_table {
    std::vector<double> _table;

public:
    /**
     * @brief Construct a new data table object
     * 
     */
    data_table();
    
    /**
     * @brief Destroy the data table object
     * 
     */
    ~data_table() {}

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
     * @brief Display data of the table into the standard output
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
     * @return data_table new data table with all calculated averages
     */
    data_table moving_average(size_t window_width);
    
    /**
     * @brief Sort the data depending on the parameter value.
     * If parameter is <code>true</code> : ascending
     * If parameter is <code>false</code> : descending
     * 
     * @param ascending the sort direction, default ascending
     * @return data_table new sorted data table
     */
    data_table sort_table(bool ascending=true);
    
    /**
     * @brief Calculate the average of all data
     * 
     * @return data_table with only one value : the calculation result
     */
    data_table average();
    
    /**
     * @brief Calculate the sum of all data
     * 
     * @return data_table with only one value : the calculation result
     */
    data_table table_sum();
    
    /**
     * @brief Count the number of data
     * 
     * @return data_table with only one value : the count result
     */
    data_table table_count();
};

#endif // DATA_TABLE_H
