/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include <bits/stdc++.h>
void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root == nullptr) return;
	stack<BinaryTreeNode<int>*>st;
	st.push(root);
	while(!st.empty())
	{
		BinaryTreeNode<int>* top = st.top();
		st.pop();
		cout << top->data << " ";
		if(top->right != NULL) st.push(top->right);
		if(top->left != NULL) st.push(top->left);
	}

}