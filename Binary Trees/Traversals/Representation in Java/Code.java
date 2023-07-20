/*
    Time complexity: O(N)
    Space complexity: O(N)

    Where 'N' is the number of elements in the array 'arr'
*/
Node* createTree(vector<int>& arr)
{
    queue<Node*> q;
    // Create the root node with the value from the first element of the array
    Node* root = new Node(arr[0]);
    q.push(root);

    int i = 0;

    // Construct the binary tree using the remaining elements of the array
    while (!q.empty() && i < 3) {
        Node* t = q.front();
        q.pop();

        // Create the left child node with the value from the corresponding index in the array
        Node* left = new Node(arr[2 * i + 1]);
        t->left = left;
        q.push(left);

        // Create the right child node with the value from the corresponding index in the array
        Node* right = new Node(arr[2 * i + 2]);
        t->right = right;
        q.push(right);
        i++;
    }
    return root;
}
 
