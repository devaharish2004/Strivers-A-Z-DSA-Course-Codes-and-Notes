public class Code {
    public static boolean searchInBST(BinaryTreeNode root, int x) {
        // Write your code here.
        if(root == null) return false;
        if(root.data == x) {
            return true;
        }
        else if(x < root.data) {
            return searchInBST(root.left, x);
        }
        else {
            return searchInBST(root.right, x);
        }
    }    
}
class BinaryTreeNode {
    int data;
    BinaryTreeNode left;
    BinaryTreeNode right;
    BinaryTreeNode() {
        this.data = 0;
        this.left = null;
        this.right = null;
    }
    BinaryTreeNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
    BinaryTreeNode(int data, BinaryTreeNode left, BinaryTreeNode right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
};

//Iterative in C++

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
// class Solution {
//     public:
//         TreeNode* searchBST(TreeNode* root, int val) {
//             if(root == nullptr) return nullptr;
//             TreeNode* temp = root;
//             while(temp != nullptr)
//             {
//                 if(val < temp->val)
//                 {
//                     temp = temp->left;
//                 }
//                 else if(val > temp->val)
//                 {
//                     temp = temp->right;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//             return temp;
//         }
//     };