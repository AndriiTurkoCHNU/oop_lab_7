#ifndef OOP_LAB_7_LINKEDLIST_H
#define OOP_LAB_7_LINKEDLIST_H

#include <stdexcept>
#include "Node.h"


template<typename T>
class LinkedList {
private:
    shared_ptr<Node<T>> head;
public:
    LinkedList() : head(nullptr) {}

    void push_front(T data) {
        auto newNode = make_shared<Node<T>>();
        newNode->data = data;
        newNode->next = head;
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
            temp->next = newNode;
        }
    }

    void pop_front() {
        if (head) {
            head = head->next;
        }
    }

    void pop_back() {
        if (head) {
            if (!head->next) {
                head = nullptr;
            } else {
                auto temp = head;
                while (temp->next->next) {
                    temp = temp->next;
                }
                temp->next = nullptr;
            }
        }
    }

    T get(int index) {
        auto temp = head;
        for (int i = 0; i < index; i++) {
            if (!temp) throw out_of_range("Index out of range");
            temp = temp->next;
        }
        if (!temp) throw out_of_range("Index out of range");
        return temp->data;
    }

    void insert(int index, T data) {
        auto newNode = make_shared<Node<T>>();
        newNode->data = data;
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            auto temp = head;
            for (int i = 0; i < index - 1; i++) {
                if (!temp)
                    throw out_of_range("Index out of range");
                temp = temp->next;
            }
            if (!temp)
                throw out_of_range("Index out of range");
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void remove(int index) {
        if (index == 0) {
            if (head) {
                head = head->next;
            }
        } else {
            auto temp = head;
            for (int i = 0; i < index - 1; i++) {
                if (!temp)
                    throw out_of_range("Index out of range");
                temp = temp->next;
            }
            if (!temp || !temp->next)
                throw out_of_range("Index out of range");
            temp->next = temp->next->next;
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

    friend ostream& operator<<(ostream& os, const LinkedList<T>& list) {
        auto temp = list.head;
        while (temp) {
            os << temp->data << " ";
            temp = temp->next;
        }
        return os;
    }
};

#endif //OOP_LAB_7_LINKEDLIST_H
