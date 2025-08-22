//leetcode 138
// copy linklist with random pointer in this the main fun required a random number and slo the initialization therefore this will not work on vs code only on leetcode
#include<iostream>
#include<unordered_map>
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

class solution{
    public:
    Node* head = NULL;

// this is the main logic
    Node* copyrl(Node* head){ // if linklist is empty then return 
        if(head == NULL){
            return NULL;
        }

        unordered_map<Node*,Node*> m; // cerat a map to store the randp, of bothe the new and the old list 
        Node* newhead = new Node(head->data); // create a new head witht he data of the old ehad 
        Node* oldtemp = head->next; // oldtemp ko start kare 2 post se becuase pehel to ban chuka upar 
        Node* newtemp = newhead; // newtemp pointer banaya hai new heasd se start kiya new list ko 
        m[head] = newhead; // head ko map me store kar siya hai 

        while(oldtemp != NULL){
            Node* copynode = new Node(oldtemp->data); // new node with old  node data 
            m[oldtemp] = copynode; // map kiya old node with ne node data 
            newtemp->next = copynode; // 

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        oldtemp = head; //  jab sab map ho jaye or a new ban list ban jaye to ab usko fir se head pe le aayo 
        newtemp = newhead;

        while(oldtemp != NULL){
            newtemp->random = m[oldtemp->random]; // old ke random ko dhundo or for usko new ke sarh attach kar do 
            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }
        return newhead; // new list ka ehad return kar do 
    }
};

int main(){
    return 0;
}