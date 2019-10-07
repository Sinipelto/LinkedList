#ifndef DOUBLELINKEDLIST_HH
#define DOUBLELINKEDLIST_HH

#include <string>

namespace DLL {

struct Data {
    long id;
    int order;
    std::string value;
};

class DoubleLinkedList
{

public:
    DoubleLinkedList();
    DoubleLinkedList(Data * const data);
    DoubleLinkedList(const Data &data);
    DoubleLinkedList(const long& id, const int &order, const std::string &value);
    DoubleLinkedList(const DoubleLinkedList &&list);

    unsigned long length();
    Data* get_value(const unsigned &n);

    void add_value(Data * const data);
    void add_value(const Data &data);
    void add_value(const long &id, const int &order, const std::string &value);

    void combine(const DoubleLinkedList& list);

    Data* pop_first();
    Data* pop_last();
    Data* pop_nth(const unsigned &n);

private:
    struct Node {
        Node* next;
        Node* prev;
        Data* data;
    };

    Node* _first;
    Node* _last;

    unsigned long _count;

    bool check_n(const unsigned &n);

};

} // DLL

#endif // DOUBLELINKEDLIST_HH
