#include <iostream>
#include <fstream>
#include <conio.h>
#include "ArrayList.h"
#include "DoublyLinkedList.h"
#include "Linked_list_h.h"
#include "Linked_list_ht.h"
using namespace std;

void run() {
    Struktura* wsk{};
    ArrayList array;
    Linked_list_h list_h;
    Linked_list_ht list_ht;
    DoublyLinkedList dll;
    int choice=0;
    while (choice != 5) {
        cout << "Wybierz strukture:" << endl;
        cout << "1. Tablica dynamiczna" << endl;
        cout << "2. Lista jednokierunkowa (head)" << endl;
        cout << "3. Lista jednokierunkowa (head,tail)" << endl;
        cout << "4. Lista dwukierunkowa" << endl;
        cout << "5. Wyjdz" << endl;

        cin >> choice;
        system("cls");
        switch (choice) {
        case 1: {
            wsk = &array;
            break;
        }
        case 2: {
            wsk = &list_h;
            break;
        }
        case 3: {
            wsk = &list_ht;
            break;
        }
        case 4: {
            wsk = &dll;
            break;
        }
        case 5: {
            return;
            break;
        }
        }

        int choice1 = 0;
        while (choice1 != 10)
        {
            cout << "1. Dodaj element na poczatku" << endl;
            cout << "2. Dodaj element na wybranej pozycji" << endl;
            cout << "3. Dodaj element na koncu" << endl;
            cout << "4. Usun element na poczatku" << endl;
            cout << "5. Usun element na wybranej pozycji" << endl;
            cout << "6. Usun element na koncu" << endl;
            cout << "7. Znajdz wybrany element (zwraca pozycje)" << endl;
            cout << "8. Wyswietl" << endl;
            cout << "9. Wczytaj z pliku" << endl;
            cout << "10. Cofnij do menu glownego" << endl;
            cin >> choice1;

            switch (choice1) {
            case 1: {
                system("cls");
                int data;
                cout << "Podaj wartosc: ";
                cin >> data;
                wsk->insert_front(data);
                break;
            }
            case 2: {
                system("cls");
                int data;
                int index;
                cout << "Podaj wartosc: ";
                cin >> data;
                cout << endl << "Podaj numer indeksu (numeracja od 0): ";
                cin >> index;
                wsk->insert(data, index);
                break;
            }
            case 3: {
                system("cls");
                int data;
                cout << "Podaj wartosc: ";
                cin >> data;
                wsk->insert_back(data);
                break;
            }
            case 4: {
                wsk->remove_front();
                break;
            }
            case 5: {
                system("cls");
                int index;
                cout << "Podaj numer indeksu, ktory chcesz usunac (numeracja od 0): ";
                cin >> index;
                wsk->remove(index);
                break;
            }
            case 6: {
                wsk->remove_back();
                break;
            }
            case 7: {
                system("cls");
                int data;
                cout << "Podaj wartosc, ktora chcesz znalezc: ";
                cin >> data;
                cout << "Numer indeksu: " << wsk->search(data);
                cout << endl << "Nacisnij dowolny klawisz, aby kontynuowac...";
                cin.ignore();
                _getch();  // Odczytaj znak z klawiatury
                break;
            }
            case 8: {
                system("cls");
                wsk->print();
                cout << endl << "Nacisnij dowolny klawisz, aby kontynuowac...";
                cin.ignore();
                _getch();  // Odczytaj znak z klawiatury
                break;
            }
            case 9: {
                break;
            }
            case 10: {
                break;
            }
            }
            system("cls");
        }
    }
}

int main() {

    run();

    return 0;
}

