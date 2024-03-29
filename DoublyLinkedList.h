#pragma once
#include <iostream>
#include "Node.h"
#include "Struktura.h"
using namespace std;


class DoublyLinkedList : public Struktura {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert_front(int data);
    void insert(int data, int index);
    void insert_back(int data);
    void remove_front();
    void remove(int index);
    void remove_back();
    int search(int data);
    void print();
};

