/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// APPROACH 1 : TO NAIVELY CONSTRUCT THE TREE BY INSERTING NODES
//APPROACH 2 : TO SORT THE GIVEN PREORDER ARRAY TO GIVE ITS INORDER TRAVERSAL AND USING THESE TO CONSTRUCT THE TREE ( REFER TO BT SERIES )
// APPROACH 3 : 
// TC : O(N) + O(N)
// SC : O(1) - WITHOUT RECURSIVE STACK SPACE
class Code {
    public static TreeNode solve(int[] preOrder,int startIndex, int endIndex) {

        if(startIndex > endIndex) {
            return null;
        }

        //create a root node
        int nodeVal = preOrder[startIndex];
        TreeNode node = new TreeNode(nodeVal);
        //iterate in the array to find the index that divides left and right
        int splitIndex = startIndex;
        for(int i = startIndex+1; i <= endIndex; i++) {
            if(preOrder[i] <= nodeVal) {
                splitIndex = i;
            }
            else {
                break;
            }
        }
        
        node.left = solve(preOrder, startIndex+1, splitIndex);
        node.right = solve(preOrder, splitIndex + 1, endIndex);

        return node;
    }

    public TreeNode bstFromPreorder(int[] preorder) {
        if(preorder.length == 0) return null;

        int startIndex = 0;
        int endIndex = preorder.length - 1;
        TreeNode root = solve(preorder, startIndex, endIndex);
        return root;
    }
}