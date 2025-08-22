//leetcode 21


#include<iostream>
using namespace std;

class Node{
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


    Node* mergell(Node* head1, Node* head2){
        if(head1 == NULL || head2 == NULL){
            return head1 == NULL ? head2 : head1;
        }

        if(head1-> data <= head2->data){
            head1->next = mergell(head1->next, head2);
            return head1;
        }else{
            head2->next = mergell(head1,head2->next);
            return head2;
        }
        
    }
};

int main(){
  


}
/// ye ayesa he hai ab kya hofa ne ye merge hogi to apn ko object bana ke usko callkarne padega lekin fie apn ko uska head1 or head 2 chaye jo scope ke bahar hai to apn ko ek metohod or bannae padeg jisme wo merge metoj     od call hoga
