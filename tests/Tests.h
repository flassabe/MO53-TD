//
// Created by axels on 13/06/2022.
//

#ifndef MO53_REFRACTO_TESTS_H
#define MO53_REFRACTO_TESTS_H

// This check function would be provided by the test framework
#include "TestsValuesList.h"

#define IS_TRUE(x) { if (!(x)) std::cout << __FUNCTION__ << " failed on line " << __LINE__ << std::endl; }

class Tests {

public:
    void testsValuesList() {
        IS_TRUE(testValuesListSizeEmpty());
        IS_TRUE(testValuesListSize());
        IS_TRUE(testValuesListPop());
        IS_TRUE(testValuesListGet());
        IS_TRUE(testValuesListClear());
    }

    void run() {
        testsValuesList();
    }
};

#endif //MO53_REFRACTO_TESTS_H
