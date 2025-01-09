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
    Node* copyrl(Node* head){
        if(head == NULL){
            return NULL;
        }

        unordered_map<Node*,Node*> m;
        Node* newhead = new Node(head->val);
        Node* oldtemp = head->next;
        Node* newtemp = newhead;
        m[head] = newhead;

        while(oldtemp != NULL){
            Node* copynode = new Node(oldtemp->val);
            m[oldtemp] = copynode;
            newtemp->next = copynode;

            oldtemp = oldtemp->next;
            newtemp = newtemp->next;
        }

        oldtemp = head;
        newtemp = newhead;

        while(oldtemp != NULL){
            newtemp->random = m[oldtemp->random];
            oldtemp = oldtemp->next;
            newtemp newtemp->next;
        }
        return newhead;
    }
};

int main(){
    return 0;
}