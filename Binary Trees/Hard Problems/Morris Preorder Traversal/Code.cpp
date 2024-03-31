
vector<int> preOrder(TreeNode<int> * root){
    // Write your code here.
	vector<int> v;
	TreeNode<int>* curr = root;
	while(curr != nullptr) {
		if(curr -> left == nullptr) {
			v.push_back(curr->data);
			curr = curr -> right;
		}
		else {
			TreeNode<int>* last = curr -> left;
			while( last->right && last -> right != curr ) {
				last = last -> right;
			}

			if( last -> right == nullptr ) {
				//form the thread and print the curr value
				last -> right = curr;
				v.push_back(curr->data);
				// move the curr to the left
				curr = curr -> left;
			}
			
			if( last -> right == curr ) {
				//remove the thread and move to the right
				last -> right = nullptr;
				curr = curr -> right;
			}
		}
	}
	return v;
}
