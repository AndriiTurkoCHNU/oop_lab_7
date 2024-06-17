#include <iostream>
#include "LinkedList.h"
#include "DoubleLinkedList.h"


using namespace std;


int main() {
    // Create a linked list
    LinkedList<int> list;
    cout << "Is list empty? " << (list.isEmpty() ? "yes" : "no") << endl;
    cout << "Size of list: " << list.size() << endl;
    cout << "Add 1 to list" << endl;
    list.push_back(1);
    cout << "Is list empty? " << (list.isEmpty() ? "yes" : "no") << endl;
    cout << "Size of list: " << list.size() << endl;
    cout << "List: " << list << endl;
    cout << "Add 2 to list front" << endl;
    list.push_front(2);
    cout << "Size of list: " << list.size() << endl;
    cout << "List: " << list << endl;
    cout << "Add 3 to list on index 1" << endl;
    list.insert(1, 3);
    cout << "Size of list: " << list.size() << endl;
    cout << "List: " << list << endl;
    cout << "Get element on index 2: " << list.get(2) << endl;
    cout << "List: " << list << endl;
    cout << "Remove element on index 1" << endl;
    list.remove(1);
    cout << "List: " << list << endl;
    cout << "Pop front" << endl;
    list.pop_front();
    cout << "List: " << list << endl;
    cout << "Pop back" << endl;
    list.pop_back();
    cout << "List: " << list << endl;
    cout << "Add 1 to list" << endl;
    list.push_back(1);
    cout << "Add 2 to list" << endl;
    list.push_back(2);
    cout << "Add 3 to list" << endl;
    list.push_back(3);
    cout << "List: " << list << endl;
    cout << "Find 2 in list: " << list.find(2) << endl;
    cout << "Find 4 in list: " << list.find(4) << endl;

    cout << endl;

    // Create a double linked list
    DoubleLinkedList<int> doubleList;
    cout << "Is doubleList empty? " << (doubleList.isEmpty() ? "yes" : "no") << endl;
    cout << "Size of doubleList: " << doubleList.size() << endl;
    cout << "Add 1 to doubleList" << endl;
    doubleList.push_back(1);
    cout << "Is doubleList empty? " << (doubleList.isEmpty() ? "yes" : "no") << endl;
    cout << "Size of doubleList: " << doubleList.size() << endl;
    cout << "doubleList: " << doubleList << endl;
    cout << "Add 2 to doubleList front" << endl;
    doubleList.push_front(2);
    cout << "Size of doubleList: " << doubleList.size() << endl;
    cout << "doubleList: " << doubleList << endl;
    cout << "Add 3 to doubleList on index 1" << endl;
    doubleList.insert(1, 3);
    cout << "Size of doubleList: " << doubleList.size() << endl;
    cout << "doubleList: " << doubleList << endl;
    cout << "Get element on index 2: " << doubleList.get(2) << endl;
    cout << "doubleList: " << doubleList << endl;
    cout << "Remove element on index 1" << endl;
    doubleList.remove(1);
    cout << "doubleList: " << doubleList << endl;
    cout << "Pop front" << endl;
    doubleList.pop_front();
    cout << "doubleList: " << doubleList << endl;
    cout << "Pop back" << endl;
    doubleList.pop_back();
    cout << "doubleList: " << doubleList << endl;
    cout << "Add 1 to doubleList" << endl;
    doubleList.push_back(1);
    cout << "Add 2 to doubleList" << endl;
    doubleList.push_back(2);
    cout << "Add 3 to doubleList" << endl;
    doubleList.push_back(3);
    cout << "doubleList: " << doubleList << endl;
    cout << "Find 2 in doubleList: " << doubleList.find(2) << endl;
    cout << "Find 4 in doubleList: " << doubleList.find(4) << endl;



    return 0;
}