Node *deleteLast(Node *list){
    // Write your code here
    Node* currNode = list;
    while(currNode->next->next != nullptr)
    {
        currNode = currNode->next;
    }
    currNode->next = nullptr;
    return(list);
}