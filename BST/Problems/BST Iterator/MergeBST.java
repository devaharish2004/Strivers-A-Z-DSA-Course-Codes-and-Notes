//BRUTE FORCE WOULD BE TO STORE THE INORDER TRAVERSALS OF BOTH THE ARRAYS AND USING THE MERGE TECHNIQUE IN MERGE SORT TO COMBINE THE BST


//EFFICIENT APPROACH USING BST ITERATOR CONCEPT
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
     TreeNode(int val) {
         this.data = val;
         this.left = null;
         this.right = null;
     }
     TreeNode(int val, TreeNode left, TreeNode right) {
         this.data = val;
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
    TreeNode(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.data = val;
        this.left = left;
        this.right = right;
    }
};

 class BSTIterator {
 
     private Stack<TreeNode> st = new Stack<>();
     public BSTIterator(TreeNode root) {
         pushAllLeft(root);
     }
 
     public int next() {
         TreeNode node = st.pop();
         pushAllLeft(node.right);
         return node.data;
     }
 
     public boolean hasNext() {
         return !st.isEmpty();
     }
 
     public int curr() {
         return st.peek().data;
     }
 
     private void pushAllLeft(TreeNode node) {
         while(node != null) {
             st.push(node);
             node = node.left;
         }
     }
 
 }
 public class MergeBST {
     public static List<Integer> mergeBST(TreeNode root1, TreeNode root2) {
         // Write your code here.
         BSTIterator it1 = new BSTIterator(root1);
         BSTIterator it2 = new BSTIterator(root2);
         List<Integer> list = new ArrayList<>();
         while(it1.hasNext() && it2.hasNext()) {
             int val1 = it1.curr();
             int val2 = it2.curr();
             if(val1 >= val2) {
                 list.add(it2.next());
             }
             else {
                 list.add(it1.next());
             }
         }
 
         while(it1.hasNext()) {
             list.add(it1.next());
         }
 
         while(it2.hasNext()) {
             list.add(it2.next());
         }
 
         return list;
     }
 }

 //TC : O(1) + O(N) + O(M) - Amortized
 // SC : O(H1) + O(H2)