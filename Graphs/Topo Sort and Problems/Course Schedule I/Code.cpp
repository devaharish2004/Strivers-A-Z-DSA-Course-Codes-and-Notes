//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    //form the graph initially
	    vector<int> adj[N];
	    for(auto it : prerequisites)
	    {
	        //if the pair is [0,1] then the graph will be 1->0
	        adj[it.second].push_back(it.first);
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
	        return true;
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends