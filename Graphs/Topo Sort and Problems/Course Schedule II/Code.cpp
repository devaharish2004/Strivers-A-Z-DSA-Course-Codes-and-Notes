//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
        //code here
         vector<int> adj[N];
	    for(auto it : prerequisites)
	    {
	        //if the pair is [0,1] then the graph will be 1->0
	        adj[it[1]].push_back(it[0]);
	    }
	    
	    //using topo sort - BFS approach for this problem
	    
	    vector<int>indegree(N,0);
	    
	    //initialize the indegree
	    for(int i = 0; i < N; i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i = 0; i < N; i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    //atleast one of the nodes will have indegree 0
	    vector<int>ans;
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto adjNode : adj[node])
	        {
	            indegree[adjNode]--;
	            if(indegree[adjNode] == 0)
	            {
	                q.push(adjNode);
	            }
	        }
	        
	    }
	    
	    if(ans.size() == N)
	    {
	        return ans;
	    }
	    return vector<int>();
        
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends