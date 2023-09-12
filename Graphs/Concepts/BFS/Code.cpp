vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    queue<int>q;
    vector<int>visited(n,0);
    q.push(0);
    visited[0] = 1;
    vector<int>ans;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        //put its neighbours in the queue
        for(auto it : adj[node])
        {
            if(visited[it] != 1)
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return ans;

}