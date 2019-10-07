#include "doublelinkedlist.hh"
#include <iostream>

#include <vector>

using namespace std;
using namespace DLL;


int main()
{
    DoubleLinkedList list(0, 1, "first_value");
    DoubleLinkedList list2(new Data{-5, -3, "test_2"});

    DoubleLinkedList list_x(Data {0, 0, "null"});

    for (int i = 1; i < 8; i++) {
        list.add_value(new Data {i, i+1, "test_data"});
    }

    for (int i = 0; i < 5; i++) {
        list2.add_value(new Data {99+i, 100+i, "otherdata"});
    }

    auto unit = Data {99, 90, "last_data"};
    list.add_value(unit);

    auto val = list.get_value(5); // list item 5
    auto val2 = list.get_value(99); // nullptr

    cout << val << " " << val2 << endl;

    cout << "{" << val->id << " " << val->order << " " << val->value << "}" << endl;

    for (int i = 0; i < 1000; i++) {
        auto v = list.pop_nth(1);
        //cout << i << " " << v->id << endl;
    }
    auto x = list.pop_nth(3);
    auto y = list.pop_first();

    auto list3 = list2; // call copy constructor
    auto list4 = DoubleLinkedList(std::move(list3)); // call move constructor

    cout << list2.pop_nth(1) << " VS " << list4.pop_nth(3) << endl;


    cout << "RETURN" << endl;

    return 0;
}
