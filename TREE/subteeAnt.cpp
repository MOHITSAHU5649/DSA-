// leetocde 572 
// to check that the subtree is present in the another trree or not 

// after getting the root as same then check for the left and the right node 
// bool isIdentical(TreeNode* p, TreeNode* q){
//         if(p == NULL || q == NULL){
//             return p == q;
//         }

//         return p->val == q->val && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
//     }

//     bool isSubtree(TreeNode* root, TreeNode* subRoot) { // just find the root, that from ehwere checking for left and right can be sttarte
//          if(root == NULL || subRoot == NULL){
//             return root == subRoot;
//          }
//             if(root->val == subRoot->val && isIdentical(root,subRoot)){
//                 return true;
//             }

//             return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
         