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
    TreeNode() {}
    TreeNode(int val) {this.val = val;}
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Code {
    
    private TreeNode prev;
    private TreeNode first;
    private TreeNode middle;
    private TreeNode last;

    public void inorder(TreeNode root) {
        if(root == null) return ;
        inorder(root.left);
        //main logic for marking the swapped nodes
        if(prev != null && root.val < prev.val) {
            if(first == null) {
                //first violation
                first = prev;
                middle = root;
            }
            else {
                //second violation
                last = root;
            }
        }
        prev = root;
        inorder(root.right);
    }

    public void recoverTree(TreeNode root) {
        first = middle = last = null;
        prev = new TreeNode(Integer.MIN_VALUE);
        inorder(root);
        //first and middle are the only ones
        if(last == null) {
            //swap the values from the first and the middle elements
            int temp = first.val;
            first.val = middle.val;
            middle.val = temp;
        }
        else {
            //swap the values from the first and the last elements
            int temp = first.val;
            first.val = last.val;
            last.val = temp;
        }
    }
}