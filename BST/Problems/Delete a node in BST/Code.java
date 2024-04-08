/*********************************************************

 Following is the BinaryTreeNode structure:

 class BinaryTreeNode<T> {
     T data;
     BinaryTreeNode<T> left;
     BinaryTreeNode<T> right;
     BinaryTreeNode() {
         this.data = null;
         this.left = null;
         this.right = null;
     }
     BinaryTreeNode(T data) {
         this.data = data;
         this.left = null;
         this.right = null;
     }
     BinaryTreeNode(T data, BinaryTreeNode<T> left, BinaryTreeNode<T> right) {
         this.data = data;
         this.left = left;
         this.right = right;
     }
 };
 ********************************************************/
class BinaryTreeNode<T> {
    T data;
    BinaryTreeNode<T> left;
    BinaryTreeNode<T> right;
    BinaryTreeNode() {
        this.data = null;
        this.left = null;
        this.right = null;
    }
    BinaryTreeNode(T data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
    BinaryTreeNode(T data, BinaryTreeNode<T> left, BinaryTreeNode<T> right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
};

 public class Code {
    public static BinaryTreeNode<Integer> deleteNode(BinaryTreeNode<Integer> root, int key) {
        // Write your code here.
        if(root == null) {
            return null;
        }

        if(root.data == key) {
            return modifyBinaryTree(root);
        }

        BinaryTreeNode<Integer> node = root;

        while(node != null) {
            //to search in left subtree
            if(key <= node.data) {
                //check if the left node is the node you have to delete
                if(node.left != null && node.left.data == key) {
                    node.left = modifyBinaryTree(node.left);
                    break;
                }
                //if the left node is not the node
                else {
                    node = node.left;
                }
            }
            //to search in right subtree
            else {
                //check if the right node is the deleting node
                if(node.right != null && node.right.data == key) {
                    node.right = modifyBinaryTree(node.right);
                    break;
                }
                //the right node is not the node to be deleted
                else {
                    node = node.right;
                }
            }
        }
        return root;
    }

    static BinaryTreeNode<Integer> modifyBinaryTree(BinaryTreeNode<Integer> node) {
        if(node.left == null) {
            return node.right;
        }
        if(node.right == null) {
            return node.left;
        } 
        //both left and right have nodes
        //two approaches can be used
        // attaching the left subtree first and attaching the right subtree to the right of the left subtree
        //find the last node of the left subtree
        BinaryTreeNode<Integer> lastNode = findLastNode(node.left);
        //attach the right subtree to the lastNode's right
        lastNode.right = node.right;
        //attach the left subtree to the root
        return node.left;
    }

    static BinaryTreeNode<Integer> findLastNode(BinaryTreeNode<Integer> node) {
        while(node.right != null) {
            node = node.right;
        }
        return node;
    }
}

// TC : O(height of the tree)