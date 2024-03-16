/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

int findSum(Node* node)
{
    if(node == nullptr) return 0;

    //post order traversal
    int left = findSum(node->left);
    int right = findSum(node->right);

    if(left == 0 && right == 0) return node->data;

    if(left == -1 || right == -1 || left+right != node->data) return -1;

    return node->data;
}

bool isParentSum(Node *root){
    // Write your code here.
    int ans = findSum(root);
    if(ans == -1)
    {
        return false;
    }
    return true;
}

/*
This code is to check if the BT given satisfies the children sum property : which means that each node other than the leaf nodes has its value equal to the left node's and right node's values.
If we have to convert the BT to satisfy the children sum property, then this code will work :
Before that, this condition is to be considered :
* Any node's value can be incremented by one but cannot be decremented.
What we do in this code is that, we increment the child node's value to node's value if the sum of left and right nodes is less than root node's value .
Else we change the node's value to the sum of its child nodes.
#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

void reorder(node * root) {
  if (root == NULL) return;
  int child = 0;
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }

  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }

  reorder(root -> left);
  reorder(root -> right);

  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}
void changeTree(node * root) {
  reorder(root);
}

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(2);
  root -> left = newNode(35);
  root -> left -> left = newNode(2);
  root -> left -> right = newNode(3);
  root -> right = newNode(10);
  root -> right -> left = newNode(5);
  root -> right -> right = newNode(2);

  changeTree(root);

  return 0;
}
*/