// Declaring the class for Tree implementation
class Node {
    int data;
    Node left, right;

    // Constructor
    Node(int item) {
        data = item;
        left = right = null;
    }
}

public class Code {
    // Function for inserting a new node in BST
    static Node newNode(int data) {
        Node node = new Node(data);
        node.left = null;
        node.right = null;
        return node;
    }

    // Function to find floor in BST
    static int findFloor(Node root, int input) {
        int floor = -1;
        while (root != null) {
            if (root.data == input)
                return input;
            else if (root.data < input) {
                floor = root.data;
                root = root.right;
            } else {
                root = root.left;
            }
        }
        return floor;
    }

    public static void main(String[] args) {
        // Driver Code
        Node root = newNode(10);
        root.left = newNode(5);
        root.left.left = newNode(4);
        root.left.right = newNode(7);
        root.left.right.right = newNode(8);
        root.right = newNode(11);

        System.out.println(findFloor(root, 6));
    }
}

// TC : O(log2N)