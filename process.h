#ifndef PROCESS_H
#define PROCESS_H

#include "storage_type.h"

class process { // raw pointers may be improved
    storage_type *_storage;
    loader *_loader;
    calculation *_calc;
    writer *_writer;

public:
    process(storage_type *stor, loader *load, calculation *calc, writer *write);
    void execute();
};

#endif // PROCESS_H
