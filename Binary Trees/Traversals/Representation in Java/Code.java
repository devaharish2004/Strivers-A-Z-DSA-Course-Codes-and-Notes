/****************************************************************

 Following is the class structure of the Node class:

 class Node {
     public int data;
     public Node left;
     public Node right;

     Node()
     {
         this.data = 0;
         this.left = null;
         this.right = null;
     }

     Node(int data)
     {
         this.data = data;
         this.left = null;
         this.right = null;
     }

     Node(int data, Node left, Node right)
     {
         this.data = data;
         this.left = left;
         this.right = right;
     }
 }

 *****************************************************************/
public class Code {
    public static Node createTree(int []arr){
        // Write your code here.
        Node root = new Node(arr[0]);
        root.left = new Node(arr[1]);
        root.right = new Node(arr[2]);
        root.left.left = new Node(arr[3]);
        root.left.right = new Node(arr[4]);
        root.right.left = new Node(arr[5]);
        root.right.right = new Node(arr[6]);
        return(root);
    }
}