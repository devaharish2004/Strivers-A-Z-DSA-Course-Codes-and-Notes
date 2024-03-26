#include <bits/stdc++.h>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
 TreeNode<int>* createBinaryTree( int postStart, int postEnd, vector<int>&postOrder, int inStart, int inEnd, vector<int>&inOrder, map<int,int>& mp) {

      if( postStart > postEnd || inStart > inEnd) {
          return nullptr;
      }
     TreeNode<int>* node = new TreeNode<int>( postOrder[ postEnd ] );
     int ind = mp[ node -> data ]; // find the index
     int nElem = inEnd - ind;
     node -> right = createBinaryTree( postEnd - nElem, postEnd - 1, postOrder, ind + 1, inEnd, inOrder, mp);
     node -> left = createBinaryTree( postStart, postEnd - nElem - 1, postOrder, inStart, ind - 1, inOrder, mp);
     return node;
 }

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
	// Write your code here.
     int postStart = 0;
     int postEnd = postOrder.size()-1;
     int inStart = 0;
     int inEnd = inOrder.size()-1;

     map<int,int> mp;
     for(int i = 0; i < inOrder.size(); i++) {
          mp[inOrder[i]] = i;
     }
     TreeNode<int>* root = createBinaryTree(postStart, postEnd, postOrder, inStart, inEnd, inOrder, mp);
     return root;
}

// TC : O(N)
// SC : O(N)