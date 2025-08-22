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

class list{
    Node* start;
    Node* tail;
    public:

    list(){
        start = tail = NULL;
    }

    void push_front(int val){
        Node* newnode = new Node(val); // dynaamic 
        // Node newnode(val);  this is static scope end after execution of the fun

        if(start == NULL){
            start =tail = newnode;
            return;
        }else
        {
            newnode->next = start;
            start = newnode;
        }
    }

    void Push_back(int val){
        Node* newnode = new Node(val);

        if(start == NULL){
            start = tail = newnode;
            return;
        }else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void pop_front(){
        if(start ==  NULL){
            return;
        }
        Node* temp = start;
        start = start->next;
        temp->next = NULL; //optional
        delete temp;
    }

    void pop_back(){
        if(start == NULL) return;

        Node* temp = start;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next =NULL;
        delete tail;
        tail = temp;
        // delete temp; this is producing  infinite loop why?
    }

    void insertmid(int val,int pos){
        if(pos<0) return; // check if the numebr is lees that zero 

        if(pos == 0){ // if the list is empty then add it in the first position 
            push_front(val);
            return;
        }

        Node* newnode = new Node(val); // created a new node 
        Node* temp = start; // a temp variable to store the start node 
        for(int i =0;i<pos-1;i++){ // traverset to the previosu of the postiton 
            temp = temp->next; // tatke the temp to the n-1
        }

        newnode->next = temp->next; 
        temp->next = newnode;

    }

    void popmid(int pos){
        if(pos<0) return;

        if(pos == 0){
            pop_front();
            return;
        }

        Node* temp1 = start;
        Node* temp2;
        for(int i=0;i<pos-1;i++){
            temp1 = temp1->next;
            temp2 =temp1->next;
        }

        temp1->next = temp2->next;
        temp2->next = NULL;
        delete temp2; 
    }

    int search(int val){
        Node* temp = start;
        int idx =0;
        while(temp->next != NULL){
            if(temp->data == val){
                return idx;
            }else{
                temp = temp->next;
                idx++;
            }
        }

    }

    void printele(){
        Node* temp = start;
        while (temp != NULL) // we cannot tatek the start ot eh end because for the next other operation the postion of the ater will be change 
        {
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
   list ll;
    ll.push_front(2);
    ll.push_front(2);
    ll.Push_back(3);
    ll.Push_back(3);
    ll.Push_back(3);
    ll.pop_front();
    ll.pop_back();
    ll.insertmid(4,2);
    ll.printele();
    ll.popmid(2);

    ll.printele();
    cout<<ll.search(3);



    return 0;
}