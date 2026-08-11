#pragma once
#include <stdexcept>

namespace linked_list {

template <typename T>
class List {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;
        Node(T val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        while (head) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    // Add to end
    void push(T value) {
        Node* node = new Node(value);
        if (!tail) {
            head = tail = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
        size++;
    }

    // Remove from end
    T pop() {
        if (!tail) throw std::out_of_range("List is empty");
        T val = tail->value;
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete tmp;
        size--;
        return val;
    }

    // Add to front
    void unshift(T value) {
        Node* node = new Node(value);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        size++;
    }

    // Remove from front
    T shift() {
        if (!head) throw std::out_of_range("List is empty");
        T val = head->value;
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
        size--;
        return val;
    }

    // Remove first occurrence of value
    bool erase(T value) {
        Node* curr = head;
        while (curr) {
            if (curr->value == value) {
                if (curr->prev) curr->prev->next = curr->next;
                else head = curr->next;

                if (curr->next) curr->next->prev = curr->prev;
                else tail = curr->prev;

                delete curr;
                size--;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    int count() const { return size; }
};

}  // namespace linked_list