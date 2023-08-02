/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 * };
 *
 *************************************************************************/

int lengthOfLoop(Node *head) {
    // Write your code here
    if(head == nullptr || head->next == nullptr) return 0;
    //slow and fast pointers
    Node* slow = head;
    Node* fast = head;
    Node* entry = head;
    int flag = 0;
    while(fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
        {
            flag = 1;
            break;
        }
    }
    if(flag) //there is a cycle
    {
        int len = 0;
        do
        {
            fast = fast->next;
            len++;
        } while(slow != fast);

        return len;
    }

    return 0;
}
