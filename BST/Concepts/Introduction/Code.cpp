bool isValidBST(vector<int> &order){
    // Write your code here.
    for(int i = 1; i < order.size(); i++) {
        if(order[i-1] >= order[i]) {
            return false;
        }
    }
    return true;
}


// The above code will check if the given vector represents a valid inorder traversal of a BST
// BST is used for :
// The height will be always O(log2(N)) or less in most cases
// Searching takes O(log2N), but in BT it will take O(N)