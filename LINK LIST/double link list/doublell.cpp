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

    Node* newnode = new Node(val);
    if(head == NULL){
        head = tail = newnode;
    }else{
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void pop_front(){
    if(head == NULL){
        return;
    }

    Node* temp = head;
    head = head->next;

    if(head != NULL){
        head->prev = NULL;
    };

    temp->next = NULL;
    delete temp;
}

void pop_back(){
    if(tail == NULL){
        return;
    }

    Node* temp = tail;
    tail = tail->prev;

    if(tail != NULL){
        tail->next = NULL;
    }

    temp->prev = NULL;

    delete temp;
}



};


int main(){
    doublell ll;
    ll.push_front(5);
    ll.push_front(5);
    ll.push_front(5);

    ll.push_back(6);

    ll.pop_front();
    ll.pop_back();


    ll.printall();

    return 0;
}