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

Node *findMiddle(Node *head) {
    // Write your code here
    Node* tortoise = head;
    Node* hare = head;
    while(hare != nullptr && hare->next != nullptr) //whenever the conditions fail, we are at the final stage.
    {
        tortoise = tortoise->next;
        hare = hare->next->next;
    }
    return(tortoise);
}

