/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root == nullptr) return 0;

    int ans = 0;

    //level order traversal
    queue<pair<TreeNode<int>*, int>> q;

    q.push({root, 0});

    while(!q.empty())
    {
        int min_index = q.front().second;
        int q_size = q.size();
        int first, last;
        //take the level completely
        for(int i = 0; i < q_size;  i++)
        {
           TreeNode<int>* node = q.front().first;
           int cur_index = q.front().second - min_index;
           q.pop();
           if(i == 0) first = cur_index;
           if(i == q_size - 1) last = cur_index;

           if(node->left)
           {
               q.push({ node->left, cur_index*2 + 1 });
           }

           if(node->right)
           {
               q.push({ node->right, cur_index*2 + 2 });
           }

           cout << node->val << endl;
        }

        ans = max(ans, last-first+1);
    }

    return ans;


}

// TC : O(N)
// SC : O(W)

// This is done if the null values between two nodes in a level are considered. Otherwise, a simple level order traversal will do so.