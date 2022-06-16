#include "storage_type.h"
#include "loader.h"
#include "writer.h"
#include "calculation.h"

class factory
{
    public:
    factory();
    ~factory();
    storage_type* storage_type_factory();
    loader* loader_factory();
    writer* writer_factory();
    calculation* calculation_factory();

};