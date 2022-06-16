#ifndef DATA_TABLE_H
#define DATA_TABLE_H

#include <vector>
#include <string>

class DataTable {
    std::vector<double> _table;

public:
    DataTable();
    ~DataTable() {}

    // Input methods
    void fromText(const std::string &source);
    void fromBinary(const std::string &source);

    // Output methods
    void toText(const std::string &destination);
    void toBinary(const std::string &destination);
    void printData()const;

    // Computation (return new instances of DataTable)
    DataTable movingAverage(size_t window_width);
    DataTable sortTable(bool ascending=true);
    DataTable average(); // returns a DataTable with only one value
    DataTable tableSum(); // returns a DataTable with only one value
    DataTable tableCount(); // returns a DataTable with only one value
};

#endif // DATA_TABLE_H
