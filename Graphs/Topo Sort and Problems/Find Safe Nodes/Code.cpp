class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //using bfs
        //first step - reverse the graph
        int v = graph.size();
        vector<int>indegree(v,0);
        vector<int> adjRev[v];
        for(int i = 0; i < v; i++)
        {
            for(auto it : graph[i])
            {
                //i -> it
                //we want it->i
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        //second step - declare the queue and find the terminal nodes and push the terminal nodes
        queue<int>q;
        vector<int> safeNodes;
        for(int i = 0; i < v; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        //third step - use topo sort - start from the terminal nodes
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto adjNode : adjRev[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                {
                    q.push(adjNode);
                }
            }
        }

        //finally sort the safeNodes so that it will be in increasing order
        sort(safeNodes.begin(),safeNodes.end());

        return safeNodes;
    }
};