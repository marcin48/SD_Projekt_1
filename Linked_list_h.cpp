#include<iostream>
#include "Linked_list_h.h"
#include "Node.h"
using namespace std;

    void Linked_list_h::insert_front(int value) {

        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            size++;

        }
        else {

            newNode->next = head;
            head = newNode;
            size++;

        }

    }

    void Linked_list_h::insert_back(int value) {

        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            size++;

        }
        else {
            Node* current = head;

            while (current->next) {
                current = current->next;
            }

            current->next = newNode;

            size++;


        }
    }

    void Linked_list_h::remove_front() {

        if (!head) {
            cout << "Lista nie posiada elementow" << endl;
            return;
        }
        else if (!head->next) {
            delete head;
            head = nullptr;
            size--;
            return;  
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;

    }

    void Linked_list_h::remove_back() {

    if (!head) {
        cout << "Lista nie posiada elementow" << endl;
        return;
    }
    else if (!head->next) {
        delete head;
        head = nullptr;
        size--;
        return;  // Dodajemy return tutaj
    }

    Node* current = head;

    while (current->next->next) {
        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
    size--;

}


    void Linked_list_h::insert(int value, int id) {

        Node* newNode = new Node(value);
        Node* current = head;

        if (id > size || id < 0) {

            cout << "Wskazujesz poza zakres listy" << endl;
            return;

        }
        else if (id == 1) {

            insert_front(value);
            return;

        }
        else if (id == size) {

            insert_back(value);
            return;
        }

        while (id - 2) {
            current = current->next;
            id--;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;


    }

    void Linked_list_h::remove(int id) {

        Node* behind = head;

        if (size == 0) {

            cout << "Lista nie ma elementow" << endl;
            return;

        }
        else if (id > size || id < 0) {
            cout << "Podany indeks nie pasuje do rozmiaru listy" << endl;
            return;

        }
        else if (id == 0) {

            cout << "Nie ma elementu o indeksie 0" << endl;
            return;

        }
        else if (id == 1) {

            remove_front();
            return;

        }
        else if (id == size) {

            remove_back();
            return;
        }

        while (id - 2) {
            behind = behind->next;
            id--;
        }
        Node* current = behind->next;
        behind->next = current->next;
        delete current;

        size--;


    }

    int Linked_list_h::search(int value) {

        Node* current = head;

        while (current) {

            if (current->data == value) {

                return current->data;
            }
            current = current->next;
        }
        return -1;

    }


    void Linked_list_h::print() {

        Node* current = head;

        while (current) {

            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;

    }

    int Linked_list_h::Size_of_list()const {
        return size;
    }

