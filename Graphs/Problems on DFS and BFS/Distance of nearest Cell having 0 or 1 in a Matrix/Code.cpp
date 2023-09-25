vector < vector < int > > nearest(vector < vector < int >> & mat, int n, int m) {
    // Write your code here.
    // visited and ans array
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<int>> ans(n, vector<int>(m,0));
    
    // queue for storing the values
    queue<pair<pair<int, int>, int>> q; // EX : {2,3},0

    //bfs approach for levelwise traversal
    //store all the ones
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == 1)
            {
                vis[i][j] = 1;
                q.push({{i,j},0});
            }
        }
    }

    //ones are going to be the source for BFS traversal
    while(!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int step = q.front().second;
        q.pop();
        ans[row][col] = step;
        
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int i = 0; i < 4; i++)
        {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0)
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow,ncol},step+1});
            }
        }
    }

    return ans;
    
    
    
}