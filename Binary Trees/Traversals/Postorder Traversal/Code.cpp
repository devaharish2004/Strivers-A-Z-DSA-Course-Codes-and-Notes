#include <bits/stdc++.h> 
/*
Following is the structure of Tree Node

class TreeNode 
{
   public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) 
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
*/
void postOrder(TreeNode* root, vector<int>&v)
{
    if(root == nullptr)
    {
        return;
    }
    postOrder(root->left,v);
    postOrder(root->right,v);
    v.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root)
{
    // Write your code here	
    vector<int>v;
    postOrder(root,v);
    return(v);
}
