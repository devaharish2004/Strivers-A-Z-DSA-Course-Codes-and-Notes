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
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    
}
class Code {
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    public boolean isValidBST(TreeNode root, long low, long high) {
        if(root == null) return true;
        if(root.val <= low || root.val >= high) return false;
        return isValidBST(root.left, low, root.val) && isValidBST(root.right, root.val, high);
    }
}

//TC : O(N)
// SC : O(1) (without additional O(N) recursive stack space)