#include "doublelinkedlist.hh"

namespace DLL {

DoubleLinkedList::DoubleLinkedList()
{
    _first = nullptr;
    _last = nullptr;
    _count = 0;
}

DoubleLinkedList::DoubleLinkedList(Data* const data) : DoubleLinkedList()
{
    Node* n = new Node {nullptr, nullptr, data};

    this->_first = n;
    this->_last = n;

    _count = 1;
}

DoubleLinkedList::DoubleLinkedList(const Data &data) : DoubleLinkedList(new Data {data.id, data.order, data.value}) {}

DoubleLinkedList::DoubleLinkedList(const long &id, const int &order, const std::string &value) : DoubleLinkedList(new Data {id, order, value}) {}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList &&list) : DoubleLinkedList()
{
    if (list._count <= 0) return;

    auto ptr = list._first;

    do {
        add_value(ptr->data);
        ptr = ptr->next;
    } while (ptr != nullptr);
}

unsigned long DoubleLinkedList::length()
{
    return _count;
}

Data *DoubleLinkedList::get_value(const unsigned &n)
{
    if (_count <= 0) return nullptr;
    if (n > _count) return nullptr;

    Node* ptr = _first;

    for (unsigned i = 0; i < n; i++) {
        ptr = ptr->next;
    }

    return ptr->data;
}

void DoubleLinkedList::add_value(Data* const data)
{
    if (_count <= 0) {
        (DoubleLinkedList(data));
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

    if (_count == 1) {
        auto data = _first->data;
        _first = _last = nullptr;
        return data;
    }

    auto ptr = _first;

    for (unsigned i = 1; i < n; i++) {
        ptr = ptr->next;
    }

    if (ptr == _last) {
        ptr->prev->next = nullptr;
        _last = ptr->prev;
    }
    else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
    }

    _count--;

    return ptr->data;
}

bool DoubleLinkedList::check_n(const unsigned &n)
{
    if (_count <= 0 || n > _count) return false;
    return true;
}

} // NAMESPACE
