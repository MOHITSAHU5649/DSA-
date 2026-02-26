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
Node* buildTree(vector<int> nodes){

    index++;
    if(nodes[index] == -1) return NULL;
    Node* root = new Node(nodes[index]);
    root->left = buildTree(nodes);
    root->right = buildTree(nodes);

    return root;
}   

Node* buildT(vector<int>& preorder, vector<int> &inorder){
    int preidex =0;
    return helper(preorder,inorder,preidex,0,inorder.size()-1);
}

Node* helper(vector<int>& preorder, vector<int> & inorder, int &pre, int str, int end)
{
    if(str > end) return NULL;

    Node* root = new Node(preorder[pre]);
    pre++;

    int ind = search(inorder, str, end, root->data);
    root->left = helper(preorder,inorder,pre,str,ind-1);
    root->right = helper(preorder,inorder,pre,ind+1,end);
    return root;
}

int search(vector<int> &inorder, int str, int end, int val){
    for(int i=str; i<=end; i++){
        if(inorder[i] == val) return i;
    }
    return -1;
}


int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int> inorder = {2,1,4,3,5};
    Node* root = buildT(preorder,inorder);

    return 0;
}