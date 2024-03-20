#include <iostream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;
//ahora necesito ordenar por pintas
//ordenamiento de listas letras
//para numeros, cambiar a int data y val
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
    addInicio(head,"8");
    addInicio(head,"10");
    addInicio(head,"9");
    addInicio(head,"4");
    addInicio(head,"5");
    addInicio(head,"2");
    addInicio(head,"3");
    addInicio(head,"7");
    addInicio(head,"6");
    addInicio(head,"A");
    addInicio(head,"K");
    addInicio(head,"Q");
    addInicio(head,"J");


    cout<<"La lista original es: "<<endl;
    imprimirLista(head);
    ordenarLista(head);
    cout<<"La lista ordenada es: "<<endl;
    imprimirLista(head);

    return 0;
}





