//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) 
    {
        vector<vector<int>> mat(n, vector<int>(n,1e9));
    	for(int i = 0; i < n; i++)
    	{
    		mat[i][i] = 0;
    	}
    
    	for(auto it : edges)
    	{
    		mat[it[0]][it[1]] = it[2];
    		mat[it[1]][it[0]] = it[2];
    	}
    
    	//floyd warshall algorithm
    	for(int k = 0; k < n; k++)
    	{
    		for(int i = 0; i < n; i++)
    		{
    			for(int j = 0; j < n; j++)
    			{
    				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
    			}
    		}
    	}
    
    	int city = -1;
    	int max_city = n;
    	for(int i = 0; i < n;  i++)
    	{
    		int count = 0;
    		for(int j = 0; j < n; j ++)
    		{
    			if(mat[i][j] <= distanceThreshold)
    			{
    				count++;
    			}
    		}
    		if(count <= max_city)
    		{
    			max_city = count;
    			city = i;
    		}
    	}
    	return city;
                         
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends