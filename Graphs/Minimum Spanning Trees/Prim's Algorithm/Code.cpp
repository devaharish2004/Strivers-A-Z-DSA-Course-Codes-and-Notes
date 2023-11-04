//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //min-heap
        priority_queue<pair<int,int>,
        vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        //visited array for checking if the node is in MST
        vector<int>vis(V,0);
        
        //store {weight, node}
        pq.push({0,0});
        int sum = 0;
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            int weight = it.first;
            pq.pop();
            
            //if the node is already visited - already in MST
            if(vis[node] == 1)
            {
                continue;
            }
            
            //not visited - take it into MST as it will be the minimum distance visiting the node
            vis[node] = 1;
            sum += weight;
            
            for(auto x : adj[node])
            {
                int adjNode = x[0];
                int edgeWeight = x[1];
                
                if(!vis[adjNode])
                {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        
        return sum;
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends