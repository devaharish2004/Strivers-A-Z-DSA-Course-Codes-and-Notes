/*************************************************************

    Following is the Binary Tree node structure for reference:

    class BinaryTreeNode{
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

*************************************************************/

void MarkParents(BinaryTreeNode<int>* root,unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>* > &parents ) {
    //create a queue
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            if(node->left) {
                q.push(node->left);
                parents[node->left] = node;
            }
            if(node->right) {
                q.push(node->right);
                parents[node->right] = node;
            }
        }
    }
}

vector<BinaryTreeNode<int>*> printNodesAtDistanceK(BinaryTreeNode<int>* root, BinaryTreeNode<int>* target, int K) {
    // Write your code here.
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>* > parents;
    MarkParents(root, parents);
    //create a queue and visited map
    queue<BinaryTreeNode<int>*> q;
    unordered_map<BinaryTreeNode<int>*, bool> visited;
    q.push(target);
    visited[target] = true;
    //bfs
    while(!q.empty()) {
        int size = q.size();
        if(K == 0) {
            break;
        }
        for(int i = 0; i < size; i++) {
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            //check for node's left, right and parent
            if(node->left && visited[node->left] == false) {
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && visited[node->right] == false) {
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parents[node] && visited[parents[node]] == false) {
                q.push(parents[node]);
                visited[parents[node]] = true;
            }
        }
        //after completing a level
        K--;
    }

    //result
    vector<BinaryTreeNode<int>*> result;
    while(!q.empty()) {
        result.push_back(q.front());
        q.pop();
    }

    return result;

}