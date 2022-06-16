#ifndef DATA_LIST_H
#define DATA_LIST_H


#include <vector>
#include <string>
#include "Iterator.h"
#include "ListElement.h"
#include "ValuesList.h"

class DataList {
    ValuesList _values;
public:
    DataList();
    DataList(const DataList &other);
    ~DataList() {_values.clear();}

    // Input methods
    void fromText(const std::string &source);
    void fromBinary(const std::string &source);

    // Output methods
    void toText(const std::string &destination);
    void toBinary(const std::string &destination);
    void printData();

    // Computation (return new instances of DataTable)
    DataList movingAverage(size_t window_width);
    DataList sortTable(bool ascending=true);
    DataList average(); // returns a DataTable with only one value
    DataList tableSum(); // returns a DataTable with only one value
    DataList tableCount(); // returns a DataTable with only one value

    // Iterator
    Iterator begin() { return _values.begin(); }
    Iterator end() { return _values.end(); }

    // Operator []
    ListElement &operator[](int i) { return _values[i]; }

};

#endif // DATA_LIST_H
