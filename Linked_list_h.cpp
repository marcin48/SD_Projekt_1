#include<iostream>
#include "Linked_list_h.h"
#include "Node.h"
using namespace std;

    void Linked_list_h::Add_First(int value) {

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

    void Linked_list_h::Add_End(int value) {

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

    void Linked_list_h::Remove_First() {

        if (!head) {
            cout << "Lista nie posiada elementow" << endl;
            return;
        }
        else if (!head->next) {

            delete head;
            head = nullptr;
            size--;

        }

        Node* temp = head;
        head = head->next;
        delete temp;
        size--;

    }

    void Linked_list_h::Remove_End() {



        if (!head) {

            cout << "Lista nie posiada elementow" << endl;
            return;

        }
        else if (!head->next) {

            delete head;
            head = nullptr;
            size--;
        }

        Node* current = head;

        while (current->next->next) {

            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
        size--;

    }

    void Linked_list_h::Add_Random(int value, int id) {

        Node* newNode = new Node(value);
        Node* current = head;

        if (id > size || id < 0) {

            cout << "Wskazujesz poza zakres listy" << endl;
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

    void Linked_list_h::Remove_Random(int id) {

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

            Remove_First();
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

    void Linked_list_h::Look_For(int value) {

        Node* current = head;

        while (current) {

            if (current->data == value) {
                cout << "Znaleziono wartosc: " << current->data << endl;

                return;
            }
            current = current->next;
        }
        cout << "Brak podanego elementu" << endl;

    }


    void Linked_list_h::Show() {

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

