//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    
    private:
        void topoSort(int node, vector<pair<int,int>> adj[], int vis[], stack<int>&st)
        {
            vis[node] = 1;
            
            for(auto it : adj[node])
            {
                int v = it.first;
                if(!vis[v])
                {
                    topoSort(v, adj, vis, st);
                }
            }
            
            st.push(node);
        }
    
    public:
        vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
            // code here
            //the below algorithm will work for different sources
            //create the adjacency list
            vector<pair<int,int>> adj[n];
            for(int i = 0; i < m; i++)
            {   
                int start_node = edges[i][0];
                int end_node = edges[i][1];
                int distance = edges[i][2];
    
                adj[start_node].push_back(make_pair(end_node,distance));
            }
            
            
            //step 1 : Do the topo sort for the given graph - here we use topo sort using DFS
            int vis[n] = {0};
            stack<int>st;
            for(int i = 0; i < n; i++)
            {
                if(!vis[i])
                {
                    topoSort(i, adj, vis, st);
                }
            }
            
            //step 2 : Take each value from the stack and find the minimum distance
            vector<int>dist(n,1e9);
            dist[0] = 0;
            while(!st.empty())
            {
                int node = st.top();
                st.pop();
                
                for(auto it : adj[node])
                {
                    int v = it.first;
                    int weight = it.second;
                    
                    if(dist[node] + weight < dist[v])
                    {
                        dist[v] = dist[node] + weight;
                    }
                }
            }
            
            for(int i = 0; i < n; i++)
            {
                if(dist[i] == 1e9) dist[i] = -1;
            }
            
            return dist;
            
            
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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