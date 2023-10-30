int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    //create the adjacency matrix
    vector<vector<int>>adj(n+1,vector<int>(n+1,1e9));
    for(int i=1; i<=n; i++)
    {
        adj[i][i]=0;
    }
    
    for(auto it : edges)
    {
        adj[it[0]][it[1]] = it[2];
    }

    //algorithm
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(adj[i][k]!=1e9 && adj[k][j]!=1e9) //to avoid overflow conditions (given here according to the problem)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    return adj[src][dest];

}