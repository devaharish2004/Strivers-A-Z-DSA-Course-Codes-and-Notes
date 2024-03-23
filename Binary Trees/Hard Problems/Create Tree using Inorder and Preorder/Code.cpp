/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

TreeNode<int>* constructBinaryTree( vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& mp) {

    if(preStart > preEnd || inStart > inEnd) return nullptr;
    
    TreeNode<int>* node = new TreeNode<int>(preorder[preStart]);  //create a new node using the preorder

    //find the index of the node in the inorder
    int ind = mp[node->data];
    //find the no of elements to left of the node in inorder - this is enough to find the remaining no of elements
    int noOfElements = ind - inStart;
    //call  recursively for left and right
    node->left = constructBinaryTree(preorder, preStart+1, preStart + noOfElements, inorder, inStart, ind-1, mp);
    node-> right = constructBinaryTree(preorder, preStart + noOfElements + 1, preEnd, inorder, ind+1, inEnd, mp);

    return node;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int preStart = 0;
    int preEnd = preorder.size() - 1;
    int inStart = 0;
    int inEnd = inorder.size() - 1;

    map<int, int> mp; //Since we do not consider duplicate nodes. If there are duplicate nodes, we can store TreeNode<int>*
    //store the inorder elements and indices in a separate map for easy lookup
    for(int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }

    return constructBinaryTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);

}