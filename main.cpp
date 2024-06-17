#include <iostream>
#include "lab_8.h"


using namespace std;


int main() {
    cout << "Linked list:" << endl;

    // create a queue using a linked list
    LinkedListQueue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    cout << "Peek: " << queue.peek() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Dequeue: " << queue.dequeue() << endl;
    cout << "Is empty: " << (queue.isEmpty() ? "yes" : "no") << endl;
//    cout << queue.dequeue() << endl; // Index out of range
//    cout << "Peek: " << queue.peek() << endl; // Index out of range

    cout << "====================" << endl;
    cout << "Queue using array:" << endl;

    // create a queue using an array
    Queue<int> queue2(2);
    queue2.enqueue(1);
    queue2.enqueue(2);
    queue2.peek();
//    queue2.enqueue(3); // Queue is full
    cout << "Dequeue: " << queue2.dequeue() << endl;
    cout << "Dequeue: " << queue2.dequeue() << endl;
    cout << "Is empty: " << (queue2.isEmpty() ? "yes" : "no") << endl;
//    cout << queue2.dequeue() << endl; // Index out of range
//    cout << "Peek: " << queue2.peek() << endl; // Index out of range

    cout << "====================" << endl;
    cout << "Circular queue:" << endl;

    // create a circular queue
    CircularQueue<int> queue3;
    queue3.enqueue(1);
    queue3.enqueue(2);
    cout << "Peek: " << queue3.peek() << endl;
    cout << "Dequeue: " << queue3.dequeue() << endl;
    cout << "Is empty: " << (queue3.isEmpty() ? "yes" : "no") << endl;
    cout << "Dequeue: " << queue3.dequeue() << endl;
    cout << "Is empty: " << (queue3.isEmpty() ? "yes" : "no") << endl;
//    cout << queue3.dequeue() << endl; // Index out of range
//    cout << "Peek: " << queue3.peek() << endl; // Index out of range

    cout << "====================" << endl;
    cout << "Stack using array:" << endl;

    // create a stack using an array
    Stack<int> stack(2);
    stack.push(3);
    stack.push(2);
//    stack.push(1); // Stack is full
    cout << "Peek: " << stack.peek() << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Is empty: " << (stack.isEmpty() ? "yes" : "no") << endl;
    cout << "Pop: " << stack.pop() << endl;
    cout << "Is empty: " << (stack.isEmpty() ? "yes" : "no") << endl;
//    cout << stack.pop() << endl; // Stack is empty
//    cout << stack.peek() << endl; // Stack is empty

    cout << "====================" << endl;
    cout << "Stack using linked list:" << endl;

    // create a stack using a linked list
    LinkedListStack<int> stack2;
    stack2.push(5);
    stack2.push(6);
    cout << "Peek: " << stack2.peek() << endl;
    cout << "Pop: " << stack2.pop() << endl;
    cout << "Is empty: " << (stack2.isEmpty() ? "yes" : "no") << endl;
    cout << "Pop: " << stack2.pop() << endl;
    cout << "Is empty: " << (stack2.isEmpty() ? "yes" : "no") << endl;
//    cout << stack2.pop() << endl; // Stack is empty

    return 0;
}