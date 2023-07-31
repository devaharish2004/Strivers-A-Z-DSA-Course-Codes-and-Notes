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
    vector<int> postorderTraversal(TreeNode* root) 
    {
         vector<int>v;
        if(root == nullptr) return v;
        stack<TreeNode*>s1,s2;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode* value = s1.top();
            s2.push(value);
            s1.pop();
            if(value && value->left != NULL) s1.push(value->left);
            if(value && value->right != NULL) s1.push(value->right);
        }
       
        while(!s2.empty())
        {
            TreeNode* value = s2.top();
            v.push_back(value->val);
            s2.pop();
        }
        return(v);
    }
};