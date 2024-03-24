#pragma once
#include <iostream>
using namespace std;
class ArrayList 
{
private:
    int* arr;
    int size;
    int end;

public:
    ArrayList();
    ~ArrayList();

    void insert_front(int data);
    void insert(int index, int data);
    void insert_back(int data);
    void remove(int index);
    int search(int data);
    void print();
};

