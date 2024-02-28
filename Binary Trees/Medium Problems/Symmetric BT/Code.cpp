/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

bool traverse(TreeNode<int>*node1, TreeNode<int>*node2)
{
    if(node1 == nullptr || node2 == nullptr) return node1 == node2;

    return (node1->data == node2->data) && traverse(node1->left, node2->right) && traverse(node1->right, node2->left);
}

bool isSymmetric(TreeNode<int> *root)
{
    // Write your code here
    return traverse(root, root);

}

/* Just find if the node's left is equal to the second node's right and vice versa.
*/