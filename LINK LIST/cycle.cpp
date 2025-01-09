//leetcode 141 142to find a cycle and remoce it
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
    Node* head = NULL;
    Node* tail = NULL;
public:

    void pushfront(int val){
        Node* newnode = new Node(val);
        if(head == NULL){
            head = newnode;
            return;
        }else{
            newnode->next = head;
            head =newnode;
        }
    }

    void print(){
        Node* temp = head;
        while (temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
            
        cout<<endl;
    } }

     void createCycle(int position) {
    if (!head) return;

    Node* temp = head;
    Node* cycleNode = nullptr;
    int count = 0;

    // Traverse the list to find the node at 'position'
    while (temp->next) {
        if (count == position) {
            cycleNode = temp;
        }
        temp = temp->next;
        count++;
    }
    // Create the cycle
    if (cycleNode) {
        temp->next = cycleNode;
    }
}


   
   Node*  cycle() {
        Node* slow = head;
        Node* fast = head;
        bool cycle = false;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cycle = true;
                break;
            }
            }

            if(!cycle){
                return NULL;
            }

            slow = head;
            Node* prev = fast;
            while(slow != fast){
                slow = slow->next;
                prev = fast;
                fast = fast->next;

            }

            prev->next = NULL;
            return slow;
    }

};

int main(){
    linklist ll;
    ll.pushfront(5);
    ll.pushfront(5);
    ll.pushfront(5);
    ll.pushfront(5);
    ll.pushfront(5);
    ll.createCycle(3);
    ll.cycle();

ll.print();
return 0;
}