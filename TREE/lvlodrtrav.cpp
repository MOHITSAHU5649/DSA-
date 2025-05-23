#include<iostream>
#include<vector>
#include<queue>
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
Node* pre(vector<int> preorder){
    index++;

    if(preorder[index] == -1) return NULL;

    Node* root = new Node(preorder[index]);
    root->left = pre(preorder);
    root->right = pre(preorder);

    return root; 
}

void levelorder(Node* root){ // first way that the ouput will be in a one line 
    queue<Node*> q;

    q.push(root);
    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        cout<<curr->data<<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

//seconfd way that the output will be in a next line if the level of the tree decrease 
void levelorder2(Node* root){ 
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
                break;
            }
        }
        cout<<curr->data<<" ";

        if(curr->left != NULL){
            q.push(curr->left);
        }

        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}


int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};


Node* root = pre(preorder);
levelorder(root);
levelorder2(root);

    return 0;}