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

    /* SHOULD BE REMOVED: NO DATA-DEPENDENT IMPLEMENTATIONS */
    DoubleLinkedList(const long& id, const int &order, const std::string &value);

    DoubleLinkedList(const DoubleLinkedList &list);
    DoubleLinkedList(DoubleLinkedList &&list);

    unsigned long length() const;
    Data* get_value(const unsigned &n) const;

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
    void reset();
    void add_first(Data * const data);

};

} // DLL

#endif // DOUBLELINKEDLIST_HH
