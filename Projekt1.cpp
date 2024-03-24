#include <iostream>
#include "ArrayList.h"
using namespace std;

int main() {
    ArrayList array;
    array.insert_front(1);
    array.insert_front(1);
    array.insert_front(6);
    array.insert_back(5);
    array.print();
    return 0;
}

