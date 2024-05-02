/*********************************************************

 Following is the TreeNode structure:

 class TreeNode {
     int data;
     TreeNode left;
     TreeNode right;
     TreeNode() {
         this.data = 0;
         this.left = null;
         this.right = null;
     }
     TreeNode(int data) {
         this.data = data;
         this.left = null;
         this.right = null;
     }
     TreeNode(int data, TreeNode left, TreeNode right) {
         this.data = data;
         this.left = left;
         this.right = right;
     }
 };
 ********************************************************/ 

import java.util.*;

class TreeNode {
    int data;
    TreeNode left;
    TreeNode right;
    TreeNode() {
        this.data = 0;
        this.left = null;
        this.right = null;
    }
    TreeNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
    TreeNode(int data, TreeNode left, TreeNode right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
};

class BSTIterator {
    private Stack<TreeNode> st = new Stack<>();
    boolean before = true;

    public BSTIterator(TreeNode root, boolean flag) {
        before = flag;
        pushAll(root);
    }

    //function for both next and before
    public int next() {
        TreeNode node = st.pop();
        if(before == true) {
            pushAll(node.left);
        }
        else {
            pushAll(node.right);
        }
        return node.data;
    }

    public boolean hasNext() {
        return !st.isEmpty();
    }

    private void pushAll(TreeNode node) {
        while(node != null) {
            st.push(node);
            if(before == true) {
                node = node.right;
            }
            else {
                node = node.left;
            }
        }
    }
};

public class Code {
    public static boolean pairSumBst(TreeNode root, int k) {
        // Write your code here.
        BSTIterator start = new BSTIterator(root, false);
        BSTIterator end = new BSTIterator(root, true);
        int i = start.next();
        int j = end.next(); //iterator from the last
        boolean flag = false;
        while(i < j) {
            if(i + j == k) {
                flag = true;
                break;
            }
            else if(i + j < k){
                i = start.next();
            }
            else {
                j = end.next();
            }
        }
        return flag;
    }
}