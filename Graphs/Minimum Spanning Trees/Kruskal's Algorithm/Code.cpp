class DisjointSet
{
	vector<int>rank,parent,size;
public :
	DisjointSet(int n)
	{
		rank.resize(n+1,0);
		size.resize(n+1,1);
		parent.resize(n+1);
		for(int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}
	}
	
	int findUltParent(int node)
	{
		if(node == parent[node])
		{
			return node;
		}
		return parent[node] = findUltParent(parent[node]);
	}

	void unionByRank(int u, int v)
	{
		int ulp_u = findUltParent(u);
		int ulp_v = findUltParent(v);
		if(ulp_u == ulp_v) return; //same parents
		if(rank[ulp_u] < rank[ulp_v])
		{
			parent[ulp_u] = ulp_v;
		}
		else if(rank[ulp_v] < rank[ulp_u])
		{
			parent[ulp_v] = ulp_u;
		}
		else
		{
			parent[ulp_u] = ulp_v;
			rank[ulp_v]++;
		}
	} 

	void unionBySize(int u, int v)
	{
		int ulp_u = findUltParent(u);
		int ulp_v = findUltParent(v);
		if(ulp_u == ulp_v) return; //same parents
		if(size[ulp_u] < size[ulp_v])
		{
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
		else
		{
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}	
	}

};


int kruskalMST(int n, vector<vector<int>> &edges)
{
	// Write your code here.
	vector<pair<int,pair<int,int>>> adj;
	for(auto it : edges)
	{
		int u = it[0];
		int v = it[1];
		int wt = it[2];
		adj.push_back({wt,{u,v}});
	}
	DisjointSet ds(n);
	sort(adj.begin(),adj.end());
	int ans = 0;
	for(auto it : adj)
	{
		int weight = it.first;
		int u = it.second.first;
		int v = it.second.second;
		if(ds.findUltParent(u) != ds.findUltParent(v))
		{
			ans += weight;
			ds.unionBySize(u,v);
		}
	}
	return ans;
}
