/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(T x) : data(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
    };

************************************************************/
void inorder(TreeNode<int>*root,vector<int>&ans){

if(root == NULL){

return;

}

inorder(root->left,ans);

ans.push_back(root->data);

inorder(root->right,ans);

}

int kthSmallest(TreeNode<int> *root, int k)

{

// Write the code here.

vector<int>ans;

inorder(root,ans);

return ans[k-1];

}