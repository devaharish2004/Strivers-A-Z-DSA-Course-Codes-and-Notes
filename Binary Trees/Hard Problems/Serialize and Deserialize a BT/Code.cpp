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

string serializeTree(TreeNode<int> *root) {
    //    Write your code here for serializing the tree
    if(root == nullptr) return "";
    string s = "";
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();
        if(node == nullptr) {
            s.append("-1 ");
        }
        else {
            s.append(to_string(node->data) + ' ');
        }
        if(node != nullptr) {
            q.push(node->left);
            q.push(node->right);
        }
        
    }

    return s;

}

TreeNode<int>* deserializeTree(string &serialized) {
    //    Write your code here for deserializing the tree
    if(serialized.size() == 0) return nullptr;
    stringstream ss(serialized);
    queue<TreeNode<int>*> q;
    string s;
    getline(ss,s, ' ');
    TreeNode<int>* root = new TreeNode(stoi(s));
    q.push(root);
    while(!q.empty()) {
        TreeNode<int>* node = q.front();
        q.pop();

        getline(ss, s, ' ');

        if(s == "-1") {
            node->left = nullptr;
        }
        else {
            TreeNode<int>* leftNode = new TreeNode(stoi(s));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(ss, s, ' ');

        if(s == "-1") {
            node->right = nullptr;
        }
        else {
            TreeNode<int>* rightNode = new TreeNode(stoi(s));
            node->right = rightNode;
            q.push(rightNode);
        }

    }

    return root;

}


// TC : O(N)
// SC : O(N)