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
    Node* current = head; // Ustawia wska�nik na pocz�tek listy
    Node* next;

    while (current != nullptr) { // Przechodzi przez ca�� list�
        next = current->next; // Zapisuje wska�nik na nast�pny element
        delete current; // Usuwa bie��cy element
        current = next; // Przechodzi do nast�pnego elementu
    }

    head = nullptr; // Ustawia wska�nik na pocz�tek listy na null
    tail = nullptr; // Ustawia wska�nik na koniec listy na null
}


void DoublyLinkedList::insert_front(int data) {
    Node* newNode = new Node(data); 
    if (head != nullptr) { 
        newNode->next = head; // Ustawia wska�nik na nast�pny element jako pocz�tek listy
        head->prev = newNode; // Ustawia wska�nik na poprzedni element head jako nowy w�ze�
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

    if (index <= size / 2) { // Je�eli indeks jest bli�ej pocz�tku listy
        Node* temp = head; 
        for (int i = 0; i < index; i++) { // Przechodzi do okre�lonej pozycji
            temp = temp->next;
        }
        newNode->next = temp; 
        newNode->prev = temp->prev; 
        if (temp->prev != nullptr) { // Je�eli bie��cy element nie jest pocz�tkiem listy
            temp->prev->next = newNode; 
        }
        temp->prev = newNode; 
        if (index == 0) { // Je�eli nowy w�ze� jest pocz�tkiem listy
            head = newNode; 
        }
    }
    else { // Je�eli indeks jest bli�ej ko�ca listy
        Node* temp = tail; 
        for (int i = size; i > index; i--) { // Przechodzi do okre�lonej pozycji
            temp = temp->prev;
        }
        newNode->prev = temp; 
        newNode->next = temp->next; 
        if (temp->next != nullptr) { // Je�eli bie��cy element nie jest ko�cem listy
            temp->next->prev = newNode; 
        }
        temp->next = newNode; 
        if (index == size) { // Je�eli nowy w�ze� jest ko�cem listy
            tail = newNode; 
        }
    }

    size++; 
}


void DoublyLinkedList::insert_back(int data) {
    Node* newNode = new Node(data); 
    if (head == nullptr) { // Je�eli lista jest pusta
        head = newNode; 
        tail = newNode; 
    }
    else { // Je�eli lista nie jest pusta
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

    if (temp->next != nullptr) { // Je�eli lista ma wi�cej ni� jeden element
        temp->next->prev = nullptr; 
        head = temp->next; 
    }
    else { // Je�eli lista ma tylko jeden element
        head = nullptr; 
        tail = nullptr; 
    }

    delete temp; // Usuwa pierwszy element
    size--; 
}


void DoublyLinkedList::remove(int index) {
    if (index < 0 || index >= size) {
        return;
    }

    Node* temp;
    
    if (index <= size / 2) { // Je�li indeks jest w pierwszej po�owie listy, rozpoczyna od pocz�tku
        temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
    }
    
    else { // Je�li indeks jest w drugiej po�owie listy, rozpoczyna si� od ko�ca
        temp = tail;
        for (int i = size - 1; i > index; i--) {
            temp = temp->prev;
        }
    }

    if (temp->prev != head->prev) { // Je�li poprzedni element to nie head, wska�nik next poprzedni element jest aktualizowany
        temp->prev->next = temp->next;
    }
    else { // Je�li poprzedni element to head, head jest aktualizowany
        head = temp->next;
    }

   
    if (temp->next != tail->next) {  // Je�li nast�pny element to nie tail, wska�nik prev nast�pnego elementu jest aktualizowany
        temp->next->prev = temp->prev;
    }
    
    else { // Je�li nast�pny element to tail, tail jest aktualizowany
        tail = temp->prev;
    }

    
    delete temp; 
    size--;
}


void DoublyLinkedList::remove_back() {
    if (size == 0) {
        return;
    }

    Node* temp = tail;

   
    if (temp->prev != nullptr) {  // Je�eli istnieje obiekt przed tail
        temp->prev->next = nullptr;
        tail = temp->prev;
    }
    else {
        head = nullptr;
        tail = nullptr;
    }

    delete temp; // usuwa ostatni obiekt 
    size--;
}


int DoublyLinkedList::search(int data) {
    Node* temp = head;
    int position = 0;
    while (temp != nullptr) { // Lista jest przeszukiwana do ko�ca lub do momentu znalezienia elementu
        if (temp->data == data) {
            return position;
        }
        position++;
        temp = temp->next;
    }
    return -1; // Je�eli elementu nie ma na li�cie, zwracane jest -1
}


void DoublyLinkedList::print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

