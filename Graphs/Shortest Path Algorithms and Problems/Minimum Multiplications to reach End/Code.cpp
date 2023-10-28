//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        //using a queue as the steps keep increasing by 1 - no need of priority queue
        //also we can store it in the queue as {node, steps} or {steps, node} - doesn't matter here
        queue<pair<int,int>> q;
        q.push({0,start});
        
        //array from 0,1,2,....,99999 - since we have to find the minimum distance for each node
        //if some node is repeated with higher steps, we won't take into the queue
        vector<int>dist(100000,1e9);
        
        dist[start] = 0;
        
        int mod = 100000;
        
        //edge case
        if(start == end) return 0;
        
        while(!q.empty())
        {
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            
            //multiply with array elements
            for(auto it : arr)
            {
                int val = (it*node)%mod;
                if(val == end) return steps + 1;
                
                if(steps + 1 < dist[val])
                {
                    dist[val] = steps+1;
                    q.push({dist[val], val});
                }
                
            }
        }
        
        return -1;
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends