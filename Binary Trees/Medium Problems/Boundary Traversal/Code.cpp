/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

//ANTICLOCKWISE - RECURSIVE

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

bool isLeaf(TreeNode<int>* node)
{
    if(node->left == nullptr && node->right == nullptr) return true;

    return false;
}

void addLeftBoundary(TreeNode<int>* node, vector<int>& ans)
{
    if(node == nullptr || isLeaf(node))
    {
        return;
    }

    ans.push_back(node->data);

    if(node->left)
    {
        addLeftBoundary(node->left, ans);
    }
    else
    {
        addLeftBoundary(node->right, ans);
    }
}

void addRightBoundary(TreeNode<int>* node, vector<int>& ans, vector<int>& tmp)
{
    if(node == nullptr || isLeaf(node))
    {
        return;
    }

    tmp.push_back(node->data);

    if(node->right)
    {
        addRightBoundary(node->right, ans, tmp);
    }
    else
    {
        addRightBoundary(node->left, ans, tmp);
    }
}

void addLeaf(TreeNode<int>* node, vector<int>& ans)
{
    if(isLeaf(node)) 
    {
        ans.push_back(node->data);
        return ;
    }

    if(node->left)
    {
        addLeaf(node->left, ans);
    }

    if(node->right)
    {
        addLeaf(node->right, ans);
    }
   
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int> ans, tmp;
    if(root == nullptr) return ans;
   
    ans.push_back(root->data);

    if(isLeaf(root)) return ans;

    addLeftBoundary(root->left,ans);
    addLeaf(root,ans);
    
    addRightBoundary(root->right,ans, tmp);

    for(int i = tmp.size()-1; i >= 0; i--)
    {
        ans.push_back(tmp[i]);
    }

    return ans;
}


/*
FOR ANTI-CLOCKWISE DIRECTION, traverse the left boundary first, then the leaf nodes and the right boundary in reverse direction.
FOR CLOCKWISE, do the opposite : traverse the right boundary, then the leaf nodes and the left boundary in reverse direction.
THE GIVEN CODE IS RECURSIVE, FOR ITERATIVE CODE REFER TO THE SHEET.
*/