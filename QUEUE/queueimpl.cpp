#include<iostream>
#include<queue> // 2. using the stl method
#include<deque>//double ended queue push from back and front  
using namespace std;

//1. using linklist 
class Node{
     public:
    int data;
    Node* next;
   
    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
    Node * head;
    Node * tail;
    public:
    
    Queue(){
        head = tail = NULL;
    }

    void push(int val){
        Node  * newNode = new Node(val);
        if(empty()){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }

    }

    void pop()
{if(empty()){
    cout<<"it ios mepty";
    return;
}
    Node* temp = head;
    head = head->next;
    delete temp;
}

int front(){
    if(empty()){
        cout<<"empty";
        return -1;
    }else{
        return head->data;
    }
}

bool empty(){
    return head ==  NULL;
}
};


int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

while(!q.empty()){
    cout<<q.front();
    q.pop();
}

return 0;

}