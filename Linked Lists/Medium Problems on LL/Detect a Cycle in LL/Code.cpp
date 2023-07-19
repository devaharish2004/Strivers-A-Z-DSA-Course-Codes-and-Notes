#include<bits/stdc++.h>
/****************************************************************

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


*****************************************************************/

bool detectCycle(Node *head)
{
	//	Write your code here
    //check if there is no LL or only one element
    if(head->next == nullptr || head == nullptr) return(false);
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr) //if the fast does not point to last and second last node 
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return(true);
    }
    return(false);
    
}