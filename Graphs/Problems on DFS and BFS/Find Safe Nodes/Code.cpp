#include <bits/stdc++.h> 

bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<int> adj[], vector<int>&mark)
{
    visited[node] = 1;
    pathVisited[node] = 1;

    for(auto adjNode : adj[node])
    {
        if(!visited[adjNode])
        {
            if(dfs(adjNode, visited, pathVisited, adj, mark) == false)
            {
                return false;
            }
        }
        else if(pathVisited[adjNode] == 1)
        {
            return false;
        }
    }
    pathVisited[node] = 0;
    mark[node] = 1;
    return true;
}


vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    // Write your code here.
    //create adjacency list
    vector<int> adj[n];
    for(int i = 0; i < e; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }  

    //visited and pathvisited
    vector<int> visited(n,0);
    vector<int> pathVisited(n,0);

    vector<int>mark(n,0);

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i,visited,pathVisited,adj,mark) == true)
            {
                mark[i] = 1;
            }
        }
    }

    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        if(mark[i] == 1)
        {
            ans.push_back(i);
        }
    }

    return ans;

}