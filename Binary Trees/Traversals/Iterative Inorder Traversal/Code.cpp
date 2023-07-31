#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*>st;
    vector<int>v;
    TreeNode* node = root;
    while(true)
    {
        if(node != NULL)
        {
            st.push(node);
            node = node->left;            
        }
        else
        {
            if(st.empty()) break;
            TreeNode* ref = st.top();
            v.push_back(ref->data);
            st.pop();
            node = ref->right;
        }
    }
    return(v);
}