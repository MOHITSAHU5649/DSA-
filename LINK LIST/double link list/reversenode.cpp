//this is leetcode 25 reverse bnodes 
#include <iostream>
using namespace std;

//int his we have to reverse the number of nodes as in k , fior this we have to swap the addres of each node 
//the second part is bti complex as we are incerasint the temp to next node because if the k is 2 then then understand i seay but as <2 then became comples 

// class Solution {
//     public:
//         ListNode* reverseKGroup(ListNode* head, int k) {
//             ListNode* temp = head;
//             int count =0;
//             while(count<k){
//                 if(temp ==NULL){
//                     return head;
//                 }
//                 temp= temp->next;
//                 count++;
//             }
    
//             ListNode* prevNode = reverseKGroup(temp, k);
//                 temp = head; count =0;
    
//                 while(count<k){
//                     ListNode* next = temp->next;
//                     temp->next = prevNode;
    
//                     prevNode = temp;
//                     temp = next;
    
//                     count++;
//                 } 
    
//             return prevNode;
//         }
//     };