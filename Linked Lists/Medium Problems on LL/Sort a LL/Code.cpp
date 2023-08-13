/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* getMid(Node* head)
    {
        Node* slow = head;
        Node* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

Node* merge(Node* left, Node* right)
    {
        Node* ans = new Node();
        Node* ref = ans;
        while(left != nullptr && right != nullptr)
        {
            if(left->data <= right->data)
            {
                ans->next = left;
                left = left->next;
            }
            else
            {
                ans->next = right;
                right = right->next;
            }
            ans = ans->next;
        }
        while(left != nullptr)
        {
            ans->next = left;
            left = left->next;
            ans = ans->next;
        }
        while(right != nullptr)
        {
            ans->next = right;
            right = right->next;
            ans = ans->next;
        }
        return(ref->next); //this is because each time we create a new ans Node and attach it at the front, so we cannot return ref explicitly.
    }




Node* sortList(Node* head){
    // Write your code here.
     if(head == nullptr || head->next == nullptr)
        {
            return head;
        }

        //finding the mid
        Node* mid = getMid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = nullptr;

        //recursive calls
        left = sortList(left);
        right = sortList(right);

        //merge
        Node* ans = merge(left,right);
        return ans;
}
