#include<iostream>

using namespace std;

struct Node{

int data;
Node* next;

Node(int value) : data(value), next(nullptr) {}
};


class Linked_list_h{

private:
    Node* head;
    int size = 0;

public:
    Linked_list_h(): head(nullptr){};
    ~Linked_list_h(){};

    void Add_First(int value){

    Node* newNode = new Node(value);

    if(!head){
        head = newNode;
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
        size++;

    }else{
        Node* current = head;

        while(current->next){
            current = current -> next;
        }

        current->next = newNode;

    size++;


    }
    }

    void Remove_First(){

    if(!head){
        cout<<"Lista nie posiada elementów"<<endl;
        return;
    }else if(!head->next){

    delete head;
    head = nullptr;
    size--;

    }

    Node* temp = head;
    head = head -> next;
    delete temp;
    size--;

    }

    void Remove_End(){



    if(!head){

        cout<<"Lista nie posiada elementów"<<endl;
        return;

    }else if (!head->next){

    delete head;
    head = nullptr;
    size--;
    }

    Node* current = head;

    while(current->next->next){

        current = current->next;
    }

    delete current->next;
    current->next = nullptr;
    size--;

    }

    void Add_Random(int value, int id){

    Node* newNode = new Node(value);
    Node* current = head;

    if(id>size || id<0){

        cout<<"Wskazujesz poza zakres listy"<<endl;
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

    }else if(id>size || id<0){
        cout<<"Podany indeks nie pasuje do rozmiru listy"<<endl;
        return;

    }else if (id == 0){

    cout<<"Nie ma elementu o indeksie 0"<<endl;
    return;

    }else if(id == 1){

        Remove_First();
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


    void Show(){

    Node* current = head;

    while(current){

        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;

    }

    int Size_of_list()const{
    return size;
    }

    };

int main()
{
    Linked_list_h list;

    list.Add_First(1);
    list.Add_First(2);
    list.Add_First(3);
    list.Add_End(4);
    list.Add_End(5);
    list.Add_Random(98,3);
    list.Show();
    list.Remove_Random(4);
    //list.Remove_First();
    //list.Remove_End();
    list.Look_For(4);
    list.Show();
    cout<<"Liczba elementów w liœcie: "<<list.Size_of_list()<<endl;
    return 0;
}
