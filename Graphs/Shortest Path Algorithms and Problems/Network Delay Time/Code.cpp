#include <bits/stdc++.h>
int networkDelayTime(vector<vector<int>> &edges, int n, int k)
{
    // Write your code here.
    //using Dijkstra's algorithm
    //create the graph
    vector<pair<int,int>> adj[n+1];
    for(auto it : edges)
    {
        adj[it[0]].push_back({it[1],it[2]});
    }

    //dist array
    vector<int> dist(n+1,1e9);

    //priority queue 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0,k});
    dist[k] = 0;

    while(!pq.empty())
    {
        auto it = pq.top();
        int distance = it.first;
        int node = it.second;
        pq.pop();

        for(auto iterator : adj[node])
        {
            int adjNode = iterator.first;
            int newDistance = iterator.second + distance;
            if(newDistance < dist[adjNode])
            {
                dist[adjNode] = newDistance;
                pq.push({newDistance,adjNode});
            }
        }
    }
    //the minimum time it takes for all nodes to receive the signal will be the maximum time in the array
    int m = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] == 1e9)
        {
            return -1;
        }
        if(dist[i] > m)
        {
            m = dist[i];
        }
    }

        
    return m;
}