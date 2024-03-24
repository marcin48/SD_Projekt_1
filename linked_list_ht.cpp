#include <iostream>

using namespace std;

struct Node{

int data;
Node* next;

Node(int value) : data(value), next(nullptr) {}
};


class Linked_list_ht{

private:
    Node* head;
    Node*tail;
    int size = 0;

public:
    Linked_list_ht(): head(nullptr), tail(nullptr){};
    ~Linked_list_ht(){};

    void Add_First(int value){

    Node* newNode = new Node(value);

    if(!head){
        head = newNode;
        tail = newNode;
        size++;

    }else{

    newNode->next = head;
    head = newNode;
    size++;

    }

    }

    void Add_End(int value){

    Node* newNode = new Node(value);

    if(!head){
        head = newNode;
        tail = newNode;
        size++;

    }else{

    tail->next = newNode;
    tail=newNode;
    size++;


    }

    }

    void Remove_First(){

    if(!head){
        cout<<"List is empty"<<endl;
        return;
    }

    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;

    }

    Node* current = head;
    head = current -> next;
    delete current;
    size--;

    }

        void Remove_End(){

    if(!head){
        cout<<"List is empty"<<endl;
        return;
    }

    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;

    }

    Node* current = head;

    while(current ->next != tail){
        current = current->next;
    }
    delete tail;
    tail = current;
    tail -> next = nullptr;
    size--;

    }

    void Look_For(int value){

    Node* current = head;

    while(current){

        if(current->data == value){
            cout<<"Znaleziono wartoœæ: "<<current->data<<endl;

        return;
        }
        current = current->next;
    }
    cout<<"Brak podanego elementu"<<endl;

    }

    void Add_Random(int value, int id){

    Node* newNode = new Node(value);
    Node* current = head;

    if(id>size){

        cout<<"Za ma³a lista"<<endl;
        return;

    }else if(id == 1){

        Add_First(value);
        return;

    }else if(id == size){

        Add_End(value);
        return;
    }

    while(id-2){
        current = current->next;
        id--;
    }
    newNode->next = current->next;
    current->next = newNode;
    size++;


    }


    void Remove_Random(int id){

    Node* behind = head;

    if(size==0){

        cout<<"Lista nie ma elementów"<<endl;
        return;

    }else if (id == 0){

    cout<<"Nie ma elementu o indeksie 0"<<endl;
    return;

    }else if(id == 1){

        Remove_First();
        return;

    }else if(id>size || id<0){

        cout<<"Podany indeks nie pasuje do rozmiru listy"<<endl;
        return;

    }else if(id == size){

        Remove_End();
        return;
    }

    while(id-2){
        behind = behind->next;
        id--;
    }
    Node* current = behind->next;
    behind->next = current->next;
    delete current;

    size--;


    }

    void Show(){

    Node* current = head;
    while(current){
        cout<<current->data <<" ";
        current = current->next;

    }
    cout<<endl;

    }

    int Size_of_list()const{
    return size;
    }


};
int main() {
    Linked_list_ht list;

    list.Add_End(1);
    list.Add_End(2);
    list.Add_End(3);
    list.Add_First(4);
    list.Add_First(5);
    list.Add_Random(98,2);
    list.Remove_Random(2);
    list.Show();
    cout<<"Rozmiar listy: "<<list.Size_of_list()<<endl;
    list.Remove_End();
    list.Remove_First();
    list.Show();
    cout<<"Rozmiar listy: "<<list.Size_of_list()<<endl;
    list.Look_For(4);
    list.Look_For(6);


    return 0;
}

