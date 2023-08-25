/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //step 1 - inserting the clone nodes between the nodes
        Node* temp = head;
        while(temp != nullptr)
        {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        //step 2 - pointing all the random pointers
        temp = head;
        while(temp != nullptr)
        {
            if(temp->random != nullptr)
            {
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        //step 3 - forming all the next pointers and bringing back the lists
        Node* dummy = new Node(0);
        temp = head;
        Node* head_ref = dummy;
        while(temp != nullptr)
        {
            Node* front = temp->next->next;
            dummy->next = temp->next;
            temp->next = front;
            temp = temp->next;
            dummy = dummy->next;
        }

        return head_ref->next;

    }
};