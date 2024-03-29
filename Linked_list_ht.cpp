#include "Linked_list_ht.h"
#include "Node.h"

#include <iostream>

using namespace std;


    void Linked_list_ht::insert_front(int value) {

        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            tail = newNode;
            size++;

        }
        else {

            newNode->next = head;
            head = newNode;
            size++;

        }

    }

    void Linked_list_ht::insert_back(int value) {

        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;
            tail = newNode;
            size++;

        }
        else {

            tail->next = newNode;
            tail = newNode;
            size++;


        }

    }

    void Linked_list_ht::remove_front() {

        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;

        }

        Node* current = head;
        head = current->next;
        delete current;
        size--;

    }

    void Linked_list_ht::remove_back() {

        if (!head) {
            cout << "List is empty" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;

        }

        Node* current = head;

        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
        size--;

    }

    int Linked_list_ht::search(int value) {

        Node* current = head;

        while (current) {

            if (current->data == value) {
                return current->data;
            }
            current = current->next;
        }
        return -1;

    }

    void Linked_list_ht::insert(int value, int id) {

        Node* newNode = new Node(value);
        Node* current = head;

        if (id > size) {

            cout << "Za ma?a lista" << endl;
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

    void Linked_list_ht::remove(int id) {

        Node* behind = head;

        if (size == 0) {

            cout << "Lista nie ma element?w" << endl;
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
        else if (id > size || id < 0) {

            cout << "Podany indeks nie pasuje do rozmiru listy" << endl;
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

    void Linked_list_ht::print() {

        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;

        }
        cout << endl;

    }

    int Linked_list_ht::Size_of_list()const {
        return size;
    }

