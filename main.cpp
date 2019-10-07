#include "doublelinkedlist.hh"
#include <iostream>

#include <vector>

using namespace std;
using namespace DLL;


int main()
{
    DoubleLinkedList list(0, 1, "first_value");
    DoubleLinkedList list2(new Data{});

    for (int i = 1; i < 8; i++) {
        list.add_value(new Data {i, i+1, "test_data"});
    }

    auto unit = Data {99, 90, "last_data"};
    list.add_value(unit);

    auto val = list.get_value(5); // list item 5
    auto val2 = list.get_value(99); // nullptr

    cout << val << " " << val2 << endl;

    cout << "{" << val->id << " " << val->order << " " << val->value << "}" << endl;

    for (int i = 0; i < 1000; i++) {
        auto v = list.pop_nth(3);
        cout << i << " " << v->id << endl;
    }

    return 0;
}
