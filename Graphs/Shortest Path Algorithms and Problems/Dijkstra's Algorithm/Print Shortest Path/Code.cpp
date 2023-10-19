//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here 
        //create the graph initially
        //1-based indexing
        vector<pair<int,int>> adj[n+1];
        for(auto it : edges)
        {
            int startNode = it[0];
            int endNode = it[1];
            int weight = it[2];
            adj[startNode].push_back({endNode,weight});
            adj[endNode].push_back({startNode,weight});
        }
        
        //using Dijkstra's algorithm and remembering the parent node for each node when the shortest distances are updated
        //priority queue - min heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        //distance array
        vector<int>dist(n+1, 1e9);
        
        //parent array for remembering the last node from where the shortest path comes to the node
        vector<int>parent(n+1);
        //initialize all the elements with the same element
        for(int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        
        dist[1] = 0;
        pq.push({0,1});
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int distance = it.first;
            int node = it.second;
            pq.pop();
            
            for(auto adjacentPair : adj[node])
            {
                int adjNode = adjacentPair.first;
                int adjDistance = adjacentPair.second;
                
                if(distance + adjDistance < dist[adjNode])
                {
                    dist[adjNode] = distance + adjDistance;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }
        
        //if not able to reach the destination node
        if(dist[n] == 1e9)
        {
            return {-1};
        }
        
        //backtracking the answers, starting from the destination node
        vector<int>ans;
        int final_node = n;
        //if it is equal to final_node, then that is the source node
        while(parent[final_node] != final_node)
        {
            ans.push_back(final_node);
            final_node = parent[final_node];
        }
        
        //source will not be added due to the condition in the while loop
        ans.push_back(1);
        
        //the path will be in reverse
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends