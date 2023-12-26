#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * 
 */

//Code 1 : Naive Brute Force Approach

struct TreeNode {
    
     int val;

    TreeNode *left;

    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 class Solution {
public:

    int depth(TreeNode* root)
    {
        if(root == nullptr) return 0;
        
        int left = depth(root->left);
        int right = depth(root->right);

        return 1 + max(left, right);

        
    }
    
    bool isBalanced(TreeNode* root) {
        
        if(root == nullptr) return true;

        int left = depth(root->left);

        int right = depth(root->right);

        if(abs(left-right) > 1)
        {
            return false;
        }

        bool left_check = isBalanced(root->left);
        bool right_check = isBalanced(root -> right);

        if(!left_check || !right_check)
        {
            return false;
        }

        return true;

    }
};

//Code 2 : Optimized Solution

int depth(TreeNode<int>* root)
{
    if(root == nullptr) return 0;

    int left = depth(root->left);
    int right = depth(root->right);

    if(left == -1 || right == -1) return -1;
    if(abs(left-right) > 1) return -1;

    return 1 + max(left,right);
}


bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    return depth(root) != -1;
}

