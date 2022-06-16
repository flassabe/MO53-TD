#include "factory.h"

using namespace std;

factory::factory()
{
}
factory::~factory()
{
}
calculation* :: calculation_factory()
{
 return new calculation();
}
storage_type* :: storage_type_factory()
{
    return new storage_type();
}
loader* :: loader_factory()
{
    return new loader();
}
writer* :: writer_factory()
{
    return new writer();
}
