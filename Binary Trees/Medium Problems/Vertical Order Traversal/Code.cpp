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

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //data structure to store the result
        // here we use multiset to take duplicate values also in the same level 
        //vertical, level, multiset
        //when two nodes are in the same vertical and same level, we should sort them in order.
        map<int, map<int, multiset<int>>> nodes;

        //queue for level order traversal
        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0,0}});

        //level order traversal - can use inorder, postorder or preorder
        while(!q.empty())
        {
            auto el = q.front();
            TreeNode* node = el.first;
            int vertical = el.second.first;
            int level = el.second.second;
            q.pop();

            //store it in the multiset
            nodes[vertical][level].insert(node->val);

            if(node->left)
            {
                q.push({node->left, {vertical-1, level+1}});
            }
            if(node->right)
            {
                q.push({node->right, {vertical+1, level+1}});
            }
        }

        //take the result from the nodes
        vector<vector<int>> ans;
        for(auto mp : nodes)
        {
            vector<int> col;
            for(auto q : mp.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        } 
        return ans;
    }
};

// TC : O(N * logN) - using map (logN) for every node (O(n))
// SC : O(N) + O(N) ~ O(N) - at max can store N nodes