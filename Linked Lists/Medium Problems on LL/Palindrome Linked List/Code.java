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

    ListNode reverseList(ListNode head)
    {
        ListNode pre = null;
        ListNode next = null;
        while(head != null)
        {
            next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;

        ListNode slow = head;
        ListNode fast = head;

        //finding the middle 
        while(fast.next != null && fast.next.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }

        //reversing the second half
        slow.next = reverseList(slow.next);

        //moving slow to the next one
        slow = slow.next;

        //check
        ListNode dummy = head;
        while(slow != null)
        {
            if(slow.val != dummy.val)
            {
                return false;
            }
            dummy = dummy.next;
            slow = slow.next;
        }
        return true;
    }
}