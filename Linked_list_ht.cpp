#include "Linked_list_ht.h"
#include "Node.h"

#include <iostream>

using namespace std;


    void Linked_list_ht::Add_First(int value) {

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

    void Linked_list_ht::Add_End(int value) {

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

    void Linked_list_ht::Remove_First() {

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

    void Linked_list_ht::Remove_End() {

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

    void Linked_list_ht::Look_For(int value) {

        Node* current = head;

        while (current) {

            if (current->data == value) {
                cout << "Znaleziono warto??: " << current->data << endl;

                return;
            }
            current = current->next;
        }
        cout << "Brak podanego elementu" << endl;

    }

    void Linked_list_ht::Add_Random(int value, int id) {

        Node* newNode = new Node(value);
        Node* current = head;

        if (id > size) {

            cout << "Za ma?a lista" << endl;
            return;

        }
        else if (id == 1) {

            Add_First(value);
            return;

        }
        else if (id == size) {

            Add_End(value);
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

    void Linked_list_ht::Remove_Random(int id) {

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

            Remove_First();
            return;

        }
        else if (id > size || id < 0) {

            cout << "Podany indeks nie pasuje do rozmiru listy" << endl;
            return;

        }
        else if (id == size) {

            Remove_End();
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

    void Linked_list_ht::Show() {

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

