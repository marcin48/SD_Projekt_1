#pragma once
#include <iostream>
#include "Node.h"
using namespace std;


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert_front(int data);
    void insert(int data, int index);
    void insert_end(int data);
    void remove_front();
    void remove(int index);
    void remove_end();
    int search(int data);
    void print();
};

