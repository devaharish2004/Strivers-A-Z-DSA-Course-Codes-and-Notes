class Graph {

public:
  bool findCycle(int start, vector<int> adj[], int visited[]) 
    {
        queue<pair<int, int>> q;
        q.push({start,-1});
        visited[start] = 1;
        while(!q.empty())
        {
            int val = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(int adjNode : adj[val])
            {
                if(!visited[adjNode])
                {
                    q.push({adjNode,val});
                    visited[adjNode] = 1;
                }
                else if(parent != adjNode)
                {
                    return true;
                }
            }
        }
        return false;
    }


    bool detectCycle(int V, vector<int> adj[]) {
        // Write your code here.

        //this is the code to check the adjacency array

        // for(int i = 0; i < V; i++)
        // {
        //     for(auto it : adj[i])
        //     {
        //         cout << it << " ";
        //     }
        //     cout << endl;
        // }


        // a cycle is present if a node visited is visited again
        //using bfs
        
        //create a visited array

        int visited[V] = {0};

        //for connected components
        for(int i =0; i < V; i++)
        {
            if(!visited[i])
            {
                bool ans = findCycle(i, adj, visited);
                if(ans == true)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};