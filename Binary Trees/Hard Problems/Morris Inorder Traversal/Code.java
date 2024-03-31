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
import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Code {
    public List<Integer> inorderTraversal(TreeNode root) {
        // Morris Traversal
        List<Integer> list = new ArrayList<>();
        TreeNode curr = root;
        while(curr != null) {
            //case 1 : if the left is null
            if(curr.left == null) {
                list.add(curr.val);
                curr = curr.right;
            }
            else {
                //find the last node in the left subtree and form the thread
                // if the thread is already there, then we have traversed the left, go to the right
                TreeNode last = curr.left;
                while(last.right != null && last.right != curr) {
                    last = last.right;
                }
                // two choices are here 
                //if there is no thread, and if there is a thread
                if(last.right == null) {
                    //no thread, point to cur and move to cur
                    last.right = curr;
                    // go to the left subtree to find the last nodes
                    curr = curr.left;
                }
                //if the thread is present already
                if(last.right == curr) {
                    //make the last node's right to null to avoid conflicts
                    last.right = null;
                    list.add(curr.val);
                    curr = curr.right;
                }
            }
        }
        return list;
    }
}