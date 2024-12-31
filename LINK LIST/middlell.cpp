//leetcode 876
//2. approracjh is brute force in ehich we use loop until the midel ele we find it usinf size /2;
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
    Node* start;
    Node* tail;
public:

linklist(){
    start = tail = NULL;
}

    void push_front(int val){
        Node* newnode  = new Node(val);
        if(start == NULL){
            start = tail = newnode;
            return;
        }else{
            newnode->next = start;
            start = newnode;
        }
    }

    void print(){
        Node* temp = start;
        while (temp!= NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }

        cout<<endl; 
    }

    Node* middleele(){
        Node* slow = start;
        Node* fast = start;

        while (fast != NULL && fast->next != NULL)
        {
           slow = slow->next;
           fast = fast->next->next;
        }
        return slow;
    }

};

int main(){
    linklist ll;
    ll.push_front(5);
    ll.push_front(5);
    ll.push_front(5);
    ll.push_front(5);
    ll.push_front(5);
    ll.print();
    Node* another = ll.middleele();
    cout<<another->data;

     return 0;
}   