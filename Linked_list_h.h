#pragma once
#include<iostream>
#include "Node.h"
using namespace std;


class Linked_list_h {

private:
    Node* head;
    int size;

public:
    Linked_list_h() : head(nullptr), size(0) {};
    ~Linked_list_h() {};

    void Add_First(int value);
    void Add_End(int value);
    void Remove_First();
    void Remove_End();
    void Add_Random(int value, int id);
    void Remove_Random(int id);
    void Look_For(int value);
    void Show();
    int Size_of_list()const;

};


