//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        //create adjacency list
        vector<int> adj[N];
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        //use distance array - visited array is not needed as we will calculate if it is visited in distance array itself 
        vector<int>distance(N,1e9);
        
        queue<int>q; //for storing the node and its distance from the source node
        q.push(src);
        distance[src] = 0;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto adjNode : adj[node])
            {
                if(distance[node] + 1 < distance[adjNode])
                {
                    q.push(adjNode);
                    distance[adjNode] = distance[node]+1;
                }
            }
        }
        
        vector<int>ans(N,-1);
        for(int i = 0; i < N; i++)
        {
            if(distance[i] == 1e9)
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = distance[i];
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends