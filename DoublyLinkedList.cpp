#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"
using namespace std;

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::insert_front(int data) {
    Node* newNode = new Node(data);
    if (head != nullptr) {
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::insert(int data, int index) {
    if (index < 0 || index > size) {
        return;
    }

    Node* newNode = new Node(data);

    if (index <= size / 2) {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != nullptr) {
            temp->prev->next = newNode;
        }
        temp->prev = newNode;
        if (index == 0) {
            head = newNode;
        }
    }
    else {
        Node* temp = tail;
        for (int i = size; i > index; i--) {
            temp = temp->prev;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        if (index == size) {
            tail = newNode;
        }
    }

    size++;
}

void DoublyLinkedList::insert_end(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::remove_front() {
    if (size == 0) {
        return;
    }

    Node* temp = head;

    if (temp->next != nullptr) {
        temp->next->prev = nullptr;
        head = temp->next;
    }
    else {
        head = nullptr;
        tail = nullptr;
    }

    delete temp;
    size--;
}

void DoublyLinkedList::remove(int index) {
    if (index < 0 || index >= size) {
        return;
    }

    Node* temp;
    if (index <= size / 2) {
        temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    }
    else {
        temp = tail;
        for (int i = size - 1; i > index; i--) {
            temp = temp->prev;
        }
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }
    else {
        head = temp->next;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    else {
        tail = temp->prev;
    }

    delete temp;   // usuwa obiekt zadany obiekt 
    size--;
}

void DoublyLinkedList::remove_end() {
    if (size == 0) {
        return;
    }

    Node* temp = tail;

    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;
        tail = temp->prev;
    }
    else {
        head = nullptr;
        tail = nullptr;
    }

    delete temp;
    size--;
}

int DoublyLinkedList::search(int data) {
    Node* temp = head;
    int position = 0;
    while (temp != nullptr) {
        if (temp->data == data) {
            return position;
        }
        position++;
        temp = temp->next;
    }
    return -1;
}

void DoublyLinkedList::print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

