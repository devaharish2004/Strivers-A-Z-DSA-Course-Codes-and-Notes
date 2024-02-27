#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> bottomView(TreeNode<int> *root) {
  // Write your code here.
    vector<int> ans;
    map<int, int> mp;

    // level order traversal
    queue<pair<TreeNode<int>*, int>> q;

    q.push({root, 0});

    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        
        TreeNode<int>* node = p.first;
        int vertical = p.second;

        mp[vertical] = node->data;

        if(node->left)
        {
          q.push({node->left, vertical - 1});
        }

        if(node->right)
        {
            q.push({node->right, vertical + 1});
        }
    }

    for(auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;

    

}
