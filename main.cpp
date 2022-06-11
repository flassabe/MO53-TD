#include <iostream>
#include "data_table.h"
#include "data_list.h"

using namespace std;

int main() {
    data_list t;
    t.from_binary("binary.bin");
    cout << "t:" << endl;
    t.print_data();
    //auto t2 = t.sort_table(false);
    auto t2 = t.moving_average(2);
    cout << "t2:" << endl;
    t2.print_data();
    return 0;
}

/*int main() {
    resource_manager mgr{};
    // Next line can be parameterized
    process p{mgr.make_storage(LIST),
              mgr.make_reader(BIN),
              mgr.make_calculation(AVG),
              mgr.make_writer(TEXT)};
    p.execute();
    mgr.clear_resources();
    return 0;
}*/
