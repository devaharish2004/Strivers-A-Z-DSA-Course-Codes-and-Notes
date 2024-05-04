/*********************************************************

 Following is the TreeNode structure:

 class TreeNode {
     int data;
     TreeNode left;
     TreeNode right;
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
     BinaryTreeNode(int data, TreeNode left, TreeNode right) {
         this.data = data;
         this.left = left;
         this.right = right;
     }
 };
 ********************************************************/
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
 
class Container {
    int size;
    int smallest;
    int largest;

    Container() {
        this.size = 0;
        this.smallest = Integer.MAX_VALUE;
        this.largest = Integer.MIN_VALUE;
    }

    Container(int size, int smallest, int largest) {
        this.size = size;
        this.smallest = smallest;
        this.largest = largest;
    }
}

public class Code {

    public static Container largestBSTHelper(TreeNode node) {
        //perform a postorder traversal
        //for each node, the largest value in the left subtree and the smallest value in the right subtree is compared with the root node value, to ensure it is a valid BST
        //if the node is null
        if(node == null) {
            return new Container(0, Integer.MAX_VALUE, Integer.MIN_VALUE);
        }

        Container left = largestBSTHelper(node.left);
        Container right = largestBSTHelper(node.right);

        //main code to solve the problem

        if(left.largest < node.data && node.data < right.smallest) {
            //valid BST
            //Math.min() and Math.max() for taking the node's value if both the left and right are null
            return new Container(1 + left.size + right.size, Math.min(node.data, left.smallest), Math.max(node.data, right.largest));
        }
        
        //else it is not a valid BST
        // return a container in such a way that it cannot be used in further recursion calls
        return new Container(Math.max(left.size, right.size), Integer.MIN_VALUE, Integer.MAX_VALUE);

    }
    public static int largestBST(TreeNode root) {
        // Write your code here.
        Container c = largestBSTHelper(root);
        return c.size;
    }
}