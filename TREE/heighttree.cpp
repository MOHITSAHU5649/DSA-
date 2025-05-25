// height of the binary tree 

#include<iostream>
#include<vector>
using namespace std;

// node class is created
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

// build the tree 
static int index =-1; 
Node* buildTree(vector<int> nodes){
    index++;
    if(nodes[index] == -1) return NULL; 
    Node* root = new Node(nodes[index]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes); 

        return root;
    }


// find the height
int height (Node* root){
    if(root == NULL) return 0;

    int leftidx = height(root->left);
    int rightidx = height(root->right);
    return max(leftidx,rightidx) +1;
} 


// main to call the function
int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    cout<<height(root);
    return 0;
}


 