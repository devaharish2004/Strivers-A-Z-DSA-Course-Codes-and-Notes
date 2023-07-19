/*
    Time Complexity: O(N)
    Space Complexity: O(1),

    Where N is the number of nodes in the doubly linked list
*/
Node* reverseDLL(Node* head)
{
    if(head->next==NULL)
    {
        return head;
    }
    
    Node * curr = head;
    Node * temp = NULL;

    // Traverse the linked list to the end
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev ;
    }

    head = temp->prev ;

    // New head of the modified list is returned
    return head;
}