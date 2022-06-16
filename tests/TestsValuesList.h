//
// Created by axels on 13/06/2022.
//

#include "../headers/ValuesList.h"

bool testValuesListSizeEmpty() {
    ValuesList valuesList;
    return valuesList.size() == 0;
}

bool testValuesListSize() {
    ValuesList valuesList;
    valuesList.pushBack(0);
    return valuesList.size() == 1;
}

bool testValuesListPop() {
    ValuesList valuesList;
    valuesList.pushBack(5);
    valuesList.pushBack(3);
    valuesList.popElement();
    return valuesList.size() == 1;
}

bool testValuesListGet() {
    ValuesList valuesList;
    valuesList.pushBack(5);
    return valuesList.getValue(0) == 5;
}

bool testValuesListClear() {
    ValuesList valuesList;

    for(int i = 0; i < 5; i++)
        valuesList.pushBack(i);

    valuesList.clear();
    return valuesList.size() == 0;
}
