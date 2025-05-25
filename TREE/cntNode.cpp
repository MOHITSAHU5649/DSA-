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
static int index  = -1;
Node* buildtree(vector<int> preorder){
    index++;

    if(preorder[index] == -1) return NULL;

    Node* root = new Node(preorder[index]);
    root->left = buildtree(preorder);
    root->right = buildtree(preorder);
        return root;
}

int count(Node* root){
    if(root == NULL) return 0;

    int leftcoutn = count(root->left);
    int rightcoutn = count(root->right);
    return leftcoutn + rightcoutn + 1;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildtree(preorder);

    cout<<count(root);
    
    return 0;
}