#include<iostream>
#include<vector>
#include<queue>
#include<map>
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
Node* buildTree(vector<int> &preorder){
    index++;
    if(preorder[index] == -1) return NULL;
    Node* root = new Node(preorder[index]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;
}

void topview(Node* root){
    if(root == NULL) return;
    map<int,int> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        Node* curr = {q.front().first};
        int currhd = {q.front().second};
        q.pop();
        
        if(mp.find(currhd) == mp.end()){
            mp[currhd] = curr->data;
        }
        if(curr->left) q.push({curr->left,currhd-1});
        if(curr->right) q.push({curr->right,currhd+1});
    }
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<<it->second<<" ";
    }
}

void kthlevel(Node* root, int k){
    if(root == NULL) return;
    if(k ==1){
        cout<<root->data<<" ";
        return;
    }
    kthlevel(root->left,k-1);
    kthlevel(root->right,k-1);
}

int main(){
vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
Node* root = buildTree(preorder);
    return 0;
}