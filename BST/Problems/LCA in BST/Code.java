/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

 class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
 }

 public class Code {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root == null) return null;
        int val = root.val;
        //both of them are right
        if(val < p.val && val < q.val) {
            return lowestCommonAncestor(root.right, p, q);
        }   
        //both of them are left
        if(val > p.val && val > q.val) {
            return lowestCommonAncestor(root.left, p, q);
        }
        return root;
    }
}

//TC : O(H)
// SC : O(1)