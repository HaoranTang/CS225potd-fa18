#include "TreeNode.h"
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
stack<TreeNode*>s;
queue<TreeNode*>q;
int height(TreeNode* croot){
    if(croot == NULL)
        return -1;
    int leftHeight = height(croot -> left_);
    int rightHeight = height(croot -> right_);
    return max(leftHeight, rightHeight) + 1;
}

bool isHeightBalanced(TreeNode* root) {
    if (root==NULL)
        return true;
    int left = height(root -> left_);
    int right = height(root -> right_);
    return abs(left-right)<=1 && isHeightBalanced(root->left_) && isHeightBalanced(root->right_);
}

TreeNode* findLastUnbalanced(TreeNode* root) {
    if(root == NULL)
        return root;
    q.push(root);
    if (!isHeightBalanced(root))
        s.push(root);
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        
        if(node->left_ != NULL){
            q.push(node->left_);
            if(!isHeightBalanced(node->left_)){
                s.push(node->left_);
            }
        }
        if(node->right_ != NULL){
            q.push(node->right_);
            if(!isHeightBalanced(node->right_)){
                s.push(node->right_);
            }
        }
    }
    if(s.empty()){
        return NULL;
    }
    else{
        return s.top();
    }
}


void rightRotate(TreeNode* root) {
    // Your code here
    TreeNode* temp = root->left_;
    temp->parent_ = root->parent_;
    root->left_ = temp->right_;
    if (temp->right_)
        temp->right_->parent_ = root;
    temp->right_ = root;
    root->parent_ = temp;
    root = temp;
}


void leftRotate(TreeNode* root) {
    // your code here
    TreeNode *temp = root->right_;
    temp->parent_ = root->parent_;
    root->right_ = temp->left_;
    if(temp->left_)
        temp->left_->parent_ = root;
    temp->left_ = root;
    root->parent_ = temp;
    root = temp;
}



void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}

