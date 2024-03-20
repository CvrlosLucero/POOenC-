#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

//ordenamiento de listas

struct Node{
    string data;
    Node* next;

    Node(string val):data(val),next(nullptr){}
};

void addInicio(Node* &head, string val){
    Node* nuevoNodo = new Node(val);
    nuevoNodo->next=head;
    head=nuevoNodo;

};

void imprimirLista(Node* head){
    while(head!= nullptr){
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
};

void ordenarLista(Node* &head){
    if(head==nullptr || head->next==nullptr)
    return;
    Node* sorted=nullptr;
    Node* current = head;
    while(current!=nullptr){
        Node* nextNode = current->next;
        if(sorted==nullptr || sorted->data>= current->data){
            current->next=sorted;
            sorted=current;
        }else{
            Node* temp = sorted;
            while(temp->next!=nullptr && temp->next->data < current->data){
                temp=temp->next;
            }
            current->next=temp->next;
            temp->next=current;
        }
        current=nextNode;
    }
    head=sorted;

};

int main(){
    Node* head=nullptr;
    addInicio(head,"A");
    addInicio(head,"C");
    addInicio(head,"S");
    addInicio(head,"G");
    addInicio(head,"J");
    addInicio(head,"T");
    addInicio(head,"L");
    addInicio(head,"O");

    cout<<"La lista original es: "<<endl;
    imprimirLista(head);
    ordenarLista(head);
    cout<<"La lista ordenada es: "<<endl;
    imprimirLista(head);

    return 0;
}





