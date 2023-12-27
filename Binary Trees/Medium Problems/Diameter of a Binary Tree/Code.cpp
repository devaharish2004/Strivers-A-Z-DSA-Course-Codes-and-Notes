/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int findHeight(TreeNode* root, int& diameter)
    {
        if(root == nullptr) return 0;

        int left = findHeight(root->left, diameter);
        int right = findHeight(root->right, diameter);

        diameter = max(diameter, left+right); //store the answer in the diameter

        return 1 + max(left, right); // return the height of the tree
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        int diameter = 0;
        int height = findHeight(root,diameter);
        return diameter;

    }
};