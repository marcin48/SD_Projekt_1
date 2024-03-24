#include <iostream>
#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList() {
    size = 1;
    arr = new int[size];
    end = size - 1;
}
ArrayList::~ArrayList() {
    delete[] arr;
}

void ArrayList::insert_front(int data) {
    if (end == size) {
        int* temp = new int[2 * size];

        for (int i = 0; i < end; i++) {
            temp[i + 1] = arr[i];
        }

        delete[] arr;
        size *= 2;
        arr = temp;
    }
    else {
        for (int i = end; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
    }

    arr[0] = data;
    end++;
}

void ArrayList::insert(int data, int index) {
    if (index < end) {
        if (end == size) {
            int* temp = new int[2 * size];

            for (int i = 0; i < index; i++) {
                temp[i] = arr[i];
            }

            for (int i = index; i < end; i++) {
                temp[i + 1] = arr[i];
            }

            delete[] arr;
            size *= 2;
            arr = temp;
        }
        else {
            for (int i = end; i > index; i--) {
                arr[i] = arr[i - 1];
            }
        }

        arr[index] = data;
        end++;
    }
}

void ArrayList::insert_back(int data) {
    if (end == size) {
        int* temp = new int[2 * size];

        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        size *= 2;
        arr = temp;
    }

    arr[end] = data;
    end++;
}

void ArrayList::remove(int index) {
    if (index < end) {
        for (int i = index; i < end - 1; i++) {
            arr[i] = arr[i + 1];
        }
        end--;
    }
}

int ArrayList::search(int data) {
    for (int i = 0; i < end; i++) {
        if (arr[i] == data) {
            return i;
        }
    }
    return -1;
}

void  ArrayList::print() {
    for (int i = 0; i < end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}









