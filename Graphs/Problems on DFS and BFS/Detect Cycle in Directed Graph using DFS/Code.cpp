bool dfs(int node, vector<int>&vis, vector<int>&pathVis, vector<int> adj[])
{
	vis[node] = 1;
	pathVis[node] = 1;

	for(int adjNode : adj[node])
	{
		if(!vis[adjNode]) //if it is not visited
		{
			if(dfs(adjNode, vis, pathVis, adj) == true)
			{
				return true;
			}
		}
		//if the adjNode is visited and it is on the same path
		else if(pathVis[adjNode])
		{
			return true;
		}
	}

	//when returning from the path, make sure to make pathVis of the node zero
	pathVis[node] = 0;
	return false;
}



bool isCyclic(vector<vector<int>>& edges, int v, int e)
{
	// Write your code here
	//convert to adjacency list
	vector<int> adj[v];
	int n = edges.size();
	for(int i = 0; i < n; i++)
	{	
		adj[edges[i][0]].push_back(edges[i][1]);
	}

	vector<int> vis(v,0);
	vector<int>pathVis(v,0);

	for(int i = 0; i < v; i++)
	{
		if(!vis[i])
		{
			if(dfs(i,vis,pathVis,adj) == true)
			{
				return true;
			}
		}
	}

	return false;

	
}
