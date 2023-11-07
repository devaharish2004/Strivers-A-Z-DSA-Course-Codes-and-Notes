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