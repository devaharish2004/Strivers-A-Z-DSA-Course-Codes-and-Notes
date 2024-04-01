// approach 1 - using recursion 
// TC : O(N), SC : O(N)
// import java.util.*;

// class Node {
//   int data;
//   Node  left, right;
//   Node(int data)
//   {
//       this.data=data;
//       left=null;
//       right=null;
//   }
// }

// public class Solution {
//   static Node prev = null;
//     static void flatten(Node  root) {
//       if (root == null) return;

//       flatten(root . right);
//       flatten(root . left);

//       root . right = prev;
//       root . left = null;
//       prev = root;
//     }


// public static void main(String args[]) {

//   Node  root = new Node(1);
//   root . left = new Node(2);
//   root . left . left = new Node(3);
//   root . left . right = new Node(4);
//   root . right = new Node(5);
//   root . right . right = new Node(6);
//   root . right . right . left = new Node(7);
//   flatten(root);
//   while(root.right!=null)
//   {
//       System.out.print(root.data+"->");
//       root=root.right;
//   }
// System.out.print(root.data);
// }
// }

//approach 2 - using stack
// TC : O(N), SC : O(N)
// import java.util.*;

// class Node {
//   int data;
//   Node  left, right;
//   Node(int data)
//   {
//       this.data=data;
//       left=null;
//       right=null;
//   }
// }

// public class Solution {
//   static Node prev = null;
//     static void flatten(Node  root) {
//   if (root == null) return;
//   Stack < Node  > st=new Stack<>();
//   st.push(root);
//   while (!st.isEmpty()) {
//     Node  cur = st.peek();
//     st.pop();

//     if (cur . right != null) {
//       st.push(cur . right);
//     }
//     if (cur . left != null) {
//       st.push(cur . left);
//     }
//     if (!st.isEmpty()) {
//       cur . right = st.peek();
//     }
//     cur . left = null;
//   }

// }



// public static void main(String args[]) {

//   Node  root = new Node(1);
//   root . left = new Node(2);
//   root . left . left = new Node(3);
//   root . left . right = new Node(4);
//   root . right = new Node(5);
//   root . right . right = new Node(6);
//   root . right . right . left = new Node(7);
//   flatten(root);
//   while(root.right!=null)
//   {
//       System.out.print(root.data+"->");
//       root=root.right;
//   }
// System.out.print(root.data);
// }
// }

// approach 3 : Using Morris Traversal
// TC : O(N), SC : O(1)

class Node {
  int data;
  Node  left, right;
  Node(int data)
  {
      this.data=data;
      left=null;
      right=null;
  }
}

public class Code {
  static Node prev = null;
    static void flatten(Node root) {
        Node cur = root;
		while (cur!=null)
		{
			if(cur.left!=null)
			{
				Node pre = cur.left;
				while(pre.right!=null)
				{
					pre = pre.right;
				}
				pre.right = cur.right;
				cur.right = cur.left;
				cur.left = null;
			}
			cur = cur.right;
		}
    }




public static void main(String args[]) {

  Node  root = new Node(1);
  root . left = new Node(2);
  root . left . left = new Node(3);
  root . left . right = new Node(4);
  root . right = new Node(5);
  root . right . right = new Node(6);
  root . right . right . left = new Node(7);
  flatten(root);
  while(root.right!=null)
  {
      System.out.print(root.data+"->");
      root=root.right;
  }
System.out.print(root.data);
}
}