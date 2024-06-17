#ifndef OOP_LAB_8_H
#define OOP_LAB_8_H

#include <vector>
#include "LinkedList.h"

template<typename T>
class Queue {
private:
    vector<T> arr;
    int capacity;
    int front;
    int rear;
    int count;
public:
    Queue(int capacity) : capacity(capacity), front(0), rear(-1), count(0) {
        arr.resize(capacity);
    }

    void enqueue(T data) {
        if (isFull()) {
            throw out_of_range("Queue is full");
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        count++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        T data = arr[front];
        front = (front + 1) % capacity;
        count--;
        return data;
    }

    T peek() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return arr[front];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

template<typename T>
class LinkedListQueue {
private:
    LinkedList<T> list;
public:
    void enqueue(T data) {
        list.push_back(data);
    }

    T dequeue() {
        T data = list.get(0);
        list.pop_front();
        return data;
    }

    T peek() {
        return list.get(0);
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    bool isFull() {
        // Linked list can never be full until memory is available
        return false;
    }
};

template<typename T>
class CircularQueue {
private:
    LinkedList<T> list;
    int count;
public:
    CircularQueue() : count(0) {}

    void enqueue(T data) {
        list.push_back(data);
        count++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        T data = list.get(0);
        list.pop_front();
        count--;
        return data;
    }

    T peek() {
        if (isEmpty()) {
            throw out_of_range("Queue is empty");
        }
        return list.get(0);
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        // Linked list can never be full until memory is available
        return false;
    }
};

template<typename T>
class Stack {
private:
    vector<T> arr;
    int capacity;
public:
    Stack(int capacity) : capacity(capacity) {}

    void push(T data) {
        if (arr.size() < capacity) {
            arr.push_back(data);
        } else {
            throw out_of_range("Stack is full");
        }
    }

    T pop() {
        if (!arr.empty()) {
            T data = arr.back();
            arr.pop_back();
            return data;
        } else {
            throw out_of_range("Stack is empty");
        }
    }

    T peek() {
        if (!arr.empty()) {
            return arr.back();
        } else {
            throw out_of_range("Stack is empty");
        }
    }

    bool isEmpty() {
        return arr.empty();
    }

    bool isFull() {
        return arr.size() == capacity;
    }
};

template<typename T>
class LinkedListStack {
private:
    LinkedList<T> list;
public:
    void push(T data) {
        list.push_back(data);
    }

    T pop() {
        T data = list.get(list.size() - 1);
        list.pop_back();
        return data;
    }

    T peek() {
        return list.get(list.size() - 1);
    }

    bool isEmpty() {
        return list.isEmpty();
    }

    bool isFull() {
        // Linked list can never be full until memory is available
        return false;
    }
};

#endif //OOP_LAB_8_H
