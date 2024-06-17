#ifndef OOP_LAB_7_NODE_H
#define OOP_LAB_7_NODE_H

#include <memory>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    shared_ptr<Node<T>> next;
    // use for double-linked list
    weak_ptr<Node<T>> prev;
};

#endif //OOP_LAB_7_NODE_H
