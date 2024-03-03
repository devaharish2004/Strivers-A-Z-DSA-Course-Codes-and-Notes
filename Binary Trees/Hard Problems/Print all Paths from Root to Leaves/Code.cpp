#include <bits/stdc++.h>
using namespace std;
/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/

void traverse(BinaryTreeNode<int>* node, vector<int>&ref, vector<string>&ans) {
    if(node == nullptr) return;
    ref.push_back(node->data);
    //check if this is a leaf node
    if(node->left == nullptr && node->right == nullptr) {
        //get the elements from ref and push them to ans
        string s = "";
        for(int x : ref) {
            s += to_string(x) + " ";
        }
        ans.push_back(s);
    }
    traverse(node->left, ref, ans);
    traverse(node->right, ref, ans);
    ref.pop_back();
    return ;
}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    // Write your code here.
    vector<string> ans;
    if(root == nullptr) return ans;
    vector<int>ref;
    traverse(root, ref, ans);
    return ans;
}

//TC : O(N)
//SC : O(H)

/*
TO PRINT A PATH FROM THE ROOT TO THE GIVEN LEAF NODE, THE SAME APPROACH IS FOLLOWED BUT RETURN TRUE IF THE LEAF NODE IS FOUND, ELSE RETURN FALSE. 
IF FALSE IS RETURNED, CHECK FOR OTHER PATHS, ELSE RETURN TRUE TILL THE LAST AND PRINT THE PATH.
*/