//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        //create undirected graph (since given bi-directional)
        vector<pair<int,int>> adj[n];
        for(auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        //create the min heap with {distance, node}
        priority_queue< pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>> > pq;
            
        
        //dist array and ways array
        vector<long>dist(n,1e18);
        vector<int>ways(n,0);
        
        //initial config
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        int mod = (int)(1e9+7);
        
        //Dijsktra's algorithm
        while(!pq.empty())
        {
            long distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if(distance + edgeWeight < dist[adjNode]) //first time we found a shorter path
                {
                    dist[adjNode] = (distance + edgeWeight);
                    
                    pq.push({dist[adjNode], adjNode});
                    
                    ways[adjNode] = ways[node]%mod; //takes the number of paths as its parent node
                }
                else if(distance + edgeWeight == dist[adjNode]) //if the path length is same as the minimum
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod; //takes the number of paths as its parent node + the number of ways that it can be reached with shortest distance.
                }
            }
        }
        
        return (ways[n-1]) % mod;
        
    }
    
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends