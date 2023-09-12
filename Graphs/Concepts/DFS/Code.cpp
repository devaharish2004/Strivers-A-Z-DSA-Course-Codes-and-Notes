class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int val, vector<int>& dfs_ans, vector<int>& visited, vector<int> adj[])
    {
        dfs_ans.push_back(val);
        visited[val] = 1;
        for(auto it : adj[val])
        {
            if(!visited[it])
            {
                dfs(it,dfs_ans,visited,adj);
            }
        }
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>dfs_ans;
        vector<int>visited(V,0);
        
        int node = 0;
        
        dfs(node,dfs_ans,visited,adj);
        
        return dfs_ans;
        
    }
};