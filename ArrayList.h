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
    void insert(int data, int index);  
    void insert_back(int data);        
    void remove_front();
    void remove(int index);
    void remove_end();
    int search(int data);              
    void print();                       
    int get_size();

};

