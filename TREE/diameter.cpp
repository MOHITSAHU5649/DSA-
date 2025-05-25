// leetcode 543
// diamerte of the tree which means one node to another node idistance by passing the root or not 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val ){
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

//bog o n
int height( Node* root){
    if(root == NULL) return 0;

    int leftheight = height(root->left);
    int rightheight = height(root->right);
    return max(leftheight, rightheight) +1;
}

//brute force approach
//n square 
int diameter(Node* root){
    if(root== NULL) return 0;

      int leftd = diameter(root->left);
      int rightd = diameter(root->right);
      int currd = height(root->left) + height(root->right);

      return max(currd, max(leftd,rightd));
}

//optimized approach 
int ans = 0;
int heightopti(Node* root){
    if(root == NULL) return 0;

    int lefth = heightopti(root->left);
    int righth = heightopti(root->right);
// here we are storung the ans of the three height from that node 
    ans = max( ans, lefth + righth);
return max(lefth, righth) +1;
}

int diaopti(Node* root){
    heightopti(root);
// no recursive cal in this method 
    return ans;
}

int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);

    cout<<diameter(root)<<endl;
    cout<<diaopti(root); // this is he optimized 

    return 0;
}
