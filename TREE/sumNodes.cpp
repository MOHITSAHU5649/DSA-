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

static int index =-1;
Node* buildtree(vector<int> preorder){
    index++;
    if(preorder[index] == -1) return NULL;

    Node* root = new Node(preorder[index]);
    root->left = buildtree(preorder); 
    root->right = buildtree(preorder); 
return root;

}

int sum(Node* root){
    if(root == NULL) return 0;

    int leftsum = sum(root->left);
    int rightsum = sum(root->right);
    return leftsum + rightsum + root->data;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildtree(preorder);

    cout<<sum(root);
    return 0;
}