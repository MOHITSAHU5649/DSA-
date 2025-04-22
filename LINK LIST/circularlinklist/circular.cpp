#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node * next;

    Node(int val){
        data = val;
        next = NULL;
    }
};


class circularList{
    Node * head; 
    Node* tail;

    public:
    
    circularList(){
        head = tail = NULL;
    }

    void insertHead(int val){
        Node* newnode = new Node(val);

        if(tail == NULL){
            head = tail = newnode;
            tail->next = newnode;
        }else{
            newnode -> next = head;
            head = newnode;
            tail->next = head;
        }
    }

    void inserttail(int val){
        Node * newnode = new Node(val);

        if(head == NULL){
            head = tail = newnode;
        }

        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }

    void deletehead(){
        Node * temp = head;
        if(head == tail){
            delete head; 
            head = tail = NULL;
        }else{
            head = head->next;
            tail->next = head;
            delete temp;
          
        }
    }

    void deletetail(){
        if(head == NULL ) return;
        else if( head == tail){
            delete head;
            head = tail = NULL;
        }else {
            Node * temp = tail;
            Node * prev = head;
            while(prev->next != tail){
                prev = prev->next;
            }
            tail = prev;
            tail->next = head;
            temp->next = NULL;
            delete temp;
        }
    }

    void printall(){
    if (head == NULL) return;

    cout<<head->data <<"->";
    Node * temp = head->next;

    while(temp != head){
        cout<<temp->data <<"->";
        temp = temp->next;
    }

    //cout<<temp->data<<endl;
    delete temp;
}


};



int main(){
    circularList cl;

    cl.insertHead(1);
    cl.insertHead(1);
    cl.inserttail(2);
    cl.inserttail(2);
    cl.inserttail(2);
    cl.deletehead();
    cl.deletetail();

    cl.printall();

    return 0;
}