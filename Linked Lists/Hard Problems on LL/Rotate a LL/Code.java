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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null) return head;
        //finding the length and iterating till the last node
        ListNode curr = head;
        int length = 1;
        while(curr.next != null)
        {
            curr = curr.next;
            length++;
        }
        //assigning the last node to the first node
        curr.next = head;
        //iterating till length-k times
        k = k%length;
        int count = 1;
        while(count <= length-k)
        {
            curr = curr.next;
            count++;
        }
        //final steps
        head = curr.next;
        curr.next = null;

        return head;
    }
}