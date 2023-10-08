class Solution {
private :
    bool dfs(int node, int col, vector<int>& color, vector<vector<int>>& graph)
    {
        color[node] = col;
        
        for(int adjNode : graph[node])
        {
            if(color[adjNode] == -1)
            {
                if(dfs(adjNode, !col, color, graph) == false) // if any of the dfs calls return false
                {
                    return false;
                }
            }
            else if(color[adjNode] == col) //important line as this checks if the adjacent node is colored with the same color
            {
                return false;
            }
        }

        return true;

    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1); //-1 for not coloured
        //Connected components can be there
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                if(dfs(i,0,color,graph) == false) return false;
            }
        }
        return true;
    }
};