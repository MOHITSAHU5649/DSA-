//leetcode 100 
// identical tree thta the two tree are same or not 
#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

static int index = -1;
Node* buildTree(vector<int> preorder){
    index++;

    if(preorder[index] == -1) return NULL;
    Node* root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}


// thisis for tio check the two tree are same or not for this we required two tree to check thererfore create two tree to executer this  

// bool isSameTree(TreeNode* p, TreeNode* q) {  
//         if(p == NULL || q == NULL){
//             return p == q;
//         }

//         bool isLeft = isSameTree(p->left, q->left);
//         bool isRight = isSameTree(p->right, q->right);

//         return isLeft && isRight && p->val == q->val;
//     }

int main(){
vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node* root = buildTree(preorder);

    return 0;
}