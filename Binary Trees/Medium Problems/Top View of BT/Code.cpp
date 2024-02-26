#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    // taking only the first node from all the vertical lines
    // map - vertical, topNode
    map<int,int> mp;
    
    //level order
    queue<pair<TreeNode<int>*,int>> q;

    q.push({root, 0});

    while(!q.empty())
    {
        auto p = q.front();
        TreeNode<int>* node = p.first;
        int vertical = p.second;
        q.pop();

        if(mp[vertical] == 0)
        {
            mp[vertical] = node->data;
        }

        if(node->left != nullptr)
        {
            q.push({node->left, vertical-1});
        }

        if(node->right != nullptr)
        {
            q.push({node->right, vertical+1});
        }
    }

    vector<int> ans;

    for(auto it : mp)
    {
        //cout << it.first << " " << it.second << endl;
        ans.push_back(it.second);
    }

    return ans;
}

/*
    DO NOT USE RECURSION TO SOLVE THIS PROBLEM, AS WE SHOULD DETERMINE THE FIRST LEVEL OF EACH VERTICAL IN THE TREE.
    TAKING RECURSION WILL GIVE US WRONG ANSWER.
    TC : O(N * LOGN) = using map takes logN time and doing it for each node takes O(N) time.
    SC : O(N) = atmost all nodes are stored
*/