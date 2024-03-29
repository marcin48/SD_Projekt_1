#pragma once
#include<iostream>
#include "Node.h"
#include "Struktura.h"
using namespace std;


class Linked_list_h : public Struktura {

private:
    Node* head;
    int size;

public:
    Linked_list_h() : head(nullptr), size(0) {};
    ~Linked_list_h() {};

    void insert_front(int value);
    void insert_back(int value);
    void remove_front();
    void remove_back();
    void insert(int value, int id);
    void remove(int id);
    int search(int value);
    void print();
    int Size_of_list()const;

};


