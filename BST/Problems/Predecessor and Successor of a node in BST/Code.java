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

//BRUTE FORCE : STORE THE INORDER TRAVERSAL IN A LIST AND FIND THE PREV AND NEXT ELEMENTS OF THE NODE
// TC : O(N) + O(N) - INORDER + TRAVERSING A LIST
// SC : O(N) + O(N) - STACK SPACE + LIST


//BETTER APPROACH : FIND THE PREDECESSOR AND SUCCESSOR SEPARATELY AS YOU INORDERLY TRAVERSE THE TREE
//TC AND SC ONLY TO FIND EITHER OF PREDECESSOR OR SUCCESSOR
// TC : O(N)
// SC : O(1) - USING MORRIS TRAVERSAL (NO STACK SPACE)


 //OPTIMAL APPROACH 
 import java.util.List;
 import java.util.ArrayList;

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

public class Code {
    public static int findPredecessor(TreeNode root, int key) {
        int predecessor = -1;
        while(root != null) {
            if(root.data < key) {
                predecessor = root.data;
                root = root.right;
            }
            else {
                root = root.left;
            }
        }
        return predecessor;
    }
    public static int findSuccessor(TreeNode root, int key) {
        int successor = -1;
        while(root != null) {
            if(root.data > key) {
                successor = root.data;
                root = root.left;
            }
            else {
                root = root.right;
            }
        }
        return successor;
    }
    public static List<Integer> predecessorSuccessor(TreeNode root, int key) {
        // Write your code here.
        List<Integer> ans = new ArrayList<>();
        int predecessor = findPredecessor(root, key);
        int successor = findSuccessor(root, key);
        ans.add(predecessor);
        ans.add(successor);
        return ans;
    }
 }

 //TC : O(H)
 //SC : O(1)