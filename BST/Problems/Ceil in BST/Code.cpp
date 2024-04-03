#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *root, int x){
    // Write your code here.
    BinaryTreeNode<int>* node = root;
    int val = -1;
    while(node != nullptr) {
        if(x <= node->data) {
            val = node->data;
            //go to left to find lesser number with the given condition
            node = node->left;
        }
        else {
            //go to right to find greater numbers
            node = node->right;
        }
    }
    return val;
}

// TC  : O(log2N)