//leetode 430 
// anode of linklist is haivng a child we have to make this to one ln]inklist 
//for full ocde we have to create main in whihc we have to create a doubly linklist and hviang a child field as well and then have to insert the values 
#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node* child;
Node(int val){
    data = val;
    next = prev = NULL;
    child= NULL;
}
};

class doublell{
    public:
    Node* head = NULL;
    Node* tail = NULL;
};







Node* flatten(Node* head) {
            if(head == NULL){
                return head;
            }
    
            Node* curr = head;
            while(curr != NULL){
                if(curr->child != NULL){
    
                    Node* next = curr->next;
                    curr->next = flatten(curr->child);
    
                    curr->next->prev = curr;
                    curr->child = NULL;
    
                    while(curr->next != NULL){
                        curr = curr->next;
                    }
    
                    if(next != NULL){
                        curr->next = next;
                        next->prev = curr;
                    }
    
                }
    
                curr = curr->next;
            }
            return head;
        }

        int main(){
            doublell ll;
        
            return 0;
        }
    


