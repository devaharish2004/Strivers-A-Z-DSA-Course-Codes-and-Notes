#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

int findLeftHeight(BinaryTreeNode<int>* node) {
    int left = 0;
    while(node) {
        node = node->left;
        left++;
    }
    return left;
}

int findRightHeight(BinaryTreeNode<int>* node) {
    int right = 0;
    while(node) {
        node = node->right;
        right++;
    }
    return right;
}

int countNodes(BinaryTreeNode<int> *root) {
    // Write your code here.
    if(root == nullptr) return 0;

    int leftHeight = findLeftHeight(root);
    int rightHeight = findRightHeight(root);

    if(leftHeight == rightHeight) {
        //means that all the levels are filled, so use the formula to compute the height ( 2 ^ height - 1)
        return (1 << leftHeight) - 1;
    }
    //else calculate for the remaining subtrees
    return 1 + countNodes(root->left) + countNodes(root->right);

}

/* We can use any traversal technique to find the number of nodes in O(N) time.
To further the time complexity, the above technique is used based on the properties of a complete binary tree :
All levels except the last one are completely filled
Last level nodes are as left as possible.
If the left and right height are equal, then the number of nodes is given by the formula - 2^height - 1;
Else, count the current node and go to the left and right subtrees recursively. 
TC : O((logN) * (logN)) //since the height of the tree will not be beyond logN and we will not traverse more than logN times definitely - even for the worst case scenario
one logN for finding the height and another for traversing.
SC : O(logN) - to store the logN nodes in the recursion stack.
*/