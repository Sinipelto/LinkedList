#include "doublelinkedlist.hh"

namespace DLL {

DoubleLinkedList::DoubleLinkedList()
{
    reset();
}

DoubleLinkedList::DoubleLinkedList(Data* const data) : DoubleLinkedList()
{
    add_first(data);
}

DoubleLinkedList::DoubleLinkedList(const Data &data) : DoubleLinkedList(new Data (data)) {}

DoubleLinkedList::DoubleLinkedList(const long &id, const int &order, const std::string &value) : DoubleLinkedList(new Data {id, order, value}) {}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &list) : DoubleLinkedList()
{
    if (list._count <= 0) return;

    auto ptr = list._first;

    do {
        // Copy Data attributes to new Data object
        add_value(new Data (*ptr->data));
        ptr = ptr->next;
    } while (ptr != nullptr);
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList &&list) : DoubleLinkedList()
{
    if (list.length() <= 0) return;

    while (list.length() > 0) {
        Data *item = list.pop_first();
        add_value(item);
    }
}

unsigned long DoubleLinkedList::length() const
{
    return _count;
}

Data *DoubleLinkedList::get_value(const unsigned &n) const
{
    if (_count <= 0) return nullptr;
    if (n > _count) return nullptr;

    Node* ptr = _first;

    for (unsigned i = 1; i < n; i++) {
        ptr = ptr->next;
    }

    return ptr->data;
}

void DoubleLinkedList::add_value(Data* const data)
{
    if (_count <= 0) {
        add_first(data);
        return;
    }

    _last->next = new Node {nullptr, _last, data};
    _last = _last->next;
    _count++;
}

void DoubleLinkedList::add_value(const Data &data)
{
    Data* dta = new Data {data.id, data.order, data.value};
    add_value(dta);
}

void DoubleLinkedList::add_value(const long &id, const int &order, const std::string &value)
{
    Data* dta = new Data {id, order, value};
    add_value(dta);
}

Data *DoubleLinkedList::pop_first()
{
    return pop_nth(1);
}

Data *DoubleLinkedList::pop_last()
{
    return pop_nth(_count);
}

Data *DoubleLinkedList::pop_nth(const unsigned &n)
{
    if (!check_n(n)) return nullptr;

    Data *data;
    auto ptr = _first;

    for (unsigned i = 1; i < n; i++) {
        ptr = ptr->next;
    }

    if (_first == _last) {
        data = _first->data;
        delete _first;
        reset();
        return data;
    }
    else if (ptr == _first) {
        ptr->next->prev = nullptr;
        _first = ptr->next;
        data = ptr->data;
        delete ptr;
    }
    else if (ptr == _last) {
        ptr->prev->next = nullptr;
        _last = ptr->prev;
        data = ptr->data;
        delete ptr;
    }
    else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        data = ptr->data;
        delete ptr;
    }

    _count--;

    return data;
}

bool DoubleLinkedList::check_n(const unsigned &n)
{
    if (_count <= 0 || n > _count) return false;
    return true;
}

void DoubleLinkedList::reset()
{
    _first = nullptr;
    _last = nullptr;
    _count = 0;
}

void DoubleLinkedList::add_first(Data * const data)
{
    Node* n = new Node {nullptr, nullptr, data};

    this->_first = n;
    this->_last = n;

    _count = 1;
}

} // DLL
