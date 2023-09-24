class Graph {

public:
//BFS METHOD
//   bool findCycle(int start, vector<int> adj[], int visited[]) 
//     {
//         queue<pair<int, int>> q;
//         q.push({start,-1});
//         visited[start] = 1;
//         while(!q.empty())
//         {
//             int val = q.front().first;
//             int parent = q.front().second;
//             q.pop();

//             for(int adjNode : adj[val])
//             {
//                 if(!visited[adjNode])
//                 {
//                     q.push({adjNode,val});
//                     visited[adjNode] = 1;
//                 }
//                 else if(parent != adjNode)
//                 {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

//DFS APPROACH

    bool findCycle(int start, int parent, vector<int> adj[], int visited[])
    {
        visited[start] = 1;
        for(int adjNode : adj[start])
        {
            if(!visited[adjNode])
            {
                bool ans = findCycle(adjNode, start, adj, visited);
                if(ans == true)
                {
                    return true;
                }
            }
            else if(adjNode != parent)
            {
                return true;
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
        
        //create a visited array

        int visited[V] = {0};

        //for connected components
        for(int i =0; i < V; i++)
        {
            if(!visited[i])
            {
                bool ans = findCycle(i, -1, adj, visited); //carry the parent also
                if(ans == true)
                {
                    return true;
                }
            }
        }
        return false;
        
    }
};