//Right view
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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;
        if(root == nullptr) return ans;
        //map to store nodes for each level
        map<int,int> mp;

        //level order - node, level
        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});

        while(!q.empty())
        {
            auto p = q.front();
            TreeNode* node = p.first;
            int level = p.second;
            q.pop();

            mp[level] = node->val;

            if(node->left)
            {
                q.push({node->left, level+1});
            }
            if(node->right)
            {
                q.push({node->right, level+1});
            }
        }

        for(auto it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;

    }
};

/*
Similar to top and bottom view, but this time we check in terms of levels rather than checking verticals.
Based on taking whether the left as first or right as first, we can change the code to work for both right and left view.
RECURSIVE SOLUTION :
func(node, level, ans)  //for right side - Root, Right, Left ; for left side - root, left, right
{
    if(node == null) return ;

    if(level == ans.size()) //indicates a new level
    {
        ans.push_back(node->val);
    }

    func(node->right, level+1, ans);
    func(node->left, level+1, ans);
}

//Recursive solution is preferred in interviews since the code is crisp and clean.
*/