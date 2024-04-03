/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left, *right;
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(T x) : val(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
    };


************************************************************/

// RECURSIVE SOLUTION
TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    // Write your code here.
    if(root == nullptr) {
        TreeNode<int>* newNode = new TreeNode<int>(val);
        return newNode;
    }
    else {
        if(val < root->val) {
            root->left = insertionInBST(root->left, val);
        }
        else {
            root->right = insertionInBST(root->right, val);
        }
        return root;
    }
}