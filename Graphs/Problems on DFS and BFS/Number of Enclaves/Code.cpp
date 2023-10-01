class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        //using bfs traversal
        int n = grid.size();
        int m = grid[0].size();
        //visited array
        vector<vector<int>>visited(n,vector<int>(m,0));
        //queue for bfs
        queue<pair<int,int>>q;
        //finding the boundary 1's and storing them in queue as starting nodes
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || j == 0 || i == n-1 || j == m-1)
                {
                    if(grid[i][j] == 1)
                    {
                        q.push({i,j});
                        visited[i][j] = 1;
                    }
                }
            }
            
        }
        //bfs - travel level wise
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0)
                {
                    q.push({nrow,ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }

        //check which 1's are not visited in the array
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1 && visited[i][j] == 0)
                {
                    count++;
                }
            }
        }

        return count;


    }
};