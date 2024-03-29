#include <iostream>
#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList() {
    size = 1;
    arr = new int[size];
    end = 0;
}
ArrayList::~ArrayList() {
    delete[] arr;                              // Destruktor usuwa tablice
}

void ArrayList::insert_front(int data) {
    if (end == size) {
        int* temp = new int[2 * size];         // jezeli tablica jest pelna, tworzy tymczasowa dwa razy wieksza tablice

        for (int i = 0; i < end; i++) {        // nastepnie wpisuje wszystkie elementy ze starej tablicy do nowej
            temp[i + 1] = arr[i];              // z indeksem przesunietym o 1 w lewo 
        }

        delete[] arr;
        size *= 2;
        arr = temp;                            // kasuje stara tablice, zwieksza size razy 2, i zamienia tablice tymczasowa w domyslna
    }
    else {                                     // przesuwa od konca wszystkie elementy o jeden w lewo 
        for (int i = end; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
    }

    arr[0] = data;
    end++;                                     // wstawia dane na poczatek tablicy i zwieksza wartosc end 
}

void ArrayList::insert(int data, int index) {
    if (index <= end) {
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

void ArrayList::remove_front() {
    if (end > 0) {
        for (int i = 0; i < end - 1; i++) {
            arr[i] = arr[i + 1];
        }
        end--;
    }
}

void ArrayList::remove(int index) {
    if (index < end) {
        for (int i = index; i < end - 1; i++) {
            arr[i] = arr[i + 1];
        }
        end--;
    }
}

void ArrayList::remove_end() {
    if (end > 0) {
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

int ArrayList::get_size() {
    return size;
}









