// simple_linked_list.cpp
#include "simple_linked_list.h"
#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    Element* node = new Element{entry};
    node->next = head;
    head = node;
    ++current_size;
}

int List::pop() {
    if (head == nullptr)
        throw std::out_of_range("list is empty");
    Element* old_head = head;
    int value = old_head->data;
    head = old_head->next;
    delete old_head;
    --current_size;
    return value;
}

void List::reverse() {
    Element* prev = nullptr;
    Element* curr = head;
    while (curr != nullptr) {
        Element* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

List::~List() {
    while (head != nullptr) {
        Element* temp = head;
        head = head->next;
        delete temp;
    }
}

} // namespace simple_linked_list