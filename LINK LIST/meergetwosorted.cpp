//leetcode 21
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};

class linklist{
    public:
    Node* head = NULL;

    void pushfront(int val){
        Node* newnode = new Node(val);

        if(head == NULL){
            head = newnode;
            return;
        }else{
            newnode->next = head;
            return;
        }
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }cout<<endl;
    }

};

