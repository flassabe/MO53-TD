cmake_minimum_required(VERSION 3.19)
project(MO53_Refracto)

set(CMAKE_CXX_STANDARD 17)

add_executable(MO53_Refracto
        src/main.cpp
        src/DataList.cpp
        headers/DataList.h
        headers/DataTable.h
        src/DataTable.cpp
        headers/StorageType.h
        headers/Iterator.h
        headers/ListElement.h
        src/ValuesList.cpp
        headers/ValuesList.h
        tests/Tests.h tests/TestsValuesList.h)
