/*
    Problem - 2 Coding Ninjas Variant
    Time complexity: O(N)
    Space complexity: O(N)
    
    Where 'N' is number of nodes in linked list.
*/

Node* segregateEvenOdd(Node* head)
{
    // Create two different linked list 'even' and 'odd'
    Node *oddStart = NULL;
    Node *oddEnd = NULL;
    Node *evenStart = NULL;
    Node *evenEnd = NULL;
    
    // Copy the 'head'
    Node *curr = head; 

    while(curr != NULL)
    {
        int currVal = curr -> data;

        // Current node value is even then add in even linked list
        if(currVal % 2 == 0)
        {
            // If current node is first node of even linked list
            if(evenStart == NULL)
            {
                evenStart = new Node(currVal);
                evenEnd = evenStart;
            }
            
            else
            {
                evenEnd -> next = curr;
                evenEnd = evenEnd -> next;
            }
        }
        
        // Current node value is odd then add in odd linked list
        else
        {
            // If current node is first node of odd linked list
            if(oddStart == NULL)
            {
                oddStart = new Node(currVal);
                oddEnd = oddStart;
            }
            else
            {
                oddEnd -> next = curr;
                oddEnd = oddEnd -> next;
            }
        }
        
        curr = curr -> next;
    }

    // At least one even and odd node present in linked list
    if(oddStart!= NULL and evenStart != NULL)
    {
        evenEnd -> next = oddStart;
        oddEnd -> next = NULL;
        head = evenStart;
    }
        
    return head;
}
