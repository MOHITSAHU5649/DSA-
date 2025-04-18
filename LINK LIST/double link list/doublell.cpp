#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
Node(int val){
    data = val;
    next = prev =NULL;
}
};

class doublell{
    public:
    Node* head = NULL;
    Node* tail = NULL;

void push_front(int val){
    Node* newnode =new Node(val);

    if(head == NULL){
        head = tail = newnode;
    }else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}



void printall(){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

void push_back(int val){
    
}

};


int main(){
    doublell ll;
    ll.push_front(5);
    ll.push_front(5);
    ll.push_front(5);

    ll.printall();

    return 0;
}