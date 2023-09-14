// When using an adjacency matrix


class Solution
{
    public:

        void dfs(int node, vector<int>& visited, vector<vector<int>>& isConnected )
        {
            visited[node] = 1;
            for(int i = 0; i < isConnected.size(); i++)
            {
                if(isConnected[node-1][i] == 1 && i != node-1 && visited[i+1] != 1)
                {
                    dfs(i+1, visited, isConnected);
                }
            }
        }

        int findCircleNum(vector<vector<int>>& isConnected) 
        {
            //isConnected is an adjacency matrix
            int provinces = 0;
            int nodes = isConnected.size();
            vector<int>visited(nodes+1,0);
            for(int i = 1; i <= nodes; i++)
            {
                if(visited[i] != 1)
                {
                    provinces++;
                    dfs(i,visited,isConnected);
                }
            }
            return provinces;

        }
};


// When using an adjacency list

void dfs(int node,vector<int>adj[],int vis[])
{
    vis[node]=1;
    for(auto j:adj[node])
    {
        if(vis[j]==0)
        dfs(j,adj,vis);
    }
}
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    vector<int>adj[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(roads[i][j] && i!=j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int vis[n]={0};
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            ans++;
            dfs(i,adj,vis);
        }
    }
    return ans;
}