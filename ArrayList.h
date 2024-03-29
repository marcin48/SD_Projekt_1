#pragma once
#include <iostream>
#include "Struktura.h"
using namespace std;

class ArrayList : public Struktura
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
    void remove_back();
    int search(int data);     
    void load_file();
    void print();                       
    int get_size();

};

