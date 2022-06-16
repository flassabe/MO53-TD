#include "../headers/DataList.h"
#include <fstream>
#include <exception>
#include <array>
#include <iostream>
#include <algorithm>

using namespace std;
/*Constructor of DataList*/
DataList::DataList() {
}
/*Constructor of DataList with parameter*/
DataList::DataList(const DataList &other) {
    _values = other._values;
}

void DataList::fromText(const std::string &source) {
    _values.clear();
    ifstream f{source};
    if (f.is_open()) {
        array<char, 100> buffer;
        while (f.getline(&buffer[0], 100)) {
            _values.pushBack(stold(string{buffer.data()}));
        }
    } else {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}
/*Read data from binary file*/
void DataList::fromBinary(const std::string &source) {
    _values.clear();
    ifstream f{source, std::ios::binary};
    if (f.is_open()) {
        double buffer;
        while (f.read(reinterpret_cast<char *>(&buffer), sizeof(double))) {
            _values.pushBack(buffer);
        }
    } else  {
        throw ios_base::failure("File cannot be opened for reading.");
    }
}

void DataList::toText(const std::string &destination) {
    ofstream f{destination};
    if (f.is_open()) {
        for (size_t i=0; i<_values.size(); ++i) {
            f << _values.getValue(i) << endl;
        }
    }
}

void DataList::toBinary(const std::string &destination) {
    ofstream f{destination, std::ios::binary};
    if (f.is_open()) {
        for (size_t i=0; i<_values.size(); ++i) {
            double val = _values.getValue(i);
            f.write(reinterpret_cast<const char *>(&val), sizeof(double));
        }
    } else  {
        throw ios_base::failure("File cannot be opened for writing.");
    }
}

/*Function to print the data of a values list*/
void DataList::printData() {
    for(const ListElement& i : _values)
        cout << i.getValue() << endl;
}

DataList DataList::movingAverage(size_t window_width) {
    DataList result;
    if (window_width < _values.size()) {
        double current_sum = 0.0;
        for (size_t i=0; i<window_width; ++i) {
            current_sum += _values.getValue(i);
        }
        result._values.pushBack(current_sum / window_width);
        for (size_t i=0; i+window_width<_values.size(); ++i) {
            current_sum -= _values.getValue(i);
            current_sum += _values.getValue(i + window_width);
            result._values.pushBack(current_sum / window_width);
        }
    }
    return result;
}

/*This function is used to sort the table according to a boolean to choose the order*/
DataList DataList::sortTable(bool ascending) {
    DataList result{*this};
    result._values.sortList(ascending);
    return result;
}

/*This function is used to get a liste of average value.*/
DataList DataList::average() {
    DataList result;
    DataList sum_table = tableSum();
    result._values.pushBack(sum_table._values.getValue(0) / _values.size());
    return result;
}

DataList DataList::tableSum() {
    DataList result;
    double current_sum = 0.0;
    for (size_t i=0; i<_values.size(); ++i) {
        current_sum += _values.getValue(i);
    }
    result._values.pushBack(current_sum);
    return result;
}

DataList DataList::tableCount() {
    DataList result;
    result._values.pushBack(static_cast<double>(_values.size()));
    return result;
}


