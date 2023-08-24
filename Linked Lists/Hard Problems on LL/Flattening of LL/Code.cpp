/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *merge(Node* a, Node* b) 
{
	//assign two nodes, one to iterate through the LL and another one to track the head
  	Node *temp = new Node(0);
  	Node *res = temp;

	//do what we do in merge step in merge sort
  	while (a != NULL && b != NULL)
	{
		if(a->data <= b->data)
		{
			temp->child = a;
			temp = temp->child;
			a = a->child;
		}
		else
		{
			temp->child = b;
			temp = temp->child;
			b = b->child;
		}
	}
	if(a != NULL)
	{
		temp->child = a; //simply attach the remaining nodes of the LL a
	}
	else if(b != NULL)
	{
		temp->child = b;
	}

	//make every next node of child nodes as null
	//since in question they have given the condition that all the child nodes' next should point to null.
	Node* last = res->child;

	while (last->child) 
	{
		last->next=NULL;
		last = last->child;
	}

	last->next = NULL;

	return res->child; //since res points to dummy node before the head
}

Node *flattenLinkedList(Node *head) {
    // Write your code here
    // using recursion similar to merge sort technique
    if (head == NULL || head->next == NULL)
	{
		return head;
	}
	//recur for list on right side of LL
	head->next = flattenLinkedList(head->next);

	//now merge the LL
	head = merge(head, head->next);

	//return the root so that it will recursively merge with the LL
	return head;
}
