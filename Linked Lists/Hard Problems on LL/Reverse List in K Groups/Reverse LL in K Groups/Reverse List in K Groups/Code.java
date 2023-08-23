/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        
        if(head == null || k == 1) return head;

        ListNode dummy = new ListNode(0,head);

        ListNode curr = dummy;
        ListNode prev = dummy; //keeps track of the last value of the previous group
        ListNode nex = dummy;

        //find the length initially
        int count = 0;
        while(curr.next != null)
        {
            curr = curr.next;
            count++;
        }
        
        while(count >= k)
        {
            curr = prev.next;  //points to the first node of the group
            nex = curr.next;    //points to the next node of curr
            //k-1 iterations are required for reversing the nodes
            for(int i = 1; i < k; i++)
            {
                curr.next = nex.next;
                nex.next = prev.next; // do not write curr as prev.next will change
                prev.next = nex;
                nex = curr.next;
            }
            prev = curr; 
            count -= k;
        }

        return dummy.next;
    }
}