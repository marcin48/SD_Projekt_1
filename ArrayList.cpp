#include <iostream>
#include "ArrayList.h"
using namespace std;


ArrayList::ArrayList() {
    size = 1; 
    arr = new int[size]; 
    end = 0; 
}


ArrayList::~ArrayList() {
    delete[] arr; 
}

// Wstawia element na początek tablicy
void ArrayList::insert_front(int data) {
    if (end == size) { 
        int* temp = new int[2 * size]; // Tworzy tymczasową tablicę o dwukrotnie większym rozmiarze

        for (int i = 0; i < end; i++) { // Przenosi wszystkie elementy ze starej tablicy do nowej
            temp[i + 1] = arr[i]; // Z indeksem przesuniętym o 1 w prawo 
        }

        delete[] arr; 
        size *= 2; 
        arr = temp; 
    }
    else { // Przesuwa wszystkie elementy o jeden w prawo 
        for (int i = end; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
    }

    arr[0] = data; 
    end++; 
}

// Wstawia element na określonej pozycji w tablicy
void ArrayList::insert(int data, int index) {
    if (index <= end) { 
        if (end == size) { 
            int* temp = new int[2 * size]; // Tworzy tymczasową tablicę o dwukrotnie większym rozmiarze

            for (int i = 0; i < index; i++) { // Przenosi elementy ze starej tablicy do nowej
                temp[i] = arr[i];
            }

            for (int i = index; i < end; i++) { // Przenosi resztę elementów ze starej tablicy do nowej
                temp[i + 1] = arr[i]; // Z indeksem przesuniętym o 1 w prawo
            }

            delete[] arr; 
            size *= 2; 
            arr = temp; 
        }
        else { 
            for (int i = end; i > index; i--) { // Przesuwa wszystkie elementy o jeden w prawo od indeksu
                arr[i] = arr[i - 1];
            }
        }

        arr[index] = data; 
        end++; 
    }
}

// Wstawia element na koniec tablicy
void ArrayList::insert_back(int data) {
    if (end == size) { 
        int* temp = new int[2 * size]; // Tworzy tymczasową tablicę o dwukrotnie większym rozmiarze

        for (int i = 0; i < size; i++) { // Przenosi wszystkie elementy ze starej tablicy do nowej
            temp[i] = arr[i];
        }

        delete[] arr; 
        size *= 2; 
        arr = temp; 
    }

    arr[end] = data; 
    end++; 
}

// Usuwa element z początku tablicy
void ArrayList::remove_front() {
    if (end > 0) { 
        for (int i = 0; i < end - 1; i++) { // Przesuwa wszystkie elementy o jeden w lewo
            arr[i] = arr[i + 1];
        }
        end--; 
    }
}

// Usuwa element z określonej pozycji w tablicy
void ArrayList::remove(int index) {
    if (index < end) { 
        for (int i = index; i < end - 1; i++) { // Przesuwa wszystkie elementy o jeden w lewo od indeksu
            arr[i] = arr[i + 1];
        }
        end--; 
    }
}

// Usuwa element z końca tablicy
void ArrayList::remove_back() {
    if (end > 0) { 
        end--; 
    }
}

// Szuka elementu w tablicy
int ArrayList::search(int data) {
    for (int i = 0; i < end; i++) { // Przeszukuje tablicę
        if (arr[i] == data) { // Jeżeli znajdzie szukany element zwraca go
            return i; 
        }
    }
    return -1; 
}

// Wyświetla wszystkie elementy tablicy
void  ArrayList::print() {
    for (int i = 0; i < end; i++) { 
        cout << arr[i] << " "; 
    }
    cout << endl; 
}


void ArrayList::load_file() {};

// Zwraca rozmiar tablicy
int ArrayList::get_size() {
    return size;
}










