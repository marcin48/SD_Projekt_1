#pragma once

class Struktura {
public:
    virtual void insert_front(int data) = 0;
    virtual void insert(int data, int index) = 0;
    virtual void insert_back(int data) = 0;
    virtual void remove_front() = 0;
    virtual void remove(int index) = 0;
    virtual void remove_back() = 0;
    virtual int search(int data) = 0;
    virtual void print() = 0;
};
