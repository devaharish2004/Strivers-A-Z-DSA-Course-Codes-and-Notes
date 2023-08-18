/****************************************************************

 Following is the class structure of the Node class:

 class Node {
     public int data;
     public Node next;

     Node()
     {
         this.data = 0;
         this.next = null;
     }
     Node(int data)
     {
         this.data = data;
         this.next = null;
     }
     Node(int data, Node next)
     {
         this.data = data;
         this.next = next;
     }
 }

 *****************************************************************/

public class Solution {
    public static int findIntersection(Node firstHead, Node secondHead) {
        //Write your code here
        if(firstHead == null || secondHead == null)
        {
            return 0;
        }
        Node a = firstHead;
        Node b = secondHead;

        while(a != b)
        {
            a = a == null ? secondHead : a.next;
            b = b == null ? firstHead : b.next;
        }

        return a!= null?a.data:0;
    }
}