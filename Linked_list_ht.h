#pragma once
#include <iostream>
#include "Node.h"

using namespace std;

class Linked_list_ht {

private:
    Node* head;
    Node* tail;
    int size;

public:
    Linked_list_ht() : head(nullptr), tail(nullptr), size(0) {};
    ~Linked_list_ht() {};

    void Add_First(int value);
    void Add_End(int value);
    void Remove_First();
    void Remove_End();
    void Look_For(int value);
    void Add_Random(int value, int id);
    void Remove_Random(int id);
    void Show();
    int Size_of_list()const;

};

