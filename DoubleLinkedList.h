#ifndef OOP_LAB_7_DOUBLELINKEDLIST_H
#define OOP_LAB_7_DOUBLELINKEDLIST_H

#include <stdexcept>
#include "Node.h"

template<typename T>
class DoubleLinkedList {
private:
    shared_ptr<Node<T>> head;
public:
    DoubleLinkedList() : head(nullptr) {}

    void push_front(T data) {
        auto newNode = make_shared<Node<T>>();
        newNode->data = data;
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void push_back(T data) {
        auto newNode = make_shared<Node<T>>();
        newNode->data = data;
        if (!head) {
            head = newNode;
        } else {
            auto temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            newNode->prev = temp;
            temp->next = newNode;
        }
    }

    void pop_front() {
        if (head) {
            head = head->next;
            if (head) {
                head->prev.reset();
            }
        }
    }

    void pop_back() {
        if (head) {
            auto temp = head;
            while (temp->next && temp->next->next) {
                temp = temp->next;
            }
            if (temp->next) {
                temp->next = nullptr;
            } else {
                head = nullptr;
            }
        }
    }

    T get(int index) {
        auto temp = head;
        for (int i = 0; i < index; i++) {
            if (!temp)
                throw out_of_range("Index out of range");
            temp = temp->next;
        }
        if (!temp)
            throw out_of_range("Index out of range");
        return temp->data;
    }

    void insert(int index, T data) {
        if (index == 0) {
            push_front(data);
        } else {
            auto newNode = make_shared<Node<T>>();
            newNode->data = data;
            auto temp = head;
            for (int i = 0; i < index - 1; i++) {
                if (!temp)
                    throw out_of_range("Index out of range");
                temp = temp->next;
            }
            if (!temp)
                throw out_of_range("Index out of range");
            newNode->next = temp->next;
            if (newNode->next) {
                newNode->next->prev = newNode;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void remove(int index) {
        if (index == 0) {
            pop_front();
        } else {
            auto temp = head;
            for (int i = 0; i < index; i++) {
                if (!temp)
                    throw out_of_range("Index out of range");
                temp = temp->next;
            }
            if (!temp)
                throw out_of_range("Index out of range");
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            if (temp->prev.lock()) {
                temp->prev.lock()->next = temp->next;
            }
        }
    }

    int size() {
        int size = 0;
        auto temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int find(T data) {
        auto temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == data) {
                return index;
            }
            index++;
            temp = temp->next;
        }
        return -1;
    }

    friend ostream& operator<<(ostream& os, const DoubleLinkedList<T>& list) {
        auto temp = list.head;
        while (temp) {
            os << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }
};

#endif //OOP_LAB_7_DOUBLELINKEDLIST_H
