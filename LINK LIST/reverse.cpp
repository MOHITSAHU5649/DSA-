//leetcode 206
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
    Node* head;
    Node* tail;
public:
    linklist(){
        head = tail = NULL;
    }

    void push_front(int data){
        Node* newnode = new Node(data);
        if(head == NULL){
            head = tail = newnode;
            return;
        }else{
                newnode->next = head;
                head = newnode;

        }
    }

    void rever(){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head =  prev;
    }

    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl; 
    }
};



int main(){
    linklist ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1); 
    ll.rever();
    ll.print();
    return 0;

}