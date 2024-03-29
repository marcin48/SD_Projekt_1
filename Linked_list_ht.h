#pragma once
#include <iostream>
#include "Node.h"
#include "Struktura.h"

using namespace std;

class Linked_list_ht : public Struktura {

private:
    Node* head;
    Node* tail;
    int size;

public:
    Linked_list_ht() : head(nullptr), tail(nullptr), size(0) {};
    ~Linked_list_ht() {};

    void insert_front(int value);
    void insert_back(int value);
    void remove_front();
    void remove_back();
    int search(int value);
    void insert(int value, int id);
    void remove(int id);
    void print();
    int Size_of_list()const;

};

